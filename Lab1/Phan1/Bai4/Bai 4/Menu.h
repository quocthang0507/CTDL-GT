void XuatMenu()
{
	cout << "=====================HE THONG CHUC NANG=====================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap chuoi";
	cout << "\n2. Xem chuoi";
	cout << "\n3. Tinh chieu dai chuoi";
	cout << "\n4. Dao nguoc chuoi";
	cout << "\n5. Chep chuoi s sang chuoi t";
	cout << "\n6. So sanh 2 chuoi (co phan biet chu hoa)";
	cout << "\n7. So sanh 2 chuoi (khong phan biet chu hoa)";
	cout << "\n8. Noi chuoi s vao sau chuoi t";
	cout << "\n==========================================================";
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
		{
			break;
		}
	}
	return stt;
}

void XuLyMenu(int menu, Chuoi s, Chuoi t)
{
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Nhap chuoi\n";
		cout << "\nMoi ban nhap chuoi s : ";
		_flushall();
		gets_s(s, MAX);
		cout << "\nMoi ban nhap chuoi t : ";
		_flushall();
		gets_s(t, MAX);
		//break;
	case 2:
		system("cls");
		cout << "\n2. Xem chuoi\n";
		cout << "\nChuoi da nhap : ";
		cout << "\nChuoi s : " << s
			<< "\nChuoi t : " << t;
		break;
	case 3:
		system("cls");
		cout << "\n3. Tinh chieu dai chuoi\n";
		cout << "\nChieu dai cua : "
			<< "\nChuoi s : " << ChieuDai(s)
			<< "\nCHuoi t : " << ChieuDai(t);
		break;
	case 4:
		system("cls");
		cout << "\n4. Dao nguoc chuoi\n";
		DaoChuoi(s); DaoChuoi(t);
		cout << "\nChuoi da dao nguoc : "
			<< "\nChuoi s : " << s
			<< "\nChuoi t : " << t;
		break;
	case 5:
		system("cls");
		cout << "\n5. Chep chuoi s sang chuoi t\n";
		ChepChuoi(s, t);
		cout << "\nChuoi da chep : "
			<< "\nChuoi s : " << s
			<< "\nChuoi t : " << t;
		break;
	case 6:
		system("cls");
		cout << "\n6. So sanh 2 chuoi (co phan biet chu hoa)\n";
		cout << "\nKet qua so sanh : "
			<< "Chuoi s " 
			<< SoSanh_Co(s, t)
			<< " Chuoi t ";
		break;
	case 7:
		system("cls");
		cout << "\n7. So sanh 2 chuoi (khong phan biet chu hoa)\n";
		cout << "\nKet qua so sanh : "
			<< "Chuoi s "
			<< SoSanh_Khong(s, t)
			<< " Chuoi t ";
		break;
	case 8:
		system("cls");
		cout << "\n8. Noi chuoi s vao sau chuoi t\n";
		NoiChuoi(s, t);
		cout << "\nChuoi sau khi noi : "
			<< "\nChuoi s : " << s
			<< "\nChuoi t : " << t;
		break;
	default:
		break;
	}
	_getch();
}