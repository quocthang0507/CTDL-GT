void XuatMenu()
{
	cout << "==================HE THONG CHUC NANG==================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap vao day so";
	cout << "\n2. Chen mot so vao dau day";
	cout << "\n3. Chen mot so vao cuoi day";
	cout << "\n4. Chen mot so vao day tai mot vi tri quy dinh";
	cout << "\n5. Xoa phan tu dau day";
	cout << "\n6. Xoa phan tu cuoi day";
	cout << "\n7. Xoa phan tu tai vi tri cho truoc";
	cout << "\n8. Xuat cac gia tri khac nhau trong day va so lan xuat hien cua no";
	cout << "\n====================================================";
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

void XuLyMenu(int menu, DaySo a, int &n)
{
	int vt, gt;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:		
		system("cls");
		cout << "\n1. Nhap vao day so\n";
		NhapDay(a, n);
		XuatDay(a, n);
		break;
	case 2:
		system("cls");
		cout << "\n2. Chen mot so vao dau day\n";
		cout << "\nNhap gia tri can chen tai dau chuoi = ";
		cin >> gt;
		ChenTaiX(a, n, 0, gt);
		XuatDay(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Chen mot so vao cuoi day\n";
		cout << "\nNhap gia tri can chen tai cuoi chuoi = ";
		cin >> gt;
		ChenTaiX(a, n, n, gt);
		XuatDay(a, n);
		break;
	case 4:
		system("cls");
		cout << "\n4. Chen mot so vao day tai mot vi tri quy dinh\n";
		cout << "\nNhap vi tri can chen = ";
		cin >> vt;
		cout << "\nNhap gia tri can chen tai vi tri " << vt << " = ";
		cin >> gt;
		ChenTaiX(a, n, vt, gt);
		XuatDay(a, n);
		break;
	case 5:
		system("cls");
		cout << "\n5. Xoa phan tu dau day\n";
		cout << "\nXem lai day : ";
		XuatDay(a, n);
		XoaTaiX(a, n, 0);
		XuatDay(a, n);
		break;
	case 6:
		system("cls");
		cout << "\n6. Xoa phan tu cuoi day\n";
		cout << "\nXem lai day : ";
		XuatDay(a, n);
		XoaTaiX(a, n, n);
		XuatDay(a, n);
		break;
	case 7:
		system("cls");
		cout << "\n7. Xoa phan tu tai vi tri cho truoc\n";
		cout << "\nNhap vi tri can xoa = ";
		cin >> vt;
		cout << "\nXem lai day : ";
		XuatDay(a, n);
		XoaTaiX(a, n, vt);
		XuatDay(a, n);
		break;
	case 8:
		system("cls");
		cout << "\n8. Xuat cac gia tri khac nhau trong day va so lan xuat hien cua no\n";
		PhanBiet(a, n);
		break;
	default:
		break;
	}
	_getch();
}