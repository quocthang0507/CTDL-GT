//MSSV: 1610207
//Ho va ten: La Quoc Thang

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	char filename[MAX];
	Queue q;
	CreatQueue(q);
	cout << "\nNhap ten tap tin can mo : ";
	cin >> filename;
	TapTin_Queue(filename, q);
	cout << "\nDanh sach ban dau : \n";
	XuatQueue(q);
	Radix(q);
	cout << "\nDanh sach sau khi sap xep : \n";
	XuatQueue(q);
}

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}