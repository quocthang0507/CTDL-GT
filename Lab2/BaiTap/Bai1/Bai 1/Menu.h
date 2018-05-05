void XuatMenu()
{
	cout << "\n=========================HE THONG CHUC NANG=========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem theo ho, ten";
	cout << "\n4. Tim kiem theo nam sinh";
	cout << "\n5. Tim kiem theo ho, ten va nam sinh";
	cout << "\n6. Tim kiem theo ten va dia chi";
	cout << "\n7. Tim kiem theo nam sinh va luong";
	cout << "\n8. Tim kiem nhi phan theo ma nhan vien";
	cout << "\n====================================================================";
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
	char filename[MAX], ho[10], ten[10], diaChi[15], maNV[8];
	int kq;
	double luong;
	unsigned namSinh;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao danh sach sinh vien\n";
		cout << "\nNhap ten tap tin filename = ";
		cin >> filename;
		kq = DocTapTin(filename, a, n);
		if (kq)
		{
			cout << "\nDanh sach nhan vien hien co : ";
			Xuat_DS(a,n);
		}
		else
			cout << "\nLoi mo file!";
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem danh sach sinh vien\n";
		cout << "\nDanh sinh nhan vien hien co : ";
		Xuat_DS(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Tim kiem theo ho, ten\n";
		cout << "\nNhap ho : ";
		cin >> ho;
		cout << "\nNhap ten : ";
		cin >> ten;
		Tim_Ho_Ten(a, n, ho, ten);
		break;
	case 4:
		system("cls");
		cout << "\n4. Tim kiem theo nam sinh\n";
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		Tim_NamSinh(a, n, namSinh);
		break;
	case 5:
		system("cls");
		cout << "\n5. Tim kiem theo ho, ten va nam sinh\n";
		cout << "\nNhap ho : ";
		cin >> ho;
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		Tim_Ho_Ten_NamSinh(a, n, ho, ten, namSinh);
		break;
	case 6:
		system("cls");
		cout << "\n6. Tim kiem theo ten va dia chi\n";
		cout << "\nNhap ten : ";
		cin >> ten;
		cout << "\nNhap dia chi : ";
		cin >> diaChi;
		Tim_Ten_DiaChi(a, n, ten, diaChi);
		break;
	case 7:
		system("cls");
		cout << "\n7. Tim kiem theo nam sinh va luong\n";
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		cout << "\nNhap luong : ";
		cin >> luong;
		Tim_Luong_NamSinh(a, n, luong, namSinh);
		break;
	case 8:
		system("cls");
		cout << "\n8. Tim kiem nhi phan theo ma nhan vien\n";
		cout << "\nNhap ma nhan vien : ";
		cin >> maNV;
		TKNP_MaNV(a, n, maNV);
		break;
	default:
		break;
	}
	_getch();
}