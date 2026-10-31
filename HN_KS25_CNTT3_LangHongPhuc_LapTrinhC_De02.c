#include <stdio.h>
#include <string.h>

#define MAX 50

struct Thuoc {
    int maThuoc;
    char tenThuoc[50];
    int soLuong;
    float donGia;
};

struct Thuoc ds[MAX];
int soLuong = 0;

int timTheoMa(int ma) {
    int i;

    for (i = 0; i < soLuong; i++) {
        if (ds[i].maThuoc == ma) {
            return i;
        }
    }

    return -1;
}

void nhapTenThuoc(char tenThuoc[]) {
    fgets(tenThuoc, 50, stdin);
    tenThuoc[strcspn(tenThuoc, "\n")] = '\0';
}

void nhapSoLuong(int *soLuong) {
    do {
        printf("Nhap so luong: ");
        scanf("%d", soLuong);

        if (*soLuong < 0 ) {
            printf("So luong khong hop le\n");
        }
    } while (*soLuong < 0);
}

void nhapDonGia(float *donGia) {
    do {
        printf("Nhap don gia: ");
        scanf("%f", donGia);

        if (*donGia < 0) {
            printf("Don gia khong hop le\n");
        }
    } while (*donGia < 0);
}

void nhapThongTin(struct Thuoc *th) {
    printf("Nhap ten thuoc: ");
    nhapTenThuoc(th->tenThuoc);

    nhapSoLuong(&th->soLuong);
    nhapDonGia(&th->donGia);
}

void inMotLoaiThuoc(struct Thuoc th) {
    printf("%-10d %-25s %-12d %-12.2f\n",
           th.maThuoc, th.tenThuoc, th.soLuong, th.donGia);
}

void inTieuDe() {
    printf("%-10s %-25s %-12s %-12s\n",
           "Ma", "Ten thuoc", "So luong", "Don gia");

    printf("-----------------------------------------------------------\n");
}

void themThuoc() {
    int ma;

    if (soLuong >= MAX) {
        printf("Danh sach da day\n");
        return;
    }

    printf("Nhap ma thuoc: ");
    scanf("%d", &ma);

    if (ma <= 0) {
        printf("Ma thuoc khong hop le\n");
        return;
    }

    if (timTheoMa(ma) != -1) {
        printf("Ma thuoc da ton tai\n");
        return;
    }

    ds[soLuong].maThuoc = ma;

    getchar();
    nhapThongTin(&ds[soLuong]);

    soLuong++;

    printf("Them thuoc thanh cong\n");
}

void hienThiDanhSach() {
    int i;

    if (soLuong == 0) {
        printf("Danh sach rong\n");
        return;
    }

    inTieuDe();

    for (i = 0; i < soLuong; i++) {
        inMotLoaiThuoc(ds[i]);
    }
}

void capNhatThuoc() {
    int ma;
    int viTri;

    if (soLuong == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("Nhap ma thuoc can cap nhat: ");
    scanf("%d", &ma);

    viTri = timTheoMa(ma);

    if (viTri == -1) {
        printf("Khong tim thay thuoc\n");
        return;
    }

    getchar();
    nhapThongTin(&ds[viTri]);

    printf("Cap nhat thanh cong\n");
}

void xoaThuoc() {
    int ma;
    int viTri;
    int i;

    if (soLuong == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("Nhap ma thuoc can xoa: ");
    scanf("%d", &ma);

    viTri = timTheoMa(ma);

    if (viTri == -1) {
        printf("Khong tim thay thuoc\n");
        return;
    }

    for (i = viTri; i < soLuong - 1; i++) {
        ds[i] = ds[i + 1];
    }

    soLuong--;

    printf("Xoa thanh cong\n");
}

void timThuocTheoTen() {
    char tenCanTim[50];
    int i;
    int timThay = 0;

    printf("Nhap ten can tim: ");
    nhapTenThuoc(tenCanTim);

    for (i = 0; i < soLuong; i++) {
        if (strstr(ds[i].tenThuoc, tenCanTim) != NULL) {
            if (timThay == 0) {
                inTieuDe();
            }

            inMotLoaiThuoc(ds[i]);
            timThay = 1;
        }
    }

    if (timThay == 0) {
        printf("Khong tim thay thuoc\n");
    }
}

int main() {
    int chon;

    do {
        printf("\n===== QUAN LY THUOC =====\n");
        printf("1. Them thuoc\n");
        printf("2. Hien thi danh sach thuoc\n");
        printf("3. Cap nhat thuoc theo ma\n");
        printf("4. Xoa thuoc theo ma\n");
        printf("5. Tim thuoc theo ten\n");
        printf("6. Thong kw kho hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");

        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                themThuoc();
                break;

            case 2:
                hienThiDanhSach();
                break;

            case 3:
                capNhatThuoc();
                break;

            case 4:
                xoaThuoc();
                break;

            case 5:
                timThuocTheoTen();
                break;

            case 6:
                break;

            case 0:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le\n");
        }

    } while (chon != 0);

    return 0;
}
