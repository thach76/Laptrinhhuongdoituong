#include <iostream>
#include<string>
using namespace std;
//Câu2
//Xây dựng lớp Phân số mô tả đối tượng Phân số gồm các thành phần :
//	Các thành phần thuộc tính :
//a: mô tả phần tử số; b: mô tả phần mẫu số
//	Các phương thức gồm :
//-Phương thức nhập phân số.
//- Phương thức hiển thị phân số(dạng a / b)
//
//Viết chương trình thực hiện việc nhập vào một một dãy
//gồm n phân số và thực hiện việc sắp xếp mảng phân số đã
//nhập theo chiều tăng dần bằng cách sử dụng hàm toán tử < (operator<)
//dùng để so sánh hai phân số.

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

	bool operator<(const PhanSo& other) const {
		//trả về true nếu class này nhỏ hơn other
		return (tu * other.mau < other.tu * mau);
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
	PhanSo ps[n];

	for (int i = 0; i < n; i++) {
		ps[i].nhap();
	}
	cout << "Day phan so vua nhap la: ";
	XuatMangPhanSo(ps, n);
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (!ps[min].operator<(ps[j])) {
				min = j;
			}
		}
		if (min != i) {
			swap(ps[min], ps[i]);
		}
	}
	cout << "Day phan so da sap xep la: ";
	XuatMangPhanSo(ps, n);


	return 0;
}
