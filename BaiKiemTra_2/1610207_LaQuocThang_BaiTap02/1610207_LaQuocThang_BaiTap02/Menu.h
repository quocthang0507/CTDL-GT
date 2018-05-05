void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao bang diem mon hoc tu tap tin";
	cout << "\n2. Xuat bang diem mon hoc";
	cout << "\n\tCAC THUAT TOAN SAP XEP	BANG DIEM SINH VIEN";
	cout << "\n3. Sap tang dan diem tong ket bang Quick sort";
	cout << "\n4. Sap tang dan nam sinh bang Insertion sort";
	cout << "\n5. Sap tang dan ma sinh vien bang Heap sort";
	cout << "\n6. Sap tang dan lop bang Selection sort";
	cout << "\n7. Sap bang diem theo yeu cau : "
		<< "\n\tTang dan theo ten bang Bubble sort"
		<< "\n\tNeu trung ten thi tang dan theo ho"
		<< "\n\tNeu trung ten va ho thi tang dan theo ten lot";
	cout << "\n8. Xep thu hang mon hoc theo diem tong ket mon hoc";
	cout << "\n======================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
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

void XuLyMenu(int menu,SinhVien a[MAX], int &n)
{
	char filename[15];
	int kq;
	SinhVien b[MAX];
	SaoChep(b, a, n);
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		cout << "\nHen gap lai lan sau!";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao bang diem mon hoc tu tap tin\n";
		do
		{
			cout << "\nNhap ten tap tin can mo : ";
			cin >> filename;
			kq = Doc_File(filename, a, n);
			if (kq == 0)
				cout << "\nLoi mo tap tin!\n";
		} while (kq==0);
		cout << "\nBang diem mon hoc : \n";
		Xuat_DS(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xuat bang diem mon hoc\n";
		Xuat_DS(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Sap tang dan diem tong ket bang Quick sort";
		cout << "\nDanh sach sinh vien ban dau :\n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep tang dan diem tong ket :\n";
		QuickSort(b, 0, n - 1);
		Xuat_DS(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Sap tang dan nam sinh bang Insertion sort";
		cout << "\nDanh sach sinh vien ban dau :\n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep tang dan nam sinh :\n";
		InsertionSort(b, n);
		Xuat_DS(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Sap tang dan ma sinh vien bang Heap sort";
		cout << "\nDanh sach sinh vien ban dau :\n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep tang dan ma sinh vien :\n";
		HeapSort(b, n);
		Xuat_DS(b, n);
		break;
	case 6:
		system("cls");
		cout << "\n6. Sap tang dan lop bang Selection sort";
		cout << "\nDanh sach sinh vien ban dau :\n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep tang dan lop :\n";
		Selection(b, n);
		Xuat_DS(b, n);
		break;
	case 7:
		system("cls");
		cout << "\n7. Sap bang diem theo yeu cau : "
			<< "\n\tTang dan theo ten bang Bubble sort"
			<< "\n\tNeu trung ten thi tang dan theo ho"
			<< "\n\tNeu trung ten va ho thi tang dan theo ten lot";
		cout << "\nDanh sach sinh vien ban dau :\n";
		Xuat_DS(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep theo yeu cau :\n";
		BubbleSort(b, n);
		Xuat_DS(b, n);
		break;
	case 8:
		system("cls");
		cout << "\n8. Xep thu hang mon hoc theo diem tong ket mon hoc\n";
		cout << "\nDanh sach sinh vien ban dau : \n";
		Xuat_DS(a, n);
		cout << "\nNhan phim bat ky de xuat Bang thu hang mon hoc...";
		_getch();
		cout << "\n\nBang thu hang mon hoc theo diem tong ket :\n";
		BubbleSort_TH(b, n);
		Xuat_DS_TH(b, n);
		break;
	default:
		break;
	}
	_getch();
}