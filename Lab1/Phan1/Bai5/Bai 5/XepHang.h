void HoanVi(KQXepHang &p, KQXepHang &q)
{
	KQXepHang t = p;
	p = q;
	q = t;
}

void SapGiamTheoDiem_HieuSo_SoBT_DenVong(KQXepHang kq[MAX], int sd, int vong)
{
	int i, j;
	for (i = 1; i < sd; i++)
	for (j = i + 1; j <= sd; j++)
	if (kq[i].diem < kq[j].diem)
		HoanVi(kq[i], kq[j]);
	for (i = 1; i < sd; i++)
	for (j = i + 1; j <= sd; j++)
	if (kq[i].diem == kq[j].diem)
	if (kq[i].hieuSo < kq[j].hieuSo)
		HoanVi(kq[i], kq[j]);
	for (i = 1; i < sd; i++)
	for (j = i + 1; j <= sd; j++)
	if (kq[i].diem == kq[j].diem)
	if (kq[i].hieuSo == kq[j].hieuSo)
	if (kq[i].sBThang < kq[j].sBThang)
		HoanVi(kq[i], kq[j]);
}

void XepHang_DenVong(KQXepHang kq[MAX], int sd, int vong)
{
	int n, vt = 1, soVT;
	SapGiamTheoDiem_HieuSo_SoBT_DenVong(kq, sd, vong);
	kq[1].xh = vt;
	soVT = 1;
	for (n = 2; n <= sd; n++)
	{
		if (kq[n].diem == kq[n - 1].diem && kq[n].hieuSo == kq[n - 1].hieuSo &&
			kq[n].sBThang == kq[n - 1].sBThang)
		{
			kq[n].xh = vt;
			soVT++;
		}
		else
		{
			vt += soVT;
			kq[n].xh = vt;
			soVT = 1;
		}
	}
}

void XuatTieuDe_KQ()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 64; i++)
		cout << NGANGDOI;
	cout << ':';
	cout << endl;
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(15) << "Ten doi"
		<< ": "
		<< setw(4) << "T"//So tran thang
		<< ": "
		<< setw(4) << "H"//So tran Hoa
		<< ": "
		<< setw(4) << "B"//So tran thua
		<< ": "
		<< setw(4) << "BT"//So ban thang
		<< ": "
		<< setw(4) << "BB"//So ban thua
		<< ": "
		<< setw(4) << "HS"//hieu so
		<< ": "
		<< setw(4) << "Diem"//Diem
		<< ": "
		<< setw(4) << "XH"//Xep hang
		<< ':';
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 64; i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatKQ_1D(KQXepHang p)
{
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(15) << p.tenDoi
		<< ": "
		<< setw(4) << p.sTThang//So tran thang
		<< ": "
		<< setw(4) << p.sTHoa//So tran Hoa
		<< ": "
		<< setw(4) << p.sTThua//So tran thua
		<< ": "
		<< setw(4) << p.sBThang//So ban thang
		<< ": "
		<< setw(4) << p.sBThua//So ban thua
		<< ": "
		<< setw(4) << p.hieuSo//hieu so
		<< ": "
		<< setw(4) << p.diem//Diem
		<< ": "
		<< setw(4) << p.xh//Xep hang
		<< ':';
}
void Xuat_KQXH(KQXepHang kq[MAX], int sd)
{
	int k;
	XuatTieuDe_KQ();
	for (k = 1; k < sd; k++)
	{
		cout << endl;
		XuatKQ_1D(kq[k]);
		cout << endl;
		cout << ':';
		for (int i = 1; i <= 64; i++)
			cout << NGANGDON;
		cout << ':';
	}
	cout << endl;
	XuatKQ_1D(kq[sd]);
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 64; i++)
		cout << NGANGDOI;
	cout << ':';
}
