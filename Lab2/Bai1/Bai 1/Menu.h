void XuatMenu()
{
	cout << "\n===========================HE THONG CHUC NANG===========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
	cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co (co linh canh)";
	cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co";
	cout << "\n6. Tra ve tat ca chi so i, neu co";
	cout << "\n========================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so trong khoang tu [0,..," << soMenu << "], stt = ";
		cin >> stt;
		if (0<=stt&&stt<=soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, DaySo a, int &n)
{
	int kq, x;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao du lieu\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_mang1c(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao : \n";
		XuatMang(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu\n";
		cout << "\nMang vua tao : \n";
		XuatMang(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien\n";
		cout << "\nMang du lieu ban dau : \n";
		XuatMang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		kq = TKTT_DauTien(a, n, x);
		if (kq == -1)
		{
			cout << endl << x << " khong co trong mang";
		}
		else
		{
			cout << endl << x << " xuat hien trong a tai vi tri dau tien la : " << kq;
		}
		cout << endl;
		break;
	case 4:
		system("cls");
		cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co (co linh canh)\n";
		cout << "\nMang du lieu ban dau : \n";
		XuatMang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		kq = TKTT_DauTien_LC(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << " xuat hien trong a tai vi tri dau tien la : " << kq;
		cout << endl;
		break;
	case 5:
		system("cls");
		cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co\n";
		cout << "\nMang du lieu ban dau : \n";
		XuatMang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		kq = TKTT_CuoiCung(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << " xuat hien trong a tai vt cuoi cung la : " << kq;
		cout << endl;
		break;
	case 6:
		system("cls");
		cout << "\n6. Tra ve tat ca chi so i, neu co\n";
		cout << "\nMang du lieu ban dau : \n";
		XuatMang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		TKTT_CacChiSo(a, n, x);
		cout << endl;
		break;
	default:
		break;
	}
	_getch();
}