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
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    // ���������� ��������� ��������
    int array[10000];
    printf("�������� ������:\n");
    for (int i = 0; i < 10000; i++) {
        array[i] = rand() % 10000;
        printf("%d ", array[i]);
    }
    printf("\n");

    // ��������� ������ � ������� ���������� Shell
    shellSort(array, 10000);

    printf("��������������� ������:\n");
    for (int i = 0; i < 10000; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
