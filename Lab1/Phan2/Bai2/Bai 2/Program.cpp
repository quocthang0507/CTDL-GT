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
	int n, a[MAX];
	char filename_read[MAX];
	char filename_write[MAX];
	system("cls");
	cout << "\nNhap ten file can doc : ";
	cin >> filename_read;
	File_Display1(a, filename_read, n);
	cout << "\nNhap ten file can ghi : ";
	cin >> filename_write;
	Write_Int(a, n, filename_write);
	cout << "\nDu lieu file da tao : ";
	File_Display1(a, filename_write, n);
	system("pause");
}