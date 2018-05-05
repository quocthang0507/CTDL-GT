void XuatMenu()
{
	cout << "\n======================= HE THONG CHUC NANG =======================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao day so nguyen tu tap tin";
	cout << "\n2. Xem mang so nguyen da tao";
	cout << "\n\t\tDANH SACH THUAT TOAN SAP XEP";
	cout << "\n3. Chon truc tiep (Selection Straight sort)";
	cout << "\n4. Thuat giai chon 2 dau";
	cout << "\n5. Chen truc tiep (Insertion Straight sort)";
	cout << "\n6. Doi cho truc tiep (Interchange Straight sort)";
	cout << "\n7. Noi bot (Bubble sort)";
	cout << "\n8. Thuat giai Shaker sort";
	cout << "\n==================================================================";
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

void XuLyMenu(int menu, DaySo a, int &n)
{
	DaySo b;
	char filename[15];
	int kq;
	Copy(b, a, n);
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		cout << "\nHen gap lai lan sau!\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao day so nguyen tu tap tin\n";
		do
		{
			cout << "\nNhap ten tap tin can mo : ";
			cin >> filename;
			kq = File_Array(filename, a, n);
			if (kq == 0)
				cout << "\nLoi mo tap tin!\n";
		} while (kq == 0);
		cout << "\nDay da nhap : \n";
		XuatDay(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem mang so nguyen da tao\n";
		cout << "\nDay da tao : \n";
		XuatDay(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Chon truc tiep (Selection Straight sort)\n";
		cout << "\nDay ban dau :\n";
		XuatDay(a, n);
		Selection_R(b, n);
		cout << "\nDay sau khi sap xep :\n";
		XuatDay(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Thuat giai chon 2 dau\n";
		cout << "\nDay ban dau :\n";
		XuatDay(a, n);
		Selection_R_L(b, n);
		cout << "\nDay sau khi sap xep :\n";
		XuatDay(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Chen truc tiep (Insertion Straight sort)\n";
		cout << "\nDay ban dau :\n";
		XuatDay(a, n);
		Insertion_R(b, n);
		cout << "\nDay sau khi sap xep :\n";
		XuatDay(b, n);
		break;
	case 6:
		system("cls");
		cout << "\n6. Doi cho truc tiep (Interchange Straight sort)\n";
		cout << "\nDay ban dau :\n";
		XuatDay(a, n);
		Interchange_R(b, n);
		cout << "\nDay sau khi sap xep :\n";
		XuatDay(b, n);
		break;
	case 7:
		system("cls");
		cout << "\n7. Noi bot (Bubble sort)\n";
		cout << "\nDay ban dau :\n";
		XuatDay(a, n);
		Bubble_R(b, n);
		cout << "\nDay sau khi sap xep :\n";
		XuatDay(b, n);
		break;
	case 8:
		system("cls");
		cout << "\n8. Thuat giai Shaker sort\n";
		cout << "\nDay ban dau :\n";
		XuatDay(a, n);
		Shaker(b, n);
		cout << "\nDay sau khi sap xep :\n";
		XuatDay(b, n);
		break;
	default:
		break;
	}
	_getch();
}