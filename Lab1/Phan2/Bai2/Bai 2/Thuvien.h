#define MAX 100

void File_Display1(char*filename);
void Write_Int(int a[], int n, char *filename);

void File_Display1(int a[MAX], char*filename, int &n)
{
	int x;
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		return;
	}
	in >> n;
	cout << endl << n << endl;
	for (int i = 0; i < n; i++)
	{
		in >> x;
		a[i] = x;
		cout << x << '\t';
	}
	cout << endl;
	in.close();
}

void Write_Int(int a[MAX], int n, char *filename)
{
	ofstream out(filename);
	if (!out)
	{
		cout << "\nLoi mo file!";
		return;
	}
	out << n;
	out << '\n';
	for (int i = 0; i < n; i++)
	{
		out << a[i];
		out << '\t';
	}
	out.close();
	cout << "\nGhi xong du lieu vao tep " << filename;
}