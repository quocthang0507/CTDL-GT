//Họ và tên: La Quốc Thắng
//MSSV: 1610207

#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	int n = 0, menu, soMenu = 8;
	DaySo a;
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