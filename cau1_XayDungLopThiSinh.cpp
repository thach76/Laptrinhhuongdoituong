#include <iostream>
#include<string>
using namespace std;

//Câu 1
//Xây dựng lớp Thí sinh(TS) gồm:
//Thành phần thuộc tính : họ tên(con trỏ); td(tổng điểm).
//Phương thức : nhập, in, lấy tổng điểm, …
//Nhập một danh sách thí sinh, sắp xếp danh sách theo thứ tự tăng dần của tổng điểm.
//Sử dụng :
//+Dùng mảng đối tượng thí sinh(TS)
//+ Các hàm tạo, hàm huỷ thí sinh.

class ThiSinh {
private:
	string *hoTen;//họ tên
	float td = 0;//tổng điểm
public:
	ThiSinh() {
        this->hoTen = new string;
        this->td = 0;
	}

	ThiSinh(string hoTen, float td) {
		this->hoTen = new string(hoTen);
		this->td = td;
	}

	~ThiSinh() {
		//delete hoTen;
	}
	void nhap() {
		cout << "nhap ho va ten: ";
		cin.ignore(32767, '\n');
		getline(cin, *hoTen);
		cout << "nhap tong diem: ";
		cin >> td;
	}

	void in() {
		cout << "ho ten: " << *hoTen << endl;
		cout << "tong diem: " << td << endl;
	}

	float layTongDiem() {
		return td;
	}
};

void sapXepTang(ThiSinh ts[], int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (ts[min].layTongDiem() > ts[j].layTongDiem()) {
				min = j;
			}
		}
		if (min != i) {
			swap(ts[min], ts[i]);
		}
	}
}

void Nhap(ThiSinh ts[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "thi sinh " << i << " :" << endl;
		ts[i].nhap();
		cout << endl;
	}
}

void Xuat(ThiSinh ts[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "thi sinh " << i << " :" << endl;
		ts[i].in();
		cout  << endl;
	}
}

int main() {
	ThiSinh ts[100];
	int n = 0;

	cout << "nhap so luong thi sinh: ";
	cin >> n;

	Nhap(ts, n);
	cout << endl;
	cout << "Chua sap xep: " << endl;
	Xuat(ts, n);

	sapXepTang(ts, n);
	cout << endl;
	cout << "Da sap xep: " << endl;
	Xuat(ts, n);

	return 0;
}
