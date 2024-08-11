//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 100
//
//// Hàm so sánh cho qsort
//int soSanh(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//// Hàm sắp xếp một dòng của ma trận
//void sapXepDong(int maTran[][MAX], int soCot, int dong, int tangDan) {
//    int temp[MAX];
//    for (int j = 0; j < soCot; j++) {
//        temp[j] = maTran[dong][j];
//    }
//    if (tangDan) {
//        qsort(temp, soCot, sizeof(int), soSanh);
//    }
//    else {
//        qsort(temp, soCot, sizeof(int), soSanh);
//        for (int j = 0; j < soCot / 2; j++) {
//            int t = temp[j];
//            temp[j] = temp[soCot - j - 1];
//            temp[soCot - j - 1] = t;
//        }
//    }
//    for (int j = 0; j < soCot; j++) {
//        maTran[dong][j] = temp[j];
//    }
//}
//
//// Hàm sắp xếp một cột của ma trận
//void sapXepCot(int maTran[][MAX], int soHang, int cot, int tangDan) {
//    int temp[MAX];
//    for (int i = 0; i < soHang; i++) {
//        temp[i] = maTran[i][cot];
//    }
//    if (tangDan) {
//        qsort(temp, soHang, sizeof(int), soSanh);
//    }
//    else {
//        qsort(temp, soHang, sizeof(int), soSanh);
//        for (int i = 0; i < soHang / 2; i++) {
//            int t = temp[i];
//            temp[i] = temp[soHang - i - 1];
//            temp[soHang - i - 1] = t;
//        }
//    }
//    for (int i = 0; i < soHang; i++) {
//        maTran[i][cot] = temp[i];
//    }
//}
//
//// Hàm sắp xếp ma trận theo zic-zac
//void sapXepZicZac(int maTran[][MAX], int soHang, int soCot, int tangDan) {
//    int temp[MAX * MAX];
//    int index = 0;
//
//    // Lấy tất cả phần tử của ma trận vào mảng tạm
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            temp[index++] = maTran[i][j];
//        }
//    }
//    if (tangDan) {
//        qsort(temp, index, sizeof(int), soSanh);
//    }
//    else {
//        qsort(temp, index, sizeof(int), soSanh);
//        for (int i = 0; i < index / 2; i++) {
//            int t = temp[i];
//            temp[i] = temp[index - i - 1];
//            temp[index - i - 1] = t;
//        }
//    }
//
//    // Đưa các phần tử từ mảng tạm vào ma trận theo thứ tự zic-zac
//    index = 0;
//    for (int i = 0; i < soHang; i++) {
//        if (i % 2 == 0) {
//            for (int j = 0; j < soCot; j++) {
//                maTran[i][j] = temp[index++];
//            }
//        }
//        else {
//            for (int j = soCot - 1; j >= 0; j--) {
//                maTran[i][j] = temp[index++];
//            }
//        }
//    }
//}
//
//// Hàm in ma trận
//void inMaTran(int maTran[][MAX], int soHang, int soCot) {
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            printf("%d ", maTran[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int maTran[MAX][MAX], soHang, soCot;
//
//    // Nhập kích thước ma trận và các phần tử
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
//    // Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn tăng, dòng lẻ giảm
//    for (int i = 0; i < soHang; i++) {
//        sapXepDong(maTran, soCot, i, i % 2 == 0);
//    }
//    printf("Ma tran sau khi sap xep theo yeu cau dong:\n");
//    inMaTran(maTran, soHang, soCot);
//
//    // Khôi phục ma trận gốc
//    printf("Nhap lai cac phan tu cua ma tran:\n");
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            scanf_s("%d", &maTran[i][j]);
//        }
//    }
//
//    // Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng, cột lẻ giảm
//    for (int j = 0; j < soCot; j++) {
//        sapXepCot(maTran, soHang, j, j % 2 == 0);
//    }
//    printf("Ma tran sau khi sap xep theo yeu cau cot:\n");
//    inMaTran(maTran, soHang, soCot);
//
//    // Khôi phục ma trận gốc
//    printf("Nhap lai cac phan tu cua ma tran:\n");
//    for (int i = 0; i < soHang; i++) {
//        for (int j = 0; j < soCot; j++) {
//            scanf_s("%d", &maTran[i][j]);
//        }
//    }
//
//    // Bài 3: Sắp xếp ma trận theo zic-zac
//    printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
//    int tangDan;
//    scanf_s("%d", &tangDan);
//    sapXepZicZac(maTran, soHang, soCot, tangDan);
//    printf("Ma tran sau khi sap xep theo zic-zac:\n");
//    inMaTran(maTran, soHang, soCot);
//    return 0;
//}
