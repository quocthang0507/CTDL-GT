/*Hàm kiểm tra đội A và đội B đã thi đấu với nhau chưa
Trả về là 3 nghĩa là 2 đội đó đã thi đấu với nhau rồi
Trả về là 2 nghĩa là đội A chỉ thi đấu với đội B một lần (A là đội chủ nhà)
Trả về là 1 nghĩa là đội A chỉ thi đấu với đội B một lần (B là đội chủ nhà)
Trả về là 0 nghĩa là đội A và đội B chưa thi đấu với nhau bao giờ*/
int KT_2Doi_Dau(LIST_KQTD l, char A[15], char B[15])
{
	NODE1 *p, *q;
	int kq = 0, t = 0;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (_strcmpi(p->kqtd.cNha, A) == 0 && _strcmpi(p->kqtd.khach, B) == 0)
		{
			for (q = l.pHead; q != NULL; q = q->pNext)
				if (_strcmpi(q->kqtd.cNha, B) == 0 && _strcmpi(q->kqtd.khach, A) == 0)
					t = 1;
			if (t == 0)
				kq = 1;
			else kq = 3;
			break;
		}
		if (_strcmpi(p->kqtd.cNha, B) == 0 && _strcmpi(p->kqtd.khach, A) == 0)
		{
			for (q = l.pHead; q != NULL; q = q->pNext)
				if (_strcmpi(q->kqtd.cNha, A) == 0 && _strcmpi(q->kqtd.khach, B) == 0)
					t = 1;
			if (t == 0)
				kq = 2;
			else kq = 3;
			break;
		}
	}
	return kq;
}

/*Hàm xuất danh sách các trận chưa thi đấu của đội X
Sử dụng kết quả trả về của hàm KT_2Doi_Dau ở trên*/
void Xuat_Tran_ChuaDau_CuaDoi(LIST_KQTD l, char tenDoi[15])
{
	NODE2 *q;
	LIST_KQXH h;
	KhoiTao_List_KQXH(h);
	for (q = h.pHead; q != NULL; q = q->pNext)
		if (_strcmpi(q->kqxh.tenDoi, tenDoi) != 0)
			if (KT_2Doi_Dau(l, tenDoi, q->kqxh.tenDoi) == 0)
			{
				cout << "\nDoi chu nha : " << tenDoi << "\t& Doi khach:\t" << q->kqxh.tenDoi;
				cout << "\nDoi chu nha : " << q->kqxh.tenDoi << "\t& Doi khach:\t" << tenDoi;
			}
			else if (KT_2Doi_Dau(l, tenDoi, q->kqxh.tenDoi) == 1)
				cout << "\nDoi chu nha : " << q->kqxh.tenDoi << "\t& Doi khach:\t" << tenDoi;
			else if (KT_2Doi_Dau(l, tenDoi, q->kqxh.tenDoi) == 2)
				cout << "\nDoi chu nha : " << tenDoi << "\t& Doi khach:\t" << q->kqxh.tenDoi;
}

/*Hàm xuất danh sách các trận chưa thi đấu
Sử dụng hàm KT_2Doi_Dau với 2 đội A và B lần lượt theo danh sách, nếu 2 đội chưa có trong danh sách KQTD thì xuất ra màn hình
Để tránh trường hợp lặp lại kết quả, mỗi lần tìm thấy 2 đội chưa thi đấu thì thêm vào danh sách KQTD
Thoát khỏi hàm, quay trở lại chức năng khác, danh sách KQTD trở về như cũ*/
void Xuat_Tran_ChuaDau(LIST_KQTD l)
{
	TapTin_List_KQTD(l);
	NODE2 *p, *q;
	LIST_KQXH h;
	KhoiTao_List_KQXH(h);
	for (p = h.pHead; p != NULL; p = p->pNext)
		for (q = h.pHead; q != NULL; q = q->pNext)
			if (p != q)
			{
				data1 x;
				if (KT_2Doi_Dau(l, p->kqxh.tenDoi, q->kqxh.tenDoi) == 0)
				{
					cout << "\nDoi chu nha : " << p->kqxh.tenDoi << "\t& Doi khach:\t" << q->kqxh.tenDoi;
					strcpy_s(x.cNha, p->kqxh.tenDoi);
					strcpy_s(x.khach, q->kqxh.tenDoi);
					InsertTail1(l, x);
					cout << "\nDoi chu nha : " << q->kqxh.tenDoi << "\t& Doi khach:\t" << p->kqxh.tenDoi;
					strcpy_s(x.cNha, q->kqxh.tenDoi);
					strcpy_s(x.khach, p->kqxh.tenDoi);
					InsertTail1(l, x);
				}
				else if (KT_2Doi_Dau(l, p->kqxh.tenDoi, q->kqxh.tenDoi) == 1)
				{
					cout << "\nDoi chu nha : " << q->kqxh.tenDoi << "\t& Doi khach:\t" << p->kqxh.tenDoi;
					strcpy_s(x.cNha, q->kqxh.tenDoi);
					strcpy_s(x.khach, p->kqxh.tenDoi);
					InsertTail1(l, x);
				}
				else if (KT_2Doi_Dau(l, p->kqxh.tenDoi, q->kqxh.tenDoi) == 2)
				{
					cout << "\nDoi chu nha : " << p->kqxh.tenDoi << "\t& Doi khach:\t" << q->kqxh.tenDoi;
					strcpy_s(x.cNha, p->kqxh.tenDoi);
					strcpy_s(x.khach, q->kqxh.tenDoi);
					InsertTail1(l, x);
				}
			}
}

/*Hàm tạo kết quả điểm (chỉ tính khi ở vai trò là đội khách) của các đội*/
void TaoKQ_Diem_SanKhach_Vong(LIST_KQXH &h, LIST_KQTD l, int vong)
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

/*Hàm tạo kết quả điểm (chỉ tính khi ở vai trò là đội chủ nhà) của các đội*/
void TaoKQ_Diem_SanNha_Vong(LIST_KQXH &h, LIST_KQTD l, int vong)
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
			x.hieuSo = x.sBThang - x.sBThua;
			x.st = x.sTThang + x.sTHoa + x.sTThua;
		}
		q->kqxh = x;
	}
}

/*Hàm xuất tiêu đề phục vụ chức năng xuất kết quả điểm của các đội*/
void XuatTieuDe_KQ_Diem()
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
		<< ": ";
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 64; i++)
		cout << NGANGDOI;
	cout << ':';
}

/*Hàm xuất kết quả điểm của một đội*/
void XuatKQ_Diem_1D(data2 x)
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
		<< ": ";
}

/*Hàm xuất kết quả điểm của đội X
Để sử dụng hàm này, trong menu, ngay trước lời gọi hàm, phải có hàm TaoKQ_Diem_SanKhach_Vong hoặc TaoKQ_Diem_SanNha_Vong*/
void XuatKQ_Diem(LIST_KQXH h, char tenDoi[15])
{
	NODE2 *p;
	XuatTieuDe_KQ_Diem();
	cout << endl;
	for (p = h.pHead; p != h.pTail; p = p->pNext)
	{
		if (_strcmpi(p->kqxh.tenDoi, tenDoi) == 0)
			XuatKQ_Diem_1D(p->kqxh);
	}
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 64; i++)
		cout << NGANGDON;
	cout << ':';
}