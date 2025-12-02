#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

// Функция для чтения всех вещественных чисел из файла и сохранения их в динамический массив
double* read_doubles_from_file(const char* filename, int* count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия входного файла");
        *count = 0;
        return NULL;
    }

    // 1. Сначала подсчитаем количество чисел, чтобы выделить память один раз
    double temp_val;
    int num_count = 0;
    while (fscanf(file, "%lf", &temp_val) == 1) {
        num_count++;
    }

    if (num_count == 0) {
        fclose(file);
        *count = 0;
        return NULL;
    }
    
    // Выделяем память
    double *data = (double*)malloc(num_count * sizeof(double));
    if (data == NULL) {
        perror("Ошибка выделения памяти для данных");
        fclose(file);
        *count = 0;
        return NULL;
    }

    // 2. Снова перематываем файл и считываем данные
    rewind(file);
    for (int i = 0; i < num_count; i++) {
        if (fscanf(file, "%lf", &data[i]) != 1) {
            // Этого не должно произойти, если подсчет был верным
            fprintf(stderr, "Ошибка при повторном чтении данных.\n");
            free(data);
            fclose(file);
            *count = 0;
            return NULL;
        }
    }

    fclose(file);
    *count = num_count;
    return data;
}

// Основная логика поиска локальных максимумов
void find_and_save_maxima(const double* data, int N, const char* output_filename) {
    if (N == 0) {
        printf("Входной массив пуст.\n");
        return;
    }

    FILE *outfile = fopen(output_filename, "w");
    if (outfile == NULL) {
        perror("Ошибка открытия выходного файла");
        return;
    }

    printf("Найдено локальных максимумов: ");
    int maxima_found = 0;

    for (int i = 0; i < N; i++) {
        int is_maximum = 0;

        if (N == 1) {
            // Случай 1: Один элемент
            is_maximum = 1;
        } else if (i == 0) {
            // Случай 2: Первый элемент
            if (data[i] > data[i + 1]) {
                is_maximum = 1;
            }
        } else if (i == N - 1) {
            // Случай 3: Последний элемент
            if (data[i] > data[i - 1]) {
                is_maximum = 1;
            }
        } else {
            // Случай 4: Элемент в середине
            if (data[i] > data[i - 1] && data[i] > data[i + 1]) {
                is_maximum = 1;
            }
        }

        if (is_maximum) {
            // Записываем индекс (целое число) в выходной файл
            fprintf(outfile, "%d\n", i);
            printf("%d ", i);
            maxima_found++;
        }
    }

    fclose(outfile);
    printf("\nВсе индексы сохранены в файл %s.\n", output_filename);
}


int main() {
    printf("--- Поиск локальных максимумов ---\n");
    
    int N = 0;
    // 1. Чтение данных
    double* S = read_doubles_from_file(INPUT_FILE, &N);

    if (S == NULL) {
        if (N == 0) {
             printf("Не удалось прочитать данные из %s или файл пуст.\n", INPUT_FILE);
        }
        return 1;
    }

    printf("Успешно прочитано %d элементов из %s.\n", N, INPUT_FILE);

    // 2. Поиск и сохранение
    find_and_save_maxima(S, N, OUTPUT_FILE);

    // 3. Освобождение памяти
    free(S);

    return 0;
}

