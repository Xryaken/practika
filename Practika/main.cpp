#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void shellSort(int array[], int n) {
    // ��������� ��������
    int interval = 5;
    while (interval < n / 3) {
        interval = interval * 3 + 1;
    }

    // ��������� ���������� Shell
    while (interval > 0) {
        for (int i = interval; i < n; i++) {
            int temp = array[i];
            int j = i;

            // ��������� ���������� � ���������� interval
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

    printf("������� ���������� ��������� �������: ");
    scanf("%d", &size);
    printf("\n");

    array = (int*)malloc(size*sizeof(int));

    printf("������ ��������� �����: 'input.txt'\n");
    f = fopen("input.txt", "w");

    // ���������� ��������� ��������
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
        fprintf(f, "%d  ", array[i]);
    }
    fclose(f);


    printf("��������������� ������: 'output.txt'\n");
    f = fopen("output.txt", "w");

    time_t start = clock();

    // ��������� ������ � ������� ���������� Shell
    shellSort(array, size);

    time_t stop = clock();             //����� ����� ���������� 
    for (int i = 0; i < size; i++) {
        fprintf(f, "%d  ", array[i]);
    }
    fclose(f);
    double time = (stop - start) / 1000.0;    //����� ����������
    printf("\n");
    printf("����� ���������� ����������: %lf\n", time);

    return 0;
}

   	 	
