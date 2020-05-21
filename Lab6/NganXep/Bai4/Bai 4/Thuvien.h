#define NULLDATA ' '
#define MAX 100

typedef char Data;

struct tagNode
{
	Data info;
	tagNode *pNext;
};

typedef tagNode Node;

struct Stack
{
	Node *pHead;
	Node *pTail;
};

Node *GetNode(Data x);
void CreatStack(Stack &s);
void Push(Stack &s, Data x);
void XuatStack(Stack s);
void Chuoi_Sang_Stack(Stack &s, char x[MAX]);
void Stack_Sang_Chuoi(Stack s, char y[MAX]);
Data Pop(Stack &s);
int Do_UuTien_ToanTu(char c);
int LaToanTu(char c);
void Chen_Cuoi_Chuoi(char a[MAX], char c);
int LaKySo(char c);
void TrungTo_HauTo(char sin[MAX], char sout[MAX]);

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

void CreatStack(Stack &s)
{
	s.pHead = s.pTail = NULL;
}

void Push(Stack &s, Data x)
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

Data Pop(Stack &s)
{
	Data x;
	Node *p;
	if (s.pHead == NULL)
	{
		return NULLDATA;
	}
	x = s.pHead->info;
	p = s.pHead;
	s.pHead = s.pHead->pNext;
	delete p;
	if (s.pHead == NULL)
		s.pTail = NULL;
	return x;
}

int Do_UuTien_ToanTu(char c)
{
	if (c == '*' || c == '/' || c == '%')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}

int LaToanTu(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return 1;
	else return 0;
}

void Chen_Cuoi_Chuoi(char a[MAX], char c)
{
	int chieuDai = strlen(a);
	a[chieuDai] = c;
	a[chieuDai + 1] = NULL;
}

int LaKySo(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else return 0;
}

void TrungTo_HauTo(char sin[MAX], char sout[MAX])
{
	Stack s;
	char c;
	Data x;
	int i;
	CreatStack(s);
	sout[0] = NULL;
	for (i = 0; sin[i] != NULL; i++)
	{
		c = sin[i];
		if (LaKySo(c) == 1)
			Chen_Cuoi_Chuoi(sout, c);
		else
			if (c == '(')
				Push(s, c);
			else
				if (c == ')')
				{
					x = Pop(s);
					while (x != '(')
					{
						Chen_Cuoi_Chuoi(sout, x);
						x = Pop(s);
					}
				}
				else
				{
					while (s.pHead != NULL && LaToanTu(s.pHead->info) == 1)
						if (Do_UuTien_ToanTu(s.pHead->info) >= Do_UuTien_ToanTu(c))
						{
							x = Pop(s);
							Chen_Cuoi_Chuoi(sout, x);
						}
						else break;
						Push(s, c);
				}
	}
	while (s.pHead != NULL)
	{
		x = Pop(s);
		Chen_Cuoi_Chuoi(sout, x);
	}
}