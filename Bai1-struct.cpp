#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

void nhapSinhVien(struct Student sv[], int index) {
    printf("Nhap ten sinh vien: ");
    scanf("%s", sv[index].name);
    printf("Nhap tuoi cua sinh vien: ");
    scanf("%d", &(sv[index].age));
    printf("Nhap diem trung binh cua sinh vien: ");
    scanf("%f", &(sv[index].gpa));
}

void hienThiSinhVien(struct Student sv) {
    printf("Ten: %s\n", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("Diem trung binh: %.2f\n", sv.gpa);
}

int main() {
    int numStudents;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);

    struct Student* students = (struct Student*) malloc(numStudents * sizeof(struct Student));
    for (int i = 0; i < numStudents; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(students, i);
    }

    printf("\nThong tin sinh vien:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        hienThiSinhVien(students[i]);
        printf("\n");
    }

    int studentIndex;
    printf("Nhap so thu tu sinh vien can cap nhat thong tin (1 - %d): ", numStudents);
    scanf("%d", &studentIndex);
    if (studentIndex >= 1 && studentIndex <= numStudents) {
        studentIndex--;
        printf("Nhap thong tin moi cho sinh vien thu %d:\n", studentIndex + 1);
        nhapSinhVien(students, studentIndex);
        printf("\nThong tin sinh vien sau khi cap nhat:\n");
        printf("Sinh vien thu %d:\n", studentIndex + 1);
        hienThiSinhVien(students[studentIndex]);
    } else {
        printf("So thu tu sinh vien khong hop le.\n");
    }
    return 0;
}
