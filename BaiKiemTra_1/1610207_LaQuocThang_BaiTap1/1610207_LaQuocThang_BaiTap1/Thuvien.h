#define MAX 100

struct NgayThangNam
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
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

void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 77; i++)
	{
		cout << '=';
	}
	cout << ':';
}

void Xuat_KeDon()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 77; i++)
	{
		cout << '-';
	}
	cout << ':';

}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma NV"
		<< ':'
		<< setw(10) << "Ho"
		<< ':'
		<< setw(10) << "Ten lot"
		<< ':'
		<< setw(8) << "Ten"
		<< ':'
		<< setw(15) << "Dia chi"
		<< ':'
		<< setw(3) << "NS"
		<< setw(3) << "TS"
		<< setw(4) << "NaS"
		<< ':'
		<< setw(10) << "Luong"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_1NV(NhanVien a)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << a.maNV
		<< ':'
		<< setw(11) << a.ho
		<< setw(11) << a.tenLot
		<< setw(9) << a.ten
		<< setw(15) << a.diaChi
		<< ':'
		<< setw(2) << a.ntns.ngay
		<< '/'
		<< setw(2) << a.ntns.thang
		<< '/'
		<< setw(4) << a.ntns.nam
		<< ':'
		<< setw(10) << setiosflags(ios::fixed) << setprecision(0) << a.luong
		<< ':';
}

void Xuat_DS(NhanVien a[MAX], int n)
{
	Xuat_TieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat_1NV(a[i]);
		if ((i + 1) % 5 == 0)
			Xuat_KeDon();
	}
	Xuat_KeDoi();
	cout << endl;
}

int Doc_File(char *filename, NhanVien a[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;

	char maNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	unsigned ngay;
	unsigned thang;
	unsigned nam;
	char diaChi[15];
	double luong;

	n = 0;
	in >> maNV; strcpy_s(a[n].maNV, maNV);
	in >> ho; strcpy_s(a[n].ho, ho);
	in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
	in >> ten; strcpy_s(a[n].ten, ten);
	in >> diaChi; strcpy_s(a[n].diaChi, diaChi);
	in >> ngay; a[n].ntns.ngay = ngay;
	in >> thang; a[n].ntns.thang = thang;
	in >> nam; a[n].ntns.nam = nam;
	in >> luong; a[n].luong = luong;

	while (!in.eof())
	{
		n++;
		in >> maNV; strcpy_s(a[n].maNV, maNV);
		in >> ho; strcpy_s(a[n].ho, ho);
		in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
		in >> ten; strcpy_s(a[n].ten, ten);
		in >> diaChi; strcpy_s(a[n].diaChi, diaChi);
		in >> ngay; a[n].ntns.ngay = ngay;
		in >> thang; a[n].ntns.thang = thang;
		in >> nam; a[n].ntns.nam = nam;
		in >> luong; a[n].luong = luong;
	}
	n++;
	in.close();
	return 1;
}

void Tim_DiaChi(NhanVien a[MAX], int n, char diaChi[15])
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	if (_stricmp(a[i].diaChi, diaChi) == 0)
	{
		kq = 1;
		break;
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co dia chi o '" << diaChi << "' trong danh sach";
	else
	{
		cout << "\nDanh sach nhan vien co dia chi o '" << diaChi << "' : \n";
		Xuat_TieuDe();
		for (int i = 0; i < n; i++)
		if (_stricmp(a[i].diaChi, diaChi) == 0)
			Xuat_1NV(a[i]);
		Xuat_KeDoi();
	}
}

void Tim_NamSinh(NhanVien a[MAX], int n, int namSinh)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	if (a[i].ntns.nam == namSinh)
	{
		kq = 1;
		break;
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co nam sinh " << namSinh << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhan vien co nam sinh " << namSinh << " : \n";
		Xuat_TieuDe();
		for (int i = 0; i < n; i++)
		if (a[i].ntns.nam == namSinh)
			Xuat_1NV(a[i]);
		Xuat_KeDoi();
	}
}

void Tim_Ten(NhanVien a[MAX], int n, char ten[10])
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	if (_stricmp(a[i].ten, ten) == 0)
	{
		kq = 1;
		break;
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co ten '" << ten << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhan vien co ten '" << ten << "' : \n";
		Xuat_TieuDe();
		for (int i = 0; i < n; i++)
		if (_stricmp(a[i].ten, ten) == 0)
			Xuat_1NV(a[i]);
		Xuat_KeDoi();
	}
}

void Tim_Ho_TenLot_Ten(NhanVien a[MAX], int n, char ho[10], char tenLot[10], char ten[10])
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].tenLot, tenLot) == 0 && _stricmp(a[i].ten, ten) == 0)
	{
		kq = 1;
		break;
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co ho va ten '" << ho << ' ' << tenLot << ' ' << ten << "' trong danh sach";
	else
	{
		cout << "\nDanh sach nhan vien co ho va ten '" << ho << ' ' << tenLot << ' ' << ten << "' : \n";
		Xuat_TieuDe();
		for (int i = 0; i < n; i++)
		if (_stricmp(a[i].ho, ho) == 0 && _stricmp(a[i].tenLot, tenLot) == 0 && _stricmp(a[i].ten, ten) == 0)
			Xuat_1NV(a[i]);
		Xuat_KeDoi();
	}
}

void Tim_Thang(NhanVien a[MAX], int n, int thang)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	if (a[i].ntns.thang == thang)
	{
		kq = 1;
		break;
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien sinh thang " << thang << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhan vien sinh thang " << thang << " : \n";
		Xuat_TieuDe();
		for (int i = 0; i < n; i++)
		if (a[i].ntns.thang == thang)
			Xuat_1NV(a[i]);
		Xuat_KeDoi();
	}
}

void Tim_Luong_NamSinh(NhanVien a[MAX], int n, double luong, int namSinh)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	if (a[i].luong >= luong&&a[i].ntns.nam <= namSinh)
	{
		kq = 1;
		break;
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co muc luong >= " << luong << " va nam sinh <= " << namSinh << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhan vien co muc luong >= " << luong << " va nam sinh <= " << namSinh << " : \n";
		Xuat_TieuDe();
		for (int i = 0; i < n; i++)
		if (a[i].luong >= luong&&a[i].ntns.nam <= namSinh)
			Xuat_1NV(a[i]);
		Xuat_KeDoi();
	}
}

int KiemTra_Tang(NhanVien a[MAX], int n, char maNV[8])
{ 
	int kq = 1;
	for (int i = 0; i < n-1; i++)
	{
		if (_stricmp(a[i + 1].maNV, a[i].maNV) < 0)
		{
			kq = 0;
			break;
		}
	}
	return kq;
}

int KiemTra_Giam(NhanVien a[MAX], int n, char maNV[8])
{
	int kq = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (_stricmp(a[i + 1].maNV, a[i].maNV) > 0)
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
		else if (_stricmp(maNV, a[middle].maNV) > 0)
			left = middle + 1;
		else right = middle - 1;
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
		else if (_stricmp(maNV, a[middle].maNV) > 0)
			right = middle + 1;
		else left = middle - 1;
	} while (left <= right);
	return kq;
}

void Xuat_DS_TKNP_TKNS(NhanVien a[MAX], int n, char maNV[8], int kq)
{
	if (kq == -1)
		cout << "\nKhong co nhan vien co ma nhan vien la " << maNV << " trong danh sach";
	else
	{
		cout << "\nKet qua tim duoc voi ma nhan vien " << maNV << " :\n";
		Xuat_TieuDe();
		Xuat_1NV(a[kq]);
		Xuat_KeDoi();
	}
}

void Tim_MaNV_TKNP(NhanVien a[MAX], int n, char maNV[8])
{
	int kq;
	if (!KiemTra_Giam(a, n, maNV) && !KiemTra_Tang(a, n, maNV))
	{
		cout << "\nDay ma nhan vien khong don dieu";
		cout << "\nDo do khong the dung tim kiem nhi phan ma nhan vien\n";
	}
	else if (KiemTra_Giam(a, n, maNV))
	{
		kq = TKNP_Giam(a, n, maNV);
		Xuat_DS_TKNP_TKNS(a, n, maNV, kq);
	}
	else
	{
		kq = TKNP_Tang(a, n, maNV);
		Xuat_DS_TKNP_TKNS(a, n, maNV, kq);
	}
}

double TachSo(char maNV[8])
{
	string chuoiSo = "";
	for (int i = 2; i < strlen(maNV); i++)
	{
		chuoiSo += maNV[i];
	}
	return stoi(chuoiSo);
}

int TKNS_Tang(NhanVien a[MAX], int n, char maNV[8])
{
	int kq = -1, middle, left = 0, right = n - 1;
	double t, dau, cuoi;
	do
	{
		t = TachSo(maNV);
		dau = TachSo(a[left].maNV);
		cuoi = TachSo(a[right].maNV);
		middle = left + (right - left)*(t - dau) / (cuoi - dau);
		if (_stricmp(a[middle].maNV, maNV) == 0)
		{
			kq = middle;
			break;
		}
		else if (_stricmp(maNV, a[middle].maNV) > 0)
			left = middle + 1;
		else right = middle - 1;
	} while (left <= right);
	return kq;
}

int TKNS_Giam(NhanVien a[MAX], int n, char maNV[8])
{
	int kq = -1, middle, left = 0, right = n - 1;
	double t, dau, cuoi;
	do
	{
		t = TachSo(maNV);
		dau = TachSo(a[left].maNV);
		cuoi = TachSo(a[right].maNV);
		middle = left + (right - left)*(t - dau) / (cuoi - dau);
		if (_stricmp(a[middle].maNV, maNV) == 0)
		{
			kq = middle;
			break;
		}
		else if (_stricmp(maNV, a[middle].maNV) > 0)
			right = middle + 1;
		else left = middle - 1;
	} while (left <= right);
	return kq;
}

void Tim_MaNV_TKNS(NhanVien a[MAX], int n, char maNV[8])
{
	int kq;
	if (!KiemTra_Giam(a, n, maNV) && !KiemTra_Tang(a, n, maNV))
	{
		cout << "\nDay ma nhan vien khong don dieu";
		cout << "\nDo do khong the dung tim kiem noi suy ma nhan vien\n";
	}
	else if (KiemTra_Giam(a, n, maNV))
	{
		kq = TKNS_Giam(a, n, maNV);
		Xuat_DS_TKNP_TKNS(a, n, maNV, kq);
	}
	else
	{
		kq = TKNS_Tang(a, n, maNV);
		Xuat_DS_TKNP_TKNS(a, n, maNV, kq);
	}
}