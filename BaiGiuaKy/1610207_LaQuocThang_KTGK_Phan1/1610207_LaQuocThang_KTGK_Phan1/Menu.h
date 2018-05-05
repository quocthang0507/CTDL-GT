void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao bang diem mon hoc";
	cout << "\n2. Xem bang diem mon hoc";
	cout << "\n3. Sua ten sinh vien trong bang diem voi ma sinh vien cho truoc";
	cout << "\n4. Cat sinh vien cuoi cung va chen vao dau bang diem";
	cout << "\n5. Xoa cac sinh vien co diem thap nhat ra khoi bang diem mon hoc";
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

void XuLyMenu(int menu, LIST &l)
{
	int kq;
	char maSV[11];
	data x;
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Tao bang diem mon hoc\n";
		DocFile("Text.txt", l);
		Xuat_DS(l);
		break;
	case 2:
		cout << "\n2. Xem bang diem mon hoc\n";
		Xuat_DS(l);
		break;
	case 3:
		cout << "\n3. Sua ten sinh vien trong bang diem voi ma sinh vien cho truoc\n";
		cout << "\nDanh sach sinh vien ban dau : \n";
		Xuat_DS(l);
		cout << "\n\nNhap ma sinh vien can thay doi ten : ";
		_flushall();
		gets_s(maSV, 11);
		kq = Tim_MSSV_Doi_Ten(l, maSV);
		if (kq == 1)
		{
			cout << "\nDanh sach sinh vien moi cap nhat : \n";
			Xuat_DS(l);
		}
		break;
	case 4:
		cout << "\n4. Cat sinh vien cuoi cung va chen vao dau bang diem\n";
		cout << "\nDanh sach sinh vien ban dau : \n";
		Xuat_DS(l);
		x = RemoveTail(l);
		AddHead(l, x);
		cout << "\nDanh sach sinh vien moi cap nhat : \n";
		Xuat_DS(l);
		break;
	case 5:
		cout << "\n5. Xoa cac sinh vien co diem thap nhat ra khoi bang diem mon hoc\n";
		cout << "\nDanh sach sinh vien ban dau : \n";
		Xuat_DS(l);
		Xoa_SV_DiemThap(l);
		cout << "\nDanh sach sinh vien moi cap nhat : \n";
		Xuat_DS(l);
		break;
	default:
		break;
	}
	_getch();
}