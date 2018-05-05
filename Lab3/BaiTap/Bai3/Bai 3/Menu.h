void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu tu file";
	cout << "\n2. Xem lai du lieu da tao";
	cout << "\n\t\tTHUAT TOAN SAP XEP DANH SACH NHAN VIEN";
	cout << "\n3. Thuat giai chon truc tiep - Tang dan theo ma nhan vien";
	cout << "\n4. Thuat giai chen truc tiep - Tang dan theo dia chi";
	cout << "\n5. Thuat giai Radix - Tang dan theo nam sinh";
	cout << "\n6. Thuat giai nang cao Quick Sort - Tang dan theo luong";
	cout << "\n   Neu cung luong, xep tang dan theo ten";
	cout << "\n   Neu cung luong, ten, xep tang dan theo ho";
	cout << "\n   Neu cung luong, ten, ho, xep tang dan theo nam sinh";
	cout << "\n======================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, NhanVien a[MAX], int &n)
{
	NhanVien b[MAX];
	Copy(b, a, n);
	char filename[15];
	int kq;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		cout << "\nHen gap lai lan sau!\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao du lieu tu file\n";
		do
		{
			cout << "\nNhap ten tap tin can mo : ";
			cin >> filename;
			kq = Doc_File(filename, a, n);
			if (kq == 0)
				cout << "\nLoi mo tap tin!\n";
		} while (kq == 0);
		cout << "\nDanh sach nhan vien da tao : \n";
		Xuat_DS(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem lai du lieu da tao\n";
		cout << "\nDanh sach nhan vien hien co : \n";
		Xuat_DS(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Thuat giai chon truc tiep - Tang dan theo ma nhan vien\n";
		cout << "\nDanh sach nhan vien truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach nhan vien sau khi sap xep : \n";
		SelectionSort(b, n);
		Xuat_DS(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Thuat giai chen truc tiep - Tang dan theo dia chi\n";
		cout << "\nDanh sach nhan vien truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach nhan vien sau khi sap xep : \n";
		InsertionSort(b, n);
		Xuat_DS(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Thuat giai Radix - Tang dan theo nam sinh\n";
		cout << "\nDanh sach nhan vien truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach nhan vien sau khi sap xep : \n";
		Radix(b, n);
		Xuat_DS(b, n);
		break;
	case 6:
		system("cls");
		cout << "\n5. Thuat giai nang cao Quick Sort - Tang dan theo luong";
		cout << "\n   Neu cung luong, xep tang dan theo ten";
		cout << "\n   Neu cung luong, ten, xep tang dan theo ho";
		cout << "\n   Neu cung luong, ten, ho, xep tang dan theo nam sinh\n";
		cout << "\nDanh sach nhan vien truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach nhan vien sau khi sap xep : \n";
		QuickSort(b, 0, n - 1);
		Xuat_DS(b, n);
		break;
	default:
		break;
	}
	_getch();
}