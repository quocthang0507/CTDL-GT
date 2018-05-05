#define MAX 100
#define NULLDATA ' '

typedef char data;

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

void CreatQueue(Queue &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

int IsEmpty(Queue q)
{
	if (q.pHead == NULL)
		return 1;
	return 0;
}

void InsertTail(Queue &q, data x)
{
	Node *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (q.pHead == NULL)
	{
		q.pHead = new_ele;
		q.pTail = q.pHead;
	}
	else
	{
		q.pTail->pNext = new_ele;
		q.pTail = new_ele;
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
	if (q.pHead == NULL)
		return NULLDATA;
	p = q.pHead;
	x = p->info;
	q.pHead = q.pHead->pNext;
	delete p;
	if (q.pHead == NULL)
		q.pTail = NULL;
	return x;
}

void File_String(char *filename, char a[MAX])
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> a;
	in.close();
}

void Xuat_Queue(Queue q)
{
	Node *p = q.pHead;
	while (p != NULL)
	{
		cout << p->info;
		p = p->pNext;
	}
}

void XuLy_ThaoTac(char a[MAX])
{
	Queue q;
	CreatQueue(q);
	char c;
	int i;
	for (i = 0; a[i] != NULL; i++)
	{
		c = a[i];
		if ('A' <= c && c <= 'Z')
		{
			EnQueue(q, c);
			Xuat_Queue(q);
		}
		else if (c == '*')
		{
			if (DeQueue(q))
				Xuat_Queue(q);
		}
	}
	cout << "\nKet qua sau khi thuc hien chuoi thao tac \"" << a << "\":\n";
	Xuat_Queue(q);
	cout << endl;
	_getch();
}