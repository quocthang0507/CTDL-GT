#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>

using namespace std;

#include "KetQuaTranDau.h"
#include "KetQuaCacDoi.h"
#include "XepHang.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int menu,
		soMenu = 7;
	KetQuaTranDau a[MAX];
	int st = 1;
	TaoBang_KQTD(a, st); //nap du lieu ket qua thi dau
	KQXepHang kq[MAX];
	int sd = 1;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, kq, sd, a, st);
	} while (menu > 0);
}