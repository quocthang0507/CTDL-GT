#define MAX 100

struct NhanVien
{
	char MaNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	char diaChi[15];
	unsigned namSinh;
	double luong;
};

int Doc_File(char *filename, NhanVien a[MAX], int &n);
void Xuat_KeDon();
void Xuat_KeDoi();
void Xuat_TieuDe();
void Xuat_1NV(NhanVien a);
void Xuat_DS(NhanVien a[MAX], int n);
void Copy(NhanVien b[MAX], NhanVien a[MAX], int n);
void SelectionSort(NhanVien a[MAX], int n);
void InsertionSort(NhanVien a[MAX], int n);
void Radix(NhanVien a[MAX], int n);
void QuickSort(NhanVien a[MAX], int l, int r);

int Doc_File(char *filename, NhanVien a[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;

	char MaNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	char diaChi[15];
	unsigned namSinh;
	double luong;

	n = 0;
	in >> MaNV; strcpy_s(a[n].MaNV, MaNV);
	in >> ho; strcpy_s(a[n].ho, ho);
	in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
	in >> ten; strcpy_s(a[n].ten, ten);
	in >> diaChi; strcpy_s(a[n].diaChi, diaChi);
	in >> namSinh; a[n].namSinh = namSinh;
	in >> luong; a[n].luong = luong;

	while (!in.eof())
	{
		n++;
		in >> MaNV; strcpy_s(a[n].MaNV, MaNV);
		in >> ho; strcpy_s(a[n].ho, ho);
		in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
		in >> ten; strcpy_s(a[n].ten, ten);
		in >> diaChi; strcpy_s(a[n].diaChi, diaChi);
		in >> namSinh; a[n].namSinh = namSinh;
		in >> luong; a[n].luong = luong;
	}
	n++;

	in.close();
	return 1;
}

void Xuat_KeDon()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 75; i++)
		cout << '-';
	cout << ':';
}

void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 75; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "MaNV"
		<< ':'
		<< setw(10) << "Ho"
		<< ':'
		<< setw(10) << "Ten lot"
		<< ':'
		<< setw(10) << "Ten"
		<< ':'
		<< setw(15) << "Dia chi"
		<< ':'
		<< setw(6) << "NSinh"
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
		<< setw(8) << a.MaNV
		<< ':'
		<< setw(10) << a.ho
		<< ':'
		<< setw(10) << a.tenLot
		<< ':'
		<< setw(10) << a.ten
		<< ':'
		<< setw(15) << a.diaChi
		<< ':'
		<< setw(6) << a.namSinh
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

void Copy(NhanVien b[MAX], NhanVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void SelectionSort(NhanVien a[MAX], int n)
{
	int cs_min, i, j;
	for (i = 0; i < n; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (_strcmpi(a[cs_min].MaNV, a[j].MaNV)>0)
				cs_min = j;
		swap(a[cs_min], a[i]);
	}
}

void InsertionSort(NhanVien a[MAX], int n)
{
	int i, pos;
	char x[15];
	for (i = 1; i < n; i++)
	{
		strcpy_s(x, a[i].diaChi);
		for (pos = i - 1; (pos >= 0) && (_strcmpi(a[pos].diaChi, x)>0); pos--)
			a[pos + 1] = a[pos];
		strcpy_s(a[pos + 1].diaChi, x);
	}
}

void Radix(NhanVien a[MAX], int n)
{
	int max = a[0].namSinh, m = 0, k = 0, i, j, du, thuong;
	int b0[MAX], b1[MAX], b2[MAX], b3[MAX], b4[MAX], b5[MAX], b6[MAX], b7[MAX], b8[MAX], b9[MAX];
	int p0, p1, p2, p3, p4, p5, p6, p7, p8, p9;
	for (i = 0; i < n; i++)
		if (a[i].namSinh>max)
			max = a[i].namSinh;
	while (max != 0)
	{
		max = max / 10;
		m++;
	}
	while (k < m)
	{
		p0 = p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = 0;
		for (i = 0; i < n; i++)
		{
			thuong = a[i].namSinh;
			for (j = 0; j <= k; j++)
			{
				du = thuong % 10;
				thuong = thuong / 10;
			}
			switch (du)
			{
			case 0:
				b0[p0++] = a[i].namSinh;
				break;
			case 1:
				b1[p1++] = a[i].namSinh;
				break;
			case 2:
				b2[p2++] = a[i].namSinh;
				break;
			case 3:
				b3[p3++] = a[i].namSinh;
				break;
			case 4:
				b4[p4++] = a[i].namSinh;
				break;
			case 5:
				b5[p5++] = a[i].namSinh;
				break;
			case 6:
				b6[p6++] = a[i].namSinh;
				break;
			case 7:
				b7[p7++] = a[i].namSinh;
				break;
			case 8:
				b8[p8++] = a[i].namSinh;
				break;
			case 9:
				b9[p9++] = a[i].namSinh;
				break;
			}
		}
		j = 0;
		for (i = 0; i < p0; i++)
			a[j++].namSinh = b0[i];
		for (i = 0; i < p1; i++)
			a[j++].namSinh = b1[i];
		for (i = 0; i < p2; i++)
			a[j++].namSinh = b2[i];
		for (i = 0; i < p3; i++)
			a[j++].namSinh = b3[i];
		for (i = 0; i < p4; i++)
			a[j++].namSinh = b4[i];
		for (i = 0; i < p5; i++)
			a[j++].namSinh = b5[i];
		for (i = 0; i < p6; i++)
			a[j++].namSinh = b6[i];
		for (i = 0; i < p7; i++)
			a[j++].namSinh = b7[i];
		for (i = 0; i < p8; i++)
			a[j++].namSinh = b8[i];
		for (i = 0; i < p9; i++)
			a[j++].namSinh = b9[i];
		k++;
	}
}

void QuickSort(NhanVien a[MAX], int l, int r)
{
	int i, j;
	double x;
	x = a[(l + r) / 2].luong;
	i = l; j = r;
	do
	{
		while (a[i].luong<x)
			i++;
		while (a[j].luong>x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
	for (int m = 0; m <= r; m++)
	for (int n = m + 1; n<r; n++)
	if (a[m].luong == a[n].luong)
	{
		if (_strcmpi(a[m].ten, a[n].ten) > 0)
			swap(a[m], a[n]);
		else if (_strcmpi(a[m].ten, a[n].ten) == 0)
		{
			if (_strcmpi(a[m].ho, a[n].ho) > 0)
				swap(a[m], a[n]);
			else if (_strcmpi(a[m].ho, a[n].ho) == 0)
			{
				if (a[m].namSinh > a[n].namSinh)
					swap(a[m], a[n]);
			}
		}
	}
}