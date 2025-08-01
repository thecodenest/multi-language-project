document.addEventListener('DOMContentLoaded', () => {
    const ageInput = document.getElementById('ageInput');
    const subjectSelect = document.getElementById('subjectSelect');
    const startGKQuizBtn = document.getElementById('startGKQuizBtn');
    const gkQuizSetup = document.getElementById('gkQuizSetup'); 
    const gkQuizContainer = document.getElementById('gkQuizContainer');
    const gkQuizResults = document.getElementById('gkQuizResults'); 
    const gkFinalScore = document.getElementById('gkFinalScore'); 
    const gkTotalQuestions = document.getElementById('gkTotalQuestions'); 

    // Music elements
    const musicToggleButton = document.getElementById('musicToggleButton');
    const speakerIcon = document.getElementById('speakerIcon');
    const backgroundMusic = document.getElementById('backgroundMusic');
    let isPlaying = false; // Initial state for music

    // Quiz State Variables
    let currentQuestionIndex = 0;
    let score = 0;
    let quizData = []; // Questions for the current quiz
    let overallTimerInterval = null; // Overall quiz timer
    let overallTimeLeft = 120; // 2 minutes = 120 seconds

    const gkQuestions = {
        science: [
            { question: "What planet is known as the Red Planet?", options: ["Earth", "Mars", "Venus", "Jupiter"], answer: 1 }, // Index 1 for Mars
            { question: "What is H2O commonly known as?", options: ["Salt", "Water", "Oxygen", "Hydrogen Peroxide"], answer: 1 },
            { question: "What is the chemical symbol for Gold?", options: ["Ag", "Au", "Fe", "Pb"], answer: 1 },
            { question: "Which force pulls objects towards the center of the Earth?", options: ["Magnetism", "Friction", "Gravity", "Tension"], answer: 2 },
            { question: "What is the nearest star to Earth?", options: ["Proxima Centauri", "Sirius", "Sun", "Alpha Centauri"], answer: 2 },
        ],
        math: [
            { question: "What is 5 + 7?", options: ["10", "12", "14", "11"], answer: 1 },
            { question: "What is the square root of 16?", options: ["3", "4", "5", "8"], answer: 1 },
            { question: "If a = 3 and b = 4, what is a * b?", options: ["7", "1", "12", "10"], answer: 2 },
            { question: "What is 15 divided by 3?", options: ["3", "4", "5", "6"], answer: 2 },
            { question: "Which number is prime?", options: ["4", "6", "9", "7"], answer: 3 },
        ],
        geography: [
            { question: "Which is the largest continent by land area?", options: ["Africa", "North America", "Asia", "Europe"], answer: 2 },
            { question: "What is the capital of France?", options: ["London", "Berlin", "Paris", "Rome"], answer: 2 },
            { question: "Which ocean is the largest?", options: ["Atlantic", "Indian", "Arctic", "Pacific"], answer: 3 },
            { question: "What is the longest river in the world?", options: ["Amazon", "Nile", "Mississippi", "Yangtze"], answer: 1 },
            { question: "Which country is famous for its pyramids?", options: ["Italy", "Egypt", "Mexico", "Greece"], answer: 1 },
        ],
        history: [
            { question: "Who was the first President of the United States?", options: ["Abraham Lincoln", "Thomas Jefferson", "George Washington", "John Adams"], answer: 2 },
            { question: "When did World War II end?", options: ["1942", "1945", "1950", "1939"], answer: 1 },
            { question: "Which ancient civilization built the Colosseum?", options: ["Greeks", "Egyptians", "Romans", "Mayans"], answer: 2 },
            { question: "Who discovered America in 1492?", options: ["Vasco da Gama", "Ferdinand Magellan", "Christopher Columbus", "Marco Polo"], answer: 2 },
            { question: "The Magna Carta was signed in what year?", options: ["1066", "1215", "1492", "1776"], answer: 1 },
        ],
        sports: [
            { question: "How many players are on a standard soccer team?", options: ["9", "10", "11", "12"], answer: 2 },
            { question: "Which sport uses a shuttlecock?", options: ["Tennis", "Badminton", "Squash", "Table Tennis"], answer: 1 },
            { question: "In which country did the Olympic Games originate?", options: ["Italy", "Greece", "Egypt", "China"], answer: 1 },
            { question: "What is the maximum number of points you can score with a single dart throw?", options: ["50", "60", "100", "180"], answer: 1 },
            { question: "Which golf major is played at Augusta National?", options: ["The Open Championship", "US Open", "PGA Championship", "The Masters"], answer: 3 },
        ]
    };

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
    window.onload = function() {
        speakerIcon.classList.replace('fa-volume-up', 'fa-volume-mute');
        isPlaying = false;
        backgroundMusic.pause();
        backgroundMusic.currentTime = 0;
    };
    // --- End Music Toggle ---

    startGKQuizBtn.onclick = () => {
        const age = parseInt(ageInput.value);
        const subject = subjectSelect.value;

        if (!age || age < 5) {
            alert("Please enter a valid age (5+).");
            return;
        }

        quizData = gkQuestions[subject];

        if (!quizData || quizData.length === 0) {
            alert("No quiz available for this subject.");
            return;
        }

        // Hide setup, show quiz container
        gkQuizSetup.classList.add('hidden');
        gkQuizContainer.classList.remove('hidden');

        // Reset quiz state
        currentQuestionIndex = 0;
        score = 0;
        overallTimeLeft = 30; // Reset timer for new quiz

        startOverallTimer();
        showQuestion();
    };

    function startOverallTimer() {
        const timerDisplay = document.createElement('div');
        timerDisplay.id = 'overallTimer';
        timerDisplay.className = 'text-xl font-bold text-red-600 dark:text-red-400 mb-6 text-center';
        gkQuizContainer.prepend(timerDisplay); // Add timer above the first question

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
        const existingQuestionDiv = gkQuizContainer.querySelector('.question-card');
        if (existingQuestionDiv) {
            existingQuestionDiv.remove();
        }

        // Check if quiz is finished or timer ran out
        if (currentQuestionIndex >= quizData.length || overallTimeLeft <= 0) {
            showResults();
            return;
        }

        const qData = quizData[currentQuestionIndex];

        const questionCard = document.createElement('div');
        questionCard.className = 'question-card bg-gray-100 dark:bg-gray-700 p-6 rounded-lg shadow-md';
        questionCard.innerHTML = `
            <h2 class="text-2xl font-bold mb-4 text-purple-600 dark:text-purple-300">
                Question ${currentQuestionIndex + 1} of ${quizData.length}:
                <span class="block mt-2">${qData.question}</span>
            </h2>
            <div id="optionsContainer" class="space-y-3"></div>
            <div id="feedbackContainer" class="mt-4 text-center text-lg font-semibold hidden"></div>
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
            btn.dataset.index = idx; // Store original index
            btn.onclick = (event) => checkAnswer(event, idx); // Pass event to disable all
            optionsContainer.appendChild(btn);
        });

        gkQuizContainer.appendChild(questionCard);

        nextQuestionBtn.onclick = () => {
            currentQuestionIndex++;
            showQuestion();
        };
    }

    function checkAnswer(event, selectedIndex) {
        // Disable all option buttons after selection
        const optionButtons = gkQuizContainer.querySelectorAll('.option-btn');
        optionButtons.forEach(btn => btn.disabled = true);

        const correctIndex = quizData[currentQuestionIndex].answer; // 0-indexed correct answer
        const feedbackContainer = gkQuizContainer.querySelector('#feedbackContainer');
        const selectedButton = event.target;
        const nextQuestionBtn = gkQuizContainer.querySelector('#nextQuestionBtn');

        if (selectedIndex === correctIndex) { // Check against 0-indexed answer
            score++;
            selectedButton.classList.remove('bg-gray-200', 'dark:bg-gray-600');
            selectedButton.classList.add('bg-green-200', 'dark:bg-green-700', 'border-2', 'border-green-500');
            feedbackContainer.innerHTML = '<i class="fas fa-check-circle text-green-500 mr-2"></i> Correct!';
            feedbackContainer.classList.remove('hidden');
        } else {
            selectedButton.classList.remove('bg-gray-200', 'dark:bg-gray-600');
            selectedButton.classList.add('bg-red-200', 'dark:bg-red-700', 'border-2', 'border-red-500');
            feedbackContainer.innerHTML = '<i class="fas fa-times-circle text-red-500 mr-2"></i> Incorrect!';
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
        gkQuizContainer.classList.add('hidden'); // Hide quiz container
        gkQuizResults.classList.remove('hidden'); // Show results container

        gkFinalScore.textContent = score;
        gkTotalQuestions.textContent = quizData.length;
    }
});