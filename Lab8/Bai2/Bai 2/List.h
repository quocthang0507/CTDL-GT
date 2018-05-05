struct Node
{
	BSTree info;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

Node *GetNode(BSTree info)
{
	Node *p = new Node;
	if (p != NULL)
	{
		p->info = info;
		p->pNext = NULL;
	}
	return p;
}

void CreatList(List &l)
{
	l.pHead = l.pTail = NULL;
}

int IsEmpty(List l)
{
	if (l.pHead == NULL)
		return 1;
	else return 0;
}

void InsertTail(List &l, BSTree info)
{
	Node *x = GetNode(info);
	if (x == NULL)
		return;
	if (l.pHead == NULL)
	{
		l.pHead = x;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = x;
		l.pTail = x;
		l.pTail->pNext = NULL;
	}
}

BSTree RemoveHead(List &l)
{
	Node *p;
	BSTree x;
	if (l.pHead == NULL)
		return NULL;
	else
	{
		p = l.pHead;
		x = p->info;
		l.pHead = p->pNext;
		delete p;
		return x;
	}
}

void InsertHead(List &s, BSTree info)
{
	Node *x = GetNode(info);
	if (x == NULL)
		return;
	if (s.pHead == NULL)
	{
		s.pHead = x;
		s.pTail = s.pHead;
	}
	else
	{
		x->pNext = s.pHead;
		s.pHead = x;
	}
}

void BFS(BSTree root)
{
	List q;
	Node *t;
	BSTree p;
	CreatList(q);
	if (root == NULL)
		cout << "\nCay rong!";
	else
	{
		t = GetNode(root);
		InsertTail(q, t->info);
		do
		{
			p = RemoveHead(q);
			cout << p->key << "   ";
			if (p->left != NULL)
			{
				t = GetNode(p->left);
				InsertTail(q, t->info);
			}
			if (p->right != NULL)
			{
				t = GetNode(p->right);
				InsertTail(q, t->info);
			}
		} while (IsEmpty(q) == 0);
		cout << endl;
	}
}

void BFS_Muc_k(BSTree root, int k)
{
	List q;
	Node *t;
	BSTree p;
	CreatList(q);
	if (root == NULL)
		cout << "\nCay rong!";
	else
	{
		t = GetNode(root);
		InsertTail(q, t->info);
		do
		{
			p = RemoveHead(q);
			if (TimMuc_x(root, p->key) == k)
				cout << p->key << "   ";
			if (p->left != NULL)
			{
				t = GetNode(p->left);
				InsertTail(q, t->info);
			}
			if (p->right != NULL)
			{
				t = GetNode(p->right);
				InsertTail(q, t->info);
			}
		} while (IsEmpty(q) == 0);
		cout << endl;
	}
}

void BFS_TheoMuc(BSTree root)
{
	int i, h;
	h = TinhChieuCao(root);
	cout << "\n\nXuat BST theo chieu rong (tung muc):\n";
	for (i = 0; i <= h; i++)
	{
		cout << endl << "Muc " << i << " : ";
		BFS_Muc_k(root, i);
	}
}

void DFS(BSTree root)
{
	List s;
	Node *t;
	BSTree p;
	CreatList(s);
	if (root == NULL)
		cout << "\nCay rong!";
	else
	{
		t = GetNode(root);
		InsertHead(s, t->info);
		do
		{
			p = RemoveHead(s);
			cout << p->key << "   ";
			if (p->left != NULL)
				DFS(p->left);
			if (p->right != NULL)
			{
				t = GetNode(p->right);
				InsertHead(s, t->info);
			}
		} while (IsEmpty(s) == 0);
		cout << endl;
	}
}