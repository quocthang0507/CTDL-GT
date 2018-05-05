//Họ và tên: La Quốc Thắng
//MSSV: 1610207
//Email: quocthang0507@gmail.com 

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
	Chuoi s, t;
	int soMenu = 8, menu;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, s, t);
	} while (menu > 0);
}

int main()
{
	ChayChuongTrinh();
	return 1;
}