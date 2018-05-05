//Hàm tạo thông tin rỗng dùng cho trường hợp tìm kiếm không thành công
HocVien NULL_DATA()
{
	HocVien x;
	strcpy_s(x.maHV, "\0");
	strcpy_s(x.hoHV, "\0");
	strcpy_s(x.tenLot, "\0");
	strcpy_s(x.tenHV, "\0");
	x.ngaySinh.ngay = 0;
	x.ngaySinh.thang = 0;
	x.ngaySinh.nam = 0;
	strcpy_s(x.lop, "\0");
	x.diemTK = 0;
	return x;
}

//Hàm tìm kiếm học viên trong BST dựa theo maNV
//Trả về thông tin học viên nếu tìm thấy, ngược lại thì trả về NULL_DATA
HocVien Search(BSTree root, KeyType maHV)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maHV, maHV) == 0)
			return root->info;
		else if (_strcmpi(root->info.maHV, maHV) > 0)
			return Search(root->pLeft, maHV);
		else return Search(root->pRight, maHV);
	}
	HocVien p = NULL_DATA();
	return p;
}

//Hàm tìm kiếm và thay thế điểm học viên trong BST
//Trả về thông tin học viên nếu tìm thấy, ngược lại thì trả về NULL_DATA
HocVien Search_Replace(BSTree root, KeyType maHV, double diemTK)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maHV, maHV) == 0)
		{
			root->info.diemTK = diemTK;
			return root->info;
		}
		else if (_strcmpi(root->info.maHV, maHV) > 0)
			return Search_Replace(root->pLeft, maHV, diemTK);
		else return Search_Replace(root->pRight, maHV, diemTK);
	}
	HocVien p = NULL_DATA();
	return p;
}

//Hàm tính chiều cao BST
//Trả về -1 nếu cây không có nút nào, ngược lại thì trả về chiều cao của BST
int TinhChieuCao(BSTree root)
{
	if (root == NULL)
		return -1;
	else if (root->pLeft == NULL && root->pRight == NULL)
		return 0;
	else return 1 + (TinhChieuCao(root->pLeft) > TinhChieuCao(root->pRight) ? TinhChieuCao(root->pLeft) : TinhChieuCao(root->pRight));
}

//Hàm đếm số nút trong BST
//Trả về 0 nếu BST rỗng, ngược lại chính là số nút hiện có trong BST
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	else return 1 + DemSoNut(root->pLeft) + DemSoNut(root->pRight);
}

//Hàm đếm số lá trong BST
//Trả về 0 nếu BST rỗng, ngược lại chính là số nút lá hiện có trong BST
int DemSoLa(BSTree root)
{
	if (root == NULL)
		return 0;
	else if (root->pLeft == NULL && root->pRight == NULL)
		return 1;
	else return DemSoLa(root->pLeft) + DemSoLa(root->pRight);
}

//Hàm xóa nút nhỏ nhất (nằm ngoài cùng bên trái) tại vị trí root và thay thế bằng nút bên phải
HocVien DeleteMin(BSTree &root)
{
	if (root->pLeft == NULL)
	{
		HocVien x = root->info;
		root = root->pRight;
		return x;
	}
	else return DeleteMin(root->pLeft);
}

//Hàm xóa nút bất kỳ trong BST
//Trả về 0 nếu không tìm thấy học viên, ngược lại thì xóa nút đó
int DeleteNode(BSTree &root, KeyType maHV)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maHV, maHV) == 0)
		{
			if (root->pLeft == NULL && root->pRight == NULL)
				root = NULL;
			else if (root->pLeft == NULL)
				root = root->pRight;
			else if(root->pRight == NULL)
				root = root->pLeft;
			else root->info=DeleteMin(root->pRight);
			return 1;
		}
		else if (_strcmpi(root->info.maHV, maHV) > 0)
			return DeleteNode(root->pLeft, maHV);
		else return DeleteNode(root->pRight, maHV);
	}
	return 0;
}