#define MAX 100
#define is_operator(x) ((x) == '+' || (x) == '-' || (x) == '*' || (x) == '/')

struct BSNode
{
	BSNode(void *x): data(x), left(0), right(0){}
	void *data;
	BSNode *left, *right;
};

typedef BSNode *BSTree;

void CreateBST(BSTree &root)
{
	root = NULL;
}

void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		char c = *(char *)root->data;
		if (is_operator(c))
			cout << c;
		else
			cout << *(int *)root->data;
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		char c = *(char *)root->data;
		if (is_operator(c))
			cout << c;
		else
			cout << *(int *)root->data;
		InOrder(root->right);
	}
}

void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		char c = *(char *)root->data;
		if (is_operator(c))
			cout << c;
		else
			cout << *(int *)root->data;
	}
}

BSTree EQN_to_BST(char bieuThuc[MAX])
{
	stack <char *> operators;
	stack <BSNode *> nodes;
	char *o;
	int *x;
	BSTree node1, node2, opr;;
	CreateBST(opr);
	CreateBST(node1);
	CreateBST(node2);
	for (size_t i = 0; i < strlen(bieuThuc); i++)
	{
		char c = bieuThuc[i];
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
			operators.push(new char(c));
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			x = new int((atoi((const char *)&c))); //Doi ky tu sang so
			nodes.push(new BSNode(x));
			break;
		case ')':
			if (!nodes.empty())
			{
				node1 = nodes.top();
				nodes.pop();
			}
			if (!nodes.empty())
			{
				node2 = nodes.top();
				nodes.pop();
			}
			while (true)
			{
				if (operators.empty())
					return NULL;
				o = operators.top();
				operators.pop();
				if (*o == '(')
					break;
				opr = new BSNode(o);
			}
			opr->right = node1;
			opr->left = node2;
			nodes.push(opr);
			break;
		default:
			return NULL;
		}
	}
	while (true)
	{
		if (operators.empty())
			return nodes.top();
		o = operators.top();
		operators.pop();
		opr = new BSNode(o);
		if (!nodes.empty())
		{
			node1 = nodes.top();
			nodes.pop();
		}
		if (!nodes.empty())
		{
			node2 = nodes.top();
			nodes.pop();
		}
		opr->right = node1;
		opr->left = node2;
		nodes.push(opr);
	}
	return NULL;
}

int evaluate_tree(BSTree root)
{
	char c = *(char *)root->data;
	int x = 0, y = 0;
	if (is_operator(c))
	{
		x = evaluate_tree(root->left);
		y = evaluate_tree(root->right);
		switch (c)
		{
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;
		default:
			return 0;
		}
	}
	else
		return *(int *)root->data;
}