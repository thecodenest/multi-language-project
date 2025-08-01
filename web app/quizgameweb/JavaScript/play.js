// play.js
import { db, doc, getDoc } from '../JavaScript/firebase.js';

document.addEventListener('DOMContentLoaded', () => {
    const playerNameInput = document.getElementById('playerName');
    const quizCodeInput = document.getElementById('quizCode');
    const startQuizBtn = document.getElementById('startQuizBtn');
    const quizSetup = document.getElementById('quizSetup'); // Reference to the setup div
    const quizContainer = document.getElementById('quizContainer');
    const quizResults = document.getElementById('quizResults'); // Reference to results div
    const finalPlayerName = document.getElementById('finalPlayerName'); // Player name in results
    const finalScore = document.getElementById('finalScore'); // Score in results
    const totalQuestionsDisplay = document.getElementById('totalQuestions'); // Total questions in results

    // Music elements
    const musicToggleButton = document.getElementById('musicToggleButton');
    const speakerIcon = document.getElementById('speakerIcon');
    const backgroundMusic = document.getElementById('backgroundMusic');
    let isPlaying = false; // Initial state for music

    let currentQuestionIndex = 0;
    let score = 0;
    let quizData = null; // Stores the fetched quiz data
    let overallTimerInterval = null; // Overall quiz timer
    let overallTimeLeft = 120; // 2 minutes = 120 seconds

    // --- Music Toggle Functionality (moved here from HTML) ---
    function toggleMusic() {
        if (isPlaying) {
            backgroundMusic.pause();
            speakerIcon.classList.replace('fa-volume-up', 'fa-volume-mute');
        } else {
            backgroundMusic.play();
            speakerIcon.classList.replace('fa-volume-mute', 'fa-volume-up');
        }
        isPlaying = !isPlaying;
    }
    musicToggleButton.addEventListener('click', toggleMusic);

    // Set initial state to muted on page load for music
    window.addEventListener('load', function() { // Use DOMContentLoaded for general script, load for images/media
        speakerIcon.classList.replace('fa-volume-up', 'fa-volume-mute');
        isPlaying = false;
        backgroundMusic.pause();
        backgroundMusic.currentTime = 0;
    });
    // --- End Music Toggle ---

    startQuizBtn.onclick = async () => {
        const playerName = playerNameInput.value.trim();
        const quizCode = quizCodeInput.value.trim().toUpperCase();

        if (!playerName) {
            alert("Please enter your name.");
            return;
        }

        // Option to play last created quiz if quizCode is empty
        let fetchedQuizData = null;
        if (!quizCode) {
            const lastQuiz = localStorage.getItem('lastCreatedQuiz');
            if (lastQuiz) {
                const quizDocRef = doc(db, "quizzes", lastQuiz);
                const quizDocSnap = await getDoc(quizDocRef);
                if (quizDocSnap.exists()) {
                    fetchedQuizData = quizDocSnap.data();
                    console.log("Loaded last created quiz:", lastQuiz);
                } else {
                    alert("No custom quiz found or the last created quiz is no longer available.");
                    return;
                }
            } else {
                alert("Please enter a quiz code or create a quiz first.");
                return;
            }
        } else {
            const docRef = doc(db, "quizzes", quizCode);
            const docSnap = await getDoc(docRef);

            if (docSnap.exists()) {
                fetchedQuizData = docSnap.data();
            } else {
                alert("Quiz not found. Please check the code.");
                return;
            }
        }

        quizData = fetchedQuizData;

        quizSetup.classList.add('hidden');
        quizContainer.classList.remove('hidden');


        currentQuestionIndex = 0;
        score = 0;
        overallTimeLeft = 60; 

        startOverallTimer();
        showQuestion();
    };

    function startOverallTimer() {
        const timerDisplay = document.createElement('div');
        timerDisplay.id = 'overallTimer';
        timerDisplay.className = 'text-xl font-bold text-red-600 dark:text-red-400 mb-6 text-center';
        // Check if timer already exists, if not, prepend
        if (!quizContainer.querySelector('#overallTimer')) {
             quizContainer.prepend(timerDisplay);
        }

        overallTimerInterval = setInterval(() => {
            overallTimeLeft--;
            const minutes = Math.floor(overallTimeLeft / 60);
            const seconds = overallTimeLeft % 60;
            timerDisplay.textContent = `Overall Time Left: ${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;

            if (overallTimeLeft <= 0) {
                clearInterval(overallTimerInterval);
                showResults();
            }
        }, 1000);
    }

    function showQuestion() {
        // Clear previous question, if any
        const existingQuestionCard = quizContainer.querySelector('.question-card');
        if (existingQuestionCard) {
            existingQuestionCard.remove();
        }

        // Check if quiz is finished or timer ran out
        if (currentQuestionIndex >= quizData.questions.length || overallTimeLeft <= 0) {
            showResults();
            return;
        }

        const qData = quizData.questions[currentQuestionIndex];

        const questionCard = document.createElement('div');
        questionCard.className = 'question-card bg-gray-100 dark:bg-gray-700 p-6 rounded-lg shadow-md space-y-4';
        questionCard.innerHTML = `
            <h2 class="text-2xl font-bold mb-4 text-purple-600 dark:text-purple-300">
                Question ${currentQuestionIndex + 1} of ${quizData.questions.length}:
                <span class="block mt-2">${qData.question}</span>
            </h2>
            <div id="optionsContainer" class="space-y-3"></div>
            <div id="feedbackContainer" class="mt-4 text-center text-lg font-semibold flex items-center justify-center gap-2 hidden"></div>
            <button id="nextQuestionBtn" class="button-primary text-white font-bold py-3 px-6 rounded-lg mt-6 w-full hidden">
                <i class="fas fa-arrow-right mr-2"></i> Next Question
            </button>
        `;

        const optionsContainer = questionCard.querySelector('#optionsContainer');
        const feedbackContainer = questionCard.querySelector('#feedbackContainer');
        const nextQuestionBtn = questionCard.querySelector('#nextQuestionBtn');

        qData.options.forEach((opt, idx) => {
            const btn = document.createElement('button');
            btn.textContent = opt;
            btn.className = "option-btn block w-full px-5 py-3 bg-gray-200 dark:bg-gray-600 rounded-md text-left transition-colors duration-200 ease-in-out hover:bg-purple-200 dark:hover:bg-purple-800 focus:outline-none focus:ring-2 focus:ring-purple-500 text-gray-800 dark:text-gray-200";
            btn.dataset.index = idx; // Store 0-indexed option
            btn.onclick = (event) => checkAnswer(event, idx); // Pass event and 0-indexed selected option
            optionsContainer.appendChild(btn);
        });

        // Prepend the new question card after the timer
        const overallTimerDisplay = quizContainer.querySelector('#overallTimer');
        if (overallTimerDisplay) {
            overallTimerDisplay.after(questionCard);
        } else {
            quizContainer.appendChild(questionCard);
        }

        nextQuestionBtn.onclick = () => {
            currentQuestionIndex++;
            showQuestion();
        };
    }

    function checkAnswer(event, selectedIndex) {
        // Disable all option buttons after selection
        const optionButtons = quizContainer.querySelectorAll('.option-btn');
        optionButtons.forEach(btn => btn.disabled = true);

        // Correct answer index is stored in correctAnswerIndex property
        const correctIndex = quizData.questions[currentQuestionIndex].correctAnswerIndex;
        const feedbackContainer = quizContainer.querySelector('#feedbackContainer');
        const selectedButton = event.target;
        const nextQuestionBtn = quizContainer.querySelector('#nextQuestionBtn');

        if (selectedIndex === correctIndex) {
            score++;
            selectedButton.classList.remove('bg-gray-200', 'dark:bg-gray-600', 'hover:bg-purple-200', 'dark:hover:bg-purple-800');
            selectedButton.classList.add('bg-green-200', 'dark:bg-green-700', 'border-2', 'border-green-500');
            feedbackContainer.innerHTML = '<i class="fas fa-check-circle text-green-500 text-2xl"></i> <span class="text-green-600 dark:text-green-400">Correct!</span>';
            feedbackContainer.classList.remove('hidden');
        } else {
            selectedButton.classList.remove('bg-gray-200', 'dark:bg-gray-600', 'hover:bg-purple-200', 'dark:hover:bg-purple-800');
            selectedButton.classList.add('bg-red-200', 'dark:bg-red-700', 'border-2', 'border-red-500');
            feedbackContainer.innerHTML = '<i class="fas fa-times-circle text-red-500 text-2xl"></i> <span class="text-red-600 dark:text-red-400">Incorrect!</span>';
            feedbackContainer.classList.remove('hidden');

            // Highlight the correct answer
            const correctButton = Array.from(optionButtons).find(btn => parseInt(btn.dataset.index) === correctIndex);
            if (correctButton) {
                correctButton.classList.remove('bg-gray-200', 'dark:bg-gray-600');
                correctButton.classList.add('bg-green-200', 'dark:bg-green-700', 'border-2', 'border-green-500');
            }
        }
        nextQuestionBtn.classList.remove('hidden'); // Show the next button
    }

    function showResults() {
        clearInterval(overallTimerInterval); // Stop the overall timer
        quizContainer.classList.add('hidden'); // Hide quiz container
        quizResults.classList.remove('hidden'); // Show results container

        finalPlayerName.textContent = playerNameInput.value.trim();
        finalScore.textContent = score;
        totalQuestionsDisplay.textContent = quizData.questions.length;
    }
});