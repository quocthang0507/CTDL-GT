void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu tu tap tin cho da thuc";
	cout << "\n2. Xem da thuc da nhap";
	cout << "\n\t\tCAC THAO TAC TREN HAI DA THUC";
	cout << "\n3. Tong hai da thuc";
	cout << "\n4. Hieu hai da thuc";
	cout << "\n5. Tich hai da thuc";
	cout << "\n6. Tinh dao ham hai da thuc";
	cout << "\n7. Tinh tich phan hai da thuc";
	cout << "\n8. Tinh gia tri da thuc tai x";
	cout << "\n======================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (1)
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

void XuLyMenu(int menu, Polynome &a, Polynome &b)
{
	system("cls");
	Polynome kq;
	CreatPoly(kq);
	double x;
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		cout << "\nHen gap lai lan sau\n";
		break;
	case 1:
		cout << "\n1. Nhap du lieu tu tap tin cho da thuc\n";
		Doc_File("A.txt", a);
		Doc_File("B.txt", b);
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		break;
	case 2:
		cout << "\n2. Xem da thuc da nhap\n";
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		break;
	case 3:
		cout << "\n3. Tong hai da thuc\n";
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		kq = Tong_2DT(a, b);
		cout << "\n\nA(x) + B(x) = ";
		Xuat_DT(kq);
		break;
	case 4:
		cout << "\n4. Hieu hai da thuc\n";
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		kq = Hieu_2DT(a, b);
		cout << "\n\nA(x) - B(x) = ";
		Xuat_DT(kq);
		break;
	case 5:
		cout << "\n5. Tich hai da thuc\n";
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		kq = Tich_2DT(a, b);
		cout << "\n\nA(x) x B(x) = ";
		Xuat_DT(kq);
		break;
	case 6:
		cout << "\n6. Tinh dao ham hai da thuc\n";
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDao ham cua da thuc dau tien A(x)' = ";
		kq = DaoHam_DT(a);
		Xuat_DT(kq);
		cout << "\n\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		cout << "\nDao ham cua da thuc thu hai B(x)' = ";
		kq = DaoHam_DT(b);
		Xuat_DT(kq);
		break;
	case 7:
		cout << "\n7. Tinh tich phan hai da thuc\n";
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		break;
	case 8:
		cout << "\n8. Tinh gia tri da thuc tai x\n";
		cout << "\nDa thuc dau tien A(x) = ";
		Xuat_DT(a);
		cout << "\nDa thuc thu hai B(x) = ";
		Xuat_DT(b);
		cout << "\n\nNhap gia tri cho x = ";
		cin >> x;
		cout << "\nA(" << x << ") = " << GT_DT_x(a, x);
		cout << "\nB(" << x << ") = " << GT_DT_x(b, x);
		break;
	default:
		break;
	}
	_getch();
}