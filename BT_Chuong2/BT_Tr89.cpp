//#include <stdio.h>
//
//#define MAX 100
//
//// Hàm tính tổng các phần tử nằm trên đường chéo chính
//int tongDuongCheoChinh(int maTran[][MAX], int n) {
//    int tong = 0;
//    for (int i = 0; i < n; i++) {
//        tong += maTran[i][i];
//    }
//    return tong;
//}
//
//// Hàm tính tổng các phần tử nằm trên đường chéo phụ
//int tongDuongCheoPhu(int maTran[][MAX], int n) {
//    int tong = 0;
//    for (int i = 0; i < n; i++) {
//        tong += maTran[i][n - i - 1];
//    }
//    return tong;
//}
//
//// Hàm tính tổng các phần tử nằm phía trên đường chéo chính
//int tongTrenDuongCheoChinh(int maTran[][MAX], int n) {
//    int tong = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            tong += maTran[i][j];
//        }
//    }
//    return tong;
//}
//
//// Hàm tính tổng các phần tử nằm phía trên đường chéo phụ
//int tongTrenDuongCheoPhu(int maTran[][MAX], int n) {
//    int tong = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            tong += maTran[i][j];
//        }
//    }
//    return tong;
//}
//
//// Hàm in ma trận
//void inMaTran(int maTran[][MAX], int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d ", maTran[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int maTran[MAX][MAX], n;
//
//    // Nhập kích thước ma trận
//    printf("Nhap kich thuoc ma tran vuong n x n: ");
//    scanf_s("%d", &n);
//
//    // Nhập các phần tử của ma trận
//    printf("Nhap cac phan tu cua ma tran:\n");
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            scanf_s("%d", &maTran[i][j]);
//        }
//    }
//
//    // In ma trận
//    printf("Ma tran:\n");
//    inMaTran(maTran, n);
//
//    // Tính và in tổng các phần tử trên đường chéo chính
//    int tongCheoChinh = tongDuongCheoChinh(maTran, n);
//    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongCheoChinh);
//
//    // Tính và in tổng các phần tử trên đường chéo phụ
//    int tongCheoPhu = tongDuongCheoPhu(maTran, n);
//    printf("Tong cac phan tu tren duong cheo phu: %d\n", tongCheoPhu);
//
//    // Tính và in tổng các phần tử phía trên đường chéo chính
//    int tongTrenCheoChinh = tongTrenDuongCheoChinh(maTran, n);
//    printf("Tong cac phan tu phia tren duong cheo chinh: %d\n", tongTrenCheoChinh);
//
//    // Tính và in tổng các phần tử phía trên đường chéo phụ
//    int tongTrenCheoPhu = tongTrenDuongCheoPhu(maTran, n);
//    printf("Tong cac phan tu phia tren duong cheo phu: %d\n", tongTrenCheoPhu);
//
//    return 0;
//}
