void XuatMenu()
{
	cout << "\n==================== HE THONG CHUC NANG ====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n\t\tTHUAT TOAN SAP XEP";
	cout << "\n3. Chon truc tiep (Selection Straight sort)";
	cout << "\n4. Chen truc tiep (Insertion Straight sort)";
	cout << "\n5. Doi cho truc tiep (Interchange Straight sort)";
	cout << "\n6. Noi bot (Bubble sort)";
	cout << "\n7. Chen nhi phan (Binary Insertion sort)";
	cout << "\n8. Radix";
	cout << "\n============================================================";
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
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, DaySo a, int &n)
{
	char filename[15];
	int kq;
	DaySo b;
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
		cout << "\n1. Tao du lieu\n";
		do
		{
			cout << "\nNhap ten tap tin de mo : ";
			cin >> filename;
			kq = File_Array(filename, a, n);
			if (kq == 0)
				cout << "\nLoi mo tap tin!\n";
		} while (kq == 0);
		cout << "\nDay da nhap : \n";
		Output(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu\n";
		cout << "\nDay hien hanh : \n";
		Output(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Chon truc tiep (Selection Straight sort)\n";
		cout << "\nDay truoc khi sap xep : \n";
		Output(a, n);
		Selection_L(b, n);
		cout << "\nDay sau khi sap xep : \n";
		Output(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Chen truc tiep (Insertion Straight sort)\n";
		cout << "\nDay truoc khi sap xep : \n";
		Output(a, n);
		Insertion_L(b, n);
		cout << "\nDay sau khi sap xep : \n";
		Output(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Doi cho truc tiep (Interchange Straight sort)\n";
		cout << "\nDay truoc khi sap xep : \n";
		Output(a, n);
		Interchange_L(b, n);
		cout << "\nDay sau khi sap xep : \n";
		Output(b, n);
		break;
	case 6:
		system("cls");
		cout << "\n6. Noi bot (Bubble sort)\n";
		cout << "\nDay truoc khi sap xep : \n";
		Output(a, n);
		Bubble_L(b, n);
		cout << "\nDay sau khi sap xep : \n";
		Output(b, n);
		break;
	case 7:
		system("cls");
		cout << "\n7. Chen nhi phan (Binary Insertion sort)\n";
		cout << "\nDay truoc khi sap xep : \n";
		Output(a, n);
		Binary_Insertion(b, n);
		cout << "\nDay sau khi sap xep : \n";
		Output(b, n);
		break;
	case 8:
		system("cls");
		cout << "\n8. Radix\n";
		cout << "\nDay truoc khi sap xep : \n";
		Output(a, n);
		Radix(b, n);
		cout << "\nDay sau khi sap xep : \n";
		Output(b, n);
		break;
	default:
		break;
	}
	_getch();
}