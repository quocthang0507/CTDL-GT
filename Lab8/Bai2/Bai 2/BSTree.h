typedef int KeyType;

struct BSNode
{
	KeyType key;
	BSNode *left;
	BSNode *right;
};

typedef BSNode *BSTree;

void CreatBST(BSTree &root)
{
	root = NULL;
}

BSNode *CreatNode(KeyType x)
{
	BSNode *p = new BSNode;
	if (p!=NULL)
	{
		p->key = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

int InsertNode(BSTree &root, KeyType x)
{
	if (root != NULL)
	{
		if (root->key == x)
			return 0;
		else if (root->key > x)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	root = CreatNode(x);
	if (root == NULL)
		return -1;
	return 1;
}

int File_BST(BSTree &root, char *f)
{
	ifstream in(f);
	if (!in)
		return 0;
	KeyType x;
	int kq;
	CreatBST(root);
	in >> x;
	kq = InsertNode(root, x);
	if (kq == 0 || kq == -1)
		return 0;
	while (!in.eof())
	{
		in >> x;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		cout << root->key << "   ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->key << "   ";
		InOrder(root->right);
	}
}

void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		cout << root->key << "   ";
	}
}

KeyType TinhMax(KeyType a, KeyType b)
{
	if (a >= b)
		return a;
	else return b;
}

int TinhChieuCao(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else if (root->left == NULL && root->right == NULL)
		h = 0;
	else
		h = 1 + TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right));
	return h;
}

int TimMuc_x(BSTree root, KeyType x)
{
	int muc;
	muc = 0;
	BSTree T = root;
	while (T != NULL)
	{
		if (T->key == x)
			return muc;
		else
		{
			muc++;
			if (T->key > x)
				T = T->left;
			else
				T = T->right;
		}
	}
	return 0;
}