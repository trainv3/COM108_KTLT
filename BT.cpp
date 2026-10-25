#include <stdio.h>

int main(void) {
    int n;
    unsigned long long giaiThua = 1;

    printf("Nhap n: ");
    if (scanf("%d", &n) != 1) {
        printf("Du lieu khong hop le.\n");
        return 1;
    }

    if (n < 0) {
        printf("Khong tinh duoc giai thua cua so am.\n");
        return 0;
    }

    if (n > 20) {
        printf("n qua lon; chuong trinh chi tinh duoc n <= 20.\n");
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        giaiThua *= (unsigned long long)i;
    }

    printf("%d! = %llu\n", n, giaiThua);
    return 0;
}
