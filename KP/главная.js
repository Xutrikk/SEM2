let sliderImages = document.querySelector('.slider-images');
let arrowLeft = document.querySelector('.arrow-left');
let arrowRight = document.querySelector('.arrow-right');
let currentImage = 0; // Начинаем с 0 для правильного индекса
const totalImages = sliderImages.children.length;

// Получаем ширину одного изображения
let imageWidth = sliderImages.children[0].offsetWidth;

function slideTo(index) {
    currentImage = index;
    sliderImages.style.transition = 'transform 0.5s ease-in-out'; // Добавляем анимацию
    sliderImages.style.transform = `translateX(-${currentImage * imageWidth}px)`;
}

arrowLeft.addEventListener('click', () => {
    if (currentImage > 0) {
        slideTo(currentImage - 1);
    } else {
        // Если мы находимся на первом изображении, переходим к последнему
        slideTo(totalImages - 1);
    }
});

arrowRight.addEventListener('click', () => {
    if (currentImage < totalImages - 1) {
        slideTo(currentImage + 1);
    } else {
        // Если мы находимся на последнем изображении, возвращаемся к первому
        slideTo(0);
    }
});

// Функция для обработки окончания анимации
sliderImages.addEventListener('transitionend', () => {
    sliderImages.style.transition = ''; // Убираем анимацию, чтобы не было мерцания
});

// Обновляем ширину изображения при изменении размера окна
window.addEventListener('resize', () => {
    imageWidth = sliderImages.children[0].offsetWidth;
});
