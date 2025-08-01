document.addEventListener('DOMContentLoaded', () => {
    const themeToggleButton = document.getElementById('themeToggleButton');
    const body = document.body;

    // Check for saved theme preference or default to light
    const savedTheme = localStorage.getItem('theme');
    if (savedTheme === 'dark') {
        body.classList.add('dark');
        themeToggleButton.querySelector('i').classList.replace('fa-moon', 'fa-sun');
    } else {
        body.classList.remove('dark');
        themeToggleButton.querySelector('i').classList.replace('fa-sun', 'fa-moon');
    }

    themeToggleButton.addEventListener('click', () => {
        body.classList.toggle('dark');
        if (body.classList.contains('dark')) {
            localStorage.setItem('theme', 'dark');
            themeToggleButton.querySelector('i').classList.replace('fa-moon', 'fa-sun');
        } else {
            localStorage.setItem('theme', 'light');
            themeToggleButton.querySelector('i').classList.replace('fa-sun', 'fa-moon');
        }
    });
});