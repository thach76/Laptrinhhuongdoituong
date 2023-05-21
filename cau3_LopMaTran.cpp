#include <iostream>
#include<string>
using namespace std;

class MaTran {
private:
	int N; //số hàng, số cột
	int A[20][20]; //lưu trữ thành phần dữ liệu của ma trận
public:
	MaTran(int n){
		N = n;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				A[i][j] = 0;
			}
		}
	}

	MaTran congMaTran(MaTran matran) {
		MaTran tong(N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				tong.A[i][j] = A[i][j] + matran.A[i][j];
			}
		}
		return tong;
	}

	friend void nhapMaTran(MaTran &matran);
	friend void inMaTran(MaTran matran);
};

//nhập ma trận
void nhapMaTran(MaTran &matran) {
	//int value;
	for (int i = 0; i < matran.N; i++)
	{
		for (int j = 0; j < matran.N; j++)
		{
			cout << "nhap so thu [" << i << "][" << j << "] : ";
			cin >> matran.A[i][j];
		}
	}
}

void inMaTran(MaTran matran){
	for (int i = 0; i < matran.N; i++)
	{
		for (int j = 0; j < matran.N; j++)
		{
			printf("%-5d", matran.A[i][j]);
		}
		cout << "\n";
	}
}

int main() {
	int N = 3;
	MaTran mt1(N), mt2(N), tong(N);
	cout << "Nhap ma tran 1\n";
	nhapMaTran(mt1);
	inMaTran(mt1);
	cout << "Nhap ma tran 2\n";
	nhapMaTran(mt2);
	inMaTran(mt2);
	tong = mt1.congMaTran(mt2);
	cout << "Tong mt1 + mt2\n";
	inMaTran(tong);
	return 0;
}

