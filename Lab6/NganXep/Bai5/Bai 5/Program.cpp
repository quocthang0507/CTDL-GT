//MSSV: 1610207
//Ho va ten: La Quoc Thang

#include <iostream>
#include <conio.h>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	char Chuoi_Nhap[MAX];
	int kq;
	cout << "\nNhap vao bieu thuc hau to : ";
	gets_s(Chuoi_Nhap);
	kq = Tinh_BT_HauTo(Chuoi_Nhap);
	cout << "\nKet qua cua bieu thuc hau to o tren la : " << kq;
}

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}