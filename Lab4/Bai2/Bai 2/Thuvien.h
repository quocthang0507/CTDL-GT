#define MAX 100

struct LLSinhVien
{
	char maSV[8];
	char ho[15];
	char ten[10];
	int namSinh;
	char nguyenQuan[15];
};

struct tagNodeLL
{
	LLSinhVien info;
	tagNodeLL *pNext;
};

typedef tagNodeLL NODELL;

struct  LL
{
	NODELL *pHead;
	NODELL *pTail;
};

struct DiemTP
{
	char maSV[8];
	double dBT1;
	double dBT2;
	double dGK;
	double dQT;
};

struct  tagNodeDiem
{
	DiemTP info;
	tagNodeDiem *pNext;
};

typedef tagNodeDiem NODEBD;

struct BD
{
	NODEBD *pHead;
	NODEBD *pTail;
};

NODELL* GetNode_LL(LLSinhVien x);
void CreatList_LL(LL &l);
void InsertTail_LL(LL &l, LLSinhVien x);
void TapTin_List_LL(char *filename, LL &l);
void TapTin_List_BD(char *filename, BD &l);
void InsertTail_BD(BD &l, DiemTP x);
void CreatList_BD(BD &l);
NODEBD* GetNode_BD(DiemTP x);
void XuatBangDiem(LL l, BD g);
void TieuDe();

NODELL *GetNode_LL(LLSinhVien x)
{
	NODELL *p;
	p = new NODELL;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_LL(LL &l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail_LL(LL &l, LLSinhVien x)
{
	NODELL *new_ele = GetNode_LL(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho!";
		_getch();
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

void TapTin_List_LL(char *filename, LL &l)
{
	LLSinhVien x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatList_LL(l);
	char maSV[8];
	char ho[15];
	char ten[10];
	int namSinh;
	char nguyenQuan[15];

	in >> maSV; strcpy_s(x.maSV, 8, maSV);
	in >> ho; strcpy_s(x.ho, 15, ho);
	in >> ten; strcpy_s(x.ten, 10, ten);
	in >> namSinh; x.namSinh = namSinh;
	in >> nguyenQuan; strcpy_s(x.nguyenQuan, 15, nguyenQuan);
	InsertTail_LL(l, x);

	while (!in.eof())
	{
		in >> maSV; strcpy_s(x.maSV, 8, maSV);
		in >> ho; strcpy_s(x.ho, 15, ho);
		in >> ten; strcpy_s(x.ten, 10, ten);
		in >> namSinh; x.namSinh = namSinh;
		in >> nguyenQuan; strcpy_s(x.nguyenQuan, 15, nguyenQuan);
		InsertTail_LL(l, x);
	}
	in.close();
}

NODEBD *GetNode_BD(DiemTP x)
{
	NODEBD *p;
	p = new NODEBD;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_BD(BD &l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail_BD(BD &l, DiemTP x)
{
	NODEBD *new_ele = GetNode_BD(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho!";
		_getch();
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

void TapTin_List_BD(char *filename, BD &l)
{
	DiemTP x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatList_BD(l);
	char maSV[8];
	double dBT1;
	double dBT2;
	double dGK;
	double dQT;

	in >> maSV; strcpy_s(x.maSV, maSV);
	in >> dBT1; x.dBT1 = dBT1;
	in >> dBT2; x.dBT2 = dBT2;
	in >> dGK; x.dGK = dGK;
	dQT = dBT1 + dBT2 + dGK;
	x.dQT = dQT;

	InsertTail_BD(l, x);

	while (!in.eof())
	{
		in >> maSV; strcpy_s(x.maSV, maSV);
		in >> dBT1; x.dBT1 = dBT1;
		in >> dBT2; x.dBT2 = dBT2;
		in >> dGK; x.dGK = dGK;
		dQT = dBT1 + dBT2 + dGK;
		x.dQT = dQT;
		InsertTail_BD(l, x);
	}
	in.close();
}

void TieuDe()
{
	int i;
	cout << endl;
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':' << endl;
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(10) << "Ma SV"
		<< ':'
		<< setw(16) << "Ho"
		<< setw(11) << "Ten"
		<< ':'
		<< setw(6) << "NSinh"
		<< ':'
		<< setw(8) << "DiemGK"
		<< ':';
	cout << endl;
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':';
}

void XuatBangDiem(LL l, BD g)
{
	TieuDe();
	NODELL *p = l.pHead;
	NODEBD *q = g.pHead;
	while (p != NULL && q != NULL)
	{
		cout << endl << ':'
			<< setiosflags(ios::left)
			<< setw(10) << p->info.maSV
			<< ':'
			<< setw(16) << p->info.ho
			<< setw(11) << p->info.ten
			<< ':'
			<< setw(6) << p->info.namSinh
			<< ':'
			<< setw(8) << setprecision(2) << setiosflags(ios::fixed) << q->info.dQT
			<< ':';
		p = p->pNext;
		q = q->pNext;
	}
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 54; i++)
		cout << '=';
	cout << ':' << endl;
}