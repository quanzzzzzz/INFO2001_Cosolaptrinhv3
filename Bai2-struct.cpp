#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    int id;
    char ten[50];
    float diem;
};

int soSanh(const void *a, const void *b) {
    return strcmp(((struct SinhVien *)a)->ten, ((struct SinhVien *)b)->ten);
} 
int timKiem(struct SinhVien sv[], int n, char tuKhoa[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].ten, tuKhoa) == 0 || sv[i].id == atoi(tuKhoa)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct SinhVien danhSachSV[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien %d:\n", i + 1);
        danhSachSV[i].id = i + 1;
        printf("  - Nhap ten: ");
        fflush(stdin);
        gets(danhSachSV[i].ten);
        printf("  - Nhap diem: ");
        scanf("%f", &danhSachSV[i].diem);
    }
    qsort(danhSachSV, n, sizeof(struct SinhVien), soSanh);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ten: %s, Diem: %.2f\n", danhSachSV[i].id, danhSachSV[i].ten, danhSachSV[i].diem);
    }
    
    char tuKhoa[50];
    printf("\nNhap ten hoac ID sinh vien can tim kiem: ");
    fflush(stdin);
    gets(tuKhoa);

    int viTri = timKiem(danhSachSV, n, tuKhoa);

    if (viTri != -1) {
        printf("Tim thay sinh vien tai vi tri %d.\n", viTri + 1);
        printf("Thong tin sinh vien:\n");
        printf("ID: %d, Ten: %s, Diem: %.2f\n", danhSachSV[viTri].id, danhSachSV[viTri].ten, danhSachSV[viTri].diem);
    } else {
        printf("Khong tim thay sinh vien co ten hoac ID nhu vay.\n");
    }

    return 0;
}

