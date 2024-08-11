#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MON_HOC 5
#define MAX_HO_TEN 50
#define MAX_SINH_VIEN 100

typedef struct {
    char maMon[10];
    char tenMon[50];
    int soTinChi;
    float diem;
} MonHoc;

typedef struct {
    char maSoSinhVien[10];
    char hoTen[MAX_HO_TEN];
    MonHoc monHoc[MAX_MON_HOC];
    float diemTrungBinhTichLuy;
    char xepLoai[20];
} SinhVien;

void xepLoaiHocTap(SinhVien* sinhVien) {
    if (sinhVien->diemTrungBinhTichLuy >= 8.5) {
        strcpy_s(sinhVien->xepLoai, sizeof(sinhVien->xepLoai), "Xuat sac");
    }
    else if (sinhVien->diemTrungBinhTichLuy >= 7.0) {
        strcpy_s(sinhVien->xepLoai, sizeof(sinhVien->xepLoai), "Gioi");
    }
    else if (sinhVien->diemTrungBinhTichLuy >= 5.5) {
        strcpy_s(sinhVien->xepLoai, sizeof(sinhVien->xepLoai), "Kha");
    }
    else if (sinhVien->diemTrungBinhTichLuy >= 4.0) {
        strcpy_s(sinhVien->xepLoai, sizeof(sinhVien->xepLoai), "Trung binh");
    }
    else {
        strcpy_s(sinhVien->xepLoai, sizeof(sinhVien->xepLoai), "Yeu");
    }
}

void thongKeMon(const SinhVien* sinhVien, int* soMonDau, int* soMonRot) {
    *soMonDau = 0;
    *soMonRot = 0;

    for (int i = 0; i < MAX_MON_HOC; i++) {
        if (sinhVien->monHoc[i].diem >= 5.0) {
            (*soMonDau)++;
        }
        else {
            (*soMonRot)++;
        }
    }
}

void nhapSinhVien(SinhVien* sinhVien) {
    printf("Nhap ma so sinh vien: ");
    scanf_s("%9s", sinhVien->maSoSinhVien, (unsigned)_countof(sinhVien->maSoSinhVien));

    // Xóa ký tự newline còn lại từ lần nhập trước
    while (getchar() != '\n');

    printf("Nhap ho ten sinh vien: ");
    fgets(sinhVien->hoTen, MAX_HO_TEN, stdin);
    sinhVien->hoTen[strcspn(sinhVien->hoTen, "\n")] = '\0'; // Loại bỏ ký tự newline nếu có

    for (int i = 0; i < MAX_MON_HOC; i++) {
        printf("Nhap ma mon %d: ", i + 1);
        scanf_s("%9s", sinhVien->monHoc[i].maMon, (unsigned)_countof(sinhVien->monHoc[i].maMon));

        // Xóa ký tự newline còn lại từ lần nhập trước
        while (getchar() != '\n');

        printf("Nhap ten mon %d: ", i + 1);
        fgets(sinhVien->monHoc[i].tenMon, sizeof(sinhVien->monHoc[i].tenMon), stdin);
        sinhVien->monHoc[i].tenMon[strcspn(sinhVien->monHoc[i].tenMon, "\n")] = '\0'; // Loại bỏ ký tự newline nếu có

        printf("Nhap so tin chi mon %d: ", i + 1);
        scanf_s("%d", &sinhVien->monHoc[i].soTinChi);

        // Xóa ký tự newline còn lại từ lần nhập trước
        while (getchar() != '\n');

        printf("Nhap diem mon %d: ", i + 1);
        scanf_s("%f", &sinhVien->monHoc[i].diem);

        // Xóa ký tự newline còn lại từ lần nhập trước
        while (getchar() != '\n');
    }

    // Tính điểm trung bình tích lũy GPA
    float tongDiem = 0;
    int tongTinChi = 0;
    for (int i = 0; i < MAX_MON_HOC; i++) {
        tongDiem += sinhVien->monHoc[i].diem * sinhVien->monHoc[i].soTinChi;
        tongTinChi += sinhVien->monHoc[i].soTinChi;
    }
    sinhVien->diemTrungBinhTichLuy = (tongTinChi > 0) ? (tongDiem / tongTinChi) : 0.0;

    // Xếp loại học tập
    xepLoaiHocTap(sinhVien);
}

void xuatSinhVien(const SinhVien* sinhVien) {
    printf("Ma so sinh vien: %s\n", sinhVien->maSoSinhVien);
    printf("Ho ten sinh vien: %s\n", sinhVien->hoTen);
    for (int i = 0; i < MAX_MON_HOC; i++) {
        printf("Mon %d:\n", i + 1);
        printf("\tMa mon: %s\n", sinhVien->monHoc[i].maMon);
        printf("\tTen mon: %s\n", sinhVien->monHoc[i].tenMon);
        printf("\tSo tin chi: %d\n", sinhVien->monHoc[i].soTinChi);
        printf("\tDiem: %.2f\n", sinhVien->monHoc[i].diem);
    }
    printf("Diem trung binh tich luy: %.2f\n", sinhVien->diemTrungBinhTichLuy);
    printf("Xep loai hoc tap: %s\n", sinhVien->xepLoai);

    int soMonDau, soMonRot;
    thongKeMon(sinhVien, &soMonDau, &soMonRot);
    printf("So mon dau: %d\n", soMonDau);
    printf("So mon rot: %d\n", soMonRot);
}

void nhapDanhSachSinhVien(SinhVien* danhSachSinhVien, int* soLuong) {
    printf("Nhap so luong sinh vien: ");
    scanf_s("%d", soLuong);

    if (*soLuong > MAX_SINH_VIEN) {
        printf("So luong sinh vien vuot qua gioi han cho phep. Cam on.");
        *soLuong = MAX_SINH_VIEN;
    }

    for (int i = 0; i < *soLuong; i++) {
        printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&danhSachSinhVien[i]);
    }
}

void xuatDanhSachSinhVien(const SinhVien* danhSachSinhVien, int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        xuatSinhVien(&danhSachSinhVien[i]);
    }
}

SinhVien* timSinhVien(const SinhVien* danhSachSinhVien, int soLuong, const char* maSoSinhVien) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(danhSachSinhVien[i].maSoSinhVien, maSoSinhVien) == 0) {
            return (SinhVien*)&danhSachSinhVien[i];
        }
    }
    return NULL; // Nếu không tìm thấy
}

SinhVien* timSinhVienDiemCaoNhat(const SinhVien* danhSachSinhVien, int soLuong) {
    if (soLuong <= 0) {
        return NULL;
    }

    SinhVien* sinhVienMax = (SinhVien*)&danhSachSinhVien[0];
    for (int i = 1; i < soLuong; i++) {
        if (danhSachSinhVien[i].diemTrungBinhTichLuy > sinhVienMax->diemTrungBinhTichLuy) {
            sinhVienMax = (SinhVien*)&danhSachSinhVien[i];
        }
    }
    return sinhVienMax;
}

void themSinhVien(SinhVien* danhSachSinhVien, int* soLuong, const SinhVien* sinhVienMoi) {
    if (*soLuong >= MAX_SINH_VIEN) {
        printf("Danh sach sinh vien da day. Khong the them sinh vien moi.\n");
        return;
    }

    danhSachSinhVien[*soLuong] = *sinhVienMoi;
    (*soLuong)++;
}

void xoaSinhVien(SinhVien* danhSachSinhVien, int* soLuong, const char* maSoSinhVien) {
    int indexToRemove = -1;
    for (int i = 0; i < *soLuong; i++) {
        if (strcmp(danhSachSinhVien[i].maSoSinhVien, maSoSinhVien) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Khong tim thay sinh vien voi ma so: %s\n", maSoSinhVien);
        return;
    }

    for (int i = indexToRemove; i < *soLuong - 1; i++) {
        danhSachSinhVien[i] = danhSachSinhVien[i + 1];
    }
    (*soLuong)--;
}

void sapXepDanhSachSinhVien(SinhVien* danhSachSinhVien, int soLuong, int tangDan) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if ((tangDan && danhSachSinhVien[i].diemTrungBinhTichLuy > danhSachSinhVien[j].diemTrungBinhTichLuy) ||
                (!tangDan && danhSachSinhVien[i].diemTrungBinhTichLuy < danhSachSinhVien[j].diemTrungBinhTichLuy)) {
                SinhVien temp = danhSachSinhVien[i];
                danhSachSinhVien[i] = danhSachSinhVien[j];
                danhSachSinhVien[j] = temp;
            }
        }
    }
}

int main() {
    SinhVien danhSachSinhVien[MAX_SINH_VIEN];
    int soLuongSinhVien = 0;
    int luaChon;
    char maSoSinhVien[10];

    do {
        printf("\n=== Menu ===\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien theo ma so\n");
        printf("4. Tim sinh vien co diem trung binh cao nhat\n");
        printf("5. Them sinh vien\n");
        printf("6. Xoa sinh vien\n");
        printf("7. Sap xep danh sach sinh vien\n");
        printf("8. Thoat\n");
        printf("Chon thao tac (1-8): ");
        scanf_s("%d", &luaChon);

        // Xóa ký tự newline còn lại từ lần nhập trước
        while (getchar() != '\n');

        switch (luaChon) {
        case 1:
            nhapDanhSachSinhVien(danhSachSinhVien, &soLuongSinhVien);
            break;
        case 2:
            xuatDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
            break;
        case 3: {
            printf("Nhap ma so sinh vien can tim: ");
            scanf_s("%9s", maSoSinhVien, (unsigned)_countof(maSoSinhVien));
            // Xóa ký tự newline còn lại từ lần nhập trước
            while (getchar() != '\n');
            SinhVien* sinhVien = timSinhVien(danhSachSinhVien, soLuongSinhVien, maSoSinhVien);
            if (sinhVien != NULL) {
                xuatSinhVien(sinhVien);
            }
            else {
                printf("Khong tim thay sinh vien voi ma so: %s\n", maSoSinhVien);
            }
            break;
        }
        case 4: {
            SinhVien* sinhVienMax = timSinhVienDiemCaoNhat(danhSachSinhVien, soLuongSinhVien);
            if (sinhVienMax != NULL) {
                printf("Sinh vien co diem trung binh cao nhat:\n");
                xuatSinhVien(sinhVienMax);
            }
            else {
                printf("Danh sach sinh vien rong.\n");
            }
            break;
        }
        case 5: {
            SinhVien sinhVienMoi;
            printf("Nhap thong tin sinh vien moi:\n");
            nhapSinhVien(&sinhVienMoi);
            themSinhVien(danhSachSinhVien, &soLuongSinhVien, &sinhVienMoi);
            break;
        }
        case 6: {
            printf("Nhap ma so sinh vien can xoa: ");
            scanf_s("%9s", maSoSinhVien, (unsigned)_countof(maSoSinhVien));
            // Xóa ký tự newline còn lại từ lần nhập trước
            while (getchar() != '\n');
            xoaSinhVien(danhSachSinhVien, &soLuongSinhVien, maSoSinhVien);
            printf("Danh sach sinh vien sau khi xoa:\n");
            xuatDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
            break;
        }
        case 7: {
            printf("1. Sap xep tang dan\n");
            printf("2. Sap xep giam dan\n");
            printf("Chon thao tac (1-2): ");
            int luaChonSapXep;
            scanf_s("%d", &luaChonSapXep);
            // Xóa ký tự newline còn lại từ lần nhập trước
            while (getchar() != '\n');
            sapXepDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien, luaChonSapXep == 1);
            printf("Danh sach sinh vien sau khi sap xep:\n");
            xuatDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
            break;
        }
        case 8:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (luaChon != 8);

    return 0;
}
