void XuatMenu()
{
	cout << "\n========================== HE THONG CHUC NANG ==========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay BST";
	cout << "\n2. Xuat cay BST theo thu tu truoc, giua, cuoi";
	cout << "\n3. So nut cua cay";
	cout << "\n4. Dem so nut co key < x";
	cout << "\n5. Tim nut co khoa x";
	cout << "\n6. Kiem tra nut co key cho truoc co phai la nut la";
	cout << "\n7. Dem so nut la va xuat cac nut la";
	cout << "\n8. Chieu cao cua cay";
	cout << "\n9. Muc cua nut co khoa x";
	cout << "\n10. So sanh muc 2 nut";
	cout << "\n11. Them khoa x vao cay";
	cout << "\n12. Xoa nut co khoa x";
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

void XuLyMenu(int menu, BSTree& root)
{
	char filename[50];
	int kq;
	KeyType x;
	KeyType y;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << "\0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Tao cay BST\n";
		cout << "\nTen tap tin filename = ";
		_flushall();
		cin >> filename;
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen du lieu file " << filename << " vao cay BST";
		else
			cout << "\nKhong thanh cong!!!";
		break;
	case 2:
		cout << "\n2. Xuat cay BST theo thu tu giua\n";
		cout << "\n\nCay BST xuat theo thu tu truoc (NLR) :\n\n";
		PreOrder(root);
		cout << "\n\nCay BST xuat theo thu tu giua (LNR) :\n\n";
		InOrder(root);
		cout << "\n\nCay BST xuat theo thu tu cuoi (LRN) :\n\n";
		PosOrder(root);
		break;
	case 3:
		cout << "\n3. So nut cua cay\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nSo nut trong cay : So nut = " << DemSoNut(root);
		cout << endl;
		break;
	case 4:
		cout << "\n4. Dem so nut co key < x va xuat cac nut ra man hinh\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nNhap x = ";
		cin >> x;
		cout << "\n\nDanh sach cac nut cua BST co key < " << x << " :\n\n";
		kq = DemNutNhoHon(root, x);
		cout << "\n\nSo nut cua cay BST co key < " << x << " : " << kq;
		cout << endl;
		break;
	case 5:
		cout << "\n5. Tim kiem khoa x\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << endl;
		cout << "\nTim khoa x = ";
		cin >> x;
		if (Search(x, root))
			cout << "\nKhoa x = " << x << " co trong cay.\n";
		else
			cout << "\nKhoa x = " << x << " khong co trong cay!\n";
		break;
	case 6:
		cout << "\n6. Kiem tra nut cho truoc co phai la nut la\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nNhap x = ";
		cin >> x;
		kq = IsLeaf_x(root, x);
		if (kq == -1)
			cout << "\n\nKhoa " << x << " khong co trong cay ";
		else
			if (kq == 0)
				cout << "\nNut co khoa " << x << " khong la nut la";
			else
				cout << "\nNut co khoa " << x << " la nut la";
		cout << endl;
		break;
	case 7:
		cout << "\n7. Dem so nut la va xuat cac nut la\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nDanh sach cac nut la cua BST:\n\n";
		kq = DemNutLa(root);
		cout << "\n\nSo nut la cua cay BST : soNutLa = " << kq;
		cout << endl;
		break;
	case 8:
		cout << "\n8. Chieu cao cua cay\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nChieu cao cua cay BST : h = " << TinhChieuCao(root);
		cout << endl;
		break;
	case 9:
		cout << "\n9. Muc cua nut co khoa x\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nNhap x = ";
		cin >> x;
		if (!Search(x, root))
			cout << "\nCay rong hoac Khong co nut nao co khoa " << x;
		else
			cout << "\nMuc cua nut co khoa " << x << " : " << TimMuc_x(root, x);
		cout << endl;
		break;
	case 10:
		cout << "\n10. So sanh muc 2 nut\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nNhap khoa x : ";
		cin >> x;
		cout << "\nNhap khoa y : ";
		cin >> y;
		if (SoSanhMuc(root, x, y) == 1)
			cout << "\nMuc cua nut co khoa " << x << " sau hon muc cua nut co khoa " << y;
		else if (SoSanhMuc(root, x, y) == -1)
			cout << "\nMuc cua nut co khoa " << y << " sau hon muc cua nut co khoa " << x;
		else
			cout << "\nNut co khoa " << x << " va nut co khoa " << y << " cung muc";
		cout << "\n\nMuc cua nut co khoa " << x << " : " << TimMuc_x(root, x);
		cout << "\n\nMuc cua nut co khoa " << y << " : " << TimMuc_x(root, y);
		break;
	case 11:
		cout << "\n11. Them khoa x vao cay\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nNhap x = ";
		cin >> x;
		if (InsertNode(root, x) != 1)
			cout << "\nThem khoa " << x << " khong thanh cong\n";
		else
		{
			cout << "\nCay BST sau khi them khoa " << x << " :\n\n";
			InOrder(root);
		}
		cout << endl;
		break;
	case 12:
		cout << "\n12. Xoa nut co khoa x\n";
		cout << "\nCay BST xuat theo thu tu giua :\n\n";
		InOrder(root);
		cout << "\n\nNhap x = ";
		cin >> x;
		if (!Search(x, root))
		{
			cout << "\nKhoa x = " << x << " khong co trong cay\n";
			break;
		}
		else
			if (DeleteNode(x, root) != 0)
			{
				cout << "\nCay BST sau khi xoa khoa " << x << " :\n\n";
				InOrder(root);
			}
		cout << endl;
		break;
	default:
		break;
	}
	_getch();
}