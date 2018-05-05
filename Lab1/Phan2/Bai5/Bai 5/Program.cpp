#include <iostream>
#include <fstream>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int n;
	MaTran a;
	char filename_read[MAX], filename_write[MAX];
	system("cls");
	cout << "Nhap ten file de doc : ";
	cin >> filename_read;
	Read(filename_read, a, n);
	Display(filename_read);
	cout << "\nNhap ten file can ghi : ";
	cin >> filename_write;
	Write(filename_write, a, n);
	cout << "\nNoi dung file " << filename_write << " : ";
	Display(filename_write);
	system("pause");
}