#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define N 100 // Максимальная размерность статического массива

// --- Задание 1 ---

// Функция заполнения массива (например, случайными числами от -50.0 до 50.0)
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (double)(rand() % 1000) / 10.0 - 50.0;
    }
    return ptr_array;
}

// Функция печати элементов массива
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
    printf("\n");
    return n;
}

// Функция обработки элементов массива (пример: умножение всех элементов на 2)
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] *= 2;
    }
    return ptr_array;
}

// --- Задание 2 ---

// Функция вычисления суммы элементов от индекса begin до end включительно
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0;
    // Проверка на корректность границ
    if (begin < 0 || end >= 100 || begin > end) return 0;

    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// Функция поиска элемента, возвращает индекс или -1
int find_element(double* ptr_array, int n, double element) {
    double eps = 1e-6; // Погрешность для сравнения вещественных чисел (double)
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - element) < eps) {
            return i;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    srand(time(NULL));

    // 1. Объявление статического массива
    double array[N];
    int size;

    // Ввод размера массива
    printf("Введите размер массива > ");
    scanf("%d", &size);

    if (size <= 0 || size > N) {
        printf("Ошибка: размер должен быть от 1 до %d\n", N);
        return 1;
    }

    // Вызов функций для Задания 1
    printf("\n--- Задание 1 ---\n");
    full_elements(array, size);
    printf("Исходный массив:\n");
    put_elements(array, size);

    calc_elements(array, size);
    printf("Массив после обработки (умножение на 2):\n");
    put_elements(array, size);

    // Вызов функций для Задания 2
    printf("\n--- Задание 2 ---\n");
    int begin, end;
    printf("Введите начальный и конечный индексы для суммы (через пробел) > ");
    scanf("%d %d", &begin, &end);

    if (begin >= 0 && end < size && begin <= end) {
        double sum = sum_elements(array, begin, end);
        printf("Сумма элементов с %d по %d = %.2f\n", begin, end, sum);
    }
    else {
        printf("Ошибка: некорректные индексы.\n");
    }

    double target;
    printf("Введите число для поиска > ");
    scanf("%lf", &target);

    int index = find_element(array, size, target);
    if (index != -1) {
        printf("Элемент найден на индексе: %d\n", index);
    }
    else {
        printf("Элемент не найден в массиве.\n");
    }

    return 0;
}