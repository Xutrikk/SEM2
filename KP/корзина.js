document.addEventListener("DOMContentLoaded", function() {
    const quantityInput = document.querySelector('#quantity');
    const decreaseButton = document.querySelector('#decrease');
    const increaseButton = document.querySelector('#increase');
    const totalPriceElement = document.querySelector('.cart-summary p:nth-child(2)');
    const shippingPriceElement = document.querySelector('.cart-summary p:nth-child(3)');
    const totalElement = document.querySelector('.cart-summary p:nth-child(4)');
    
    const pricePerItem = 49.99; 
    const shippingPrice = 10; 
    
    function updateTotalPrice() {
        const quantity = parseInt(quantityInput.value);
        
        const totalPriceValue = pricePerItem * quantity;
        
        totalPriceElement.textContent = `Стоимость товаров: ${totalPriceValue.toFixed(2)} BYN`;
        shippingPriceElement.textContent = `Доставка: ${shippingPrice.toFixed(2)} BYN`;
        
        totalElement.textContent = `Итого: ${(totalPriceValue + shippingPrice).toFixed(2)} BYN`;
    }

    updateTotalPrice();

    decreaseButton.addEventListener('click', function() {
        if (quantityInput.value > 1) {
            quantityInput.value--;
            updateTotalPrice();
        }
    });

    increaseButton.addEventListener('click', function() {
        if (quantityInput.value < 10) {
            quantityInput.value++;
            updateTotalPrice();
        }
    });
});
