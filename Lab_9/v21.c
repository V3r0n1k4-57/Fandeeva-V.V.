#include <stdio.h>
#include <stdlib.h>

// Максимальный размер матрицы, согласно условию (M <= 10)
#define MAX_SIZE 10

// Функция для вывода матрицы
void print_matrix(int M, int matrix[MAX_SIZE][MAX_SIZE]) {
    printf("--- Матрица ---\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            // Выводим элементы с выравниванием для красоты
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
}

// Функция для обмена двух строк в матрице
void swap_rows(int M, int matrix[MAX_SIZE][MAX_SIZE], int row1, int row2) {
    if (row1 == row2) {
        return; // Нет смысла менять строку саму с собой
    }

    int temp;
    for (int k = 0; k < M; k++) {
        temp = matrix[row1][k];
        matrix[row1][k] = matrix[row2][k];
        matrix[row2][k] = temp;
    }
}

int main() {
    int M;
    int matrix[MAX_SIZE][MAX_SIZE];
    int min_val, max_val;
    int r_min = -1, r_max = -1; // Индексы строк

    // 1. ВВОД РАЗМЕРА
    printf("Введите размер квадратной матрицы M (2 <= M <= 10): ");
    if (scanf("%d", &M) != 1 || M < 2 || M > MAX_SIZE) {
        printf("Ошибка ввода размера M.\n");
        return 1;
    }

    // 2. ВВОД ЭЛЕМЕНТОВ
    printf("Введите %d элементов матрицы построчно:\n", M * M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Ошибка ввода элемента.\n");
                return 1;
            }
        }
    }

    // Вывод исходной матрицы для проверки
    printf("\nИсходная матрица:\n");
    print_matrix(M, matrix);

    // 3. ПОИСК МИНИМУМА И МАКСИМУМА И ИНДЕКСОВ ИХ СТРОК
    
    // Инициализация первыми элементами
    min_val = matrix[0][0];
    max_val = matrix[0][0];
    r_min = 0;
    r_max = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            
            // Поиск минимума
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
                r_min = i; // Запоминаем индекс строки
            }

            // Поиск максимума
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                r_max = i; // Запоминаем индекс строки
            }
        }
    }

    printf("\nНайденный минимум: %d в строке (индекс): %d\n", min_val, r_min);
    printf("Найденный максимум: %d в строке (индекс): %d\n", max_val, r_max);


    // 4. ОБМЕН СТРОКАМИ
    if (r_min != r_max) {
        printf("Строки %d и %d будут поменяны местами.\n", r_min, r_max);
        swap_rows(M, matrix, r_min, r_max);
    } else {
        printf("Минимум и максимум находятся в одной строке. Обмен не требуется.\n");
    }

    // 5. ВЫВОД РЕЗУЛЬТАТА
    printf("\nПреобразованная матрица:\n");
    print_matrix(M, matrix);

    return 0;
}

