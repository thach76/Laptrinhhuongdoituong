#include <iostream>
#include <cstring>
using namespace std;

class NGUOI {
protected:
    char Hoten[50];
    char Ngaysinh[12];
    char Quequan[100];
public:
    NGUOI() {
        strcpy(Hoten, "");
        strcpy(Ngaysinh, "");
        strcpy(Quequan, "");
    }

    void nhapThongTin() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        cin.getline(Hoten, 50);
        cout << "Nhap ngay sinh: ";
        cin.getline(Ngaysinh, 12);
        cout << "Nhap que quan: ";
        cin.getline(Quequan, 100);
    }

    void xuatThongTin() {
        cout << "Ho ten: " << Hoten << endl;
        cout << "Ngay sinh: " << Ngaysinh << endl;
        cout << "Que quan: " << Quequan << endl;
    }
};

class DIEM {
protected:
    int Diemtoan;
    int Diemly;
    int Diemhoa;
public:
    DIEM() {
        Diemtoan = 0;
        Diemly = 0;
        Diemhoa = 0;
    }

    void nhapDiem() {
        cout << "Nhap diem Toan: ";
        cin >> Diemtoan;
        cout << "Nhap diem Ly: ";
        cin >> Diemly;
        cout << "Nhap diem Hoa: ";
        cin >> Diemhoa;
    }

    void xuatDiem() {
        cout << "Diem Toan: " << Diemtoan << endl;
        cout << "Diem Ly: " << Diemly << endl;
        cout << "Diem Hoa: " << Diemhoa << endl;
    }
};

class THISINH : public NGUOI, public DIEM {
private:
    char SBD[30];
    int Tongdiem;
public:
    THISINH() {
        strcpy(SBD, "");
        Tongdiem = 0;
    }

    void nhapThongTin() {
        NGUOI::nhapThongTin();
        DIEM::nhapDiem();
        cout << "Nhap so bao danh: ";
        cin.ignore();
        cin.getline(SBD, 30);
        cout << "Nhap tong diem: ";
        cin >> Tongdiem;
    }

    void xuatThongTin() {
        NGUOI::xuatThongTin();
        DIEM::xuatDiem();
        cout << "So bao danh: " << SBD << endl;
        cout << "Tong diem: " << Tongdiem << endl;
    }
};

int main() {
    THISINH ts;
    cout << "Nhap thong tin thi sinh:" << endl;
    ts.nhapThongTin();

    cout << "Thong tin thi sinh:" << endl;
    ts.xuatThongTin();

    return 0;
}

