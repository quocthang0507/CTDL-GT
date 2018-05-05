struct KQXepHang
{
	char tenDoi[15]; //ten doi
	int sTThang; //So tran thang cua doi
	int sTHoa; //So tran hoa
	int sTThua; //So tran thua
	int sBThang; //So ban thang
	int sBThua; //So ban thua
	int hieuSo; //So ban thang – So ban thua
	int diem; //Diem so cua doi
	int xh; //Vi tri cua doi tren bang xep hang
};

void Chen_KQ1Doi(char tenDoi[15], int sTThang, int sTHoa, int sTThua,
	int sBThang, int sBThua, int hieuSo, int diem, int xh, KQXepHang kq[MAX], int &sd)
{
	if (sd < MAX)
	{
		strcpy_s(kq[sd].tenDoi, 15, tenDoi);
		kq[sd].sTThang = sTThang;
		kq[sd].sTHoa = sTHoa;
		kq[sd].sTThua = sTThua;
		kq[sd].sBThang = sBThang;
		kq[sd].sBThua = sBThua;
		kq[sd].hieuSo = hieuSo;
		kq[sd].diem = diem;
		kq[sd].xh = xh;
		sd++;
	}
}

void KhoiTaoBang_KQ(KQXepHang kq[MAX], int &sd)
{
	sd = 1;
	Chen_KQ1Doi("Arsenal", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Bournemouth", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Burley", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Chelsea", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Crystal Palace", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Everton", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Hull City", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Leicester", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Liverpool", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("MC", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Middlesbrough", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("MU", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Southampton", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Stoke City", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Sunderland", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Swansea City", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Tottenham", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("Watford", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("West bromwich", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	Chen_KQ1Doi("West Ham", 0, 0, 0, 0, 0, 0, 0, 0, kq, sd);
	sd--;
}

void TaoBang_KQ_Vong(KQXepHang kq[MAX], int &sd, KetQuaTranDau a[MAX], int vong)
{
	int i, j;
	KQXepHang p;
	KhoiTaoBang_KQ(kq, sd);
	int st = sd / 2 * vong;
	for (j = 1; j <= sd; j++)
	{
		p = kq[j];
		for (i = 1; i <= st; i++)
		{
			if (_strcmpi(p.tenDoi, a[i].cNha) == 0)
			{
				p.sBThang += a[i].bTChu;
				p.sBThua += a[i].bTKhach;
				if (a[i].bTChu > a[i].bTKhach)
				{
					p.sTThang++;
					p.diem += 3;
				}
				else
				if (a[i].bTChu < a[i].bTKhach)
					p.sTThua++;
				else
				{
					p.sTHoa++;
					p.diem += 1;
				}
				p.hieuSo = p.sBThang - p.sBThua;
			}
			else
			if (_strcmpi(p.tenDoi, a[i].khach) == 0)
			{
				p.sBThang += a[i].bTKhach;
				p.sBThua += a[i].bTChu;
				if (a[i].bTChu < a[i].bTKhach)
				{
					p.sTThang++;
					p.diem += 3;
				}
				else
				if (a[i].bTChu > a[i].bTKhach)
					p.sTThua++;
				else
				{
					p.sTHoa++;
					p.diem += 1;
				}
				p.hieuSo = p.sBThang - p.sBThua;
			}
		}
		kq[j] = p;
	}
}