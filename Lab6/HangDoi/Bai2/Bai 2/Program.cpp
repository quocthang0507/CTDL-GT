#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;

#include "Thuvien.h"

void ChayChuongTrinh()
{
	char a[MAX];
	File_String("Text.txt", a);
	XuLy_ThaoTac(a);
}

int main()
{
	ChayChuongTrinh();
	_getch();
	return 1;
}