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
//// Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
//void lietKeCotTongNhoNhat(int maTran[][100], int soHang, int soCot) {
//    int tongCot[100], tongNhoNhat;
//
//    // Tính tổng của từng cột
//    for (int j = 0; j < soCot; j++) {
//        tongCot[j] = 0;
//        for (int i = 0; i < soHang; i++) {
//            tongCot[j] += maTran[i][j];
//        }
//    }
//
//    // Tìm tổng nhỏ nhất
//    tongNhoNhat = tongCot[0];
//    for (int j = 1; j < soCot; j++) {
//        if (tongCot[j] < tongNhoNhat) {
//            tongNhoNhat = tongCot[j];
//        }
//    }
//
//    // Liệt kê các cột có tổng nhỏ nhất
//    printf("Cac cot co tong nho nhat: ");
//    for (int j = 0; j < soCot; j++) {
//        if (tongCot[j] == tongNhoNhat) {
//            printf("%d ", j);
//        }
//    }
//    printf("\n");
//}
//
//// Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
//void lietKeDongNhieuSoHoanThien(int maTran[][100], int soHang, int soCot) {
//    int demSoHoanThien[100], maxSoHoanThien = 0;
//
//    // Đếm số hoàn thiện trong từng dòng
//    for (int i = 0; i < soHang; i++) {
//        demSoHoanThien[i] = 0;
//        for (int j = 0; j < soCot; j++) {
//            if (laSoHoanThien(maTran[i][j])) {
//                demSoHoanThien[i]++;
//            }
//        }
//        if (demSoHoanThien[i] > maxSoHoanThien) {
//            maxSoHoanThien = demSoHoanThien[i];
//        }
//    }
//
//    // Liệt kê các dòng có nhiều số hoàn thiện nhất
//    printf("Cac dong co nhieu so hoan thien nhat: ");
//    for (int i = 0; i < soHang; i++) {
//        if (demSoHoanThien[i] == maxSoHoanThien) {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//}
//
//// Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
//void lietKeDongToanChan(int maTran[][100], int soHang, int soCot) {
//    printf("Cac dong chua toan gia tri chan: ");
//    for (int i = 0; i < soHang; i++) {
//        int toanChan = 1;
//        for (int j = 0; j < soCot; j++) {
//            if (maTran[i][j] % 2 != 0) {
//                toanChan = 0;
//                break;
//            }
//        }
//        if (toanChan) {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//}
//
//// Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
//int timGiaTriNhieuNhat(int maTran[][100], int soHang, int soCot) {
//    int tanSuat[10000] = { 0 }, giaTriNhieuNhat, maxTanSuat = 0;
//
//    // Tính tần suất xuất hiện của mỗi giá trị trong ma trận
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            tanSuat[maTran[i][j] + 5000]++; // Giả sử các giá trị trong khoảng [-5000, 5000]
//            if (tanSuat[maTran[i][j] + 5000] > maxTanSuat) {
//                maxTanSuat = tanSuat[maTran[i][j] + 5000];
//                giaTriNhieuNhat = maTran[i][j];
//            }
//        }
//    }
//
//    return giaTriNhieuNhat;
//}
//
//// Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
//int timSoNguyenToNhoNhat(int maTran[][100], int soHang, int soCot) {
//    int soNguyenToNhoNhat = -1;
//
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            if (laSoNguyenTo(maTran[i][j])) {
//                if (soNguyenToNhoNhat == -1 || maTran[i][j] < soNguyenToNhoNhat) {
//                    soNguyenToNhoNhat = maTran[i][j];
//                }
//            }
//        }
//    }
//
//    return soNguyenToNhoNhat;
//}
//
//// Bài 6: Tìm phần tử lớn nhất trong dòng thứ k
//int timLonNhatDongK(int maTran[][100], int soCot, int dongK) {
//    int lonNhat = maTran[dongK][0];
//    for (int j = 1; j < soCot; j++) {
//        if (maTran[dongK][j] > lonNhat) {
//            lonNhat = maTran[dongK][j];
//        }
//    }
//    return lonNhat;
//}
//
//// Bài 6: Tìm phần tử nhỏ nhất trong dòng thứ k
//int timNhoNhatDongK(int maTran[][100], int soCot, int dongK) {
//    int nhoNhat = maTran[dongK][0];
//    for (int j = 1; j < soCot; j++) {
//        if (maTran[dongK][j] < nhoNhat) {
//            nhoNhat = maTran[dongK][j];
//        }
//    }
//    return nhoNhat;
//}
//
//// Bài 7: Tìm phần tử lớn nhất trong cột thứ k
//int timLonNhatCotK(int maTran[][100], int soHang, int cotK) {
//    int lonNhat = maTran[0][cotK];
//    for (int i = 1; i < soHang; i++) {
//        if (maTran[i][cotK] > lonNhat) {
//            lonNhat = maTran[i][cotK];
//        }
//    }
//    return lonNhat;
//}
//
//// Bài 7: Tìm phần tử nhỏ nhất trong cột thứ k
//int timNhoNhatCotK(int maTran[][100], int soHang, int cotK) {
//    int nhoNhat = maTran[0][cotK];
//    for (int i = 1; i < soHang; i++) {
//        if (maTran[i][cotK] < nhoNhat) {
//            nhoNhat = maTran[i][cotK];
//        }
//    }
//    return nhoNhat;
//}
//
//int main() {
//    int maTran[100][100], soHang, soCot, dongK, cotK;
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
//    // Bài 1: Liệt kê các cột có tổng nhỏ nhất
//    lietKeCotTongNhoNhat(maTran, soHang, soCot);
//
//    // Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất
//    lietKeDongNhieuSoHoanThien(maTran, soHang, soCot);
//
//    // Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
//    lietKeDongToanChan(maTran, soHang, soCot);
//
//    // Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
//    int giaTriNhieuNhat = timGiaTriNhieuNhat(maTran, soHang, soCot);
//    printf("Gia tri xuat hien nhieu nhat trong ma tran: %d\n", giaTriNhieuNhat);
//
//    // Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
//    int soNguyenToNhoNhat = timSoNguyenToNhoNhat(maTran, soHang, soCot);
//    if (soNguyenToNhoNhat != -1) {
//        printf("So nguyen to nho nhat trong ma tran: %d\n", soNguyenToNhoNhat);
//    }
//    else {
//        printf("Khong co so nguyen to trong ma tran.\n");
//    }
//
//    // Nhập dòng k và cột k
//    printf("Nhap chi so dong k can tim: ");
//    scanf_s("%d", &dongK);
//    printf("Nhap chi so cot k can tim: ");
//    scanf_s("%d", &cotK);
//
//    // Bài 6: Tìm phần tử lớn nhất và nhỏ nhất trong dòng thứ k
//    int lonNhatDongK = timLonNhatDongK(maTran, soCot, dongK);
//    int nhoNhatDongK = timNhoNhatDongK(maTran, soCot, dongK);
//    printf("Phan tu lon nhat trong dong %d: %d\n", dongK, lonNhatDongK);
//    printf("Phan tu nho nhat trong dong %d: %d\n", dongK, nhoNhatDongK);
//
//    // Bài 7: Tìm phần tử lớn nhất và nhỏ nhất trong cột thứ k
//    int lonNhatCotK = timLonNhatCotK(maTran, soHang, cotK);
//    int nhoNhatCotK = timNhoNhatCotK(maTran, soHang, cotK);
//    printf("Phan tu lon nhat trong cot %d: %d\n", cotK, lonNhatCotK);
//    printf("Phan tu nho nhat trong cot %d: %d\n", cotK, nhoNhatCotK);
//
//    return 0;
//}
