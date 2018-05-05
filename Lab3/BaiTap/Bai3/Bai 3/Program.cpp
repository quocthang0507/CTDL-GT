//Họ và tên: La Quốc Thắng
//MSSV: 1610207

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	NhanVien a[MAX];
	int menu, soMenu = 6, n = 0;
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