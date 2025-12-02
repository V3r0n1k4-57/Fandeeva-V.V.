#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"
#define MAX_LINE_LENGTH 1024 // Максимальная длина строки, которую мы будем читать

// Функция для подсчета общего количества строк в файле
int count_lines(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия входного файла для подсчета");
        return -1; // Возвращаем -1 в случае ошибки
    }

    int count = 0;
    char ch;
    // Простой способ подсчета (считаем переводы строк '\n')
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    
    // Если файл не пустой, но не заканчивается '\n', последняя строка тоже считается.
    // Чтобы учесть это, проверим, не был ли файл пуст.
    if (count == 0) {
        // Если EOF достигнут сразу, файл пуст.
        fseek(file, 0, SEEK_END);
        if (ftell(file) > 0) {
            count = 1; // Если есть символы, но нет '\n', это одна строка.
        }
    } else {
        // Если файл заканчивается не на '\n', нужно добавить 1 к счетчику
        fseek(file, -1, SEEK_END);
        if (fgetc(file) != '\n') {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

int main() {
    printf("--- Программа удаления последних трех строк ---\n");

    // 1. Подсчет строк
    int total_lines = count_lines(INPUT_FILENAME);

    if (total_lines == -1) {
        return 1; // Ошибка открытия файла
    }

    printf("Обнаружено строк в %s: %d\n", INPUT_FILENAME, total_lines);

    // 2. Проверка условия
    if (total_lines <= 3) {
        printf("Ошибка: Файл содержит %d строк. Требуется более трех строк для удаления.\n", total_lines);
        // Создадим пустой выходной файл, чтобы показать, что обработка завершена
        FILE *outfile = fopen(OUTPUT_FILENAME, "w");
        if (outfile) fclose(outfile);
        return 0;
    }

    // 3. Определение количества строк для копирования
    int lines_to_copy = total_lines - 3;
    printf("Будет скопировано %d строк в %s.\n", lines_to_copy, OUTPUT_FILENAME);

    // 4. Чтение и запись
    FILE *infile = fopen(INPUT_FILENAME, "r");
    FILE *outfile = fopen(OUTPUT_FILENAME, "w");
    
    if (infile == NULL || outfile == NULL) {
        perror("Ошибка открытия одного из файлов");
        if (infile) fclose(infile);
        if (outfile) fclose(outfile);
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    int copied_count = 0;

    // Копируем только первые (N-3) строк
    while (copied_count < lines_to_copy) {
        if (fgets(buffer, MAX_LINE_LENGTH, infile) != NULL) {
            // Записываем прочитанную строку в выходной файл
            fputs(buffer, outfile);
            copied_count++;
        } else {
            // Если мы не дошли до lines_to_copy, значит, входной файл был поврежден
            break; 
        }
    }

    fclose(infile);
    fclose(outfile);
    
    printf("Успешно завершено. Результат в файле %s.\n", OUTPUT_FILENAME);

    return 0;
}

