//MSSV: 1610207
//Ho va ten: La Quoc Thang

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	Queue q;
	CreatQueue(q);
	int m;
	char filename[100];
	TapTin_Queue("Test.txt", q);
	cout << "\nNhap vao so ngay truc : ";
	cin >> m;
	cout << "\nDanh sach ban dau : \n\n";
	XuatQueue(q);
	Sap_Tang_TTTruc(q);
	cout << "\nDanh sach sau khi sap xep : \n\n";
	XuatQueue(q);
	cout << "\nLich truc : \n";
	XuatLichTruc(q, m);
}

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}