#include <stdio.h>
#include <stdlib.h> // Для функции exit, если нужно

// Прототип функции для обработки числа
void print_digits_reversed(int number) {
    
    // Проверка на положительное число (согласно условию задачи)
    if (number <= 0) {
        printf("Ошибка: Введите целое положительное число.\n");
        return;
    }

    printf("Цифры числа %d в порядке справа налево:\n", number);
    
    int current_number = number;
    
    // Цикл, пока число больше нуля
    while (current_number > 0) {
        
        // 1. Получение последней цифры (Остаток от деления на 10)
        int digit = current_number % 10;
        
        // 2. Вывод цифры как символа
        // Используем %d для вывода числа, но в данном контексте это и есть символ цифры
        printf("%d ", digit); 
        
        // 3. Удаление последней цифры (Целочисленное деление на 10)
        current_number = current_number / 10;
    }
    
    printf("\n");
}

int main() {
    int input_number;

    printf("Введите целое положительное число: ");
    
    // Считывание входного числа
    if (scanf("%d", &input_number) != 1) {
        printf("Ошибка ввода. Введено не число.\n");
        return 1;
    }
    
    // Вызов основной функции
    print_digits_reversed(input_number);

    return 0;
}

