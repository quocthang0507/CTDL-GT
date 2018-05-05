void XuatMenu()
{
	cout << "\n======================== HE THONG CHUC NANG ========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Chuyen du lieu tu tap tin danh sach nhan vien vao BST";
	cout << "\n2. Xem danh sach nhan vien theo cac thu tu NLR, LNR, LRN";
	cout << "\n3. Xuat thong tin nhan vien khi biet ma nhan vien";
	cout << "\n4. Thay doi tien luong cua mot nhan vien";
	cout << "\n5. Tinh chieu cao cua BST";
	cout << "\n6. Huy nhan vien ra khoi danh sach voi ma nhan vien cho truoc";
	cout << "\n====================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, BSTree &root)
{
	int kq;
	KeyType maNV;
	NhanVien x;
	double luong;
	int chieuCao;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Chuyen du lieu tu tap tin danh sach nhan vien vao BST\n";
		kq = File_BST(root, "NhanVien.txt");
		if (kq == 1)
			cout << "\nChuyen du lieu thanh cong";
		else
			cout << "\nChuyen du lieu khong thanh cong";
		break;
	case 2:
		cout << "\n2. Xem danh sach nhan vien theo cac thu tu NLR, LNR, LRN\n";
		cout << "\nDanh sach nhan vien theo thu tu NLR:\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		cout << "\n\nDanh sach nhan vien theo thu tu LNR:\n";
		Xuat_TieuDe();
		InOrder(root);
		Xuat_KeDoi();
		cout << "\n\nDanh sach nhan vien theo thu tu LRN:\n";
		Xuat_TieuDe();
		PosOrder(root);
		Xuat_KeDoi();
		break;
	case 3:
		cout << "\n3. Xuat thong tin nhan vien khi biet ma nhan vien\n";
		cout << "\nDanh sach nhan vien theo thu tu NLR:\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		cout << "\n\nNhap ma nhan vien can tim : ";
		_flushall();
		cin >> maNV;
		x = Search(maNV, root);
		if (_strcmpi(x.maNV, "\0") != 0)
		{
			cout << "\nKet qua\n";
			Xuat_TieuDe();
			Xuat_1NV(x);
			Xuat_KeDoi();
		}
		else
			cout << "\nKhong tim thay nhan vien co ma nhan vien la " << maNV;
		break;
	case 4:
		cout << "\n4. Thay doi tien luong cua mot nhan vien\n"; \
			cout << "\nDanh sach nhan vien theo thu tu NLR:\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		cout << "\n\nNhap ma nhan vien can tim : ";
		_flushall();
		cin >> maNV;
		cout << "\nNhap tien luong can doi : ";
		cin >> luong;
		x = Search_Replace(maNV, root, luong);
		if (_strcmpi(x.maNV, "\0") != 0)
		{
			cout << "\nKet qua (Theo thu tu NLR):\n";
			Xuat_TieuDe();
			PreOrder(root);
			Xuat_KeDoi();
		}
		else
			cout << "\nKhong tim thay nhan vien co ma nhan vien la " << maNV;
		break;
	case 5:
		cout << "\n5. Tinh chieu cao cua BST\n";
		cout << "\nDanh sach nhan vien theo thu tu NLR:\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		chieuCao = TinhChieuCao(root);
		cout << "\n\nChieu cao cua cay BST la : " << chieuCao;
		break;
	case 6:
		cout << "\n6. Huy nhan vien ra khoi danh sach voi ma nhan vien cho truoc\n";
		cout << "\nDanh sach nhan vien theo thu tu NLR:\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		cout << "\n\nNhap ma nhan vien can xoa : ";
		_flushall();
		cin >> maNV;
		x = Search(maNV, root);
		if (_strcmpi(x.maNV, "\0") != 0)
		{
			DeleteNode(x, root);
			cout << "\n\nDanh sach moi :\n";
			Xuat_TieuDe();
			PreOrder(root);
			Xuat_KeDoi();
		}
		else
			cout << "\nKhong tim thay nhan vien co ma nhan vien la " << maNV;
		break;
	default:
		break;
	}
	_getch();
}