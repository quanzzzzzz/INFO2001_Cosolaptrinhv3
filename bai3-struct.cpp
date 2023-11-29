#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int maNV;
    char ten[50];
    char chucVu[50];
    float luong;
};

void themNhanVien(struct Employee danhSachNV[], int *soLuong) {
    printf("Nhap thong tin cho nhan vien moi:\n");
    danhSachNV[*soLuong].maNV = *soLuong + 1;

    printf("  - Nhap ten: ");
    fflush(stdin);
    gets(danhSachNV[*soLuong].ten);

    printf("  - Nhap chuc vu: ");
    fflush(stdin);
    gets(danhSachNV[*soLuong].chucVu);

    printf("  - Nhap luong: ");
    scanf("%f", &danhSachNV[*soLuong].luong);

    (*soLuong)++;
    printf("Nhan vien da duoc them.\n");
}

void xoaNhanVien(struct Employee danhSachNV[], int *soLuong, int maNV) {
    int viTri = -1;
    for (int i = 0; i < *soLuong; i++) {
        if (danhSachNV[i].maNV == maNV) {
            viTri = i;
            break;
        }
    }

    if (viTri != -1) {
        for (int i = viTri; i < *soLuong - 1; i++) {
            danhSachNV[i] = danhSachNV[i + 1];
        }
        (*soLuong)--;
        printf("Nhan vien da duoc xoa.\n");
    } else {
        printf("Khong tim thay nhan vien co ma nhan vien nhu vay.\n");
    }
}

void hienThiDanhSach(struct Employee danhSachNV[], int soLuong) {
    printf("\nDanh sach nhan vien:\n");
    printf("M? NV |   Tên   |   Ch?c v?   |   Lýõng\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < soLuong; i++) {
        printf("%5d | %-7s | %-11s | %.2f\n", danhSachNV[i].maNV, danhSachNV[i].ten, danhSachNV[i].chucVu, danhSachNV[i].luong);
    }
    printf("---------------------------------------\n");
}

void sapXepTheoMaNV(struct Employee danhSachNV[], int soLuong) {
    struct Employee temp;
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = 0; j < soLuong - i - 1; j++) {
            if (danhSachNV[j].maNV > danhSachNV[j + 1].maNV) {
                temp = danhSachNV[j];
                danhSachNV[j] = danhSachNV[j + 1];
                danhSachNV[j + 1] = temp;
            }
        }
    }
    printf("Danh sach nhan vien sau khi sap xep theo ma nhan vien:\n");
    hienThiDanhSach(danhSachNV, soLuong);
}

int main() {
    int choice;
    struct Employee danhSachNV[100];
    int soLuongNV = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep theo ma nhan vien\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                themNhanVien(danhSachNV, &soLuongNV);
                break;
            case 2:
                if (soLuongNV > 0) {
                    int maNV;
                    printf("Nhap ma nhan vien can xoa: ");
                    scanf("%d", &maNV);
                    xoaNhanVien(danhSachNV, &soLuongNV, maNV);
                } else {
                    printf("Danh sach nhan vien rong. Khong co nhan vien de xoa.\n");
                }
                break;
            case 3:
                if (soLuongNV > 0) {
                    hienThiDanhSach(danhSachNV, soLuongNV);
                } else {
                    printf("Danh sach nhan vien rong.\n");
                }
                break;
            case 4:
                if (soLuongNV > 0) {
                    sapXepTheoMaNV(danhSachNV, soLuongNV);
                } else {
                    printf("Danh sach nhan vien rong.\n");
                }
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Chon chuc nang khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

