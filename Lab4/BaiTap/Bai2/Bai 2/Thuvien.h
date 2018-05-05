struct LLNV
{
	char maNV[8];
	char hoTen[15];
	char diaChi[15];
	int TDVH;
	long int luongCB;
	long int luongTL;
	long int luongPT;
};

struct CCNV
{
	char maNV[8];
	int nghiCP;
	int nghiKP;
	int lamThem;
};

struct tagNodeLL
{
	LLNV info;
	tagNodeLL *pNext;
};

struct tagNodeCC
{
	CCNV info;
	tagNodeCC *pNext;
};

typedef tagNodeLL NodeLL;
typedef tagNodeCC NodeCC;

struct LL
{
	NodeLL *pHead;
	NodeLL *pTail;
};

struct CC
{
	NodeCC *pHead;
	NodeCC *pTail;
};

NodeLL *GetNode_LL(LLNV x)
{
	NodeLL *p;
	p = new NodeLL;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

NodeCC *GetNode_CC(CCNV x)
{
	NodeCC *p;
	p = new NodeCC;
	if (p!=NULL)
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

void CreatList_CC(CC &l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail_LL(LL &l, LLNV x)
{
	NodeLL *new_ele = GetNode_LL(x);
	if (new_ele==NULL)
	{
		cout << "\nKhong du bo nho!\n";
		_getch();
		return;
	}
	if (l.pHead==NULL)
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

void InsertTail_CC(CC &l, CCNV x)
{
	NodeCC *new_ele = GetNode_CC(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho!\n";
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
	LLNV x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatList_LL(l);

	char maNV[8];
	char hoTen[15];
	char diaChi[15];
	int TDVH;
	long int luongCB;
	long int luongPT;

	in >> maNV; strcpy_s(x.maNV, maNV);
	in >> hoTen; strcpy_s(x.hoTen, hoTen);
	in >> diaChi; strcpy_s(x.diaChi, diaChi);
	in >> TDVH; x.TDVH = TDVH;
	in >> luongCB; x.luongCB = luongCB;

	luongPT = 0;
	if (TDVH == 5)
		luongPT = 10 * luongCB / 100;
	else if (TDVH == 6)
		luongPT = 20 * luongCB / 100;
	x.luongPT = luongPT;
	InsertTail_LL(l, x);
	x.luongTL = 0;

	while (!in.eof())
	{
		in >> maNV; strcpy_s(x.maNV, maNV);
		in >> hoTen; strcpy_s(x.hoTen, hoTen);
		in >> diaChi; strcpy_s(x.diaChi, diaChi);
		in >> TDVH; x.TDVH = TDVH;
		in >> luongCB; x.luongCB = luongCB;
		luongPT = 0;
		if (TDVH == 5)
			luongPT = 10 * luongCB / 100;
		else if (TDVH == 6)
			luongPT = 20 * luongCB / 100;
		x.luongPT = luongPT;
		x.luongTL = 0;
		InsertTail_LL(l, x);
	}
	in.close();

}

void TapTin_List_CC(char *filename, CC &l, LL y)
{
	CCNV x;
	NodeLL *t = y.pHead;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		_getch();
		return;
	}
	CreatList_CC(l);

	char maNV[8];
	int nghiCP;
	int nghiKP;
	int lamThem;

	in >> maNV; strcpy_s(x.maNV, maNV);
	in >> nghiCP; x.nghiCP = nghiCP;
	in >> nghiKP; x.nghiKP = nghiKP;
	in >> lamThem; x.lamThem = lamThem;

	if (_strcmpi(t->info.maNV, maNV) != 0)
	{
		cout << "\nLoi thu tu ma nhan vien dan den khong the doc file!\n";
		_getch();
		return;
	}
	InsertTail_CC(l, x);

	t->info.luongPT += lamThem * 4 * t->info.luongCB / 100;
	t->info.luongPT -= nghiKP * 4 * t->info.luongCB / 100;
	if (nghiCP >= 15)
		t->info.luongPT -= 10 * t->info.luongCB / 100;
	t->info.luongTL = t->info.luongCB + t->info.luongPT;
	t = t->pNext;
	while (!in.eof())
	{
		in >> maNV; strcpy_s(x.maNV, maNV);
		in >> nghiCP; x.nghiCP = nghiCP;
		in >> nghiKP; x.nghiKP = nghiKP;
		in >> lamThem; x.lamThem = lamThem;

		if (_strcmpi(t->info.maNV, maNV) != 0)
		{
			cout << "\nLoi thu tu ma nhan vien dan den khong the doc file!\n";
			_getch();
			return;
		}
		InsertTail_CC(l, x);

		t->info.luongPT += lamThem * 4 * t->info.luongCB / 100;
		t->info.luongPT -= nghiKP * 4 * t->info.luongCB / 100;
		if (nghiCP >= 15)
			t->info.luongPT -= 10 * t->info.luongCB / 100;
		t->info.luongTL = t->info.luongCB + t->info.luongPT;
		t = t->pNext;
	}
	in.close();
}

void Xuat_KeDon()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 60; i++)
		cout << '-';
	cout << ':';
}

void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 60; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << "Ma NV"
		<< ':'
		<< setw(19) << "Ho va ten"
		<< ':'
		<< setw(9) << "Luong CB"
		<< ':'
		<< setw(9) << "Phu troi"
		<< ':'
		<< setw(9) << "Luong TL"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_BangLuong(LL l, CC c)
{
	cout << "\nDANH SACH TIEN LUONG CUA CAC NHAN VIEN TRONG THANG\n";
	Xuat_TieuDe();
	NodeLL *p = l.pHead;
	NodeCC *q = c.pHead;
	int i = 0;
	while (p != NULL && q != NULL)
	{
		cout << endl << ':';
		cout << setiosflags(ios::left)
			<< ':'
			<< setw(9) << p->info.maNV
			<< ':'
			<< setw(19) << p->info.hoTen
			<< ':'
			<< setw(9) << setprecision(0) << setiosflags(ios::fixed) << p->info.luongCB
			<< ':'
			<< setw(9) << setprecision(0) << setiosflags(ios::fixed) << p->info.luongPT
			<< ':'
			<< setw(9) << setprecision(0) << setiosflags(ios::fixed) << p->info.luongTL
			<< ':';
		p = p->pNext;
		q = q->pNext;
		i++;
		if ((i + 1) % 5 == 0)
			Xuat_KeDon();
	}
	Xuat_KeDoi();
	cout << endl;
}

void SapXep(LL &l)
{
	NodeLL *min;
	NodeLL *p, *q;
	p = l.pHead;
	while (p != l.pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info.luongTL < min->info.luongTL)
				min = q;
			q = q->pNext;
		}
		swap(min->info, p->info);
		p = p->pNext;
	}
	for (p = l.pHead; p != l.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->info.luongTL == q->info.luongTL)
				if (_strcmpi(p->info.maNV, q->info.maNV)>0)
					swap(q->info, p->info);
}