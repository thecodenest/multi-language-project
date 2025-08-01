// create.js
import { db, collection, doc, setDoc } from '../JavaScript/firebase.js';

document.addEventListener('DOMContentLoaded', () => {
    const quizTitleInput = document.getElementById('quizTitle');
    const numQuestionsInput = document.getElementById('numQuestions');
    const generateFormBtn = document.getElementById('generateForm');
    const questionsForm = document.getElementById('questionsForm');
    const saveQuizBtn = document.getElementById('saveQuiz');
    const quizCodeDisplay = document.createElement('div'); // New element to display code
    quizCodeDisplay.className = 'mt-6 p-4 bg-purple-100 dark:bg-purple-900 text-purple-800 dark:text-purple-200 rounded-lg shadow-inner hidden';
    quizCodeDisplay.innerHTML = `<p class="font-semibold">Your Quiz Code: <span id="generatedCode" class="text-xl font-bold select-all"></span></p>
                                <p class="text-sm mt-1">Copy this code and share it with players!</p>`;
    questionsForm.after(quizCodeDisplay); // Append after the form

    // Music elements (copy-pasted, should ideally be in a shared file or handled by theme-toggle)
    const musicToggleButton = document.getElementById('musicToggleButton');
    const speakerIcon = document.getElementById('speakerIcon');
    const backgroundMusic = document.getElementById('backgroundMusic');
    let isPlaying = false; 
    
    function toggleMusic() {
      if (isPlaying) {
        backgroundMusic.pause();
        speakerIcon.classList.remove('fa-volume-up');
        speakerIcon.classList.add('fa-volume-mute');
      } else {
        backgroundMusic.play();
        speakerIcon.classList.remove('fa-volume-mute');
        speakerIcon.classList.add('fa-volume-up');
      }
      isPlaying = !isPlaying;
    }
    musicToggleButton.addEventListener('click', toggleMusic);
    window.addEventListener('load', function() {
      speakerIcon.classList.remove('fa-volume-up');
      speakerIcon.classList.add('fa-volume-mute');
      isPlaying = false;
      backgroundMusic.pause(); // Ensure it's paused initially
      backgroundMusic.currentTime = 0; // Reset music to start
    });
    // End Music elements

    generateFormBtn.onclick = () => {
        const numQuestions = parseInt(numQuestionsInput.value);
        if (isNaN(numQuestions) || numQuestions <= 0) {
            alert('Please enter a valid number of questions (at least 1).');
            return;
        }

        questionsForm.innerHTML = ''; // Clear previous questions
        quizCodeDisplay.classList.add('hidden'); // Hide code display on new generation

        for (let i = 0; i < numQuestions; i++) {
            const questionDiv = document.createElement('div');
            questionDiv.className = 'bg-gray-100 dark:bg-gray-700 p-6 rounded-lg shadow-md'; // Apply card styling
            questionDiv.innerHTML = `
                <h3 class="text-xl font-bold mb-4 text-purple-600 dark:text-purple-300">Question ${i + 1}</h3>
                <div class="mb-4">
                    <label for="questionText${i}" class="block text-md font-semibold mb-2">Question:</label>
                    <input type="text" id="questionText${i}" class="input-field p-3 w-full rounded-md" placeholder="Enter your question" />
                </div>
                <div class="space-y-2">
                    <label class="block text-md font-semibold mb-2">Options (enter 4 options, mark the correct one):</label>
                    <input type="text" id="option${i}-0" class="input-field p-2 w-full rounded-md" placeholder="Option 1" />
                    <input type="text" id="option${i}-1" class="input-field p-2 w-full rounded-md" placeholder="Option 2" />
                    <input type="text" id="option${i}-2" class="input-field p-2 w-full rounded-md" placeholder="Option 3" />
                    <input type="text" id="option${i}-3" class="input-field p-2 w-full rounded-md" placeholder="Option 4" />
                </div>
                <div class="mt-4">
                    <label for="correctOption${i}" class="block text-md font-semibold mb-2">Correct Option Index (0-3):</label>
                    <input type="number" id="correctOption${i}" class="input-field p-2 w-full rounded-md" min="0" max="3" placeholder="e.g., 0 for Option 1" />
                </div>
            `;
            questionsForm.appendChild(questionDiv);
        }
        saveQuizBtn.classList.remove('hidden'); // Show save button
    };

    saveQuizBtn.onclick = async () => {
        const quizTitle = quizTitleInput.value.trim();
        if (!quizTitle) {
            alert('Please enter a quiz title.');
            return;
        }

        const questions = [];
        const numQuestions = parseInt(numQuestionsInput.value);
        for (let i = 0; i < numQuestions; i++) {
            const questionText = document.getElementById(`questionText${i}`).value.trim();
            const options = [];
            for (let j = 0; j < 4; j++) {
                options.push(document.getElementById(`option${i}-${j}`).value.trim());
            }
            const correctOptionIndex = parseInt(document.getElementById(`correctOption${i}`).value); // Changed to correctOptionIndex

            if (!questionText || options.some(opt => !opt) || isNaN(correctOptionIndex) || correctOptionIndex < 0 || correctOptionIndex > 3) {
                alert(`Please fill in all fields for Question ${i + 1} and ensure the correct option index is between 0 and 3.`);
                return;
            }

            questions.push({
                question: questionText,
                options: options,
                correctAnswerIndex: correctOptionIndex // Store as correctOptionIndex
            });
        }

        const quizData = {
            quizTitle: quizTitle,
            questions: questions
        };

        const code = Math.random().toString(36).substr(2, 6).toUpperCase();

        try {
            await setDoc(doc(collection(db, "quizzes"), code), quizData);

            // Store the last created quiz code in local storage
            localStorage.setItem('lastCreatedQuiz', code);

            // Display the quiz code to the user
            document.getElementById('generatedCode').textContent = code;
            quizCodeDisplay.classList.remove('hidden');

            alert(`Quiz "${quizTitle}" saved successfully!`); // Keep alert as a confirmation
            console.log(`Quiz saved with code: ${code}`);

            // Create .txt file
            let txt = `Quiz Title: ${quizTitle}\nQuiz Code: ${code}\n\n`;
            questions.forEach((q, i) => {
                txt += `Q${i + 1}: ${q.question}\n`;
                q.options.forEach((opt, idx) => {
                    txt += `  ${idx + 1}: ${opt}\n`; // Display 1-indexed for user
                });
                txt += `Correct Answer: ${q.options[q.correctAnswerIndex]}\n\n`; // Use correctAnswerIndex for actual answer
            });

            const blob = new Blob([txt], { type: 'text/plain' });
            const url = URL.createObjectURL(blob);
            const a = document.createElement('a');
            a.href = url;
            a.download = `${quizTitle || 'quiz'}-code-${code}.txt`;
            document.body.appendChild(a);
            a.click();
            document.body.removeChild(a);
            URL.revokeObjectURL(url); // Clean up the URL object

        } catch (error) {
            console.error("Error saving quiz: ", error);
            alert("Failed to save quiz. Please try again.");
        }
    };
});