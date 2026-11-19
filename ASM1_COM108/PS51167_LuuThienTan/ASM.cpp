#include <stdio.h>

// KIEM TRA SO NGUYEN
void KiemTraSoNguyen()
{
    double x;
    int n, i;
    int laSoNguyenTo = 1;
    int laSoChinhPhuong = 0;

    printf("\nNhap so nguyen x: ");
    scanf("%lf", &x);

    // 1. Kiem tra so nguyen
    if (x != (int)x) {
        printf("\n1. %.2lf khong phai la so nguyen.\n", x);
        printf("2. %.2lf khong phai la so nguyen to.\n", x);
        printf("3. %.2lf khong phai la so chinh phuong.\n", x);
        return;
    }
    else {
        n = (int)x;
        printf("\n1. %d la so nguyen.\n", n);
    }

    // 2. Kiem tra so nguyen to
    if (n < 2) {
        laSoNguyenTo = 0;
    }
    else {
        for (i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                laSoNguyenTo = 0;
                break;
            }
        }
    }

    if (laSoNguyenTo == 1) {
        printf("2. %d la so nguyen to.\n", n);
    }
    else {
        printf("2. %d khong phai la so nguyen to.\n", n);
    }

    // 3. Kiem tra so chinh phuong
    if (n >= 0) {
        for (i = 0; i * i <= n; i++) {
            if (i * i == n) {
                laSoChinhPhuong = 1;
                break;
            }
        }
    }

    if (laSoChinhPhuong == 1) {
        printf("3. %d la so chinh phuong.\n", n);
    }
    else {
        printf("3. %d khong phai la so chinh phuong.\n", n);
    }
}

//TIM USCLN VA BSCNN CUA 2 SO
void TimUSCLN_BSCNN()
{
    int x, y;
    int a, b;
    int uscln, bscnn;
    int i;

    printf("\nNhap so nguyen x: ");
    scanf("%d", &x);
	printf("Nhap so nguyen y: ");
    scanf("%d", &y);

    // Lay gia tri tuyet doi
    a = x;
    b = y;
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    // Tim USCLN
    if (a == 0) {
    uscln = b;
}
else if (b == 0) {
    uscln = a;
}
else {
    for (i = (a < b ? a : b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            uscln = i;
            break;
        }
    }
}

    // Tim BSCNN
    if (a == 0 || b == 0) {
        bscnn = 0;
    }
    else {
        bscnn = a * b / uscln;
    }

    printf("\nUoc so chung lon nhat cua %d va %d la: %d\n", x, y, uscln);
    printf("Boi so chung nho nhat cua %d va %d la: %d\n", x, y, bscnn);
}

//TINH TIEN KARAOKE
void TinhTienKaraoke()
{
    int gioBatDau, gioKetThuc;
    int soGio;
    int gioGiam;
    int tien;
    int i;

    printf("\nNhap gio bat dau: ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc: ");
    scanf("%d", &gioKetThuc);

    // Kiem tra gio hop le
    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("\nGio khong hop le!\n");
        return;
    }
	soGio = gioKetThuc - gioBatDau;

    // Tinh tien 3 gio dau
    if (soGio <= 3) {
        tien = soGio * 50000;
    }
    else {
        // 3 gio dau tinh gia goc
        tien = 3 * 50000;

        // Tu gio thu 4 giam 30%
        gioGiam = soGio - 3;
        tien = tien + gioGiam * 50000 * 70 / 100;
    }

    // Giam them 10% neu bat dau tu 14 den 17 gio
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tien = tien * 90 / 100;
    }

    printf("\nSo gio hat karaoke: %d gio\n", soGio);
    printf("Tong tien can thanh toan: %d dong\n", tien);
}

//TINH TIEN DIEN
void TinhTienDien()
{
    int kwh;
    int tien = 0;

    printf("\nNhap so dien su dung: ");
    scanf("%d", &kwh);

    if (kwh < 0) {
        printf("So kWh khong hop le!\n");
        return;
    }

    if (kwh <= 50) {
        tien = kwh * 1678;
    }
    else if (kwh <= 100) {
        tien = 50 * 1678 + (kwh - 50) * 1734;
    }
    else if (kwh <= 200) {
        tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    }
    else if (kwh <= 300) {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    }
    else if (kwh <= 400) {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    }
    else {
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    }
    printf("\nTong tien dien phai tra: %d dong\n", tien);
}

//TINH LAI SUAT VAY NGAN HANG
void TinhLaiSuatVay()
{
    double tienVay;
    double tienGoc;
    double tienLai;
    double tienPhaiTra;
    double tienConLai;
    int i;

    printf("\nNhap so tien muon vay: ");
    scanf("%lf", &tienVay);

    if (tienVay <= 0) {
        printf("So tien vay khong hop le!\n");
        return;
    }

    // Tinh tien goc phai tra moi thang
    tienGoc = tienVay / 12;

    // So tien con lai ban dau
    tienConLai = tienVay;

    printf("\n========== BANG TINH TIEN VAY ==========\n");
    printf("%-10s %-15s %-15s %-20s %-15s\n",
    	"Ky han", "Lai phai tra", "Goc phai tra","So tien phai tra", "So tien con lai");

    // Lap 12 thang
    for (i = 1; i <= 12; i++) {

        // Tinh tien lai moi thang
        tienLai = tienConLai * 5 / 100;

        // Tinh tong tien phai tra
        tienPhaiTra = tienGoc + tienLai;

        // Tru tien goc da tra
        tienConLai = tienConLai - tienGoc;

        printf("%-10d %-15.0lf %-15.0lf %-20.0lf %-15.0lf\n",
				i, tienLai, tienGoc, tienPhaiTra, tienConLai);
    }
}

//SAP XEP THONG TIN SINH VIEN
struct SinhVien {
    char hoTen[50];
    float diem;
};
void SapXepSinhVien()
{
    struct SinhVien sv[100], tam;
    int n, i, j;

    printf("\nNhap so luong sinh vien: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So luong sinh vien khong hop le!\n");
        return;
    }

    // Nhap thong tin sinh vien
    for (i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d\n", i + 1);
        printf("Ho ten: ");
        scanf(" %49[^\n]", sv[i].hoTen);
        printf("Diem: ");
        scanf("%f", &sv[i].diem);
    }

    // Sap xep diem giam dan
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                tam = sv[i];
                sv[i] = sv[j];
                sv[j] = tam;
            }
        }
    }

    // Xuat danh sach sinh vien
    printf("\n======= DANH SACH SINH VIEN =======\n");

    for (i = 0; i < n; i++) {
        printf("\nHo ten: %s", sv[i].hoTen);
        printf("\nDiem: %.2f", sv[i].diem);

        if (sv[i].diem >= 9.0) {
            printf("\nHoc luc: Xuat sac\n");
        }
        else if (sv[i].diem >= 8.0) {
            printf("\nHoc luc: Gioi\n");
        }
        else if (sv[i].diem >= 6.5) {
            printf("\nHoc luc: Kha\n");
        }
        else if (sv[i].diem >= 5.0) {
            printf("\nHoc luc: Trung binh\n");
        }
        else {
            printf("\nHoc luc: Yeu\n");
        }
    }
}

//TINH TOAN PHAN SO
struct PhanSo {
    int tu, mau;
};
int UCLN(int a, int b)
{
    int tam;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        tam = a % b;
        a = b;
        b = tam;
    }
    return a;
}
struct PhanSo RutGon(struct PhanSo ps)
{
    int u = UCLN(ps.tu, ps.mau);
    ps.tu /= u;
    ps.mau /= u;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}
void TinhToanPhanSo()
{
    struct PhanSo a, b;
    struct PhanSo tong, hieu, tich, thuong;

    // Nhap phan so thu nhat
    printf("\nNhap phan so thu nhat:\n");
    printf("Nhap tu so: ");
    scanf("%d", &a.tu);

    printf("Nhap mau so: ");
    scanf("%d", &a.mau);

    // Nhap phan so thu hai
    printf("\nNhap phan so thu hai:\n");
    printf("Nhap tu so: ");
    scanf("%d", &b.tu);

    printf("Nhap mau so: ");
    scanf("%d", &b.mau);

    // Kiem tra mau so
    if (a.mau == 0 || b.mau == 0) {
        printf("Mau so khong duoc bang 0!\n");
        return;
    }

    // Tinh tong
    tong.tu = a.tu * b.mau + b.tu * a.mau;
    tong.mau = a.mau * b.mau;

    // Tinh hieu
    hieu.tu = a.tu * b.mau - b.tu * a.mau;
    hieu.mau = a.mau * b.mau;

    // Tinh tich
    tich.tu = a.tu * b.tu;
    tich.mau = a.mau * b.mau;

    // Rut gon
    tong = RutGon(tong);
    hieu = RutGon(hieu);
    tich = RutGon(tich);

    // Xuat ket qua
    printf("\n======= KET QUA =======\n");
    printf("Tong: %d/%d\n", tong.tu, tong.mau);
    printf("Hieu: %d/%d\n", hieu.tu, hieu.mau);
    printf("Tich: %d/%d\n", tich.tu, tich.mau);

    // Tinh thuong
    if (b.tu == 0) {
        printf("Thuong: Khong the chia cho 0!\n");
    }
    else {
        thuong.tu = a.tu * b.mau;
        thuong.mau = a.mau * b.tu;
        thuong = RutGon(thuong);
        
        printf("Thuong: %d/%d\n",
               thuong.tu, thuong.mau);
    }
}

//MENU
int main()
{
	int chucnang;
	char chon;
	do {
		printf("\n|--------------MENU----------------|");
		printf("\n|1.KIEM TRA SO NGUYEN TO-----------|");
		printf("\n|2.TIM USCLN VA BSCNN CUA 2 SO-----|");
		printf("\n|3.CT TINH TIEN KARAOKE------------|");
		printf("\n|4.TINH TIEN DIEN------------------|");
		printf("\n|5.TINH LAI SUAT VAY NGAN HANG-----|");
		printf("\n|6.XAP XEP THONG TIN SINH VIEN-----|");
		printf("\n|7.TINH TOAN PHAN SO---------------|");
		printf("\n|---------------oOo----------------|");
	
	printf("\nChon Menu: ");
	scanf("%d",&chucnang);
	
	switch(chucnang)
	{
		case 1:
			KiemTraSoNguyen();
			break;
		case 2:
			TimUSCLN_BSCNN();
			break;
		case 3:
			TinhTienKaraoke();
			break;
		case 4:
			TinhTienDien();
			break;
		case 5:
			TinhLaiSuatVay();
			break;
		case 6:
			SapXepSinhVien();
			break;
		case 7:
			TinhToanPhanSo();
			break;
		default:
			printf("Chuc nang khong hop le! Vui long chon lai.\n");
	}
	printf("\nBan co muon tiep tuc khong? (Y/N): ");
    scanf(" %c", &chon);
    } while (chon == 'Y' || chon == 'y');
    printf("\n Da Thoat Chuong Trinh!");
return 0;
}
