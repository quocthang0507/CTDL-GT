#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <fstream>

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
	int soMenu = 8, menu;
	BSTree root;
	CreateBSTree(root);
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
	} while (menu > 0);
}