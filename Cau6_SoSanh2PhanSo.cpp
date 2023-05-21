#include <iostream>
#include<string>
using namespace std;

/*
Xây dựng lớp Phân số mô tả đối tượng Phân số gồm các thành phần:
	Các thành phần thuộc tính:
 a: mô tả phần tử số; b: mô tả phần mẫu số
	Các phương thức gồm:
- Phương thức nhập phân số.
- Phương thức hiển thị phân số (dạng a/b)
Viết chương trình thực hiện nhập vào một dãy số gồm n phân số và nhập thêm một phân số X hỏi xem phân số X có trong dãy phân số đã nhập hay không bằng cách xây dựng thêm hàm toán tử “==” để so sánh hai phân số.


*/
class PhanSo {
private:
	int tu;
	int mau;
public:
	PhanSo() : tu(0), mau(1) {}
	void nhap() {
		cout << "Nhap tu so: ";
		cin >> tu;
		do {
			cout << "Nhap mau so: ";
			cin >> mau;
			if (mau == 0) cout << "Mau so khong the bang 0" << endl;
		} while (mau == 0);

	}

	void hienThi() {
		cout << tu << "/" << mau;
	}

	bool soSanhBang(const PhanSo& other) const{
        return ((other.tu * mau) == (tu * other.mau));
	}
};

void XuatMangPhanSo(PhanSo ps[], int n) {
	for (int i = 0; i < n; i++) {
		ps[i].hienThi();
		cout << " ";
	}
	cout << "\n";
}



int main() {
	const int n = 5;
	PhanSo ps[n], X;
	for (int i = 0; i < n; i++) {
		ps[i].nhap();
	}
	cout << "Day phan so vua nhap la: ";
	XuatMangPhanSo(ps, n);

    cout << "\nNhap phan so X: \n";
    X.nhap();
    bool coKhong = false;
    for (int i = 0; i < n; i++) {
		if (ps[i].soSanhBang(X)){
            coKhong = true;
            break;
		}
	}
    if (coKhong){
        cout << "Day co phan so ";
        X.hienThi();
        cout << "\n";
    }
    else{
        cout << "Day khong co phan so ";
        X.hienThi();
        cout << "\n";
    }
	return 0;
}

