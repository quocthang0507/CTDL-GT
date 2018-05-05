void XuatMenu()
{
	cout << "\n=======================He thong chuc nang============================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Xem lich thi dau vong j";
	cout << "\n2. Xem lich thi dau toan giai";
	cout << "\n3. Xem ket qua thi dau vong j";
	cout << "\n4. Xem ket qua thi dau den vong j (tu v1 den vj)";
	cout << "\n5. Xem bang ket qua xep hang den vong j";
	cout << "\n6. Xem ket qua xep hang luot di";
	cout << "\n7. Xem ket qua chung cuoc";
	cout << "\n=====================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nChon 1 so trong khoang [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, KQXepHang kq[MAX], int sd, KetQuaTranDau a[MAX], int &st)
{
	int j;
	int vongDauMoiNhat;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Xem lich thi dau vong j";
		cout << "\nCho biet vong nao : j = ";
		cin >> j;
		Xuat_LTD_Vong_j(a, st, j);
		_getch();
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem lich thi dau toan giai";
		cout << "\nLICH THI DAU TOAN GIAI:\n";
		Xuat_LTD_DenVong_j(a, st, 38);
		_getch();
		break;
	case 3:
		system("CLS");
		cout << "\n3. Xem ket qua thi dau vong j";
		vongDauMoiNhat = VongTD_MoiNhat(a, st);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			system("CLS");
			cout << "\nMuon xem vong nao? ( <= vongDauMoiNhat = " << vongDauMoiNhat << " ): j = ";
			cin >> j;
		} while (j < 0 || j > vongDauMoiNhat);
		system("CLS");
		Xuat_KQTD_Vong_j(a, st, j);
		_getch();
		break;
	case 4:
		system("CLS");
		cout << "\n4. Xem ket qua thi dau den vong j";
		vongDauMoiNhat = VongTD_MoiNhat(a, st);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			system("CLS");
			cout << "\nMuon xem den vong nao? ( <= vongDauMoiNhat = " << vongDauMoiNhat << " ): j = ";
			cin >> j;
		} while (j < 0 || j > vongDauMoiNhat);
		system("CLS");
		Xuat_KQTD_DenVong_j(a, st, j);
		_getch();
		break;
	case 5:
		system("CLS");
		cout << "\n5. Xem bang ket qua xep hang den vong j";
		vongDauMoiNhat = VongTD_MoiNhat(a, st);
		cout << "\nGiai chi moi thi dau toi vong " << vongDauMoiNhat;
		do
		{
			cout << "\nMuon xem den vong nao? ( <= vongDauMoiNhat = " << vongDauMoiNhat << " ): j = ";
			cin >> j;
		} while (j < 0 || j > vongDauMoiNhat);
		TaoBang_KQ_Vong(kq, sd, a, j);
		XepHang_DenVong(kq, sd, j);
		system("CLS");
		cout << "\nKet qua xep hang den vong " << j << " :\n";
		Xuat_KQXH(kq, sd);
		_getch();
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xem Ket qua xep hang luot di";
		vongDauMoiNhat = VongTD_MoiNhat(a, st);
		if (vongDauMoiNhat < 19)
			cout << "\nChua het luot di";
		else
		{
			TaoBang_KQ_Vong(kq, sd, a, 19);
			XepHang_DenVong(kq, sd, 19);
			system("CLS");
			cout << "\nKet qua xep hang cac doi den het luot di :\n";
			Xuat_KQXH(kq, sd);
		}
		_getch();
		break;
	case 7:
		system("CLS");
		cout << "\n7. Ket qua chung cuoc";
		vongDauMoiNhat = VongTD_MoiNhat(a, st);
		if (vongDauMoiNhat < 38)
			cout << "\nGiai chua ket thuc";
		else
		{
			TaoBang_KQ_Vong(kq, sd, a, 38);
			XepHang_DenVong(kq, sd, 38);
			system("CLS");
			cout << "\nKet qua xep hangchung cuoc :\n";
			Xuat_KQXH(kq, sd);
		}
		_getch();
		break;
	}
}