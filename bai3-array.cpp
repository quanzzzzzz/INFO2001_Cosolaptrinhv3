#include <stdio.h>

void nhapDiem(float diem[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap diem cua sinh vien %d: ", i + 1);
        scanf("%f", &diem[i]);
    }
}
float tinhDiemTrungBinh(float diem[], int n) {
    float tongDiem = 0;

    for (int i = 0; i < n; i++) {
        tongDiem += diem[i];
    }

    return tongDiem / n;
}

int main() {
    int soSinhVien;
    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &soSinhVien);
    float diem[soSinhVien];
    nhapDiem(diem, soSinhVien);
    float diemTrungBinh = tinhDiemTrungBinh(diem, soSinhVien);
    printf("Diem trung binh cua lop la: %.2f\n", diemTrungBinh);

    return 0;
}

