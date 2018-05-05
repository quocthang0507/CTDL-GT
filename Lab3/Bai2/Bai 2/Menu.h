void XuatMenu()
{
	cout << "\n======================= HE THONG CHUC NANG =======================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu cho chuong trinh tu file";
	cout << "\n2. Xem du lieu";
	cout << "\n\tCAC THUAT TOAN SAP XEP THEO DIEM TRUNG BINH";
	cout << "\n3. Quick sort";
	cout << "\n4. Heap sort";
	cout << "\n5. Merge Sort";
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

void XuLyMenu(int menu, SinhVien a[MAX], int &n)
{
	char filename[15];
	int kq;
	SinhVien b[MAX];
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
		cout << "\n1. Tao du lieu cho chuong trinh tu file\n";
		do
		{
			cout << "\nNhap ten tap tin de mo : ";
			cin >> filename;
			kq = DocFile(filename, a, n);
			if (kq == 0)
				cout << "\nLoi mo file!\n";
		} while (kq == 0);
		cout << "\nDanh sach sinh vien vua tao : \n";
		Xuat_DS(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu\n";
		cout << "\nDanh sach sinh vien hien co : \n";
		Xuat_DS(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Quick sort\n";
		cout << "\nDanh sach truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sau khi sap xep theo diem trung binh : \n";
		QuickSort(b, n);
		Xuat_DS(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Heap sort\n";
		cout << "\nDanh sach truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sau khi sap xep theo diem trung binh : \n";
		HeapSort(b, n);
		Xuat_DS(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Merge Sort\n";
		cout << "\nDanh sach truoc khi sap xep : \n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sau khi sap xep theo diem trung binh : \n";
		MergeSort(b, n);
		Xuat_DS(b, n);
		break;
	default:
		break;
	}
	_getch();
}