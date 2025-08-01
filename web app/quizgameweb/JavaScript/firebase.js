// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.12.0/firebase-app.js";
import { getFirestore, collection, doc, setDoc, getDoc } from "https://www.gstatic.com/firebasejs/10.12.0/firebase-firestore.js";

// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyA6VF16aoxll9tMx8XA_XbcXK6n8IA6o9g",
  authDomain: "quizgame-3f3e4.firebaseapp.com",
  projectId: "quizgame-3f3e4",
  storageBucket: "quizgame-3f3e4.firebasestorage.app",
  messagingSenderId: "117869948973",
  appId: "1:117869948973:web:4dbd778ad035025e5748a4",
  measurementId: "G-66DN3GPCHW"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

const db = getFirestore(app);

export { db, collection, doc, setDoc, getDoc };