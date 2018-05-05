void HoanVi(data2 &x, data2 &y)
{
	data2 t = x;
	x = y;
	y = t;
}

void SapGiamTheoDiem_HieuSo_SoBT_DenVong(LIST_KQXH &h, int vong)
{
	NODE2 *p, *q;
	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->kqxh.diem < q->kqxh.diem)
				HoanVi(p->kqxh, q->kqxh);
	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->kqxh.diem == q->kqxh.diem)
				if (p->kqxh.hieuSo < q->kqxh.hieuSo)
					HoanVi(p->kqxh, q->kqxh);
	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->kqxh.diem == q->kqxh.diem)
				if (p->kqxh.hieuSo == q->kqxh.hieuSo)
					if (p->kqxh.sBThang < q->kqxh.sBThang)
						HoanVi(p->kqxh, q->kqxh);
	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->kqxh.diem == q->kqxh.diem)
				if (p->kqxh.hieuSo == q->kqxh.hieuSo)
					if (p->kqxh.sBThang == q->kqxh.sBThang)
						if (_strcmpi(p->kqxh.tenDoi, q->kqxh.tenDoi) > 0)
							HoanVi(p->kqxh, q->kqxh);
}

void XepHang_DenVong(LIST_KQXH &h, int vong)
{
	int vt = 1, soVT;
	NODE2 *p, *q;
	SapGiamTheoDiem_HieuSo_SoBT_DenVong(h, vong);
	p = h.pHead;
	p->kqxh.xh = 1;
	soVT = 1;
	for (q = p->pNext; q != NULL; q = q->pNext)
	{
		if (q->kqxh.diem == p->kqxh.diem &&	q->kqxh.hieuSo == p->kqxh.hieuSo &&	q->kqxh.sBThang == p->kqxh.sBThang)
		{
			q->kqxh.xh = vt;
			soVT++;
		}
		else
		{
			vt += soVT;
			q->kqxh.xh = vt;
			soVT = 1;
		}
		p = q;
	}
}

void XuatTieuDe_KQ()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << NGANGDOI;
	cout << ':';
	cout << endl;
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(15) << "Ten doi"
		<< ": "
		<< setw(4) << "ST"
		<< ": "
		<< setw(4) << "T"
		<< ": "
		<< setw(4) << "H"
		<< ": "
		<< setw(4) << "B"
		<< ": "
		<< setw(4) << "BT"
		<< ": "
		<< setw(4) << "BB"
		<< ": "
		<< setw(4) << "HS"
		<< ": "
		<< setw(4) << "Diem"
		<< ": "
		<< setw(4) << "XH"
		<< ':';
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatKQ_1D(data2 x)
{
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(15) << x.tenDoi
		<< ": "
		<< setw(4) << x.st
		<< ": "
		<< setw(4) << x.sTThang
		<< ": "
		<< setw(4) << x.sTHoa
		<< ": "
		<< setw(4) << x.sTThua
		<< ": "
		<< setw(4) << x.sBThang
		<< ": "
		<< setw(4) << x.sBThua
		<< ": "
		<< setw(4) << x.hieuSo
		<< ": "
		<< setw(4) << x.diem
		<< ": "
		<< setw(4) << x.xh
		<< ':';
}

void Xuat_KQXH(LIST_KQXH h)
{
	NODE2 *p;
	XuatTieuDe_KQ();
	for (p = h.pHead; p != h.pTail; p = p->pNext)
	{
		cout << endl;
		XuatKQ_1D(p->kqxh);
		cout << endl;
		cout << ':';
		for (int i = 1; i <= 70; i++)
			cout << NGANGDON;
		cout << ':';
	}
	cout << endl;
	XuatKQ_1D(p->kqxh);
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << NGANGDOI;
	cout << ':';
}