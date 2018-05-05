#include <iostream>
#include <conio.h>
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
	int soMenu = 10, menu;
	List m, n;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, m, n);
	} while (menu>0);
}