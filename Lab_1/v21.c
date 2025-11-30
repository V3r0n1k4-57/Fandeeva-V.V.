#include <stdio.h>
#include <math.h> // Для sqrt()

// Структура для хранения координат точки
typedef struct {
    double x;
    double y;
} Point;

/**
 * @brief Вычисляет расстояние между двумя точками.
 * @param p1 Первая точка.
 * @param p2 Вторая точка.
 * @return Расстояние между точками.
 */
double calculate_distance(Point p1, Point p2) {
    // (x2 - x1)^2 + (y2 - y1)^2
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    
    // Используем pow(base, exponent) для возведения в квадрат, 
    // хотя (dx * dx) было бы эффективнее.
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
    // 1. Входные данные: Координаты вершин (Инициализация тестовыми данными)
    Point P1 = {0.0, 0.0}; // x1, y1
    Point P2 = {3.0, 0.0}; // x2, y2
    Point P3 = {0.0, 4.0}; // x3, y3
    
    // 2. Промежуточные переменные
    double side_a, side_b, side_c;
    double perimeter, semi_perimeter;
    double area;

    printf("--- Triangle Calculator (C Language) ---\n");
    
    // Вывод введенных точек для справки
    printf("Vertex P1: (%.2f, %.2f)\n", P1.x, P1.y);
    printf("Vertex P2: (%.2f, %.2f)\n", P2.x, P2.y);
    printf("Vertex P3: (%.2f, %.2f)\n", P3.x, P3.y);

    // 3. Расчет длин сторон
    // Сторона a: между P1 и P2
    side_a = calculate_distance(P1, P2);
    
    // Сторона b: между P2 и P3
    side_b = calculate_distance(P2, P3);
    
    // Сторона c: между P3 и P1
    side_c = calculate_distance(P3, P1);
    
    printf("\nCalculated Sides:\n");
    printf("Side a (P1-P2): %.4f\n", side_a);
    printf("Side b (P2-P3): %.4f\n", side_b);
    printf("Side c (P3-P1): %.4f\n", side_c);

    // 4. Расчет Периметра
    perimeter = side_a + side_b + side_c;
    
    // 5. Расчет Полупериметра
    semi_perimeter = perimeter / 2.0;
    
    // 6. Расчет Площади (Формула Герона)
    // Проверка на возможность существования треугольника (необязательно, но полезно)
    if (semi_perimeter <= side_a || semi_perimeter <= side_b || semi_perimeter <= side_c) {
        printf("\nError: These points cannot form a non-degenerate triangle (Area is zero or imaginary).\n");
        area = 0.0;
    } else {
        double area_squared_term = semi_perimeter * 
                                   (semi_perimeter - side_a) * 
                                   (semi_perimeter - side_b) * 
                                   (semi_perimeter - side_c);
        area = sqrt(area_squared_term);
    }

    // 7. Вывод результатов
    printf("\n--- Results ---\n");
    printf("Perimeter (P): %.4f\n", perimeter);
    printf("Area (S) using Heron's formula: %.4f\n", area);

    return 0;
}

