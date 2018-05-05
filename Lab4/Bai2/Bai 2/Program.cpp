#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	LL l;
	BD g;
	TapTin_List_LL("LLSV.txt", l);
	TapTin_List_BD("DiemQT.txt", g);
	XuatBangDiem(l, g);
	_getch();
}