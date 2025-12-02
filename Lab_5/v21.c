#include <stdio.h>
#include <stdlib.h> // Для работы со строками, если потребуется

// Функция для определения и вывода названия фигуры
void identify_figure(int K) {
    // Используем switch для проверки значения K
    switch (K) {
        case 1:
            printf("пешка\n");
            break;
        case 2:
            printf("конь\n");
            break;
        case 3:
            printf("слон\n");
            break;
        case 4:
            printf("ладья\n");
            break;
        case 5:
            printf("ферзь\n");
            break;
        case 6:
            printf("король\n");
            break;
        default:
            // Если K не попало ни в один из case (т.е. < 1 или > 6)
            printf("ошибка\n");
            break;
    }
}

int main() {
    int K;

    // 1. Ввод данных
    printf("Введите код фигуры (K от 1 до 6): ");
    
    // Проверка успешности ввода
    if (scanf("%d", &K) != 1) {
        printf("Ошибка ввода: введено не целое число.\n");
        return 1; // Код ошибки программы
    }

    // 2. Вызов функции для обработки и вывода результата
    identify_figure(K);

    return 0; // Успешное завершение программы
}

