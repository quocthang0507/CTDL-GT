void XuatMenu()
{
	cout << "\n======================= HE THONG CHUC NANG =======================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n\t\t\tTHUAT TOAN SAP XEP";
	cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n5. Thuat giai Chon hai dau";
	cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
	cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
	cout << "\n8. Thuat giai Chen nhi phan";
	cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n11. Thuat giai Bubble - tai moi buoc dua GTNN ve dau mang";
	cout << "\n12. Thuat giai i Bubble - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n==================================================================";
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
		if (0<=stt&&stt<=soMenu)
		{
			break;
		}
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
		cout << "\n0. Thoat khoi chuong trinh";
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
		cout << "\nDay da tao  : ";
		XuatMang(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem du lieu\n";
		cout << "\nDay hien hanh : ";
		XuatMang(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Selection_L(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Selection_R(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Thuat giai Chon hai dau\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Selection_R_L(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 6:
		system("cls");
		cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Insertion_L(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 7:
		system("cls");
		cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Insertion_R(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 8:
		system("cls");
		cout << "\n8. Thuat giai Chen nhi phan\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		BinaryInsertion(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 9:
		system("cls");
		cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Interchange_L(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 10:
		system("cls");
		cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Interchange_R(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 11:
		system("cls");
		cout << "\n11. Thuat giai Bubble - tai moi buoc dua GTNN ve dau mang\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Bubble_L(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	case 12:
		system("cls");
		cout << "\n12. Thuat giai i Bubble - tai moi buoc dua GTLN ve cuoi mang\n";
		cout << "\nDay so truoc khi sap xep : ";
		XuatMang(a, n);
		Bubble_R(b, n);
		cout << "\nDay so sau khi sap xep : ";
		XuatMang(b, n);
		break;
	default:
		break;
	}
	_getch();
}