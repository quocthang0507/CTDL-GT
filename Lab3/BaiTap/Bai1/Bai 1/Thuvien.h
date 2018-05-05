#define MAX 100

typedef int DaySo[MAX];

int File_Array(char *filename, DaySo a, int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	in >> a[n];
	while (!in.eof())
	{
		n++;
		in >> a[n];
	}
	n++;
	in.close();
	return 1;
}

void XuatMang(DaySo a, int n)
{
	cout << endl << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

void Copy(DaySo b, DaySo a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void Selection_L(DaySo a, int n)
{
	int cs_min;
	for (int i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (int j = i + 1; j < n; j++)
		if (a[j] < a[cs_min])
			cs_min = j;
		swap(a[i], a[cs_min]);
	}
}

void Selection_R(DaySo a, int n)
{
	int cs_max;
	for (int i = n - 1; i >= 1; i--)
	{
		cs_max = i;
		for (int j = i - 1; j >= 0; j--)
		if (a[j] > a[cs_max])
			cs_max = j;
		swap(a[i], a[cs_max]);
	}
}

void Selection_R_L(DaySo a, int n)
{
	int cs_min, cs_max;
	for (int i = 0; i < n / 2; i++)
	{
		cs_min = i;
		cs_max = n - i - 1;
		for (int j = i; j < n - i; j++)
		{
			if (a[j] < a[cs_min])
				cs_min = j;
			if (a[j] > a[cs_max])
				cs_max = j;
		}
		if (cs_min == n - i - 1)
		{
			swap(a[i], a[cs_min]);
			if (cs_max != i)
				swap(a[cs_max], a[n - i - 1]);
		}
		else
		{
			swap(a[cs_max], a[n - i - 1]);
			swap(a[i], a[cs_min]);
		}
	}
}

void Insertion_L(DaySo a, int n)
{
	int t, vt;
	for (int i = 1; i < n; i++)
	for (int j = 0; j <= i; j++)
	if (a[i] < a[j])
	{
		t = a[i];
		vt = i;
		while (vt != j)
		{
			a[vt] = a[vt - 1];
			vt--;
		}
		a[j] = t;
	}
}

void Insertion_R(DaySo a, int n)
{
	int t, vt;
	for (int i = n - 2; i >= 0; i--)
	for (int j = n - 1; j >= i; j--)
	if (a[i] > a[j])
	{
		t = a[i];
		vt = i;
		while (vt <= j)
		{
			a[vt] = a[vt + 1];
			vt++;
		}
		a[j] = t;
	}
}

void BinaryInsertion(DaySo a, int n)
{
	int l, r, m;
	int i, j;
	int x;
	for (i = 1; i < n; i++)
	{
		x = a[i]; l = 0; r = i - 1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (x < a[m])
				r = m - 1;
			else
				l = m + 1;
		}
		for (j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = x;
	}
}

void Interchange_L(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (a[j] < a[i])
		swap(a[j], a[i]);
}

void Interchange_R(DaySo a, int n)
{
	for (int i = n - 1; i > 0; i--)
	for (int j = 0; j < i; j++)
	if (a[j]>a[i])
		swap(a[j], a[i]);
}

void Bubble_L(DaySo a, int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = n - 1; j > i; j--)
	if (a[j] < a[j - 1])
		swap(a[j], a[j - 1]);
}

void Bubble_R(DaySo a, int n)
{
	for (int i = n - 1; i > 0; i--)
	for (int j = 0; j < n - 1; j++)
	if (a[j]>a[j + 1])
		swap(a[j], a[j + 1]);
}