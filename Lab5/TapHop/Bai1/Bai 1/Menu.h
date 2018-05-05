void XuatMenu()
{
	cout << "\n==================== HE THONG CHUC NANG ====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu tu tap tin";
	cout << "\n2. Xem du lieu tap hop";
	cout << "\n\t\tCAC THAO TAC TREN TAP HOP SO NGUYEN";
	cout << "\n3. Giao 2 tap hop";
	cout << "\n4. Hop 2 tap hop";
	cout << "\n5. Hieu 2 tap hop";
	cout << "\n6. Hieu doi xung 2 tap hop";
	cout << "\n7. Tich Descartes 2 tap hop";
	cout << "\n8. Kiem tra phan tu co thuoc vao tap hop";
	cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop";
	cout << "\n10. Tinh luc luong tap hop";
	cout << "\n============================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (1)
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

void XuLyMenu(int menu, List &m, List &n)
{
	List kq;
	CreatList(kq);
	data x;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		cout << "\nHen gap lai lan sau!\n";
		break;
	case 1:
		cout << "\n1. Nhap du lieu tu tap tin\n";
		Doc_File("A.txt", m);
		Doc_File("B.txt", n);
		cout << "\nDoc du lieu tu file hoan tat, du lieu nhan duoc : \n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		break;
	case 2:
		cout << "\n2. Xem du lieu tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		break;
	case 3:
		cout << "\n3. Giao 2 tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		cout << "\nA n B = ";
		kq = Giao_2TH(m, n);
		Xuat_DS(kq);
		break;
	case 4:
		cout << "\n4. Hop 2 tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		cout << "\nA u B = ";
		kq = Hop_2TH(m, n);
		Xuat_DS(kq);
		break;
	case 5:
		cout << "\n5. Hieu 2 tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		cout << "\nA \\ B = ";
		kq = Hieu_2TH(m, n);
		Xuat_DS(kq);
		break;
	case 6:
		cout << "\n6. Hieu doi xung 2 tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		cout << "\nA /\\ B = ";
		kq = HieuDX_2TH(m, n);
		Xuat_DS(kq);
		break;
	case 7:
		cout << "\n7. Tich Descartes 2 tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		cout << "\nA x B = ";
		TichDescartes_2TH(m, n);
		break;
	case 8:
		cout << "\n8. Kiem tra phan tu co thuoc vao tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		cout << "\nNhap phan tu x = ";
		cin >> x;
		if (KT_Thuoc(m, x) && KT_Thuoc(n, x))
			cout << "\nPhan tu x thuoc 2 tap hop A va B";
		else if (KT_Thuoc(m, x))
			cout << "\nPhan tu x thuoc tap hop A";
		else if (KT_Thuoc(n, x))
			cout << "\nPhan tu x thuoc tap hop B";
		else if (!(KT_Thuoc(m, x) && KT_Thuoc(n, x)))
			cout << "\nPhan tu x khong thuoc 2 tap hop A va B";
		break;
	case 9:
		cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		if (KTQH_2TH(m, n) && KTQH_2TH(n, m))
			cout << "\nTap hop a bang tap hop b";
		else if (KTQH_2TH(m, n))
			cout << "\nTap hop a bao ham trong tap hop b";
		else if (KTQH_2TH(n, m))
			cout << "\nTap hop b bao ham trong tap hop a";
		else cout << "\nHai tap hop khong bao ham lan nhau";;
		break;
	case 10:
		cout << "\n10. Tinh luc luong tap hop\n";
		cout << "\nTap hop A = ";
		Xuat_DS(m);
		cout << "\nTap hop B = ";
		Xuat_DS(n);
		cout << "\nLuc luong cua tap hop a : " << LL_TH(m);
		cout << "\nLuc luong cua tap hop b : " << LL_TH(n);
		break;
	default:
		break;
	}
	_getch();
}