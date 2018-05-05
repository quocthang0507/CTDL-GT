 #define MAX 100

struct SinhVien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;
};

int TapTin_MangCT(char *filename, SinhVien a[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;
	n = 0;
	in >> maSV; strcpy_s(a[n].maSV, maSV);
	in >> hoSV; strcpy_s(a[n].hoSV, hoSV);
	in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
	in >> ten; strcpy_s(a[n].ten, ten);
	in >> lop; strcpy_s(a[n].lop, lop);
	in >> namSinh; a[n].namSinh = namSinh;
	in >> dtb; a[n].dtb = dtb;
	in >> tichLuy; a[n].tichLuy = tichLuy;
	while (!in.eof())
	{
		n++;
		in >> maSV; strcpy_s(a[n].maSV, maSV);
		in >> hoSV; strcpy_s(a[n].hoSV, hoSV);
		in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
		in >> ten; strcpy_s(a[n].ten, ten);
		in >> lop; strcpy_s(a[n].lop, lop);
		in >> namSinh; a[n].namSinh = namSinh;
		in >> dtb; a[n].dtb = dtb;
		in >> tichLuy; a[n].tichLuy = tichLuy;
	} n++;
	in.close();
	return 1;
}

void TieuDe()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma SV"
		<< ':'
		<< setw(30) << " Ho va Ten sinh vien"
		<< ':'
		<< setw(10) << "Lop"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':'
		<< setw(8) << "TichLuy"
		<< ':';
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Xuat_SV(SinhVien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << p.maSV
		<< ':'
		<< setw(10) << p.hoSV
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< ':'
		<< setw(10) << p.lop
		<< ':'
		<< setw(6) << p.namSinh
		<< ':'
		<< setw(6) << setprecision(2) << p.dtb
		<< ':'
		<< setw(8) << p.tichLuy
		<< ':';
}

void XuatKeDoi()
{
	cout << ':';
	for (int i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << endl;
}

void Xuat_DSSV(SinhVien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		Xuat_SV(a[i]);
		cout << '\n';
	}
	XuatKeDoi();
}

int Tim_MaSo_DauTien(char maSV[10], SinhVien a[MAX], int n)
{
	int i = 0;
	while ((i < n) && (_stricmp(a[i].maSV, maSV)))
		i++;
	if (i == n)
		return -1;
	return i;
}

void Tim_TheoTen(char ten[10], SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].ten, ten) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co ten sinh vien : " << ten;
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co ten : " << ten << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].ten, ten) == 0)
			{
				Xuat_SV(a[i]);
				cout << endl;
			}
		XuatKeDoi();
	}
}

void Tim_TheoHo(char hoSV[10], SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].hoSV, hoSV) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co sinh vien mang ho : " << hoSV;
	else
	{
		cout << "\nCac sinh vien trong danh sach mang ho : " << hoSV << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].hoSV, hoSV) == 0)
			{
				Xuat_SV(a[i]);
				cout << endl;
			}
		XuatKeDoi();
	}
}

void Tim_TheoDTB(double dtb, SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
	{
		if (a[i].dtb >= dtb)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nDanh sach khong co sinh vien co diem trung binh >= : " << dtb;
	else
	{
		cout << "\nCac sinh vien trong danh sach co diem trung binh >= : " << dtb << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (a[i].dtb >= dtb)
			{
				Xuat_SV(a[i]);
				cout << endl;
			}
		XuatKeDoi();
	}
}

void Tim_TheoLop(char lop[6], SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].lop, lop) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co sinh vien mang lop : " << lop;
	else
	{
		cout << "\nCac sinh vien trong danh sach mang lop : " << lop << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].lop, lop) == 0)
			{
				Xuat_SV(a[i]);
				cout << endl;
			}
		XuatKeDoi();
	}
}

int KiemTraDayTang(int x[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
		if (x[i]>x[i + 1])
		{
			kq = 0;
			break;
		}
	return kq;
}

int KiemTraDayGiam(int x[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
		if (x[i] < x[i + 1])
		{
			kq = 0;
			break;
		}
	return kq;
}

int TKNP_Tang(int x[MAX], int n, int tichLuy)
{
	int kq = -1, midle, left = 0, right = n - 1;
	do
	{
		midle = (left + right) / 2;
		if (tichLuy == x[midle])
		{
			kq = midle;
			break;
		}
		else
		if (tichLuy < x[midle])
			right = midle - 1;
		else
			left = midle + 1;
	} while (left <= right);
	return kq;
}

int TKNP_Giam(int x[MAX], int n, int tichLuy)
{
	int kq = -1, middle, left = 0, right = n - 1;
	do
	{
		middle = (left + right) / 2;
		if (tichLuy == x[middle])
		{
			kq = middle;
			break;
		}
		else
		if (tichLuy < x[middle])
			left = middle + 1;
		else
			right = middle - 1;
	} while (left <= right);
	return kq;
}

void Xuat_TKNP_Theo_TichLuy(int tichLuy, SinhVien a[MAX], int n, int kq)
{
	if (kq == -1)
	{
		cout << "\nKhong co sinh vien trong danh sach co so TC tich luy = " << tichLuy << " :\n";
		return;
	}
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co so TC tich luy = " << tichLuy << " :\n";
		TieuDe();
		Xuat_SV(a[kq]);
		cout << endl;
		XuatKeDoi();
		return;
	}
}

void TKNP_Theo_TichLuy(SinhVien a[MAX], int n)
{
	int i, kq;
	int x[MAX];
	for (i = 0; i < n; i++)
		x[i] = a[i].tichLuy;
	if (!KiemTraDayGiam(x, n) && !KiemTraDayTang(x, n))
	{
		cout << "\nDay so nguyen tao boi truong tich luy khong don dieu";
		cout << "\nKhong su dung duoc thuat giai tim kiem nhi phan!\n";
		return;
	}
	int tichLuy;
	cout << "\nNhap so tich luy : ";
	cin >> tichLuy;
	if (KiemTraDayTang(x, n))
	{
		kq = TKNP_Tang(x, n, tichLuy);
		Xuat_TKNP_Theo_TichLuy(tichLuy, a, n, kq);
	}
	if (KiemTraDayGiam(x, n))
	{
		kq = TKNP_Giam(x, n, tichLuy);
		Xuat_TKNP_Theo_TichLuy(tichLuy, a, n, kq);
	}
}