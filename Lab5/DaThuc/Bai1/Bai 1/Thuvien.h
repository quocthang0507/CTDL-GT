struct Poly
{
	double coef;
	int expo;
};

typedef Poly Data;

struct tagNode
{
	Data info;
	tagNode *pNext;
};

typedef tagNode Node;

struct Polynome
{
	Node *pHead;
	Node *pTail;
};

void CreatPoly(Polynome &a)
{
	a.pHead = a.pTail = NULL;
}

Node *GetNode(Data x)
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

void InsertTail(Polynome &a, Data x)
{
	Node *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (a.pHead == NULL)
	{
		a.pHead = new_ele;
		a.pTail = a.pHead;
	}
	else
	{
		a.pTail->pNext = new_ele;
		a.pTail = new_ele;
	}
}

void Doc_File(char *filename, Polynome &a)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		return;
	}
	CreatPoly(a);
	Data x;
	in >> x.coef;
	in >> x.expo;
	InsertTail(a, x);
	while (!in.eof())
	{
		in >> x.coef;
		in >> x.expo;
		InsertTail(a, x);
	}
	in.close();
}

int IsEmpty(Polynome a)
{
	if (a.pHead == NULL)
		return 1;
	return 0;
}

void Xuat_DT(Polynome a)
{
	Node *p;
	if (IsEmpty(a))
	{
		cout << "\nDanh sach rong!\n";
		return;
	}
	p = a.pHead;
	if (p->info.coef == -1) cout << "- 1";
	else if (p->info.coef < -1) cout << "- ";
	while (p != NULL)
	{
		//Xu ly he so
		if (p->info.coef < -1)
			cout << -p->info.coef;
		else if (p->info.coef == -1 || p->info.coef == 1)
			cout << "";
		else cout << p->info.coef;
		//Xu ly so mu
		if (p->info.expo == 1)
			cout << 'x';
		else if (p->info.expo == 0)
			cout << "";
		else cout << "x^" << p->info.expo;
		p = p->pNext;
		if (p != NULL)
		{
			if (p->info.coef < 0)
				cout << " - ";
			else cout << " + ";
		}
	}
}

void RutGon_DT(Polynome &a)
{
	if (a.pHead == NULL)
	{
		cout << "\nDa thuc rong!\n";
		_getch();
		return;
	}
	int kq;
	Polynome b;
	Node *pB, *pA;
	pA = a.pHead;
	CreatPoly(b);
	while (pA!=NULL)
	{
		kq = 0;
		pB = b.pHead;
		while (pB!=NULL)
		{
			if (pB->info.expo==pA->info.expo)
			{
				kq = 1;
				break;
			}
			pB = pB->pNext;
		}
		if (kq == 1)
			pB->info.coef += pA->info.coef;
		else InsertTail(b, pA->info);
		pA = pA->pNext;
	}
	a = b;
}

void SapXep_DT(Polynome &a)
{
	Node *min, *p, *q;
	p = a.pHead;
	while (p != a.pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info.expo < min->info.expo)
				min = q;
			q = q->pNext;
		}
		swap(min->info, p->info);
		p = p->pNext;
	}
}

Polynome Tong_2DT(Polynome a, Polynome b)
{
	Polynome kq;
	CreatPoly(kq);
	Data x;
	Node *pA = a.pHead, *pB = b.pHead;
	while (pA != NULL && pB != NULL)
	{
		if (pA->info.expo < pB->info.expo)
		{
			InsertTail(kq, pA->info);
			pA = pA->pNext;
		}
		else if (pA->info.expo>pB->info.expo)
		{
			InsertTail(kq, pB->info);
			pB = pB->pNext;
		}
		else
		{
			x.coef = pA->info.coef + pB->info.coef;
			x.expo = pA->info.expo;
			if (x.coef != 0)
				InsertTail(kq, x);
			pA = pA->pNext;
			pB = pB->pNext;
		}
	}
	while (pA != NULL)
	{
		InsertTail(kq, pA->info);
		pA = pA->pNext;
	}
	while (pB != NULL)
	{
		InsertTail(kq, pB->info);
		pB = pB->pNext;
	}
	RutGon_DT(kq);
	SapXep_DT(kq);
	return kq;
}

Polynome Hieu_2DT(Polynome a, Polynome b)
{
	Polynome kq;
	CreatPoly(kq);
	Data x;
	Node *pA = a.pHead, *pB = b.pHead;
	while (pA != NULL && pB != NULL)
	{
		if (pA->info.expo < pB->info.expo)
		{
			InsertTail(kq, pA->info);
			pA = pA->pNext;
		}
		if (pA->info.expo>pB->info.expo)
		{
			x.coef = -pB->info.coef;
			x.expo = pB->info.expo;
			InsertTail(kq, x);
			pB = pB->pNext;
		}
		if (pA->info.expo == pB->info.expo)
		{
			x.coef = pA->info.coef - pB->info.coef;
			x.expo = pA->info.expo;
			if (x.coef != 0)
				InsertTail(kq, x);
			pA = pA->pNext;
			pB = pB->pNext;
		}
	}
	while (pA != NULL)
	{
		InsertTail(kq, pA->info);
		pA = pA->pNext;
	}
	while (pB != NULL)
	{
		x.coef = -pB->info.coef;
		x.expo = pB->info.expo;
		InsertTail(kq, x);
		pB = pB->pNext;
	}
	RutGon_DT(kq);
	SapXep_DT(kq);
	return kq;
}

Polynome Nhan_PT_DT(Polynome a, Node *p)
{
	Polynome kq;
	CreatPoly(kq);
	Data x;
	Node *pA = a.pHead;
	while (pA != NULL)
	{
		x.expo = pA->info.expo + p->info.expo;
		x.coef = pA->info.coef * p->info.coef;
		InsertTail(kq, x);
		pA = pA->pNext;
	}
	RutGon_DT(kq);
	SapXep_DT(kq);
	return kq;
}

Polynome Tich_2DT(Polynome a, Polynome b)
{
	Polynome kq, t1, t2;
	CreatPoly(kq);
	CreatPoly(t1);
	CreatPoly(t2);
	Node *pA;
	pA = a.pHead;
	while (pA != NULL)
	{
		t1 = Nhan_PT_DT(b, pA);
		t2 = Tong_2DT(kq, t1);
		kq = t2;
		pA = pA->pNext;
	}
	return kq;
}

Polynome DaoHam_DT(Polynome a)
{
	Polynome kq;
	CreatPoly(kq);
	Node *pA = a.pHead;
	Data x;
	while (pA != NULL)
	{
		if (pA->info.expo == 0)
		{
			x.coef = 0;
			x.expo = 0;
		}
		else
		{
			x.coef = pA->info.expo*pA->info.coef;
			x.expo = pA->info.expo - 1;
		}
		if (x.coef != 0)
			InsertTail(kq, x);
		pA = pA->pNext;
	}
	RutGon_DT(kq);
	SapXep_DT(kq);
	return kq;
}

double GT_DT_x(Polynome a, double x)
{
	double kq = 0, t;
	Node *pA = a.pHead;
	while (pA != NULL)
	{
		t = pA->info.coef*pow(x, pA->info.expo);
		kq = kq + t;
		pA = pA->pNext;
	}
	return kq;
}