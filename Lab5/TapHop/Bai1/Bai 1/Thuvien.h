#define MAX 100

typedef int data;

struct tagNode
{
	data info;
	tagNode *pNext;
};

typedef tagNode	Node;

struct List
{
	Node *pHead;
	Node *pTail;
};

void CreatList(List &a)
{
	a.pHead = a.pTail = NULL;
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

void InsertTail(List &a, data x)
{
	Node *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!\n";
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

void Doc_File(char *filename, List &a)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		return;
	}
	CreatList(a);
	data x;
	in >> x;
	InsertTail(a, x);
	while (!in.eof())
	{
		in >> x;
		InsertTail(a, x);
	}
	in.close();
}

int IsEmpty(List a)
{
	if (a.pHead == NULL)
		return 1;
	return 0;
}

void Xuat_DS(List a)
{
	Node *p;
	if (IsEmpty(a))
	{
		cout << "\nDanh sach rong!\n";
		return;
	}
	p = a.pHead;
	cout << '{';
	while (p != NULL)
	{
		cout << p->info;
		p = p->pNext;
		if (p != NULL)
			cout << ", ";
	}
	cout << "}\n";
}

int KT_Thuoc(List a, data x)
{
	Node *p;
	p = a.pHead;
	int kq = 0;
	while (p != NULL)
	{
		if (p->info == x)
		{
			kq = 1;
			break;
		}
		p = p->pNext;
	}
	return kq;
}

List Giao_2TH(List a, List b)
{
	List kq;
	CreatList(kq);
	Node *p = a.pHead;
	while (p!=NULL)
	{
		if (KT_Thuoc(b, p->info))
			InsertTail(kq, p->info);
		p = p->pNext;
	}
	return kq;
}

void SaoChep(List &b, List a)
{
	Node *p = a.pHead;
	while (p != NULL)
	{
		InsertTail(b, p->info);
		p = p->pNext;
	}
}

List Hop_2TH(List a, List b)
{
	List kq;
	CreatList(kq);
	SaoChep(kq, a);
	Node *p = b.pHead;
	while (p != NULL)
	{
		if (!KT_Thuoc(a, p->info))
			InsertTail(kq, p->info);
		p = p->pNext;
	}
	return kq;
}

List Hieu_2TH(List a, List b)
{
	List kq;
	CreatList(kq);
	Node *p = a.pHead;
	while (p!=NULL)
	{
		if (!KT_Thuoc(b, p->info))
			InsertTail(kq, p->info);
		p = p->pNext;
	}
	return kq;
}

List HieuDX_2TH(List a, List b)
{
	List kq, d, e;
	CreatList(kq);
	CreatList(d);
	CreatList(e);
	d = Hieu_2TH(a, b);
	e = Hieu_2TH(b, a);
	kq = Hop_2TH(d, e);
	return kq;
}

void TichDescartes_2TH(List a, List b)
{
	if (a.pHead == NULL || b.pHead == NULL)
		return;
	cout << '{';
	Node *p = a.pHead;
	while (p != NULL)
	{
		Node *q = b.pHead;
		while (q != NULL)
		{
			cout << '(' << p->info << ',' << q->info << ')';
			if (p != a.pTail && q != b.pTail)
				cout << ", ";
			q = q->pNext;
		}
		p = p->pNext;
	}
	cout << '}';
}

int KTQH_2TH(List a, List b)
{
	Node *p = a.pHead;
	int kq = 1;
	while (p!=NULL)
	{
		if (!KT_Thuoc(b, p->info))
			kq = 0;
		p = p->pNext;
	}
	return kq;
}

int LL_TH(List a)
{
	Node *p = a.pHead;
	if (p == NULL)
		return 0;
	int kq = 0;
	while (p!=NULL)
	{
		kq++;
		p = p->pNext;
	}
	return kq;
}