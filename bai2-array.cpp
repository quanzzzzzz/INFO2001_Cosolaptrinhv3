#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int timKiemTuyenTinh(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
int timKiemNhiPhan(int arr[], int low, int high, int x) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return timKiemNhiPhan(arr, low, mid - 1, x); 
        }

        return timKiemNhiPhan(arr, mid + 1, high, x);
    }

    return -1;
}

int main() {
    srand(time(NULL));

    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    int x;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &x);
    clock_t start_time = clock();
    int linearResult = timKiemTuyenTinh(arr, n, x);
    clock_t end_time = clock();

    if (linearResult != -1) {
        printf("Tim thay gia tri %d tai vi tri %d (Tuyen tinh).\n", x, linearResult);
    } else {
        printf("Khong tim thay gia tri %d (Tuyen tinh).\n", x);
    }

    printf("Thoi gian thuc thi (Tuyen tinh): %f giay\n", ((double)end_time - start_time) / CLOCKS_PER_SEC);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    start_time = clock();
    int binaryResult = timKiemNhiPhan(arr, 0, n - 1, x);
    end_time = clock();

    if (binaryResult != -1) {
        printf("Tim thay gia tri %d tai vi tri %d (Nhi phan).\n", x, binaryResult);
    } else {
        printf("Khong tim thay gia tri %d (Nhi phan).\n", x);
    }

    printf("Thoi gian thuc thi (Nhi phan): %f giay\n", ((double)end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}

