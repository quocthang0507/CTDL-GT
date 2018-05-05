#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

#include "01_Header_KQTD.h"
#include "02_ThuVien_KQTD.h"
#include "03_Header_KQDB.h"
#include "04_XepHang.h"
#include "06_ThuVien_KQDB.h"
#include "05_Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int soMenu = 12, menu;
	LIST_KQTD td;
	TapTin_List_KQTD(td);
	LIST_KQXH xh;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, xh, td);
	} while (menu > 0);
}