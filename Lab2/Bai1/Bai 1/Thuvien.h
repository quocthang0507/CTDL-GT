#define MAX 100

typedef int DaySo[MAX];

int TapTin_mang1c(char *filename, DaySo a, int &n)
{
	int i;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file !";
		return 0;
	}
	in >> n;
	for (i = 0; i < n; i++)
		in >> a[i];
	in.close();
	return 1;
}

void XuatMang(DaySo a, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

int TKTT_DauTien(DaySo a, int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return -1;
	return i;
}

int TKTT_DauTien_LC(DaySo a, int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}

int TKTT_CuoiCung(DaySo a, int n, int x)
{
	int i = n - 1;
	while ((i >= 0) && (a[i] != x))
		i--;
	return i;
}

void TKTT_CacChiSo(DaySo a, int n, int x)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i] == x)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nKhong co trong a";
	else
	{
		cout << "\nXuat hien trong a tai cac vi tri : \n";
		for (i = 0; i < n; i++)
			if (a[i] == x)
			{
				cout << i << '\t';
			}
	}
}