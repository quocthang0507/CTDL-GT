//Chỉ định khóa chính
typedef char KeyType[8];

//Cấu trúc ngày tháng năm sinh
struct ntns
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
};

//Cấu trúc thông tin nhân viên
struct NhanVien
{
	KeyType maNV;
	char ho[10];
	char tenLot[10];
	char ten[10];
	char diaChi[15];
	ntns ngaySinh;
	double luong;
};

//Cấu trúc của một nút
struct BSNode
{
	NhanVien info;
	BSNode *left;
	BSNode *right;
};

//Tạo thành cây nhị phân tìm kiếm
typedef BSNode *BSTree;

//Tạo nhân viên với các thông tin rỗng
NhanVien Create_NULL_DATA()
{
	NhanVien a;
	strcpy_s(a.diaChi, "\0");
	strcpy_s(a.ho, "\0");
	a.luong = 0;
	strcpy_s(a.maNV, "\0");
	a.ngaySinh.ngay = 0;
	a.ngaySinh.thang = 0;
	a.ngaySinh.nam = 0;
	strcpy_s(a.ten, "\0");
	strcpy_s(a.tenLot, "\0");
	return a;
}

//Chuyển thông tin nhân viên sang nút
BSNode *CreateNode(NhanVien x)
{
	BSNode *p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

//Tạo cây nhị phân tìm kiếm rỗng
void CreateBST(BSTree &root)
{
	root = NULL;
}

//Tìm vị trí thích hợp để chèn thông tin nhân viên
int InsertNode(BSTree &root, NhanVien x)
{
	//Nếu cây khác rỗng thì đệ quy để tìm, nếu trùng thì trả về 0
	if (root != NULL)
	{
		if (_strcmpi(root->info.maNV, x.maNV) == 0)
			return 0;
		if (_strcmpi(root->info.maNV, x.maNV) > 0)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	//Nếu tìm thấy thì gán thông tin nhân viên vào root (vị trí đã tìm thấy)
	root = CreateNode(x);
	//Gán không thành công thì trả về -1, ngược lại là 1
	if (root == NULL)
		return -1;
	return 1;
}

int File_BST(BSTree &btroot, char *filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	NhanVien x;
	KeyType maNV;
	char ho[10];
	char tenLot[10];
	char ten[10];
	char diaChi[15];
	unsigned ngay;
	unsigned thang;
	unsigned nam;
	double luong;
	int kq;
	//CreateBST(root);

	in >> maNV; strcpy_s(x.maNV, maNV);
	in >> ho; strcpy_s(x.ho, ho);
	in >> tenLot; strcpy_s(x.tenLot, tenLot);
	in >> ten; strcpy_s(x.ten, ten);
	in >> diaChi; strcpy_s(x.diaChi, diaChi);
	in >> ngay; x.ngaySinh.ngay = ngay;
	in >> thang; x.ngaySinh.thang = thang;;
	in >> nam; x.ngaySinh.nam = nam;
	in >> luong; x.luong = luong;
	kq = InsertNode(btroot, x);
	if (kq == 0 || kq == -1)
		return 0;

	while (!in.eof())
	{
		in >> maNV; strcpy_s(x.maNV, maNV);
		in >> ho; strcpy_s(x.ho, ho);
		in >> tenLot; strcpy_s(x.tenLot, tenLot);
		in >> ten; strcpy_s(x.ten, ten);
		in >> diaChi; strcpy_s(x.diaChi, diaChi);
		in >> ngay; x.ngaySinh.ngay = ngay;
		in >> thang; x.ngaySinh.thang = thang;;
		in >> nam; x.ngaySinh.nam = nam;
		in >> luong; x.luong = luong;
		kq = InsertNode(btroot, x);
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
	for (int i = 1; i <=75; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(9) << "Ma NV"
		<< ':'
		<< setw(9) << "Ho"
		<< ':'
		<< setw(9) << "Ten lot"
		<< ':'
		<< setw(8) << "Ten"
		<< ':'
		<< setw(15) << "Dia chi"
		<< ':'
		<< setw(2) << "NS"
		<< '/'
		<< setw(2) << "TS"
		<< '/'
		<< setw(4) << "NaS"
		<< ':'
		<< setw(9) << "Luong"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_1NV(NhanVien x)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(9) << x.maNV
		<< ':'
		<< setw(9) << x.ho
		<< ':'
		<< setw(9) << x.tenLot
		<< ':'
		<< setw(8) << x.ten
		<< ':'
		<< setw(15) << x.diaChi
		<< ':'
		<< setw(2) << x.ngaySinh.ngay
		<< '/'
		<< setw(2) << x.ngaySinh.thang
		<< '/'
		<< setw(4) << x.ngaySinh.nam
		<< ':'
		<< setw(9) << setiosflags(ios::fixed) << setprecision(0) << x.luong
		<< ':';
}

void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		Xuat_1NV(root->info);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_1NV(root->info);
		InOrder(root->right);
	}
}

void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_1NV(root->info);
	}
}