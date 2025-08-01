import pyttsx3                     # Import the text-to-speech conversion library
import speech_recognition as sr    # Import the speech recognition library to process voice input
import datetime                    # Import the datetime module to work with dates and times
import wikipedia                   # Import the Wikipedia library to fetch information from Wikipedia
import webbrowser                  # Import the webbrowser module to open websites
import os                          # Import the os module to interact with the operating system

# Initialize text-to-speech engine using Windows sapi5 voices
engine = pyttsx3.init('sapi5')     
voices = engine.getProperty('voices')   # Get the list of available voices
engine.setProperty('voice', voices[0].id)   # Set the voice to the first voice in the list
engine.setProperty('rate', 150)             # Set the speaking rate (words per minute)

# Function to make the system speak a given text
def speak(audio):
    engine.say(audio)           # Convert the text (audio) to speech
    engine.runAndWait()         # Wait until the speech is finished before proceeding

# Function to greet the user based on the current time of day
def wishMe():
    hour = int(datetime.datetime.now().hour)  # Get the current hour (0 to 23)
    if 0 <= hour < 12:                          # If hour is between 0 (midnight) and 11:59 AM
        speak("Good Morning!")                  # Greet with "Good Morning!"
    elif 12 <= hour < 18:                       # If hour is between 12 PM and 5:59 PM
        speak("Good Afternoon!")                # Greet with "Good Afternoon!"
    else:                                       # For any hour from 6 PM to 11:59 PM
        speak("Good Evening!")                  # Greet with "Good Evening!"
    speak("I am Jarvis. Ready to comply. What can I do for you?")  # Introduce the assistant

# Function to capture voice input from the user and convert it to text
def takeCommand():
    r = sr.Recognizer()                         # Create a Recognizer object for speech recognition
    with sr.Microphone() as source:              # Use the computer's microphone as the audio source
        print("Listening...")                    # Print to console that the program is listening
        r.pause_threshold = 1                    # Set a pause threshold (wait time before considering the speech ended)
        audio = r.listen(source)                 # Listen and record the user's speech
        try:
            print("Recognizing...")              # Print to console that the program is processing the audio
            query = r.recognize_google(audio, language='en-in').lower()  # Convert speech to text using Google and convert it to lowercase
            print(f"User said: {query}")         # Print what the user said
            return query                         # Return the recognized text
        except Exception:                        # If an error occurs during recognition
            print("Say that again, please...")   # Ask the user to repeat
            return "none"                        # Return "none" to indicate failure

# Function to close a specified browser by its process name
def closeBrowser(browser_name):
    # Dictionary mapping browser names to their executable process names
    browser_processes = {
        "chrome": "chrome.exe",  
        "edge": "msedge.exe",
    }
    if browser_name in browser_processes:         # If the specified browser exists in our dictionary
        # Use the operating system command to kill the browser process
        os.system(f"taskkill /f /im {browser_processes[browser_name]}")
        speak(f"Closing {browser_name}")           # Inform the user that the browser is closing
    else:
        speak("I couldn't find the browser to close.")  # Inform the user if the browser is not found

# Function to search Wikipedia for a user-specified topic
def searchWikipedia():
    speak("What topic should I search on Wikipedia?")   # Ask the user for the topic
    topic = takeCommand()                                  # Get the topic from the user's voice input
    if topic != "none":                                    # If a valid topic is provided
        try:
            speak("Searching Wikipedia...")              # Inform the user that the search is in progress
            # Get a summary of the topic (2 sentences) from Wikipedia without auto-suggestions
            results = wikipedia.summary(topic, sentences=2, auto_suggest=False)
            speak("According to Wikipedia")              # Inform the user that the result is from Wikipedia
            print(results)                                # Print the summary to the console
            speak(results)                                # Speak out the summary
        except Exception:                                 # If there's an error fetching the topic
            speak("Sorry, I couldn't find anything on Wikipedia.")  # Inform the user of the failure

# Main function that runs when the script is executed
if __name__ == "__main__":
    wishMe()             # First, greet the user based on the current time
    while True:          # Create an infinite loop to continuously listen for commands
        query = takeCommand()   # Get a voice command from the user
        if query == "none":     # If the command was not recognized properly
            continue          # Skip this loop iteration and listen again

        if 'jarvis' in query:                       # If the user mentions "jarvis"
            speak("Yes, sir")                       # Respond with a respectful acknowledgement
        elif "who are you" in query:                # If the user asks "who are you"
            speak("My name is Jarvis. I can do everything that my creator programmed me to do.")
        elif "who developed you" in query:          # If the user asks "who developed you"
            speak("I was created by python in Visual Studio Code.")  # Provide the response about development
        elif 'open wikipedia' in query:             # If the user asks to open Wikipedia
            searchWikipedia()                       # Call the function to search Wikipedia
        elif 'just open google' in query:           # If the user asks to open Google directly
            webbrowser.open('https://www.google.com')  # Open Google's homepage
        elif 'open google' in query:                # If the user asks to search on Google
            speak("What should I search for?")      # Ask for the search query
            qry = takeCommand()                     # Get the search query from the user
            if qry != "none":                       # If a valid query is provided
                webbrowser.open(f"https://www.google.com/search?q={qry}")  # Search for the query on Google
        elif 'just open youtube' in query:          # If the user asks to open YouTube directly
            webbrowser.open('https://www.youtube.com')  # Open YouTube's homepage
        elif 'search on youtube' in query:          # If the user asks to search on YouTube
            query = query.replace("search on youtube", "").strip()  # Remove the command part from the query
            webbrowser.open(f"https://www.youtube.com/results?search_query={query}")  # Search YouTube with the remaining query
        elif 'open chat gpt' in query:              # If the user asks to open ChatGPT
            webbrowser.open('https://chat.openai.com')  # Open ChatGPT in the browser
        elif 'open instagram' in query:             # If the user asks to open Instagram
            webbrowser.open('https://www.instagram.com')  # Open Instagram's homepage
        elif 'open tiktok' in query:                # If the user asks to open TikTok
            webbrowser.open('https://www.tiktok.com')  # Open TikTok's homepage
        elif 'open facebook' in query:              # If the user asks to open Facebook
            webbrowser.open('https://www.facebook.com')  # Open Facebook's homepage
        elif 'close google' in query or 'close youtube' in query:  # If the user asks to close Google or YouTube (Chrome browser)
            closeBrowser("chrome")                  # Call the function to close Chrome
        elif 'close edge' in query or 'close microsoft edge' in query:  # If the user asks to close Edge browser
            closeBrowser("edge")                    # Call the function to close Microsoft Edge
