struct KetQuaXepHang
{
	char tenDoi[15];
	int st;
	int sTThang;
	int sTHoa;
	int sTThua;
	int sBThang;
	int sBThua;
	int hieuSo;
	int diem;
	int xh;
};

typedef KetQuaXepHang data2;

struct tagNODE2
{
	data2 kqxh;
	tagNODE2 *pNext;
};

typedef tagNODE2 NODE2;

struct LIST_KQXH
{
	NODE2 *pHead;
	NODE2 *pTail;
};

NODE2* GetNODE2(data2 x)
{
	NODE2 *p;
	p = new NODE2;
	if (p != NULL)
	{
		p->kqxh = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_KQXH(LIST_KQXH &h)
{
	h.pHead = h.pTail = NULL;
}

void InsertTail2(LIST_KQXH &h, data2 x)
{
	NODE2* new_ele = GetNODE2(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		_getch();
		return;
	}
	if (h.pHead == NULL)
	{
		h.pHead = new_ele; h.pTail = h.pHead;
	}
	else
	{
		h.pTail->pNext = new_ele;
		h.pTail = new_ele;
	}
}

void KhoiTao_List_KQXH(LIST_KQXH &h)
{
	ifstream in("KhoiTao_KQDB.txt");
	if (!in)
	{
		cout << "\nLoi mo file !\n";
		_getch();
		return;
	}
	CreatList_KQXH(h);
	char tenDoi[15];
	int st;
	int sTThang;
	int sTHoa;
	int sTThua;
	int sBThang;
	int sBThua;
	int hieuSo;
	int diem;
	int xh;
	data2 x;
	in >> tenDoi; strcpy_s(x.tenDoi, 15, tenDoi);
	in >> st; x.st = st;
	in >> sTThang; x.sTThang = sTThang;
	in >> sTHoa; x.sTHoa = sTHoa;
	in >> sTThua; x.sTThua = sTThua;
	in >> sBThang; x.sBThang = sBThang;
	in >> sBThua; x.sBThua = sBThua;
	in >> hieuSo; x.hieuSo = hieuSo;
	in >> diem; x.diem = diem;
	in >> xh; x.xh = xh;
	InsertTail2(h, x);
	while (!in.eof())
	{
		in >> tenDoi; strcpy_s(x.tenDoi, 15, tenDoi);
		in >> st; x.st = st;
		in >> sTThang; x.sTThang = sTThang;
		in >> sTHoa; x.sTHoa = sTHoa;
		in >> sTThua; x.sTThua = sTThua;
		in >> sBThang; x.sBThang = sBThang;
		in >> sBThua; x.sBThua = sBThua;
		in >> hieuSo; x.hieuSo = hieuSo;
		in >> diem; x.diem = diem;
		in >> xh; x.xh = xh;
		InsertTail2(h, x);
	}
	in.close();
}

NODE1 *Tro_Sau_Cuoi_Vong(LIST_KQTD l, int vong)
{
	NODE1 *p;
	int sTran = 10 * vong;
	int i = 0;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		i++;
		if (i > sTran)
			break;
	}
	return p;
}

void TaoList_KQDB_Vong(LIST_KQXH &h, LIST_KQTD l, int vong)
{
	NODE1 *p;
	NODE2 *q;
	data2 x;
	NODE1 *r = Tro_Sau_Cuoi_Vong(l, vong);
	KhoiTao_List_KQXH(h);
	for (q = h.pHead; q != NULL; q = q->pNext)
	{
		x = q->kqxh;
		for (p = l.pHead; p != r; p = p->pNext)
		{
			if (_strcmpi(x.tenDoi, p->kqtd.cNha) == 0)
			{
				x.sBThang += p->kqtd.bTChu;
				x.sBThua += p->kqtd.bTKhach;
				if (p->kqtd.bTChu > p->kqtd.bTKhach)
				{
					x.sTThang++;
					x.diem += 3;
				}
				else
					if (p->kqtd.bTChu < p->kqtd.bTKhach)
						x.sTThua++;
					else
					{
						x.sTHoa++;
						x.diem += 1;
					}
			}
			else
				if (_strcmpi(x.tenDoi, p->kqtd.khach) == 0)
				{
					x.sBThang += p->kqtd.bTKhach;
					x.sBThua += p->kqtd.bTChu;
					if (p->kqtd.bTChu < p->kqtd.bTKhach)
					{
						x.sTThang++;
						x.diem += 3;
					}
					else
						if (p->kqtd.bTChu > p->kqtd.bTKhach)
							x.sTThua++;
						else
						{
							x.sTHoa++;
							x.diem += 1;
						}
				}
			x.hieuSo = x.sBThang - x.sBThua;
			x.st = x.sTThang + x.sTHoa + x.sTThua;
		}
		q->kqxh = x;
	}
}