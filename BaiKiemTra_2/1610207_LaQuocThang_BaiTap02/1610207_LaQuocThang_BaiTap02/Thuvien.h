#define MAX 100

struct NTNS
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
};

struct SinhVien
{
	char MaSV[8];
	char ho[11];
	char tenLot[11];
	char ten[11];
	NTNS ntns;
	char lop[7];
	float diem;
};

int Doc_File(char *filename, SinhVien a[MAX], int &n);
void SaoChep(SinhVien b[MAX], SinhVien a[MAX], int n);
void Xuat_KeDon();
void Xuat_KeDoi();
void Xuat_TieuDe();
void Xuat_1SV(SinhVien a);
void Xuat_DS(SinhVien a[MAX], int n);
void QuickSort(SinhVien a[MAX], int l, int r);
void InsertionSort(SinhVien a[MAX], int n);
void Shift(SinhVien a[MAX], int l, int r);
void Create_Heap(SinhVien a[MAX], int n);
void HeapSort(SinhVien a[MAX], int n);
void Selection(SinhVien a[MAX], int n);
void BubbleSort(SinhVien a[MAX], int n);
void Xuat_TieuDe_TH();
void Xuat_1SV_TH(SinhVien a, int th);
void Xuat_DS_TH(SinhVien a[MAX], int n);
void BubbleSort_TH(SinhVien a[MAX], int n);

int Doc_File(char *filename, SinhVien a[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;

	char MaSV[8];
	char ho[11];
	char tenLot[11];
	char ten[11];
	unsigned ngay;
	unsigned thang;
	unsigned nam;
	char lop[7];
	float diem;

	n = 0;
	in >> MaSV; strcpy_s(a[n].MaSV, MaSV);
	in >> ho; strcpy_s(a[n].ho, ho);
	in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
	in >> ten; strcpy_s(a[n].ten, ten);
	in >> ngay; a[n].ntns.ngay = ngay;
	in >> thang; a[n].ntns.thang = thang;
	in >> nam; a[n].ntns.nam = nam;
	in >> lop; strcpy_s(a[n].lop, lop);
	in >> diem; a[n].diem = diem;

	while (!in.eof())
	{
		n++;
		in >> MaSV; strcpy_s(a[n].MaSV, MaSV);
		in >> ho; strcpy_s(a[n].ho, ho);
		in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
		in >> ten; strcpy_s(a[n].ten, ten);
		in >> ngay; a[n].ntns.ngay = ngay;
		in >> thang; a[n].ntns.thang = thang;
		in >> nam; a[n].ntns.nam = nam;
		in >> lop; strcpy_s(a[n].lop, lop);
		in >> diem; a[n].diem = diem;
	}
	n++;

	in.close();
	return 1;
}

void SaoChep(SinhVien b[MAX], SinhVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void Xuat_KeDon()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 73; i++)
		cout << '-';
	cout << ':';
}

void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 73; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << "MSSV"
		<< ':'
		<< setw(10) << "Ho"
		<< ':'
		<< setw(10) << "Ten lot"
		<< ':'
		<< setw(10) << "Ten"
		<< ':'
		<< setw(12) << "Ngay sinh"
		<< ':'
		<< setw(10) << "Lop"
		<< ':'
		<< setw(5) << "Diem"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_1SV(SinhVien a)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << a.MaSV
		<< ':'
		<< setw(10) << a.ho
		<< ':'
		<< setw(10) << a.tenLot
		<< ':'
		<< setw(10) << a.ten
		<< ':'
		<< setw(2) << a.ntns.ngay
		<< '/'
		<< setw(2) << a.ntns.thang
		<< '/'
		<< setw(6) << a.ntns.nam
		<< ':'
		<< setw(10) << a.lop
		<< ':'
		<< setw(5) << a.diem
		<< ':';
}

void Xuat_DS(SinhVien a[MAX], int n)
{
	Xuat_TieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat_1SV(a[i]);
		if ((i + 1) % 5 == 0)
			Xuat_KeDon();
	}
	Xuat_KeDoi();
	cout << endl;
}

void QuickSort(SinhVien a[MAX], int l, int r)
{
	int i, j;
	float x;
	x = a[(l + r) / 2].diem;
	i = l; j = r;
	do
	{
		while (a[i].diem < x) i++;
		while (a[j].diem > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j) QuickSort(a, l, j);
	if (i < r) QuickSort(a, i, r);
}

void InsertionSort(SinhVien a[MAX], int n)
{
	int t, vt;
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i; j++)
			if (a[i].ntns.nam < a[j].ntns.nam)
			{
				t = a[i].ntns.nam;
				vt = i;
				while (vt != j)
				{
					a[vt] = a[vt - 1];
					vt--;
				}
				a[j].ntns.nam = t;
			}
}

void Shift(SinhVien a[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	i = l; j = 2 * i + 1;
	x = a[i];
	while (j <= r)
	{
		if (j < r)
			if (_strcmpi(a[j].MaSV, a[j + 1].MaSV) < 0)
				j = j + 1;
		if (_strcmpi(a[j].MaSV, x.MaSV) <= 0)
			return;
		else
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
			a[i] = x;
		}
	}
}

void Create_Heap(SinhVien a[MAX], int n)
{
	int l;
	l = (n - 1) / 2;
	while (l >= 0)
	{
		Shift(a, l, n - 1);
		l = l - 1;
	}
}

void HeapSort(SinhVien a[MAX], int n)
{

	int r, i = 0;
	Create_Heap(a, n);
	r = n - 1;
	while (r > 0)
	{
		i++;
		swap(a[0], a[r]);
		r = r - 1;
		Shift(a, 0, r);
	}
}

void Selection(SinhVien a[MAX], int n)
{
	int cs_min;
	for (int i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (int j = i + 1; j < n; j++)
			if (_strcmpi(a[j].lop, a[cs_min].lop) < 0)
				cs_min = j;
		swap(a[i], a[cs_min]);
	}
}

void BubbleSort(SinhVien a[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (_strcmpi(a[j].ten, a[j - 1].ten) < 0)
				swap(a[j], a[j - 1]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (_strcmpi(a[i].ten, a[j].ten) == 0)
			{
				if (_strcmpi(a[i].ho, a[j].ho)>0)
					swap(a[i], a[j]);
				else if (_strcmpi(a[i].ho, a[j].ho) == 0)
					if (_strcmpi(a[i].tenLot, a[j].tenLot)>0)
						swap(a[i], a[j]);
			}
}

void Xuat_TieuDe_TH()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(4) << "TH"
		<< ':'
		<< setw(9) << "MSSV"
		<< ':'
		<< setw(10) << "Ho"
		<< ':'
		<< setw(10) << "Ten lot"
		<< ':'
		<< setw(10) << "Ten"
		<< ':'
		<< setw(10) << "Ngay sinh"
		<< ':'
		<< setw(8) << "Lop"
		<< ':'
		<< setw(5) << "Diem"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_1SV_TH(SinhVien a, int th)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(4) << th
		<< ':'
		<< setw(9) << a.MaSV
		<< ':'
		<< setw(10) << a.ho
		<< ':'
		<< setw(10) << a.tenLot
		<< ':'
		<< setw(10) << a.ten
		<< ':'
		<< setw(2) << a.ntns.ngay
		<< '/'
		<< setw(2) << a.ntns.thang
		<< '/'
		<< setw(4) << a.ntns.nam
		<< ':'
		<< setw(8) << a.lop
		<< ':'
		<< setw(5) << a.diem
		<< ':';
}

int Dem_CungTH(SinhVien a[MAX], int n, float diem)
{
	int count = 0, i;
	for (i = 0; i < n; i++)
		if (a[i].diem == diem)
			break;
	while (a[i].diem == diem)
	{
		count++;
		i++;
	}
	return count;
}

void Xuat_DS_TH(SinhVien a[MAX], int n)
{
	Xuat_TieuDe_TH();
	int k, th = 1;
	for (int i = 0; i < n;)
	{
		k = Dem_CungTH(a, n, a[i].diem);
		for (int j = 1; j <= k; j++, i++)
		{
			Xuat_1SV_TH(a[i], th);
			if ((i + 1) % 5 == 0)
				Xuat_KeDon();
		}
		th += k;
	}
	Xuat_KeDoi();
	cout << endl;
}

void BubbleSort_TH(SinhVien a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (a[j].diem > a[j - 1].diem)
				swap(a[j], a[j - 1]);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (a[i].diem == a[j].diem)
				if (_strcmpi(a[i].MaSV, a[j].MaSV) > 0)
					swap(a[i], a[j]);
}