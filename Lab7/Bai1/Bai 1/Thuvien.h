int Search(LLIST l, data x)
{
	Node *p;
	p = l.pHead;
	do
	{
		if (p->info == x)
			return 1;
		p = p->pNext;
	} while (p != l.pHead);
}

int Search_Pos_First(LLIST l, data x)
{
	Node *p;
	int kq = -1, i = 0;
	p = l.pHead;
	do
	{
		if (p->info == x)
		{
			kq = i;
			break;
		}
		p = p->pNext;
		i++;
	} while (p != l.pHead);
	return kq;
}

int Search_Pos_End(LLIST l, data x)
{
	Node *p;
	int kq = -1, i = 0;
	p = l.pHead;
	do
	{
		if (p->info == x)
			kq = i;
		p = p->pNext;
		i++;
	} while (p != l.pHead);
	return kq;
}

void Search_All_Pos_x(LLIST l, data x)
{
	Node *p;
	int i = 0;
	int kq = Search(l, x);
	if (!kq)
	{
		cout << endl << x << " khong co trong danh sach";
		return;
	}
	cout << endl << x << " xuat hien trong danh sach tai cac vi tri : \n";
	p = l.pHead;
	do
	{
		if (p->info == x)
			cout << i << '\t';
		p = p->pNext;
		i++;
	} while (p != l.pHead);
}

Node *Search_End(LLIST l, data x)
{
	Node *p, *q = NULL;
	p = l.pHead;
	if (p == NULL);
	else
	{
		do
		{
			if (p->info == x)
				q = p;
			p = p->pNext;
		} while (p != l.pHead);
	}
	return q;
}

int Head_New(LLIST &l, data x)
{
	Node *q, *r = NULL;
	if (l.pHead == NULL)
		return 0;
	q = Search_End(l, x);
	if (q == NULL)
		return -1;
	l.pHead = q;
	do
	{
		r = q;
		q = q->pNext;
	} while (q != l.pHead);
	l.pTail = r;
	l.pTail->pNext = l.pHead;
	return 1;
}

void RemoveHead(LLIST &l)
{
	Node *p = l.pHead;
	if (p == NULL) return;
	if (l.pHead == l.pTail)
		l.pHead = l.pTail = NULL;
	else
	{
		l.pHead = p->pNext;
		l.pTail->pNext = l.pHead;
	}
	delete p;
}

void RemoveTail(LLIST &l)
{
	Node *p, *q;
	if (l.pHead == NULL)
		return;
	p = l.pHead;
	q = NULL;
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
		l.pTail->pNext = l.pHead;
}

void RemoveLLIST(LLIST &l)
{
	if (l.pHead == NULL)
		return;
	Node *p;
	do
	{
		p = l.pHead;
		l.pHead = p->pNext;
		l.pTail->pNext = l.pHead;
		delete p;
	} while (l.pHead != l.pTail);
	p = l.pHead;
	l.pHead = l.pTail = NULL;
	delete p;
}

int SoNut(LLIST l)
{
	int soLuong = 0;
	Node *p = l.pHead;
	if (l.pHead == NULL)
		return 0;
	do
	{
		soLuong++;
		p = p->pNext;
	} while (p != l.pHead);
	return soLuong;
}

void Copy_Llist(LLIST l, LLIST &l1)
{
	CreatLLIST(l1);
	if (l.pHead == NULL)
		return;
	Node *p;
	p = l.pHead;
	do
	{
		InsertTail(l1, p->info);
		p = p->pNext;
	} while (p != l.pHead);
}