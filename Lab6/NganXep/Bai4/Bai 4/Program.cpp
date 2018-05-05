//MSSV: 1610207
//Ho va ten: La Quoc Thang

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	char Chuoi_Nhap[MAX];
	char Chuoi_KQ[MAX];
	cout << "\nNhap bieu thuc trung to : ";
	_flushall();
	gets_s(Chuoi_Nhap, MAX);
	TrungTo_HauTo(Chuoi_Nhap, Chuoi_KQ);
	cout << "\nBieu thuc hau to : ";
	cout << Chuoi_KQ;
}

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}