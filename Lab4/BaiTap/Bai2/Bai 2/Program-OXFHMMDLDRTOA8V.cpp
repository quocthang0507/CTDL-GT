#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	LL l;
	CC c;
	TapTin_List_LL("LLNV.txt", l);
	TapTin_List_CC("ChamCong.txt", c, l);
	Xuat_BangLuong(l, c);
	cout << "\nNhan phim bat ky de tiep tuc...";
	_getch();
	SapXep(l);
	Xuat_BangLuong(l, c);
	_getch();
}

int main()
{
	ChayChuongTrinh();
	return 1;
}