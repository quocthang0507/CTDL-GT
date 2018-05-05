struct KetQuaTranDau
{
	int vong;
	char ngay[9];
	char gio[6];
	char cNha[15];
	int bTChu;
	int bTKhach;
	char khach[15];
};

typedef KetQuaTranDau data1;

struct tagNODE1
{
	data1 kqtd;
	tagNODE1 *pNext;
};

typedef tagNODE1 NODE1;

struct LIST_KQTD
{
	NODE1 *pHead;
	NODE1 *pTail;
};

NODE1* GetNODE1(data1 x)
{
	NODE1 *p;
	p = new NODE1;
	if (p != NULL)
	{
		p->kqtd = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_KQTD(LIST_KQTD &l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail1(LIST_KQTD &l, data1 x)
{
	NODE1* new_ele = GetNODE1(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		_getch();
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

void TapTin_List_KQTD(LIST_KQTD &l)
{
	ifstream in("KQTD.txt");
	if (!in)
	{
		cout << "\nLoi mo file !\n";
		_getch();
		return;
	}
	CreatList_KQTD(l);
	int vong;
	char ngay[9];
	char gio[6];
	char cNha[15];
	int bTChu;
	int bTKhach;
	char khach[15];
	data1 x;
	in >> vong; x.vong = vong;
	in >> ngay; strcpy_s(x.ngay, 9, ngay);
	in >> gio; strcpy_s(x.gio, 6, gio);
	in >> cNha; strcpy_s(x.cNha, 15, cNha);
	in >> bTChu; x.bTChu = bTChu;
	in >> bTKhach; x.bTKhach = bTKhach;
	in >> khach; strcpy_s(x.khach, 15, khach);
	InsertTail1(l, x);
	while (!in.eof())
	{
		in >> vong; x.vong = vong;
		in >> ngay; strcpy_s(x.ngay, 9, ngay);
		in >> gio; strcpy_s(x.gio, 6, gio);
		in >> cNha; strcpy_s(x.cNha, 15, cNha);
		in >> bTChu; x.bTChu = bTChu;
		in >> bTKhach; x.bTKhach = bTKhach;
		in >> khach; strcpy_s(x.khach, 15, khach);
		InsertTail1(l, x);
	}
	in.close();
}