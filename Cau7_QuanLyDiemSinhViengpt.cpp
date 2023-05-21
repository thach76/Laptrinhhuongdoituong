#include <iostream>
#include <vector>
using namespace std;

class SinhVien {
public:
    string maSV;
    string tenSV;
    string tenLop;
    int khoa;
    vector<string> tenMonHoc;
    vector<int> soTrinh;
    vector<float> diem;

    void nhapThongTin() {
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, tenSV);
        cout << "Nhap ten lop: ";
        getline(cin, tenLop);
        cout << "Nhap khoa: ";
        cin >> khoa;

        int n;
        cout << "Nhap so mon hoc: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string tenMH;
            int trinh;
            float diemMH;

            cout << "Nhap ten mon hoc thu " << i + 1 << ": ";
            cin.ignore();
            getline(cin, tenMH);
            cout << "Nhap so trinh: ";
            cin >> trinh;
            cout << "Nhap diem: ";
            cin >> diemMH;

            tenMonHoc.push_back(tenMH);
            soTrinh.push_back(trinh);
            diem.push_back(diemMH);
        }
    }

    void inDanhSach() {
        cout << "Ma sinh vien: " << maSV << endl;
        cout << "Ten sinh vien: " << tenSV << endl;
        cout << "Lop: " << tenLop << endl;
        cout << "Khoa: " << khoa << endl;
        cout << "Bang diem:" << endl;
        cout << "Ten mon\tSo trinh\tDiem" << endl;


        float diemTrungBinh = 0;
        float tongDiem = 0;
        int tongTrinh = 0;

        for (int i = 0; i < tenMonHoc.size(); i++) {
            cout << tenMonHoc[i] << "\t" << soTrinh[i] << "\t\t" << diem[i] << endl;
            tongDiem += diem[i] * soTrinh[i];
            tongTrinh += soTrinh[i];
        }

        if (tongTrinh > 0) {
            diemTrungBinh = tongDiem / tongTrinh;
        }

        cout << "ÐTB: " << diemTrungBinh << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<SinhVien> danhSachSV;

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        SinhVien sv;
        sv.nhapThongTin();
        danhSachSV.push_back(sv);
    }

    cout << "Danh sach sinh vien vua nhap:" << endl;
    for (int i = 0; i < danhSachSV.size(); i++) {
        cout << "Phieu bao diem" << endl;
        danhSachSV[i].inDanhSach();
        cout << endl;
    }

    return 0;
}
