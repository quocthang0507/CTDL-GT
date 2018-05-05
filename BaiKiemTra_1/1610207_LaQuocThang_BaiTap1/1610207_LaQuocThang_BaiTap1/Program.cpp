//Họ và tên: LA QUỐC THẮNG
//MSSV: 1610207

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	int soMenu = 10, n = 0, menu;
	NhanVien a[MAX];
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu>0);
}

int main()
{
	ChayChuongTrinh();
	return 1;
}