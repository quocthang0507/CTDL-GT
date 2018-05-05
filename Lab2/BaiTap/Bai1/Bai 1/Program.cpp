#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <fstream>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	NhanVien a[MAX];
	int soMenu = 8, n = 0, menu;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu>0);
}