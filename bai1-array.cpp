#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inMang(int arr[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);

    int arr1[n], arr2[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = arr2[i] = rand() % 1000;
    }

    printf("Mang truoc khi sap xep:\n");
    inMang(arr1, n);
    clock_t start_time = clock();
    bubbleSort(arr1, n);
    clock_t end_time = clock();
    printf("\nMang sau khi sap xep (Bubble Sort):\n");
    inMang(arr1, n);
    printf("Thoi gian thuc thi (Bubble Sort): %f giay\n", ((double)end_time - start_time) / CLOCKS_PER_SEC);
    printf("\nMang truoc khi sap xep lai:\n");
    inMang(arr2, n);
    start_time = clock();
    selectionSort(arr2, n);
    end_time = clock();
    printf("\nMang sau khi sap xep (Selection Sort):\n");
    inMang(arr2, n);
    printf("Thoi gian thuc thi (Selection Sort): %f giay\n", ((double)end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}

