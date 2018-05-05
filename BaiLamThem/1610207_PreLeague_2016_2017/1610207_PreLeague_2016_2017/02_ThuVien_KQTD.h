#define MAX 100
#define NGANGDOI '='
#define NGANGDON '-'

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

void XuatLTD_1TD(data1 p)
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

void Xuat_LTD_Vong_j(LIST_KQTD l, int vong)
{
	int k, dem = 0;
	cout << "\n Lich thi dau vong " << vong;
	cout << endl;
	XuatTieuDe_LTD();
	NODE1 *p;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->kqtd.vong == vong)
		{
			cout << endl;
			XuatLTD_1TD(p->kqtd);
			dem++;
			if (dem == 10)
				break;
			if (p->pNext == NULL)
				break;
			if (_strcmpi(p->kqtd.ngay, p->pNext->kqtd.ngay) != 0)
			{
				cout << endl;
				cout << ':';
				for (k = 1; k < 59; k++)
					cout << NGANGDON;
				cout << ':';
			}
		}
	}
	cout << endl;
	XuatNganDoi();
}

void Xuat_LTD_DenVong_j(LIST_KQTD l, int vong)
{
	int j;
	cout << endl;
	system("CLS");
	for (j = 1; j <= vong; j++)
	{
		Xuat_LTD_Vong_j(l, j);
		cout << endl;
		_getch();
	}
}

void XuatTieuDe_KQTD()
{
	int i;
	cout << ':';
	for (i = 1; i < 70; i++)
		cout << NGANGDOI;
	cout << ':';
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
	cout << ':';
	for (i = 1; i < 70; i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatKQ_1TD(data1 p)
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

void Xuat_KQTD_Vong_j(LIST_KQTD l, int vong)
{
	NODE1 *p;
	int k;
	int dem = 0;
	cout << "\n Ket qua cac tran dau vong " << vong;
	cout << endl;
	XuatTieuDe_KQTD();
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->kqtd.vong == vong)
		{
			cout << endl;
			XuatKQ_1TD(p->kqtd);
			dem++;
			if (dem == 10)
				break;
			if (p->pNext == NULL)
				break;
			if (_strcmpi(p->kqtd.ngay, p->pNext->kqtd.ngay) != 0)
			{
				cout << endl;
				cout << ':';
				for (k = 1; k < 70; k++)
					cout << NGANGDON;
				cout << ':';
			}
		}
	}
	cout << endl;
	cout << ':';
	for (k = 1; k < 70; k++)
		cout << NGANGDOI;
	cout << ':';
}

void Xuat_KQTD_DenVong_j(LIST_KQTD l, int vong)
{
	int j;
	cout << "\nKet qua cac tran dau den vong " << vong << " :";
	cout << endl;
	for (j = 1; j <= vong; j++)
	{
		Xuat_KQTD_Vong_j(l, j);
		cout << endl;
		_getch();
	}
}

int VongTD_MoiNhat(LIST_KQTD l)
{
	/*int vong = 38;
	NODE1 *p;
	for (p = l.pHead; p != NULL; p = p->pNext)
	if (p->kqtd.bTChu == -1)
	{
	vong = p->kqtd.vong - 1;
	break;
	}
	return vong;*/
	NODE1 *p;
	int vong = 0;
	for (p = l.pHead; p != NULL; p = p->pNext)
		if (p->kqtd.vong > vong)
			vong = p->kqtd.vong;
	return vong;
}