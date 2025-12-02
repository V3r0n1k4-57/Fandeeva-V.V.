#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функция для определения, является ли символ пробелом.
int is_separator(char c) {
    // Проверяем стандартный пробел, табуляцию, новую строку.
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int find_longest_word_length(const char *s) {
    int maxLength = 0;
    int currentLength = 0;
    int i = 0;

    // Проходим по строке до достижения нуль-терминатора '\0'
    while (s[i] != '\0') {
        
        // 1. Если символ НЕ является разделителем (т.е. это часть слова)
        if (!is_separator(s[i])) {
            currentLength++;
        } 
        // 2. Если символ ЯВЛЯЕТСЯ разделителем
        else {
            // Проверяем, не закончилось ли слово только что
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            // Сбрасываем счетчик для следующего слова
            currentLength = 0;
        }
        
        // Переходим к следующему символу
        i++;
    }
    
    // 3. Финальная проверка: Если строка закончилась, но последнее слово не было 
    // завершено пробелом.
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength;
}

int main() {
    // Ввод данных. Используем строковые литералы для демонстрации.
    
    const char *test_string_1 = "Это очень длинное слово и короткое";
    const char *test_string_2 = "Один  два   триста    четыре";
    const char *test_string_3 = "слово";
    const char *test_string_4 = "   "; // Только пробелы

    printf("--- Тест 1 ---\n");
    // ИСПРАВЛЕНО: Экранирование внутренних кавычек \"
    printf("Строка: \"%s\"\n", test_string_1);
    int result1 = find_longest_word_length(test_string_1);
    printf("Длина самого длинного слова: %d\n\n", result1);

    printf("--- Тест 2 ---\n");
    // ИСПРАВЛЕНО: Экранирование внутренних кавычек \"
    printf("Строка: \"%s\"\n", test_string_2);
    int result2 = find_longest_word_length(test_string_2);
    printf("Длина самого длинного слова: %d\n\n", result2);
    
    printf("--- Тест 3 ---\n");
    // ИСПРАВЛЕНО: Экранирование внутренних кавычек \"
    printf("Строка: \"%s\"\n", test_string_3);
    int result3 = find_longest_word_length(test_string_3);
    printf("Длина самого длинного слова: %d\n\n", result3);

    printf("--- Тест 4 (Только пробелы) ---\n");
    // ИСПРАВЛЕНО: Экранирование внутренних кавычек \"
    printf("Строка: \"%s\"\n", test_string_4);
    int result4 = find_longest_word_length(test_string_4);
    printf("Длина самого длинного слова: %d\n\n", result4);

    return 0;
}
