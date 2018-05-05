void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, LIST &l);

void XuatMenu()
{
	cout << "\n============================ HE THONG CHUC NANG ============================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim x Co/Khong?";
	cout << "\n4. Tim x - Tra ve vi nut dau tien xuat hien neu co";
	cout << "\n5. Tim x - Tra ve vi nut cuoi cung xuat hien neu co";
	cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
	cout << "\n7. Chen x vao dau danh sach";
	cout << "\n8. Chen x vao cuoi danh sach";
	cout << "\n9. Chen x vao danh sach sau nut co du lieu y xuat hien dau tien";
	cout << "\n10. Chen x vao danh sach sau nut co du lieu y xuat hien cuoi cung";
	cout << "\n11. Huy nut dau danh sach";
	cout << "\n12. Huy nut cuoi danh sach";
	cout << "\n13. Huy nut dau tien co x";
	cout << "\n14. Huy nut cuoi cung co x";
	cout << "\n15. Huy cac nut co x";
	cout << "\n16. Huy toan bo danh sach";
	cout << "\n17. Sap tang-Chon truc tiep - Hoan doi du lieu";
	cout << "\n18. Sap tang-Chon - Hoan doi lien ket";
	cout << "\n============================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so trong khoang tu [0,..," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LIST &l)
{
	char filename[MAX];
	data x, y;
	NODE *p;
	int kq;
	LIST l1;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			kq = File_List(filename, l);
			if (!kq)
				cout << "\nLoi mo file ! nhap lai\n";
		} while (!kq);
		cout << "\nDanh sach nhap co " << SoNut(l) << " phan tu : \n\n";
		XuatDS(l);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu\n";
		cout << "\nDanh sach l co " << SoNut(l) << " phan tu : \n";
		XuatDS(l);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim x Co/Khong?\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		p = Search_First(l, x);
		if (p != NULL)
			cout << endl << x << " co khong danh sach";
		else
			cout << endl << x << " khong co khong danh sach";
		cout << endl;
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim x - Tra ve vi nut dau tien xuat hien neu co\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		kq = Search_Node_x_First(l, x);
		if (kq == -1)
			cout << endl << x << " khong co trong danh sach";
		else
			cout << endl << x << " xuat hien dau tien trong danh sach tai nut : " << kq;
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim x - Tra ve vi nut cuoi cung xuat hien neu co\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		kq = Search_Node_x_End(l, x);
		if (kq == -1)
			cout << endl << x << " khong co trong danh sach";
		else
			cout << endl << x << " xuat hien cuoi cung trong danh sach tai nut : " << kq;
		cout << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << "\nNhap x : ";
		cin >> x;
		Search_Node_x(l, x);
		cout << endl;
		break;
	case 7:
		system("CLS");
		cout << "\n7. Chen x vao dau danh sach\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x : ";
		cin >> x;
		InsertHead(l, x);
		cout << "\nDanh sach da chen " << x << " vao dau danh sach:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;
	case 8:
		system("CLS");
		cout << "\n8. Chen x vao cuoi danh sach\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x : ";
		cin >> x;
		InsertTail(l, x);
		cout << "\nDanh sach da chen " << x << " vao cuoi danh sach:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;
	case 9:
		system("CLS");
		cout << "\n9. Chen x vao danh sach sau nut co du lieu y xuat hien dau tien\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x can chen : ";
		cin >> x;
		cout << "\nNhap y can tim kiem : ";
		cin >> y;
		Insert_x_After_first_y(l, y, x);
		cout << "\nDanh sach da chen " << x << " vao danh sach sau vi tri dau tien " << y << " xuat hien:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;
	case 10:
		system("CLS");
		cout << "\n10. Chen x vao danh sach sau nut co du lieu y xuat hien cuoi cung\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x can chen : ";
		cin >> x;
		cout << "\nNhap y can tim kiem : ";
		cin >> y;
		Insert_x_After_End_y(l, y, x);
		cout << "\nDanh sach da chen " << x << " vao DS sau vi tri dau tien " << y << " xuat hien:\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;
	case 11:
		system("CLS");
		cout << "\n11. Huy nut dau danh sach\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		RemoveHead(l);
		cout << "\nDanh sach sau khi huy nut dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;
	case 12:
		system("CLS");
		cout << "\n12. Huy nut cuoi danh sach\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		RemoveTail(l);
		cout << "\nDanh sach sau khi huy nut cuoi :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		break;
	case 13:
		system("CLS");
		cout << "\n13. Huy nut dau tien co x\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x = ";
		cin >> x;
		kq = RemoveNode_First(l, x);
		if (!kq)

			cout << endl << x << " khong co trong danh sach\n";
		else
		{
			cout << "\nDanh sach sau khi huy nut dau tien co " << x << ":\n";
			XuatDS(l);
			cout << endl;
			cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		}
		break;
	case 14:
		system("CLS");
		cout << "\n14. Huy nut cuoi cung co x\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x = ";
		cin >> x;
		kq = RemoveNode_End(l, x);
		if (!kq)
			cout << endl << x << " khong co trong danh sach\n";
		else
		{
			cout << "\nDanh sach sau khi huy nut dau tien co " << x << ":\n";
			XuatDS(l);
			cout << endl;
			cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		}
		break;
	case 15:
		system("CLS");
		cout << "\n15. Huy cac nut co x\n";
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x = ";
		cin >> x;
		if (!RemoveNode_First(l, x))
			cout << "\nKhong co " << x << " trong danh sach, danh sach khong doi\n";
		else
		{
			Remove_x(l, x);
			cout << "\nDanh sach sau khi huy cac nut  co " << x << ":\n";
			XuatDS(l);
			cout << endl;
			cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		}
		break;
	case 16:
		system("CLS");
		cout << "\n16. Huy toan bo danh sach\n";
		Copy(l1, l);
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		RemoveList(l);
		cout << endl << "Danh sach sau khi huy tat ca cac phan tu:\n";
		XuatDS(l);
		cout << "\nPhuc hoi lai danh sach nhu truoc khi huy";
		Copy(l, l1);
		cout << "\nDanh sach da phuc hoi :\n";
		XuatDS(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		break;
	case 17:
		system("CLS");
		cout << "\n17. Sap tang-Chon truc tiep - Hoan doi du lieu\n";
		Copy(l1, l);
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l1);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l1) << " phan tu.\n";
		List_Selection_Sort1(l1);
		cout << endl << "Danh sach sau khi sap tang:\n";
		XuatDS(l1);
		cout << endl;
		break;
	case 18:
		system("CLS");
		cout << "\n18. Sap tang-Chon - Hoan doi lien ket\n";
		Copy(l1, l);
		cout << "\nDanh sach ban dau :\n";
		XuatDS(l1);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l1) << " phan tu.\n";
		system("PAUSE");
		List_Selection_Sort2(l1);
		cout << endl << "Danh sach sau khi sap tang:\n";
		XuatDS(l1);
		cout << endl;
		break;
	}
	_getch();
}