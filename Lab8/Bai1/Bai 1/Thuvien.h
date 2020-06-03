int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}

int DemNutNhoHon(BSTree root, KeyType x)
{
	int soNut;
	if (root == NULL)
		soNut = 0;
	else if (root->key < x) // Nếu nút hiện tại có giá trị nhỏ hơn x, tăng giá trị soNut lên 1
	{
		cout << root->key << '\t';
		soNut = 1 + DemNutNhoHon(root->left, x) + DemNutNhoHon(root->right, x);
	}
	else // Ngược lại, tiếp tục tìm kiếm
		soNut = DemNutNhoHon(root->left, x) + DemNutNhoHon(root->right, x);
	return soNut;
}

BSTree TimKiem_DeQuy(KeyType x, BSTree root)
{
	if (root != NULL)
	{
		if (root->key == x)
			return root;
		else if (root->key < x)
			return TimKiem_DeQuy(x, root->right);
		else
			return TimKiem_DeQuy(x, root->left);
	}
	return NULL;
}

BSTree TimKiem_VongLap(KeyType x, BSTree root)
{
	if (root != NULL)
	{
		BSTree current = root;
		while (current != NULL)
		{
			if (current->key == x)
				return current;
			else if (x > current->key)
				current = current->right;
			else
				current = current->left;
		}
	}
	return NULL;
}

// Nút lá là nút không có nhánh con nào hết
int IsLeaf_x(BSTree root, KeyType x)
{
	int kq = 0;
	BSTree T = TimKiem_DeQuy(x, root);
	if (T == NULL)
		kq = -1;
	else
		kq = (T->left == NULL) && (T->right == NULL);
	return kq;
}

int DemNutLa(BSTree root)
{
	int soNutLa;
	if (root == NULL)
		soNutLa = 0;
	else if (root->right == NULL && root->left == NULL) // Nếu nút đang xét không có nhánh con, thì nút đó là nút lá
	{
		cout << root->key << '\t';
		soNutLa = 1;
	}
	else // Nếu nút đó có nhánh, thì tìm tất cả các nhánh con của nút đó
		soNutLa = DemNutLa(root->left) + DemNutLa(root->right);
	return soNutLa;
}

KeyType TinhMax(KeyType a, KeyType b)
{
	return a > b ? a : b;
}

int TinhChieuCao(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else if (root->left == NULL && root->right == NULL) // Không tính nút gốc
		h = 0;
	else // Tìm nhánh nào dài hơn làm chiều cao của cây
		h = 1 + TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right)); // Từ nút gốc trở đi, cứ mỗi nút trong nhánh thì tăng chiều cao lên 1
	return h;
}

// Tìm mức (level) của nút bằng vòng lặp
int TimMuc_x_VongLap(BSTree root, KeyType x)
{
	int muc = 0;
	BSTree current = root;
	if (current == NULL)
		return -1;
	while (current != NULL)
	{
		if (current->key == x)
			return muc;
		else
		{
			muc++;
			if (current->key > x)
				current = current->left;
			else current = current->right;
		}
	}
	return 0;
}

// Tìm mức (level) của nút bằng đệ quy
int TimMuc_x_DeQuy(BSTree root, KeyType x)
{
	int muc;
	if (root == NULL)
		muc = -1;
	else if (root->left == NULL && root->right == NULL)
		muc = 0;
	else if (root->key != x)
		muc = 1 + TimMuc_x_DeQuy(root->left, x) + TimMuc_x_DeQuy(root->right, x);
	return muc; // Điều kiện dừng (neo) là nếu giá trị của nút bằng với x
}

// Trả về 0 nếu hai nút có cùng mức, 1 nếu mức x > mức y, -1 nếu mức x < mức y
int SoSanhMuc(BSTree root, KeyType x, KeyType y)
{
	int kq1, kq2;
	kq1 = TimMuc_x_VongLap(root, x);
	kq2 = TimMuc_x_VongLap(root, y);
	if (kq1 > kq2)
		return 1;
	else if (kq1 < kq2)
		return -1;
	return 0;
}

KeyType Xoa_Nut_NhoNhat(BSTree& root)
{
	KeyType k;
	if (root->left == NULL)
	{
		k = root->key;
		root = root->right;
		return k;
	}
	else
		return Xoa_Nut_NhoNhat(root->left);
}

int Xoa_Nut_x(KeyType x, BSTree& root)
{
	if (root != NULL)
	{
		if (x < root->key) // Nếu nút cần xóa nằm bên trái
			Xoa_Nut_x(x, root->left);
		else if (x > root->key) // Nếu nút cần xóa nằm bên phải
				Xoa_Nut_x(x, root->right);
			else if ((root->left == NULL) && (root->right == NULL)) // Nếu nút cần xóa là nút lá
					root = NULL;
				else if (root->left == NULL) // Nếu nút cần xóa chỉ có nhánh bên phải
						root = root->right;
					else if (root->right == NULL) // Nếu nút cần xóa chỉ có nhánh bên trái
							root = root->left;
						else // Nếu nút cần xóa là một cây con (có hai nhánh)
							root->key = Xoa_Nut_NhoNhat(root->right); // Lấy nút nhỏ nhất bên phải thế vào nó
		return 1;
	}
	return 0;
}