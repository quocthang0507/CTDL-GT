#define MAX 100

struct NgayThangNam
{
	int ngay;
	int thang;
	unsigned int nam;
};

struct NhanVien
{
	char maNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	NgayThangNam ntns;
	char diaChi[15];
	double luong;
};

int DocTapTin(char *filename, NhanVien a[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	char maNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	char diaChi[15];
	double luong;
	int ngay;
	int thang;
	int nam;
	n = 0;
	in >> maNV; strcpy_s(a[n].maNV, maNV);
	in >> ho; strcpy_s(a[n].ho, ho);
	in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
	in >> ten; strcpy_s(a[n].ten, ten);
	in >> ngay; a[n].ntns.ngay = ngay;
	in >> thang; a[n].ntns.thang = thang;
	in >> nam; a[n].ntns.nam = nam;
	in >> diaChi; strcpy_s(a[n].diaChi, diaChi);
	in >> luong; a[n].luong = luong;
	while (!in.eof())
	{
		n++;
		in >> maNV; strcpy_s(a[n].maNV, maNV);
		in >> ho; strcpy_s(a[n].ho, ho);
		in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
		in >> ten; strcpy_s(a[n].ten, ten);
		in >> ngay; a[n].ntns.ngay = ngay;
		in >> thang; a[n].ntns.thang = thang;
		in >> nam; a[n].ntns.nam = nam;
		in >> diaChi; strcpy_s(a[n].diaChi, diaChi);
		in >> luong; a[n].luong = luong;
	}
	n++;
	in.close();
	return 1;
}

void XuatKeDoi()
{
	cout << "\n:";
	for (int i = 1; i <= 76; i++)
		cout << '=';
	cout << ":";
}

void XuatKeDon()
{
	cout << "\n:";
	for (int i = 1; i <= 76; i++)
		cout << '-';
	cout << ':';
}

void XuatTieuDe()
{
	XuatKeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma NV"
		<< ':'
		<< setw(10) << "Ho"
		<< setw(10) << "Ten lot"
		<< setw(10) << "Ten"
		<< ':'
		<< setw(10) << "Ngay sinh"
		<< ':'
		<< setw(15) << "Dia chi"
		<< ':'
		<< setw(9) << "Luong"
		<< ':';
	XuatKeDoi();
}

void Xuat_1NV(NhanVien a)
{
	cout << endl
		<< setiosflags(ios::left)
		<< ':'
		<< setw(8) << a.maNV
		<< ':'
		<< setw(10) << a.ho
		<< setw(10) << a.tenLot
		<< setw(10) << a.ten
		<< ':'
		<< setw(2) << a.ntns.ngay
		<< '/'
		<< setw(2) << a.ntns.thang
		<< '/'
		<< setw(4) << a.ntns.nam
		<< ':'
		<< setw(15) << a.diaChi
		<< ':'
		<< setw(9) << setiosflags(ios::fixed) << setprecision(0) << a.luong
		<< ':';
}

void Xuat_DS(NhanVien a[MAX], int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat_1NV(a[i]);
		if ((i + 1) % 5 == 0)
			XuatKeDon();
	}
	XuatKeDoi();
}

void Tim_Ho_Ten(NhanVien a[MAX], int n, char ho[10], char ten[10])
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].ten, ten) == 0)
	{
		kq = 1;
		break;
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co ho '" << ho << "' va ten '" << ten << "' trong danh sach";
	else
	{
		cout << "\nDanh sach nhung nhan vien co ho '" << ho << "' va ten '" << ten << "' trong danh sach : \n";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
		if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].ten, ten) == 0)
			Xuat_1NV(a[i]);
		XuatKeDoi();
	}
}

void Tim_NamSinh(NhanVien a[MAX], int n, unsigned namSinh)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i].ntns.nam == namSinh)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co nam sinh " << namSinh << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhung nhan vien co nam sinh " << namSinh << " trong danh sach : \n";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
		if (a[i].ntns.nam == namSinh)
			Xuat_1NV(a[i]);
		XuatKeDoi();
	}
}

void Tim_Ho_Ten_NamSinh(NhanVien a[MAX], int n, char ho[10], char ten[10], unsigned namSinh)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].ten, ten) == 0 && a[i].ntns.nam < namSinh)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co ho '" << ho << "' va ten '" << ten << "'"
		<< "\n va nam sinh < " << namSinh << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhung nhan vien co ho '" << ho << "' va ten '" << ten << "'"
			<< "\n va nam sinh < " << namSinh << " trong danh sach : \n";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
		if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].ten, ten) == 0 && a[i].ntns.nam < namSinh)
			Xuat_1NV(a[i]);
		XuatKeDoi();
	}
}

void Tim_Ten_DiaChi(NhanVien a[MAX], int n, char ten[10], char diaChi[15])
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(a[i].diaChi, diaChi) == 0 && _stricmp(a[i].ten, ten) == 0)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co ten '" << ten << "' o dia chi " << diaChi << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhung nhan vien co ten '" << ten << "' o dia chi " << diaChi << " trong danh sach : \n";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
		if (_stricmp(a[i].diaChi, diaChi) == 0 && _stricmp(a[i].ten, ten) == 0)
			Xuat_1NV(a[i]);
		XuatKeDoi();
	}
}

void Tim_Luong_NamSinh(NhanVien a[MAX], int n, double luong, unsigned namSinh)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i].luong >= luong&&a[i].ntns.nam <= namSinh)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co luong >= " << luong << " va nam sinh <= " << namSinh << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhung nhan vien co luong >= " << luong << " va nam sinh <= " << namSinh << " trong danh sach : \n";
		XuatTieuDe();
		for (int i = 0; i < n; i++)
		if (a[i].luong >= luong&&a[i].ntns.nam <= namSinh)
			Xuat_1NV(a[i]);
		XuatKeDoi();
	}
}

int KiemTraDayTang(NhanVien a[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
	{
		if (_stricmp(a[i].maNV, a[i + 1].maNV)>0)
		{
			kq = 0;
			break;
		}
	}
	return kq;
}

int KiemTraDayGiam(NhanVien a[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
	{
		if (_stricmp(a[i].maNV, a[i + 1].maNV) < 0)
		{
			kq = 0;
			break;
		}
	}
	return kq;
}

int TKNP_Tang(NhanVien a[MAX], int n, char maNV[8])
{
	int kq = -1, middle, left = 0, right = n - 1;
	do
	{
		middle = (left + right) / 2;
		if (_stricmp(a[middle].maNV, maNV) == 0)
		{
			kq = middle;
			break;
		}
		else
		if (_stricmp(a[middle].maNV, maNV) > 0)
			right = middle - 1;
		else
			left = middle + 1;
	} while (left <= right);
	return kq;
}

int TKNP_Giam(NhanVien a[MAX], int n, char maNV[8])
{
	int kq = -1, middle, left = 0, right = n - 1;
	do
	{
		middle = (left + right) / 2;
		if (_stricmp(a[middle].maNV, maNV) == 0)
		{
			kq = middle;
			break;
		}
		else
		if (_stricmp(a[middle].maNV, maNV) < 0)
			left = middle + 1;
		else
			right = middle - 1;
	} while (left <= right);
	return kq;
}

void Xuat_TKNP_maNV(NhanVien a[MAX], int n, int kq, char maNV[8])
{
	if (kq == -1)
	{
		cout << "\nKhong co nhan vien trong danh sach co ma nhan vien " << maNV;
		return;
	}
	else
	{
		cout << "\nThong tin nhan vien co ma nhan vien " << maNV << " : ";
		XuatTieuDe();
		Xuat_1NV(a[kq]);
		XuatKeDoi();
	}
}

void TKNP_MaNV(NhanVien a[MAX], int n, char maNV[8])
{
	int kq;
	if (!KiemTraDayGiam(a, n) && !KiemTraDayTang(a,n))
	{
		cout << "\nDay ma so nhan vien khong don dieu";
		cout << "\nDo do khong the su dung thuat giai tim kiem nhi phan";
		return;
	}
	if (KiemTraDayTang(a,n))
	{
		kq = TKNP_Tang(a, n, maNV);
		Xuat_TKNP_maNV(a, n, kq, maNV);
	}
	if (KiemTraDayGiam(a,n))
	{
		kq = TKNP_Giam(a, n, maNV);
		Xuat_TKNP_maNV(a, n, kq, maNV);
	}
}