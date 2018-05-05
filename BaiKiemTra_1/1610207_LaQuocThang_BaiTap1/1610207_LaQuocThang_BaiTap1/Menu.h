void XuatMenu()
{
	cout << "\n======================= HE THONG CHUC NANG =======================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach nhan vien";
	cout << "\n2. Xem danh sach nhan vien";
	cout << "\n3. Xuat tat ca nhan vien co dia chi cho truoc";
	cout << "\n4. Xuat tat ca nhan vien co nam sinh cho truoc";
	cout << "\n5. Xuat tat ca nhan vien co ten cho truoc";
	cout << "\n6. Xuat tat ca nhan vien trung ho, ten lot va ten cho truoc";
	cout << "\n7. Xuat tat ca nhan vien co cung sinh nhat trong thang cho truoc";
	cout << "\n8. Xuat tat ca nhan vien co muc luong >=x va co nam sinh <=y";
	cout << "\n9. Tim kiem nhi phan theo ma nhan vien";
	cout << "\n10. Tim kiem noi suy theo ma nhan vien";
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

void XuLyMenu(int menu, NhanVien a[MAX], int &n)
{
	char filename[10], diaChi[15], ten[10], ho[10], tenLot[10], maNV[8];
	int kq = 0, namSinh, thang;
	double luong;
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		cout << "\nHen gap lai lan sau!\n";
		break;
	case 1:
		system("cls");
		cout << "\n1. Tao danh sach nhan vien\n";
		while (kq == 0)
		{
			cout << "\nNhap ten file can doc : ";
			cin >> filename;
			kq = Doc_File(filename, a, n);
			if (kq != 0)
			{
				cout << "\nDanh sach nhan duoc : \n";
				Xuat_DS(a, n);
			}
			else
			{
				cout << "\nLoi mo tap tin!\n";
				cout << "\n-----------------------\n";
			}
		}
		break;
	case 2:
		system("cls");
		cout << "\n2. Xem danh sach nhan vien\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		break;
	case 3:
		system("cls");
		cout << "\n3. Xuat tat ca nhan vien co dia chi cho truoc\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap dia chi can tim : ";
		cin >> diaChi;
		Tim_DiaChi(a, n, diaChi);
		break;
	case 4:
		system("cls");
		cout << "\n4. Xuat tat ca nhan vien co nam sinh cho truoc\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap nam sinh can tim : ";
		cin >> namSinh;
		Tim_NamSinh(a, n, namSinh);
		break;
	case 5:
		system("cls");
		cout << "\n5. Xuat tat ca nhan vien co ten cho truoc\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap ten can tim : ";
		cin >> ten;
		Tim_Ten(a, n, ten);
		break;
	case 6:
		system("cls");
		cout << "\n6. Xuat tat ca nhan vien trung ho, ten lot va ten cho truoc\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap ho : ";
		cin >> ho;
		cout << "\nNhap ten lot : ";
		cin >> tenLot;
		cout << "\nNhap ten : ";
		cin >> ten;
		Tim_Ho_TenLot_Ten(a, n, ho, tenLot, ten);
		break;
	case 7:
		system("cls");
		cout << "\n7. Xuat tat ca nhan vien co cung sinh nhat trong thang cho truoc\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap thang sinh can tim : ";
		cin >> thang;
		Tim_Thang(a, n, thang);
		break;
	case 8:
		system("cls");
		cout << "\n8. Xuat tat ca nhan vien co muc luong >=x va co nam sinh <=y\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap luong : ";
		cin >> luong;
		cout << "\nNhap nam sinh : ";
		cin >> namSinh;
		Tim_Luong_NamSinh(a, n, luong, namSinh);
		break;
	case 9:
		system("cls");
		cout << "\n9. Tim kiem nhi phan theo ma nhan vien\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap ma nhan vien can tim : ";
		cin >> maNV;
		Tim_MaNV_TKNP(a, n, maNV);
		break;
	case 10:
		system("cls");
		cout << "\n10. Tim kiem noi suy theo ma nhan vien\n";
		cout << "\nDanh sach hien co : \n";
		Xuat_DS(a, n);
		cout << "\nNhap ma nhan vien can tim : ";
		cin >> maNV;
		Tim_MaNV_TKNS(a, n, maNV);
		break;
	default:
		break;
	}
	_getch();
}