void XuatMenu()
{
	cout << "\n========================= HE THONG CHUC NANG =========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim x - Co / Khong";
	cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
	cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
	cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
	cout << "\n7. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
	cout << "\n8. Chen x vao dau danh sach vong";
	cout << "\n9. Chen x vao cuoi danh sach vong";
	cout << "\n10. Huy nut dau danh sach vong";
	cout << "\n11. Huy nut cuoi danh sach vong";
	cout << "\n12. Huy toan bo danh sach vong";
	cout << "\n13. Dem so nut danh sach vong";
	cout << "\n==================================================================";
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

void XuLyMenu(int menu, LLIST &l)
{
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		cout << "\n1. Tao du lieu";
		break;
	case 2:
		cout << "\n2. Xem du lieu";
		break;
	case 3:
		cout << "\n3. Tim x - Co / Khong";
		break;
	case 4:
		cout << "\n4. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
		break;
	case 5:
		cout << "\n5. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
		break;
	case 6:
		cout << "\n6. Tim x - Xuat cac vi tri xuat hien neu co";
		break;
	case 7:
		cout << "\n7. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
		break;
	case 8:
		cout << "\n8. Chen x vao dau danh sach vong";
		break;
	case 9:
		cout << "\n9. Chen x vao cuoi danh sach vong";
		break;
	case 10:
		cout << "\n10. Huy nut dau danh sach vong";
		break;
	case 11:
		cout << "\n11. Huy nut cuoi danh sach vong";
		break;
	case 12:
		cout << "\n12. Huy toan bo danh sach vong";
		break;
	case 13:
		cout << "\n13. Dem so nut danh sach vong";
		break;
	default:
		break;
	}
}