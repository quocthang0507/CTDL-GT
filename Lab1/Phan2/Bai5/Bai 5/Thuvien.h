#define MAX 100

typedef int MaTran[MAX][MAX];

void Read(char*filename, MaTran &a, int&n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> n;
	int i, j;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		in >> a[i][j];
	}
	in.close();
}

void Write(char*filename, MaTran a, int n)
{
	ofstream out(filename);
	if (!out)
	{
		cout << "\nLoi mo file!";
		return;
	}
	out << n;
	out << endl;
	int i, j;
	for (i = 0; i < n; i++, out << endl)
	for (j = 0; j < n; j++)
	{
		out << a[i][j] << '\t';
	}
	out.close();
	cout << "\nLuu file thanh cong!";
}

void Display(char*filename)
{
	int n, x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> n;
	cout << n;
	cout << endl;
	for (int i = 0; i < n; i++, cout << endl)
	for (int j = 0; j < n; j++)
	{
		in >> x;
		cout << x << '\t';
	}
	in.close();
}