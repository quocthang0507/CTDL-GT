#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#include "Header.h"
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
	int menu, soMenu = 13;
	BSTree root = NULL;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
	} while (menu>0);
}