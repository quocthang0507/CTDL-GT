#define MAX 20
#define THOAT 0

struct DATE
{
	int ngay;
	int thang;
	int nam;
};

struct NHANVIEN
{
	int ms;
	char hoten[MAX];
	DATE DATE;
	char diachi[MAX];
	double luong;
};

void xuat(NHANVIEN ds[MAX], int n);
void Read_struct(char *filename, NHANVIEN ds[MAX], int &n);

void Read_struct(char *filename, NHANVIEN ds[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file !";
		return;
	}
	int ms;
	char hoten[MAX];
	char diachi[MAX];
	double luong;
	int ngay, thang, nam;
	n = 0;
	in >> ms; ds[n].ms = ms;
	in >> hoten; strcpy_s(ds[n].hoten, hoten);
	in >> ngay; ds[n].DATE.ngay = ngay;
	in >> thang; ds[n].DATE.thang = thang;
	in >> nam; ds[n].DATE.nam = nam;
	in >> diachi; strcpy_s(ds[n].diachi, diachi);
	in >> luong; ds[n].luong = luong;
	while (!in.eof())
	{
		n++;
		in >> ms; ds[n].ms = ms;
		in >> hoten; strcpy_s(ds[n].hoten, hoten);
		in >> ngay; ds[n].DATE.ngay = ngay;
		in >> thang; ds[n].DATE.thang = thang;
		in >> nam; ds[n].DATE.nam = nam;
		in >> diachi; strcpy_s(ds[n].diachi, diachi);
		in >> luong; ds[n].luong = luong;
	}
	n++;
	in.close();
}
void xuat(NHANVIEN ds[MAX], int n)
{
	cout << setiosflags(ios::left);
	cout << setw(20) << "MS"
		<< setw(20) << "Ho Ten"
		<< setw(20) << "DATE Sinh"
		<< setw(20) << "Dia chi"
		<< setw(20) << "Luong";
		cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(20) << ds[i].ms
			<< setw(20) << ds[i].hoten
			<< setw(2) << ds[i].DATE.ngay << '/'
			<< setw(2) << ds[i].DATE.thang << '/'
			<< setw(16) << ds[i].DATE.nam
			<< setw(20) << ds[i].diachi
			<< setw(20) << ds[i].luong;
			cout << endl;
	}
}