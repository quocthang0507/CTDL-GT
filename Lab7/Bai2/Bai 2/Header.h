#define MAX 30

typedef char data[MAX];

struct tagNode
{
	data info;
	tagNode *pNext;
};

typedef tagNode Node;

struct LLIST
{
	Node *pHead;
	Node *pTail;
};

Node *GetNode(data x)
{
	Node *p;
	p = new Node;
	if (p != NULL)
	{
		strcpy_s(p->info, x);
		p->pNext = NULL;
	}
}

void CreatList(LLIST &l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail(LLIST &l, data x)
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
		l.pTail->pNext = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

void Output_LLIST(LLIST l)
{
	Node *p;
	if (l.pHead == NULL)
	{
		cout << "\nDanh sach don vong rong!\n";
		return;
	}
	p = l.pHead;
	do
	{
		cout << p->info << '\t';
		p = p->pNext;
	} while (p != l.pHead);
}

int File_LLIST(char *f, LLIST &l)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreatList(l);
	data x;
	in >> x;
	InsertTail(l, x);
	while (!in.eof())
	{
		in >> x;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}