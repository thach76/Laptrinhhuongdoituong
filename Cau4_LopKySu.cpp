#include <iostream>
#include<string>
using namespace std;


class Person {
private:
	string hoTen;
	string ngaySinh;
	string queQuan;
public:
	Person() {

	}
	Person(string hoTen, string ngaySinh, string queQuan) {
		this->hoTen = hoTen;
		this->ngaySinh = ngaySinh;
		this->queQuan = queQuan;
	}

	void nhap() {
		cout << "Nhap ho va ten: ";
		//cin.ignore(32767, '\n');
		getline(cin, hoTen);
		cout << "Nhap ngay sinh: ";
		//cin.ignore(32767, '\n');
		getline(cin, ngaySinh);
		cout << "Nhap que quan: ";
		//
		getline(cin, queQuan);
		//cin.ignore(32767, '\n');
	}

	void in() {
		cout << "Ho va ten: " << hoTen << endl;
		cout << "Ngay sinh: " << ngaySinh << endl;
		cout << "Que quan: " << queQuan << endl;
	}
};

class KySu : public Person{
private:
	string nganhHoc;
	int namTotNghiep;
public:
	KySu() {
		namTotNghiep = 0;
	}
	KySu(string hoTen, string ngaySinh, string queQuan, string nganhHoc, int namTotNghiep) : Person(hoTen, ngaySinh, queQuan) {
		this->nganhHoc = nganhHoc;
		this->namTotNghiep = namTotNghiep;
	}
	void nhap() {
		Person::nhap();
		cout << "Nhap nganh hoc: ";
		getline(cin, nganhHoc);
		cout << "Nhap nam tot nghiep: ";
		cin >> namTotNghiep;
		cin.ignore(32767, '\n');
	}

	void in() {
		Person::in();
		cout << "Nganh hoc: " << nganhHoc << endl;
		cout << "Nam tot nghiep: " << namTotNghiep << endl;
	}

	int getNamTotNghiep() {
		return namTotNghiep;
	}
};

int main() {
	//KySu ks("thach", "03/07/2003", "quang ninh", "CNTT", 2024);
	//ks.nhap();

	KySu ks[10];
	int n = 3;
	for (int i = 0; i < n; i++) {
		cout << "Ky su " << i << endl;
		ks[i].nhap();
	}
	int min = 0;
	cout << "\n\nDanh sach cac ky su: \n";
	for (int i = 0; i < n; i++) {
		cout << "Ky su " << i << endl;
		ks[i].in();
		if (ks[min].getNamTotNghiep() > ks[i].getNamTotNghiep()) {
			min = i;
		}
		cout <<  endl;
	}
	cout << "Ky su tot nghiep khoa dau tien: \n";
	ks[min].in();
	return 0;
}
