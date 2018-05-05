void XuatMenu()
{
	cout << "\n======================== HE THONG CHUC NANG ========================";
	cout << "\n0. Thoat khoi chuong trinh"
		<< "\n1. Tao bang diem mon hoc"
		<< "\n2. Xem bang diem mon hoc theo cac thu tu dau (NLR), giua (LNR), cuoi (LRN)"
		<< "\n3. Xuat thong tin hoc vien khi biet ma hoc vien"
		<< "\n4. Thay doi diem cua mot hoc vien"
		<< "\n5. Tinh chieu cao cua BST"
		<< "\n6. Tinh so nut cua cay"
		<< "\n7. Tinh so nut la cua cay"
		<< "\n8. Huy hoc vien ra khoi bang diem voi ma hoc vien cho truoc";
	cout << "\n====================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon mot so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, BSTree &root)
{
	int kq;
	KeyType maHV;
	HocVien p;
	double diemTK;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1.Tao bang diem mon hoc\n";
		kq = File_BSTree(root, "Text.txt");
		if (kq)
			cout << "\nChuyen tap tin vao cay tim kiem nhi phan thanh cong!";
		else cout << "\nChuyen tap tin vao cay tim kiem nhi phan khong thanh cong!";
		break;
	case 2:
		cout << "\n2. Xem bang diem mon hoc theo cac thu tu dau (NLR), giua (LNR), cuoi (LRN)\n";
		cout << "\nDanh sach theo thu tu dau (NLR):\n\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		_getch();
		cout << "\n\nDanh sach theo thu tu giua (LNR):\n\n";
		Xuat_TieuDe();
		InOrder(root);
		Xuat_KeDoi();
		_getch();
		cout << "\n\nDanh sach theo thu tu cuoi (LRN):\n\n";
		Xuat_TieuDe();
		PosOrder(root);
		Xuat_KeDoi();
		break;
	case 3:
		cout << "\n3. Xuat thong tin hoc vien khi biet ma hoc vien\n";
		cout << "\nDanh sach theo thu tu dau (NLR):\n\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		if (root == NULL)
			cout << "\nBST rong!";
		else
		{
			cout << "\n\nNhap ma hoc vien can tim : ";
			_flushall();
			gets_s(maHV, 8);
			p = Search(root, maHV);
			if (_strcmpi(p.maHV, "\0") == 0)
				cout << "\nKhong tim thay hoc vien co ma la " << maHV;
			else
			{
				Xuat_TieuDe();
				Xuat_1HV(p);
				Xuat_KeDoi();
			}
		}
		break;
	case 4:
		cout << "\n4. Thay doi diem cua mot hoc vien\n";
		cout << "\nDanh sach theo thu tu dau (NLR):\n\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		if (root == NULL)
			cout << "\nBST rong!";
		else
		{
			cout << "\n\nNhap ma hoc vien can tim : ";
			_flushall();
			gets_s(maHV, 8);
			p = Search(root, maHV);
			if (_strcmpi(p.maHV, "\0") == 0)
				cout << "\nKhong tim thay hoc vien co ma la " << maHV;
			else
			{
				cout << "\nNhap diem can thay the = ";
				cin >> diemTK;
				p = Search_Replace(root, maHV, diemTK);
				Xuat_TieuDe();
				Xuat_1HV(p);
				Xuat_KeDoi();
			}
		}
		break;
	case 5:
		cout << "\n5. Tinh chieu cao cua BST\n";
		cout << "\nDanh sach theo thu tu dau (NLR):\n\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		if (TinhChieuCao(root) == -1)
			cout << "\nBST rong!";
		else cout << "\n\nChieu cao cua cay tim kiem nhi phan la : " << TinhChieuCao(root);
		break;
	case 6:
		cout << "\n6. Tinh so nut cua cay\n";
		cout << "\nDanh sach theo thu tu dau (NLR):\n\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		if (DemSoNut(root) == 0)
			cout << "\nBST rong!";
		else cout << "\n\nSo nut cua cay tim kiem nhi phan la : " << DemSoNut(root);
		break;
	case 7:
		cout << "\n7. Tinh so nut la cua cay\n";
		cout << "\nDanh sach theo thu tu dau (NLR):\n\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		if (DemSoLa(root) == 0)
			cout << "\nBST rong!";
		else cout << "\n\nSo la cua cay tim kiem nhi phan la : " << DemSoLa(root);
		break;
	case 8:
		cout << "\n8. Huy hoc vien ra khoi bang diem voi ma hoc vien cho truoc\n";
		cout << "\nDanh sach theo thu tu dau (NLR):\n\n";
		Xuat_TieuDe();
		PreOrder(root);
		Xuat_KeDoi();
		if (root == NULL)
			cout << "\nBST rong!";
		else
		{
			cout << "\n\nNhap ma hoc vien can xoa : ";
			_flushall();
			gets_s(maHV);
			kq = DeleteNode(root, maHV);
			if (kq)
			{
				cout << "\nDa xoa thanh cong";
				cout << "\nDanh sach moi theo thu tu dau (NLR):\n\n";
				Xuat_TieuDe();
				PreOrder(root);
				Xuat_KeDoi();
			}
			else cout << "\nKhong tim thay hoc vien co ma la " << maHV;
		}
		break;
	default:
		break;
	}
	_getch();
}