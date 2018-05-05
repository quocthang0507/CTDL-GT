//MSSV: 1610207
//Ho va ten: La Quoc Thang

#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	LIST l;
	int soMenu = 18, menu;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
	} while (menu>0);
}

int main()
{
	ChayChuongTrinh();
	return 1;
}