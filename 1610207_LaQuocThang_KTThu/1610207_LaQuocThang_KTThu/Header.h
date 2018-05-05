typedef char KeyType[8];

struct NgayThang
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
};

struct HocVien
{
	KeyType maHV;
	char hoHV[11];
	char tenLot[11];
	char tenHV[11];
	NgayThang ngaySinh;
	char lop[7];
	double diemTK;
};

struct BSNode
{
	HocVien info;
	BSNode *pLeft;
	BSNode *pRight;
};

typedef BSNode *BSTree;

void CreateBSTree(BSTree &root)
{
	root = NULL;
}

BSNode *CreateNode(HocVien x)
{
	BSNode *p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}

int InsertNode(BSTree &root, HocVien x)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maHV, x.maHV) == 0)
			return 0;
		else if (_strcmpi(root->info.maHV, x.maHV) > 0)
			return InsertNode(root->pLeft, x);
		else return InsertNode(root->pRight, x);
	}
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}

int File_BSTree(BSTree &root, char *filename)
{
	CreateBSTree(root);
	ifstream in(filename);
	if (!in)
		return 0;
	HocVien x;
	int kq;
	KeyType maHV;
	char hoHV[11];
	char tenLot[11];
	char tenHV[11];
	unsigned ngay;
	unsigned thang;
	unsigned nam;
	char lop[7];
	double diemTK;
	in >> maHV; strcpy_s(x.maHV, maHV);
	in >> hoHV; strcpy_s(x.hoHV, hoHV);
	in >> tenLot; strcpy_s(x.tenLot, tenLot);
	in >> tenHV; strcpy_s(x.tenHV, tenHV);
	in >> ngay; x.ngaySinh.ngay = ngay;
	in >> thang; x.ngaySinh.thang = thang;
	in >> nam; x.ngaySinh.nam = nam;
	in >> lop; strcpy_s(x.lop, lop);
	in >> diemTK; x.diemTK = diemTK;
	kq = InsertNode(root, x);
	if (kq == 0 || kq == -1)
		return 0;
	while (!in.eof())
	{
		in >> maHV; strcpy_s(x.maHV, maHV);
		in >> hoHV; strcpy_s(x.hoHV, hoHV);
		in >> tenLot; strcpy_s(x.tenLot, tenLot);
		in >> tenHV; strcpy_s(x.tenHV, tenHV);
		in >> ngay; x.ngaySinh.ngay = ngay;
		in >> thang; x.ngaySinh.thang = thang;
		in >> nam; x.ngaySinh.nam = nam;
		in >> lop; strcpy_s(x.lop, lop);
		in >> diemTK; x.diemTK = diemTK;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (size_t i = 0; i < 70; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << '\n';
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(9) << "MaHV"
		<< ':'
		<< setw(11) << "Ho"
		<< ':'
		<< setw(11) << "Ten lot"
		<< ':'
		<< setw(11) << "Ten"
		<< ':'
		<< setw(2) << "NS"
		<< '/'
		<< setw(2) << "TS"
		<< '/'
		<< setw(4) << "NS"
		<< ':'
		<< setw(8) << "Lop"
		<< ':'
		<< setw(4) << "DTK"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_1HV(HocVien x)
{
	cout << '\n';
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(9) << x.maHV
		<< ':'
		<< setw(11) << x.hoHV
		<< ':'
		<< setw(11) << x.tenLot
		<< ':'
		<< setw(11) << x.tenHV
		<< ':'
		<< setw(2) << x.ngaySinh.ngay
		<< '/'
		<< setw(2) << x.ngaySinh.thang
		<< '/'
		<< setw(4) << x.ngaySinh.nam
		<< ':'
		<< setw(8) << x.lop
		<< ':'
		<< setw(4) << x.diemTK
		<< ':';
}

void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat_1HV(root->info);
		PreOrder(root->pLeft);
		PreOrder(root->pRight);
	}
}

void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->pLeft);
		Xuat_1HV(root->info);
		InOrder(root->pRight);
	}
}

void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->pLeft);
		PosOrder(root->pRight);
		Xuat_1HV(root->info);
	}
}