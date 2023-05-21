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
Viết chương trình thực hiện việc nhập vào một dãy phân số. Xây dựng hàm rút ngọn phân số. Hiển thị dãy phân số đã nhập dưới dạng rút ngọn.

*/

int ucln(int a, int b){
    while (a*b != 0){
        if (a > b){
            a %= b; // a = a % b
        }else{
            b %= a;
        }
    }
    return a + b; // return a + b, bởi vì lúc này hoặc a hoặc b đã bằng 0.
}

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

	void rutGonPhanSo(){
	    int UCLN = ucln(tu ,mau);
	    tu /= UCLN;
	    mau /= UCLN;
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

	for (int i = 0; i < n; i++) {
		ps[i].rutGonPhanSo();
	}

	cout << "Day phan so da rut gon la: ";
	XuatMangPhanSo(ps, n);

	return 0;
}
