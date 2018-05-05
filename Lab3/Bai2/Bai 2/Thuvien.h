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

int DocFile(char *filename, SinhVien a[MAX], int &n);
void Xuat_KeDon();
void Xuat_KeDoi();
void Xuat_TieuDe();
void Xuat_1SV(SinhVien a);
void Xuat_DS(SinhVien a[MAX], int n);
void Copy(SinhVien b[MAX], SinhVien a[MAX], int n);
void Partition(SinhVien a[MAX], int l, int r);
void QuickSort(SinhVien a[MAX], int n);
void Shift(SinhVien a[MAX], int l, int r);
void Create_Heap(SinhVien a[MAX], int n);
void HeapSort(SinhVien a[MAX], int n);
void Distribution(SinhVien f[MAX], int n, SinhVien f1[MAX], int &h1, SinhVien f2[MAX], int &h2, int p);
void Merge(SinhVien f1[MAX], int h1, SinhVien f2[MAX], int h2, SinhVien f[MAX], int p);
void MergeSort(SinhVien a[MAX], int n);

int DocFile(char *filename, SinhVien a[MAX], int &n)
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
	}
	n++;
	in.close();
	return 1;
}

void Xuat_KeDon()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << '-';
	cout << ':';
}

void Xuat_KeDoi()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << '=';
	cout << ':';
}

void Xuat_TieuDe()
{
	Xuat_KeDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma SV"
		<< ':'
		<< setw(11) << "Ho"
		<< ':'
		<< setw(11) << "Ten lot"
		<< ':'
		<< setw(11) << "Ten"
		<< ':'
		<< setw(6) << "Lop"
		<< ':'
		<< setw(6) << "NSinh"
		<< ':'
		<< setw(5) << "DTB"
		<< ':'
		<< setw(5) << "TL"
		<< ':';
	Xuat_KeDoi();
}

void Xuat_1SV(SinhVien a)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << a.maSV
		<< ':'
		<< setw(11) << a.hoSV
		<< ':'
		<< setw(11) << a.tenLot
		<< ':'
		<< setw(11) << a.ten
		<< ':'
		<< setw(6) << a.lop
		<< ':'
		<< setw(6) << a.namSinh
		<< ':'
		<< setw(5) << a.dtb
		<< ':'
		<< setw(5) << a.tichLuy
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

void Copy(SinhVien b[MAX], SinhVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void Partition(SinhVien a[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	x = a[(l + r) / 2];
	i = l;
	j = r;
	do
	{
		while (a[i].dtb < x.dtb)
			i++;
		while (a[j].dtb > x.dtb)
			j--;
		if (i<=j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i<=j);
	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);
}

void QuickSort(SinhVien a[MAX], int n)
{
	Partition(a, 0, n - 1);
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
			if (a[j].dtb < a[j + 1].dtb)
				j = j + 1;
		if (a[j].dtb <= x.dtb)
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

void Distribution(SinhVien f[MAX], int n, SinhVien f1[MAX], int &h1, SinhVien f2[MAX], int &h2, int p)
{
	int i, k = 1, l = 0;
	h1 = 0; h2 = 0;
	do
	{
		i = 1;
		while (i <= p && l < n)
		{
			if (k == 1)
				f1[h1++] = f[l];
			else
				f2[h2++] = f[l];
			i++;
			l++;
		}
		k = 3 - k;
	} while (l < n);
}

void Merge(SinhVien f1[MAX], int h1, SinhVien f2[MAX], int h2, SinhVien f[MAX], int p)
{
	int i1 = 0, i2 = 0, r1, r2, h = 0;
	while (i1 < h1 && i2 < h2)
	{
		r1 = r2 = 1;
		while ((r1 <= p)  &&  (r2 <= p)  &&  i1 < h1 && i2 < h2)
		{
			if (f1[i1].dtb <= f2[i2].dtb)
			{
				f[h++] = f1[i1];
				r1++;
				i1++;
			}
			else
			{
				f[h++] = f2[i2];
				r2++;
				i2++;
			}
		}
		while (i1 < h1  &&  r1 <= p)
		{
			f[h++] = f1[i1];
			i1++; r1++;
		}
		while (i2 < h2  &&  r2 <= p)
		{
			f[h++] = f2[i2];
			i2++; r2++;
		}
	}
	while (i1 < h1)
	{
		f[h++] = f1[i1];
		i1++;
	}
	while (i2 < h2)
	{
		f[h++] = f2[i2];
		i2++;
	}
}

void MergeSort(SinhVien a[MAX], int n)
{
	int p = 1, h1, h2, i = 1;
	SinhVien a1[MAX], a2[MAX];
	while (p < n)
	{
		Distribution(a, n, a1, h1, a2, h2, p);
		Merge(a1, h1, a2, h2, a, p);
		i++;
		p = p * 2;
	}
}