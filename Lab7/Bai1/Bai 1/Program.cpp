#include <iostream>
#include <fstream>
#include <conio.h>
#include <math.h>

using namespace std;

#include "Header.h"
#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	int soMenu = MAX_MENU, menu;
	LLIST l;
	char filename[MAX];
	do
	{
		system("cls");
		cout << "\nNhap ten tap tin, filename = ";
		_flushall();
		cin >> filename;
		if (!File_LLIST(filename,l))
		{
			cout << "\nLoi mo file! Nhap lai...\n";
			_getch();
		}
		else
		{
			cout << "\nDu lieu tap tin " << filename << " da duoc chuyen vao DSLK don vong l";
			cout << "\nNhap phim bat ky de tiep tuc!";
			_getch();
			break;
		}
	} while (true);
	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
	} while (menu>0);
}

int main()
{
	ChayChuongTrinh();
	return 1;
}