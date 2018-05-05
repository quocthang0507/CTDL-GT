#define MAX 100

typedef int data;

struct tagNode
{
	data info;
	tagNode *pNext;
};

typedef tagNode Node;

struct Stack
{
	Node *pHead;
	Node *pTail;
};

Node *GetNode(data x);
void CreatStack(Stack &s);
void Push(Stack &s, data x);
data Pop(Stack &s);
int LaToanTu(char c);
int LaKySo(char c);
int So(char c);
int Tinh_BT_HauTo(char a[MAX]);

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

void CreatStack(Stack &s)
{
	s.pHead = s.pTail = NULL;
}

void Push(Stack &s, data x)
{
	Node *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho! Khong thuc hien duoc thao tac nay!";
		return;
	}
	if (s.pHead == NULL)
	{
		s.pHead = new_ele;
		s.pTail = s.pHead;
	}
	else
	{
		new_ele->pNext = s.pHead;
		s.pHead = new_ele;
	}
}

data Pop(Stack &s)
{
	data x;
	Node *p;
	if (s.pHead == NULL)
	{
		return NULL;
	}
	x = s.pHead->info;
	p = s.pHead;
	s.pHead = s.pHead->pNext;
	delete p;
	if (s.pHead == NULL)
		s.pTail = NULL;
	return x;
}

int LaToanTu(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return 1;
	else return 0;
}

int LaKySo(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else return 0;
}

int So(char c)
{
	return c - '0';
}

int Tinh_BT_HauTo(char a[MAX])
{
	int i;
	char c;
	data x, y;
	Stack s;
	CreatStack(s);
	for (i = 0; a[i] != NULL; i++)
	{
		c = a[i];
		if (LaKySo(c) == 1)
		{
			x = So(c);
			Push(s, x);
		}
		else
		{
			x = Pop(s);
			y = Pop(s);
			switch (c)
			{
			case '+':
				Push(s, y + x);
				break;
			case '-':
				Push(s, y - x);
				break;
			case '*':
				Push(s, y*x);
				break;
			case '/':
				Push(s, y / x);
				break;
			case '%':
				Push(s, y % x);
				break;
			}
		}
	}
	return s.pHead->info;
}