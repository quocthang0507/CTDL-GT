#define MAX 100
#define NGANGDOI '='
#define NGANGDON '-'

struct KetQuaTranDau
{
	int vong;
	char ngay[9];
	char gio[6];
	char cNha[15];
	int bTChu;
	int bTKhach;
	char khach[15];
};

void ChenKQ_TD(int vong, char ngay[9], char gio[6], char cNha[15], int bTChu,
	int bTKhach, char khach[15], KetQuaTranDau a[MAX], int &st)
{
	if (st < MAX)
	{
		a[st].vong = vong;
		strcpy_s(a[st].ngay, 9, ngay);
		strcpy_s(a[st].gio, 6, gio);
		strcpy_s(a[st].cNha, 15, cNha);
		a[st].bTChu = bTChu;
		a[st].bTKhach = bTKhach;
		strcpy_s(a[st].khach, 15, khach);
		st++;
	}
}

void TaoBang_KQTD(KetQuaTranDau a[MAX], int &st)
{
	ChenKQ_TD(1, "13-08-16", "18:30", "Hull City", 2, 1, "Leicester", a, st);
	ChenKQ_TD(1, "13-08-16", "21:00", "Southampton", 1, 1, "Watford", a, st);
	ChenKQ_TD(1, "13-08-16", "21:00", "Middlesbrough", 1, 1, "Stoke City", a, st);
	ChenKQ_TD(1, "13-08-16", "21:00", "Everton", 1, 1, "Tottenham", a, st);
	ChenKQ_TD(1, "13-08-16", "21:00", "Crystal Palace", 0, 1, "West bromwich", a, st);
	ChenKQ_TD(1, "13-08-16", "21:00", "Burley", 0, 1, "Swansea City", a, st);
	ChenKQ_TD(1, "13-08-16", "23:30", "MC", 2, 1, "Sunderland", a, st);
	ChenKQ_TD(1, "14-08-16", "19:30", "Bournemouth", 1, 3, "MU", a, st);
	ChenKQ_TD(1, "14-08-16", "22:00", "Arsenal", 3, 4, "Liverpool", a, st);
	ChenKQ_TD(1, "16-08-16", "02:00", "Chelsea", 2, 1, "West Ham", a, st);
	ChenKQ_TD(2, "20-08-16", "02:00", "MU", 2, 0, "Southampton", a, st);
	ChenKQ_TD(2, "20-08-16", "18:30", "Stoke City", 1, 4, "MC", a, st);
	ChenKQ_TD(2, "20-08-16", "21:00", "West bromwich", 1, 2, "Everton", a, st);
	ChenKQ_TD(2, "20-08-16", "21:00", "Watford", 1, 2, "Chelsea", a, st);
	ChenKQ_TD(2, "20-08-16", "21:00", "Tottenham", 1, 0, "Crystal Palace", a, st);
	ChenKQ_TD(2, "20-08-16", "21:00", "Swansea City", 0, 2, "Hull City", a, st);
	ChenKQ_TD(2, "20-08-16", "21:00", "Burley", 2, 0, "Liverpool", a, st);
	ChenKQ_TD(2, "20-08-16", "23:30", "Leicester", 0, 0, "Arsenal", a, st);
	ChenKQ_TD(2, "21-08-16", "19:30", "Sunderland", 1, 2, "Middlesbrough", a, st);
	ChenKQ_TD(2, "21-08-16", "22:00", "West Ham", 1, 0, "Bournemouth", a, st);
	ChenKQ_TD(3, "27-08-16", "18:30", "Tottenham", 1, 1, "Liverpool", a, st);
	ChenKQ_TD(3, "27-08-16", "21:00", "Chelsea", 3, 0, "Burley", a, st);
	ChenKQ_TD(3, "27-08-16", "21:00", "Crystal Palace", 1, 1, "Bournemouth", a, st);
	ChenKQ_TD(3, "27-08-16", "21:00", "Everton", 1, 0, "Stoke City", a, st);
	ChenKQ_TD(3, "27-08-16", "21:00", "Leicester", 2, 1, "Swansea City", a, st);
	ChenKQ_TD(3, "27-08-16", "21:00", "Southampton", 1, 1, "Sunderland", a, st);
	ChenKQ_TD(3, "27-08-16", "21:00", "Watford", 1, 3, "Arsenal", a, st);
	ChenKQ_TD(3, "27-08-16", "23:30", "Hull City", 0, 1, "MU", a, st);
	ChenKQ_TD(3, "28-08-16", "19:30", "West bromwich", 0, 0, "Middlesbrough", a, st);
	ChenKQ_TD(3, "28-08-16", "22:00", "MC", 3, 1, "West Ham", a, st);
	ChenKQ_TD(8, "15-10-16", "18:30", "Chelsea", -1, -1, "Leicester", a, st);
}

void XuatNganDoi()
{
	int i;
	cout << ':';
	for (i = 1; i < 59; i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatTieuDe_LTD()
{
	XuatNganDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(4) << "Vong"
		<< ": "
		<< setw(9) << "Ngay"
		<< ": "
		<< setw(6) << "Gio"
		<< ": "
		<< setw(15) << "Chu Nha"
		<< ": "
		<< setw(15) << "Khach"
		<< ":";
	cout << endl;
	XuatNganDoi();
}

void XuatLTD_1TD(KetQuaTranDau p)
{
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(4) << p.vong
		<< ": "
		<< setw(9) << p.ngay
		<< ": "
		<< setw(6) << p.gio
		<< ": "
		<< setw(15) << p.cNha
		<< ": "
		<< setw(15) << p.khach
		<< ':';
}

void Xuat_LTD_Vong_j(KetQuaTranDau a[MAX], int st, int vong)
{
	int i;
	int dem = 0;
	cout << "\n Lich thi dau vong " << vong << " :";
	cout << endl;
	XuatTieuDe_LTD();
	for (i = 1; i <= st; i++)
	{
		if (a[i].vong == vong)
		{
			cout << endl;
			XuatLTD_1TD(a[i]);
			dem++;
			if (dem == 10)
				break;
		}
	}
	cout << endl;
	XuatNganDoi();
}

void Xuat_LTD_DenVong_j(KetQuaTranDau a[MAX], int st, int vong)
{
	int j;
	cout << endl;
	system("CLS");
	for (j = 1; j <= vong; j++)
	{
		Xuat_LTD_Vong_j(a, st, j);
		cout << endl;
		_getch();
	}
}

void XuatTieuDe_KQTD()
{
	for (int i = 1; i < 72; i++)
		cout << NGANGDOI;
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(4) << "Vong"
		<< ':'
		<< setw(9) << "Ngay"
		<< ':'
		<< setw(6) << "Gio"
		<< ':'
		<< setw(15) << "Chu Nha"
		<< ':'
		<< setw(15) << " Ty So "
		<< ':'
		<< setw(15) << "Khach"
		<< ':';
	cout << endl;
	for (int i = 1; i < 72; i++)
		cout << NGANGDOI;
}

void XuatKQ_1TD(KetQuaTranDau p)
{
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(4) << p.vong
		<< ':'
		<< setw(9) << p.ngay
		<< ':'
		<< setw(6) << p.gio
		<< ':'
		<< setw(15) << p.cNha
		<< ':'
		<< setw(7) << p.bTChu
		<< ':'
		<< setw(7) << p.bTKhach
		<< ':'
		<< setw(15) << p.khach
		<< ':';
}

void Xuat_KQTD_Vong_j(KetQuaTranDau a[MAX], int st, int vong)
{
	int i, k;
	int dem = 0;
	cout << "\n- Ket qua cac tran dau vong " << vong << " :";
	cout << endl;
	XuatTieuDe_KQTD();
	for (i = 1; i <= st; i++)
	{
		if (a[i].vong == vong)
		{
			cout << endl;
			XuatKQ_1TD(a[i]);
			dem++;
			if (dem == 10)
				break;
			if (_strcmpi(a[i].ngay, a[i + 1].ngay) != 0)
			{
				cout << endl;
				for (k = 1; k < 72; k++)
					cout << NGANGDON;
			}
		}
	}
	cout << endl;
	for (k = 1; k < 72; k++)
		cout << NGANGDOI;
}

void Xuat_KQTD_DenVong_j(KetQuaTranDau a[MAX], int st, int vong)
{
	int j;
	cout << "\n Ket qua cac tran dau den vong " << vong << " :";
	cout << endl;
	for (j = 1; j <= vong; j++)
	{
		Xuat_KQTD_Vong_j(a, st, j);
		cout << endl;
	}
}
int VongTD_MoiNhat(KetQuaTranDau a[MAX], int st)
{
	int vong = 38, i;
	for (i = 1; i <= st; i++)
	if (a[i].bTChu == -1)
	{
		vong = a[i].vong - 1;
		break;
	}
	return vong;
}