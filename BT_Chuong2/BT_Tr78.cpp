//#include <stdio.h>
//#include <math.h>
//
//// Hàm kiểm tra số hoàn thiện
//int laSoHoanThien(int so) {
//    int tong = 0;
//    for (int i = 1; i <= so / 2; i++) {
//        if (so % i == 0) {
//            tong += i;
//        }
//    }
//    return tong == so;
//}
//
//// Hàm kiểm tra số nguyên tố
//int laSoNguyenTo(int so) {
//    if (so < 2) return 0;
//    for (int i = 2; i <= sqrt(so); i++) {
//        if (so % i == 0) return 0;
//    }
//    return 1;
//}
//
//// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
//int tongChuSoDauLe(int maTran[][100], int soHang, int soCot) {
//    int tong = 0;
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            int so = abs(maTran[i][j]);
//            while (so >= 10) {
//                so /= 10;
//            }
//            if (so % 2 != 0) {
//                tong += maTran[i][j];
//            }
//        }
//    }
//    return tong;
//}
//
//// Bài 2: Liệt kê các số hoàn thiện trong ma trận
//void lietKeSoHoanThien(int maTran[][100], int soHang, int soCot) {
//    printf("Cac so hoan thien trong ma tran: ");
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            if (laSoHoanThien(maTran[i][j])) {
//                printf("%d ", maTran[i][j]);
//            }
//        }
//    }
//    printf("\n");
//}
//
//// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
//int tongLonHonSau(int maTran[][100], int soHang, int soCot) {
//    int tong = 0;
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot - 1; j++) {
//            if (maTran[i][j] > abs(maTran[i][j + 1])) {
//                tong += maTran[i][j];
//            }
//        }
//    }
//    return tong;
//}
//
//// Bài 4: Tính tổng giá trị trên dòng k của ma trận
//int tongDongK(int maTran[][100], int soCot, int dongK) {
//    int tong = 0;
//    for (int j = 0; j < soCot; j++) {
//        tong += maTran[dongK][j];
//    }
//    return tong;
//}
//
//// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
//int tongBien(int maTran[][100], int soHang, int soCot) {
//    int tong = 0;
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            if (i == 0 || i == soHang - 1 || j == 0 || j == soCot - 1) {
//                tong += maTran[i][j];
//            }
//        }
//    }
//    return tong;
//}
//
//// Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận
//int demTanSuat(int maTran[][100], int soHang, int soCot, int giaTriX) {
//    int dem = 0;
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            if (maTran[i][j] == giaTriX) {
//                dem++;
//            }
//        }
//    }
//    return dem;
//}
//
//// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
//void demCacPhanTu(int maTran[][100], int soHang, int soCot) {
//    int soChan = 0, soLe = 0, soAm = 0, soDuong = 0, soNguyenTo = 0;
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            if (maTran[i][j] % 2 == 0) soChan++;
//            else soLe++;
//            if (maTran[i][j] < 0) soAm++;
//            if (maTran[i][j] > 0) soDuong++;
//            if (laSoNguyenTo(maTran[i][j])) soNguyenTo++;
//        }
//    }
//    printf("So chan: %d, So le: %d, So am: %d, So duong: %d, So nguyen to: %d\n", soChan, soLe, soAm, soDuong, soNguyenTo);
//}
//
//int main() {
//    int maTran[100][100], soHang, soCot, giaTriX, dongK;
//
//    // Nhập kích thước m, n và các phần tử của ma trận
//    printf("Nhap so hang va so cot: ");
//    scanf_s("%d%d", &soHang, &soCot);
//
//    printf("Nhap cac phan tu cua ma tran:\n");
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            scanf_s("%d", &maTran[i][j]);
//        }
//    }
//
//    // Thực hiện các bài toán
//    printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(maTran, soHang, soCot));
//
//    lietKeSoHoanThien(maTran, soHang, soCot);
//
//    printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", tongLonHonSau(maTran, soHang, soCot));
//
//    printf("Nhap dong k can tinh tong: ");
//    scanf_s("%d", &dongK);
//    printf("Tong tren dong %d la: %d\n", dongK, tongDongK(maTran, soCot, dongK));
//
//    printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tongBien(maTran, soHang, soCot));
//
//    printf("Nhap gia tri x can dem tan suat: ");
//    scanf_s("%d", &giaTriX);
//    printf("Tan suat xuat hien cua %d trong ma tran la: %d\n", giaTriX, demTanSuat(maTran, soHang, soCot, giaTriX));
//
//    demCacPhanTu(maTran, soHang, soCot);
//
//    return 0;
//}
