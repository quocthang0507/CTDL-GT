//Hàm tìm nhân viên dựa vào mã nhân viên
//Nếu tìm được, trả về thông tin của nhân viên đó
//Ngược lại, trả về thông tin rỗng!
NhanVien Search(KeyType x, BSTree root)
{
	NhanVien NULL_DATA;
	NULL_DATA = Create_NULL_DATA();
	//Nếu cây có dữ liệu
	if (root != NULL)
	{
		if (_strcmpi(root->info.maNV, x) == 0)	//Nếu tìm thấy
			return root->info;
		else if (_strcmpi(root->info.maNV, x) < 0)	//Ngược lại, đệ quy để tìm
			return Search(x, root->right);
		else
			return Search(x, root->left);
	}
	//Nếu cây không có dữ liệu
	return NULL_DATA;
}

//Hàm tính chiều cao của cây tìm kiếm nhị phân
//Sử dụng toán tử tam phân để tìm giá trị lớn nhất
int TinhChieuCao(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else if (root->left == NULL && root->right == NULL)
		h = 0;
	else
		h = 1 + (TinhChieuCao(root->left) > TinhChieuCao(root->right) ? TinhChieuCao(root->left) : TinhChieuCao(root->right));
	return h;
}

//Hàm xóa và trả về thông tin của nút nằm ngoài cùng bên trái (có mã nhân viên nhỏ nhất)
//Phụ trợ cho hàm DeleteNode ở dưới
//Sau khi xóa, lấy giá trị của nút bên phải thay vào
NhanVien DeleteMin(BSTree& root)
{
	NhanVien k;
	if (root->left == NULL)
	{
		k = root->info;
		root = root->right;
		return k;
	}
	else
		return DeleteMin(root->left);
}

//Hàm xóa một nhân viên ra khỏi BST
//Yêu cầu phải tìm nhân viên đó trước khi dùng hàm này
//Trả về 1 nếu thành công, ngược lại là không thành công
int DeleteNode(NhanVien x, BSTree& root)
{
	if (root != NULL)
	{
		//Nếu x.MaNV != root->info.MaNV
		if (_strcmpi(root->info.maNV, x.maNV) > 0)
			DeleteNode(x, root->left);
		else if (_strcmpi(root->info.maNV, x.maNV) < 0)
			DeleteNode(x, root->right);
		//Nếu x.MaNV == root->info.MaNV
			//Nếu nó không có 2 cây con trái phải
		else if ((root->left == NULL) && (root->right == NULL))
			root = NULL;
		//Nếu nó không có cây con trái
		else if (root->left == NULL)
			root = root->right;
		//Nếu nó không có cây con phải
		else if (root->right == NULL)
			root = root->left;
		else
			//Nếu nó có cả 2 cây con trái phải
			root->info = DeleteMin(root->right);
		return 1;
	}
	return 0;
}

//Hàm tìm nhân viên dựa vào mã nhân viên
//Nếu tìm được, thay đổi giá trị tiền lương và trả về thông tin của nhân viên đó
//Ngược lại, trả về thông tin rỗng!
NhanVien Search_Replace(KeyType x, BSTree root, double luong)
{
	NhanVien NULL_DATA;
	NULL_DATA = Create_NULL_DATA();
	if (root != NULL)
	{
		if (_strcmpi(root->info.maNV, x) == 0)
		{
			root->info.luong = luong;
			return root->info;
		}
		else if (_strcmpi(root->info.maNV, x) < 0)
			return Search_Replace(x, root->right, luong);
		else
			return Search_Replace(x, root->left, luong);
	}
	return NULL_DATA;
}

void DeleteNode_SalaryLessThan(double luong, BSTree& root, BSTree temp)
{
	if (temp != NULL)
	{
		if (temp->info.luong < luong)
			DeleteNode(temp->info, root);
		DeleteNode_SalaryLessThan(luong, root, temp->left);
		DeleteNode_SalaryLessThan(luong, root, temp->right);
	}
}

void FindMaxSalary(BSTree root, double &MAX)
{
	if (root != NULL) {
		if (MAX < root->info.luong)
		{
			MAX = root->info.luong;
		}
		FindMaxSalary(root->left, MAX);
		FindMaxSalary(root->right, MAX);
	}
}

void FindMinSalary(BSTree root, double& MIN)
{
	if (root != NULL) {
		if (MIN > root->info.luong)
		{
			MIN = root->info.luong;
		}
		FindMinSalary(root->left, MIN);
		FindMinSalary(root->right, MIN);
	}
}

void PrintNhanVien_BySalary(BSTree root, double luong)
{
	if (root != NULL)
	{
		if (root->info.luong == luong) {
			Xuat_1NV(root->info);
		}
		PrintNhanVien_BySalary(root->left, luong);
		PrintNhanVien_BySalary(root->right, luong);
	}
}