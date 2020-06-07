#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <float.h>

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
	int menu, soMenu = 8;
	BSTree root;
	CreateBST(root);
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
	} while (menu > 0);
}