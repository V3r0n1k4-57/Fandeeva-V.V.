#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Максимальная длина строки, которую мы можем обработать
#define MAX_LEN 10000

// Функция для удаления повторяющихся символов, оставляя только первые вхождения
char* remove_duplicates(const char* str) {
    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str);
    if (len == 0) {
        char* result_empty = (char*)malloc(1);
        if (result_empty) result_empty[0] = '\0';
        return result_empty;
    }

    // Используем массив для отслеживания уже встреченных символов (ASCII 0-255)
    int seen[256] = {0};
    
    // Выделяем память для результата (максимум - исходная длина + 1 для '\0')
    char* result = (char*)malloc(len + 1);
    if (result == NULL) {
        perror("Ошибка выделения памяти для результата");
        return NULL;
    }

    int result_index = 0;
    for (int i = 0; i < len; i++) {
        // Получаем текущий символ как индекс (0-255)
        unsigned char current_char = (unsigned char)str[i];

        if (seen[current_char] == 0) {
            // Символ не встречался ранее
            seen[current_char] = 1;
            result[result_index++] = str[i];
        }
    }
    
    // Завершаем строку
    result[result_index] = '\0';
    return result;
}

int main() {
    char S[MAX_LEN];
    char *S0 = NULL;

    printf("Программа для удаления повторяющихся символов в строке.\n");
    printf("Введите исходную строку S (максимум %d символов): ", MAX_LEN - 1);
    
    // Читаем строку, безопасно обрабатывая пробелы и предотвращая переполнение буфера
    if (fgets(S, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "Ошибка чтения ввода.\n");
        return 1;
    }

    // Удаляем символ новой строки, если он присутствует
    size_t len = strlen(S);
    if (len > 0 && S[len - 1] == '\n') {
        S[len - 1] = '\0';
    }

    // Вызываем функцию обработки
    S0 = remove_duplicates(S);

    if (S0 == NULL) {
        fprintf(stderr, "Не удалось обработать строку.\n");
        return 1;
    }

    // Вывод результатов
    printf("\n--- Результат ---\n");
    // ИСПРАВЛЕНИЕ: Экранируем двойные кавычки символом \
    printf("Исходная строка S: \"%s\"\n", S);
    // ИСПРАВЛЕНИЕ: Экранируем двойные кавычки символом \
    printf("Результирующая строка S0 (уникальные символы): \"%s\"\n", S0);

    // Освобождаем память, выделенную функцией remove_duplicates
    free(S0);

    return 0;
}
