//Họ và tên: La Quốc Thắng
//MSSV: 1610207

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	int menu, n = 0, soMenu = 5;
	SinhVien a[MAX];
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