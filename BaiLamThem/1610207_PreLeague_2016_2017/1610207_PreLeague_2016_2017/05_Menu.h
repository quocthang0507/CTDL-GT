void XuatMenu()
{
	cout << "\n======================== HE THONG CHUC NANG ========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Xem lich thi dau vong j";
	cout << "\n2. Xem lich thi dau toan giai";
	cout << "\n3. Xem ket qua cac tran dau vong j";
	cout << "\n4. Xem ket qua cac tran dau tu vong 1 den vong j";
	cout << "\n5. Xem ket qua xep hang den vong j";
	cout << "\n6. Xem ket qua xep hang luot di";
	cout << "\n7. Xem ket qua chung cuoc";
	cout << "\n8. Xem cac tran chua dau tu vong 1 den vong thi dau moi nhat";
	cout << "\n9. Xuat cac tran chua dau cua doi X";
	cout << "\n10. Xuat ket qua diem tren san khach cua doi X den vong j";
	cout << "\n11. Xuat ket qua diem tren san nha cua doi X den vong j";
	cout << "\n12. Xuat ket qua xep hang cua cac doi chi tinh tren san doi phuong";
	cout << "\n====================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LIST_KQXH &kq, LIST_KQTD &a)
{
	system("cls");
	int j;
	int vongDauMoiNhat;
	char tenDoi[15];
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		cout << "\nNhan phim bat ky de thoat...";
		break;
	case 1:
		cout << "\n1. Xem lich thi dau vong j\n";
		cout << "\nNhap vong j can xem : ";
		cin >> j;
		Xuat_LTD_Vong_j(a, j);
		break;
	case 2:
		cout << "\n2. Xem lich thi dau toan giai\n";
		cout << "\nLICH THI DAU TOAN GIAI:\n";
		Xuat_LTD_DenVong_j(a, 38);
		break;
	case 3:
		cout << "\n3. Xem ket qua cac tran dau vong j\n";
		vongDauMoiNhat = VongTD_MoiNhat(a);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			cout << "\nMuon xem vong nao? (<= " << vongDauMoiNhat << " ), j = ";
			cin >> j;
		} while (j<0 || j>vongDauMoiNhat);
		Xuat_KQTD_Vong_j(a, j);
		break;
	case 4:
		cout << "\n4. Xem ket qua cac tran dau tu vong 1 den vong j\n";
		vongDauMoiNhat = VongTD_MoiNhat(a);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			cout << "\nMuon xem den vong nao? (<= " << vongDauMoiNhat << " ), j = ";
			cin >> j;
		} while (j<0 || j>vongDauMoiNhat);
		Xuat_KQTD_DenVong_j(a, j);
		break;
	case 5:
		cout << "\n5. Xem ket qua xep hang den vong j\n";
		vongDauMoiNhat = VongTD_MoiNhat(a);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			cout << "\nMuon xem den vong nao? (<= " << vongDauMoiNhat << " ), j = ";
			cin >> j;
		} while (j<0 || j>vongDauMoiNhat);
		TaoList_KQDB_Vong(kq, a, j);
		XepHang_DenVong(kq, j);
		cout << "\nKet qua xep hang den vong " << j << ":\n";
		Xuat_KQXH(kq);
		break;
	case 6:
		cout << "\n6. Xem ket qua xep hang luot di\n";
		vongDauMoiNhat = VongTD_MoiNhat(a);
		if (vongDauMoiNhat < 19)
			cout << "\nChua het luot di";
		else
		{
			TaoList_KQDB_Vong(kq, a, 19);
			XepHang_DenVong(kq, 19);
			cout << "\nKet qua xep hang cac doi den het luot di :\n";
			Xuat_KQXH(kq);
		}
		break;
	case 7:
		cout << "\n7. Xem ket qua chung cuoc\n";
		vongDauMoiNhat = VongTD_MoiNhat(a);
		if (vongDauMoiNhat < 38)
			cout << "\nGiai chua ket thuc";
		else
		{
			TaoList_KQDB_Vong(kq, a, 38);
			XepHang_DenVong(kq, 38);
			cout << "\nKet qua xep hang chung cuoc :\n";
			Xuat_KQXH(kq);
		}
		break;
	case 8:
		cout << "\n8. Xem cac tran chua dau tu vong 1 den vong thi dau moi nhat\n";
		vongDauMoiNhat = VongTD_MoiNhat(a);
		if (vongDauMoiNhat < 38)
		{
			cout << "\nDanh sach cac doi chua thi dau voi nhau :\n";
			Xuat_Tran_ChuaDau(a);
		}
		else
			cout << "\nGiai da ket thuc nen khong co tran chua dau!";
		break;
	case 9:
		cout << "\n9. Xuat cac tran chua dau cua doi X\n";
		vongDauMoiNhat = VongTD_MoiNhat(a);
		if (vongDauMoiNhat < 38)
		{
			cout << "\nNhap ten doi : ";
			_flushall();
			cin >> tenDoi;
			cout << "\nDanh sach cac doi chua thi dau voi " << tenDoi << " :\n";
			Xuat_Tran_ChuaDau_CuaDoi(a, tenDoi);
		}
		else
			cout << "\nGiai da ket thuc nen khong co tran chua dau!";
		break;
	case 10:
		cout << "\n10. Xuat ket qua diem tren san khach cua doi X den vong j\n";
		cout << "\nNhap ten doi : ";
		_flushall();
		cin >> tenDoi;
		vongDauMoiNhat = VongTD_MoiNhat(a);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			cout << "\nMuon xem den vong nao? (<= " << vongDauMoiNhat << " ), j = ";
			cin >> j;
		} while (j<0 || j>vongDauMoiNhat);
		TaoKQ_Diem_SanKhach_Vong(kq, a, j);
		cout << "\nKet qua diem tren san khach cua doi " << tenDoi << " den vong " << j << " :\n";
		XuatKQ_Diem(kq, tenDoi);
		break;
	case 11:
		cout << "\n11. Xuat ket qua diem tren san nha cua doi X den vong j\n";
		cout << "\nNhap ten doi : ";
		_flushall();
		cin >> tenDoi;
		vongDauMoiNhat = VongTD_MoiNhat(a);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			cout << "\nMuon xem den vong nao? (<= " << vongDauMoiNhat << " ), j = ";
			cin >> j;
		} while (j<0 || j>vongDauMoiNhat);
		TaoKQ_Diem_SanNha_Vong(kq, a, j);
		cout << "\nKet qua diem tren san nha cua doi " << tenDoi << " den vong " << j << " :\n";
		XuatKQ_Diem(kq, tenDoi);
		break;
	case 12:
		cout << "\n12. Xuat ket qua xep hang cua cac doi chi tinh tren san doi phuong\n";
		TaoKQ_Diem_SanKhach_Vong(kq, a, 38);
		XepHang_DenVong(kq, j);
		cout << "\nKet qua xep hang cua cac doi chi tinh tren san doi phuong den het 38 vong:\n";
		Xuat_KQXH(kq);
		break;
	default:
		break;
	}
	_getch();
}