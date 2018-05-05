//MSSV: 1610207
//Họ và tên: La Quốc Thắng

#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string.h>

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
	int menu, soMenu = 5;
	LIST CTDL;
	CreatLIST(CTDL);
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, CTDL);
	} while (menu > 0);
}