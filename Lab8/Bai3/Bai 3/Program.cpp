#include <iostream>
#include <conio.h>
#include <string.h>
#include <stack>

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
	char bieuThuc[MAX];
	BSTree root;
	CreateBST(root);
	int kq;
	cout << "\nNhap bieu thuc so hoc don gian : ";
	_flushall();
	cin >> bieuThuc;
	root = EQN_to_BST(bieuThuc);
	cout << "\nBieu thuc tien to : ";
	PreOrder(root);
	_getch();
	cout << "\n\nBieu thuc trung to : ";
	InOrder(root);
	_getch();
	cout << "\n\nBieu thuc hau to : ";
	PosOrder(root);
	_getch();
	kq = evaluate_tree(root);
	cout << "\n\nGia tri cua bieu thuc tren la : " << kq;
	_getch();
}