#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 100

// Задание 3. Вариант 4.
// Функция поиска максимального значения элемента массива до позиции K включительно
double find_max_up_to_k(double* ptr_array, int n, int k) {
    // Если K выходит за пределы массива, ограничиваем его концом массива
    if (k >= n) {
        k = n - 1;
    }
    // Если K отрицательный, возвращаем ошибку (или минимально возможное значение)
    if (k < 0) {
        printf("Ошибка: позиция K не может быть отрицательной!\n");
        return -1.0;
    }

    double max_val = ptr_array[0];

    // Ищем максимум от 0 до K включительно
    for (int i = 1; i <= k; i++) {
        if (ptr_array[i] > max_val) {
            max_val = ptr_array[i];
        }
    }
    return max_val;
}

// Вспомогательные функции из задания 1
void full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (double)(rand() % 1000) / 10.0 - 50.0;
    }
}

void put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    srand(time(NULL));

    double array[N];
    int size;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    if (size <= 0 || size > N) {
        printf("Некорректный размер!\n");
        return 1;
    }

    full_elements(array, size);

    printf("\nСгенерированный массив (индексы от 0 до %d):\n", size - 1);
    put_elements(array, size);

    int K;
    printf("\nВведите позицию K (индекс) > ");
    scanf("%d", &K);

    if (K < 0 || K >= size) {
        printf("Ошибка: позиция K должна быть в пределах от 0 до %d.\n", size - 1);
    }
    else {
        double max_val = find_max_up_to_k(array, size, K);
        printf("Максимальное значение до позиции %d включительно: %.2f\n", K, max_val);
    }

    return 0;
}