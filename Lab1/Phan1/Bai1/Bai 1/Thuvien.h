#define MAX 100

typedef int DaySo[MAX];

void NhapDay(DaySo a, int &n)
{
	cout << "\nNhap kich thuoc day = ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "\nNhap phan tu thu " << i << " = ";
		cin >> a[i];
	}
}

void XuatDay(DaySo a, int n)
{
	cout << "\nDay so : \n";
	for (int i = 0; i <n; i++)
	{
		cout << a[i] << '\t';
	}
}

void ChenTaiX(DaySo a, int &n, int x, int gt)
{
	n++;
	for (int i = n - 2; i >= x; i--)
		a[i + 1] = a[i];
	a[x] = gt;
}

void XoaTaiX(DaySo a, int&n, int x)
{
	for (int i = x; i < n-1; i++)
		a[i] = a[i + 1];
	n--;
}

int Dem(DaySo a, int n, int gt)
{
	int dem = 0;
	for (int i = 0; i<n; i++)
	if (a[i] == gt)
		dem++;
	return dem;
}

void PhanBiet(DaySo a, int n)
{
	DaySo b;
	int i, m, j, dau, l = n, dem;
	m = 0;
	for (i = 0; i < l; i++)
	{
		dau = 1;
		for (j = 0; j < m && dau; j++)
			dau = dau && (a[i] != b[j]);
		if (dau)
		{
			b[m++] = a[i];
			dem = Dem(a, n, a[i]);
			cout << "\nGia tri " << a[i] << " xuat hien " << dem << " lan";
		}
	}
}