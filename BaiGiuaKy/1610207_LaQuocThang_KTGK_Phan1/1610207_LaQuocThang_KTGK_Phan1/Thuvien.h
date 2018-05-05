struct NgaySinh
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
};

struct SinhVien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char tenSV[10];
	NgaySinh ntns;
	char lop[8];
	double diemTK;
};

typedef SinhVien data;

struct tagNode
{
	data info;
	tagNode *pNext;
};

typedef tagNode Node;

struct LIST
{
	Node *pHead;
	Node *pTail;
};

void CreatLIST(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

Node *GetNode(data x)
{
	Node *p;
	p = new Node;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void Xuat_KeDon()
{
	cout << endl << ':';
	for (int i = 1; i <= 74; i++)
		cout << '-';
	cout << ':';
}

void Xuat_KeDoi()
{
	cout << endl << ':';
	for (int i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(11) << "Ma SV"
		<< ':'
		<< setw(11) << "Ho"
		<< ':'
		<< setw(11) << "Ten lot"
		<< ':'
		<< setw(11) << "Ten"
		<< ':'
		<< setw(3) << "NS"
		<< setw(3) << "TS"
		<< setw(5) << "NaS"
		<< ':'
		<< setw(8) << "Lop"
		<< ':'
		<< setw(5) << "DTK"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_SV(data x)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(11) << x.maSV
		<< ':'
		<< setw(11) << x.hoSV
		<< ':'
		<< setw(11) << x.tenLot
		<< ':'
		<< setw(11) << x.tenSV
		<< ':'
		<< setw(3) << x.ntns.ngay
		<< setw(3) << x.ntns.thang
		<< setw(5) << x.ntns.nam
		<< ':'
		<< setw(8) << x.lop
		<< ':'
		<< setw(5) << setiosflags(ios::fixed) << setprecision(1) << x.diemTK
		<< ':';
}

void Xuat_DS(LIST l)
{
	int i;
	Node *p = l.pHead;
	Xuat_TieuDe();
	for (i = 0; p != NULL; i++, p = p->pNext)
	{
		Xuat_SV(p->info);
		if ((i + 1) % 5 == 0)
			Xuat_KeDon();
	}
	Xuat_KeDoi();
	cout << "\n\nDanh sach tong cong co " << i << " sinh vien";
}

void AddHead(LIST &l, data x)
{
	Node *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(LIST &l, data x)
{
	Node *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
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

data RemoveTail(LIST &l)
{
	data x = l.pTail->info;
	Node *p = l.pHead, *q = NULL;
	do
	{
		q = p;
		p = p->pNext;
	} while (p != l.pTail);
	l.pTail = q;
	delete p;
	if (l.pTail == NULL)
		l.pHead = NULL;
	else
		l.pTail->pNext = NULL;
	return x;
}

void DocFile(char *filename, LIST &l)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	data x;
	in >> x.maSV;
	in >> x.hoSV;
	in >> x.tenLot;
	in >> x.tenSV;
	in >> x.ntns.ngay;
	in >> x.ntns.thang;
	in >> x.ntns.nam;
	in >> x.lop;
	in >> x.diemTK;
	AddTail(l, x);
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.hoSV;
		in >> x.tenLot;
		in >> x.tenSV;
		in >> x.ntns.ngay;
		in >> x.ntns.thang;
		in >> x.ntns.nam;
		in >> x.lop;
		in >> x.diemTK;
		AddTail(l, x);
	}
	in.close();
}

int Tim_MSSV_Doi_Ten(LIST &l, char maSV[11])
{
	int kq = -1;
	char ten[10];
	Node *p = l.pHead;
	for (int i = 0; p != NULL; p = p->pNext, i++)
		if (_strcmpi(maSV, p->info.maSV) == 0)
		{
			kq = i;
			break;
		}
	if (kq == -1)
	{
		cout << "\nKhong tim thay sinh vien co ma sinh vien la " << maSV << " trong danh sach";
		return 0;
	}
	else
	{
		for (p = l.pHead; p != NULL; p = p->pNext)
			if (_strcmpi(maSV, p->info.maSV) == 0)
			{
				cout << "\nTen hien tai : " << p->info.tenSV;
				cout << "\nNhap ten can doi : ";
				_flushall();
				gets_s(ten, 10);
				strcpy_s(p->info.tenSV, ten);
				break;
			}
		return 1;
	}
}

void Remove_Node_After_q(LIST &l, Node *q)
{
	Node *p;
	if (l.pHead == NULL)
	{
		cout << "\nDanh sach rong!";
		return;
	}
	if (q != NULL)
	{
		p = q->pNext;
		if (p == q)
			l.pHead = l.pTail = NULL;
		else
		{
			q->pNext = p->pNext;
			if (p == l.pTail)
				l.pTail = q;
		}
		delete p;
	}
}

double Tim_DiemThap(LIST &l)
{
	Node *p = l.pHead;
	double min = p->info.diemTK;
	for (p = p->pNext; p != NULL; p = p->pNext)
		if (min > p->info.diemTK)
			min = p->info.diemTK;
	return min;
}

int Remove_Node_DiemTK(LIST &l, double diem)
{
	int kq = 0;
	Node *p = l.pHead, *q;
	for (; p != NULL; p = p->pNext)
		if (diem == p->info.diemTK)
			kq = 1;
	if (kq == 1)
	{
		p = l.pHead;
		do
		{
			q = p;
			p = p->pNext;
		} while (p->info.diemTK != diem);
		Remove_Node_After_q(l, q);
		return 1;
	}
	else
		return 0;
}

void Xoa_SV_DiemThap(LIST &l)
{
	int kq;
	double diemThap = Tim_DiemThap(l);
	do
	{
		kq = Remove_Node_DiemTK(l, diemThap);
	} while (kq != 0);
}