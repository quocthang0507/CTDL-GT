struct nhom
{
	char ns[5];
	int stt;
};

typedef nhom data;

struct tagNode
{
	data info;
	tagNode *pNext;
};

typedef tagNode Node;

struct Queue
{
	Node *pHead;
	Node *pTail;
};

Node *GetNode(data x);
void CreatQueue(Queue &q);
void InsertTail(Queue &q, data x);
void EnQueue(Queue &q, data x);
data DeQueue(Queue &q);
void TapTin_Queue(char *filename, Queue &q);
int SoNhom(Queue q);
void XuatQueue(Queue q);
void  XuatLichTruc(Queue &q, int m);

Node *GetNode(data x)
{
	Node *p;
	p = new Node;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
		return p;
	}
}

void CreatQueue(Queue &q)
{
	q.pHead = q.pTail = NULL;
}

void InsertTail(Queue &q, data x)
{
	Node *p = GetNode(x);
	if (p == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (q.pHead == NULL)
	{
		q.pHead = p;
		q.pTail = q.pHead;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
		q.pTail->pNext = NULL;
	}
}

void EnQueue(Queue &q, data x)
{
	InsertTail(q, x);
}

data DeQueue(Queue &q)
{
	Node *p;
	data x;
	//if (q.pHead == NULL)
	//	return;
	p = q.pHead;
	x = p->info;
	q.pHead = q.pHead->pNext;
	if (q.pHead == NULL)
		q.pTail = NULL;
	return x;
}

void TapTin_Queue(char *filename, Queue &q)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	data p;
	in >> p.ns;
	in >> p.stt;
	EnQueue(q, p);
	while (!in.eof())
	{
		in >> p.ns;
		in >> p.stt;
		EnQueue(q, p);
	}
	in.close();
}

int SoNhom(Queue q)
{
	int sn = 0;
	Node *p = q.pHead;
	if (p == NULL) return sn;
	while (p != NULL)
	{
		sn++;
		p = p->pNext;
	}
	return sn;
}

void XuatQueue(Queue q)
{
	Node *p = q.pHead;
	while (p != NULL)
	{
		cout << p->info.ns << '\t' << p->info.stt << endl;
		p = p->pNext;
	}
}

void Sap_Tang_TTTruc(Queue &q)
{
	Node *x, *y;
	for (x = q.pHead; x != NULL; x = x->pNext)
		for (y = x->pNext; y != NULL; y = y->pNext)
		{
			if (x->info.stt > y->info.stt)
				swap(x->info, y->info);
		}
}

void  XuatLichTruc(Queue &q, int m)
{
	int i, sn;
	data x;
	int vong = 1;
	sn = SoNhom(q);
	Sap_Tang_TTTruc(q);
	cout << "\nVong " << vong << " :\n";
	for (i = 1; i <= m; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(13) << "\nTruc ngay thu " << setw(4) << i << setw(10) << " la nhom : ";
		x = DeQueue(q);
		cout << setw(5);
		cout << x.ns;
		EnQueue(q, x);
		if (i%sn == 0)
		{
			cout << "\n=========================";
			vong++;
			cout << "\nVong " << vong << " :\n";
		}
	}
	cout << endl;
}