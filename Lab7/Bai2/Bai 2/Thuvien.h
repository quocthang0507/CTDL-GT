int TaoSoNgauNhien()
{
	int n;
	srand(time(NULL));
	n = rand() % MAX + 1;
	return n;
}

Node *Node_q(LLIST l, int n)
{
	Node *q;
	int dem = 1;
	q = l.pHead;
	if (q != NULL)
	{
		while (dem < n - 1)
		{
			q = q->pNext;
			dem++;
		}
	}
	return q;
}

void Remove_Node_After_q(LLIST &l, Node *q)
{
	if (l.pHead == NULL)
	{
		cout << "\nDanh sach rong!";
		_getch();
		return;
	}
	Node *p = q->pNext;
	q->pNext = p->pNext;
	delete p;
	l.pHead = q->pNext;
	if (l.pHead == NULL)
		l.pTail = NULL;
	else
		if (l.pHead != l.pTail)
			l.pTail = q;
}

int SoNut(LLIST l)
{
	int dem;
	Node *p = l.pHead;
	if (p == NULL)
		dem = 0;
	else
	{
		dem = 1;
		while (p != l.pTail)
		{
			dem++;
			p = p->pNext;
		}
	}
	return dem;
}

void CryForHelp(LLIST l)
{
	int n = TaoSoNgauNhien();
	int sn = SoNut(l);
	Node *q;
	int lan = 0;
	cout << "\nSo ngau nhien: n = " << n;
	cout << "\n KET QUA TUYEN CHON:\n";
	while (sn > 1)
	{
		q = Node_q(l, n);
		lan++;
		cout << setiosflags(ios::left);
		cout << setw(21) << "\nRa khoi vong lan thu " << setw(4) << lan << setw(13)
			<< " la binh si : " << q->pNext->info;
		Remove_Node_After_q(l, q);
		sn--;
	}
	cout << "\n\n Binh si duoc cu di cau cuu la : " << l.pHead->info;
}