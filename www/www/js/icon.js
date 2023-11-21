const burgerIcon = document.getElementById('burgerIcon');
const navigationHeader = document.querySelector('.navigation-header');

// Функция для отображения/скрытия меню
function toggleMenu() {
  navigationHeader.classList.toggle('show-menu');
}

// Назначаем обработчик события клика на кнопку бургер меню
burgerIcon.addEventListener('click', toggleMenu);