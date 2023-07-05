#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void shellSort(int array[], int n) {
    // Вычисляем интервал
    int interval = 5;
    while (interval < n / 3) {
        interval = interval * 3 + 1;
    }

    // Применяем сортировку Shell
    while (interval > 0) {
        for (int i = interval; i < n; i++) {
            int temp = array[i];
            int j = i;

            // Сортируем подмассивы с интервалом interval
            while (j >= interval && array[j - interval] > temp) {
                array[j] = array[j - interval];
                j -= interval;
            }

            array[j] = temp;
        }

        interval = (interval - 1) / 3;
    }
}

int main() {
    FILE* f;
    int size;
    int* array;
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    printf("Введите количество элементов массива: ");
    scanf("%d", &size);
    printf("\n");

    array = (int*)malloc(size*sizeof(int));

    printf("Массив случайных чисел: 'input.txt'\n");
    f = fopen("input.txt", "w");

    // Генерируем рандомные значения
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
        fprintf(f, "%d  ", array[i]);
    }
    fclose(f);


    printf("Отсортированный массив: 'output.txt'\n");
    f = fopen("output.txt", "w");

    time_t start = clock();

    // Сортируем массив с помощью сортировки Shell
    shellSort(array, size);

    time_t stop = clock();             //время после сортировки 
    for (int i = 0; i < size; i++) {
        fprintf(f, "%d  ", array[i]);
    }
    fclose(f);
    double time = (stop - start) / 1000.0;    //время сортировки
    printf("\n");
    printf("Время выполнения сортировки: %lf\n", time);

    return 0;
}

   	 	
