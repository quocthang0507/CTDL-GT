//Họ và tên: La Quốc Thắng
//MSSV: 1610207
//Email: quocthang0507@gmail.com

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

#include "Thuvien.h""

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	char filename[80];
	NHANVIEN ds[MAX];
	int n;
	system("cls");
	cout << "Nhap ten file mo de doc : ";
	cin >> filename;
	Read_struct(filename, ds, n);
	xuat(ds, n);
	system("PAUSE");
}