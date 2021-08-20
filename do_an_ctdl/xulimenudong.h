#pragma once
//Xu Li Doc Gia
void NhapDocGia(DSDocGia& dsDG, int toadoX, int toadoY)  //toadoX=95, toadoY=17
{
	textcolor(112);
	if (dsDG.sl == MaxRanDom)
	{
		GiaoDienThongBao("Bo Nho Day");
		return;
	}

	DocGia dg;
	dg.maDG = mangRanDomMaTheDG[soLgSoConLai - 1];
	dg.phai = 1;
	dg.trangthai = 1;
	dg.soSachDangmuon = 0;

	int pointer1 = toadoY;

	ToMauHCN(5, 1, 200, 7, 96);
	ToMauHCN(5, 7, 200, 44, 112);
	VeKhung(5, 1, 200, 50, 7);
	gotoXY(95, 4);
	textcolor(96);
	cout << "THEM DOC GIA";

	GiaoDienThemDocGia(toadoX, toadoY);
	textcolor(112);
	gotoXY(toadoX + 2, toadoY - 2);
	cout << dg.maDG;
	gotoXY(toadoX + 2, toadoY + 7);
	cout << dg.phai;

	ShowCur(1);//hien
	while (true)
	{
		if (pointer1 == toadoY) // nhap ho va ten lot
		{
			gotoXY(toadoX + 2 + dg.ho.length(), pointer1 + 1);
			XuLyNhapChu(dg.ho, toadoX + 2, pointer1, 30);
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 9;
			}
		}
		else if (pointer1 == toadoY + 3) // nhap ten
		{
			gotoXY(toadoX + 2 + dg.ten.length(), pointer1 + 1);
			XuLyNhapChu(dg.ten, toadoX + 2, pointer1, 8);  
		}
		else if (pointer1 == toadoY + 6) // gioi tinh
		{
			gotoXY(toadoX + 2 + DemChuSo(dg.phai), pointer1 + 1);
			XuLyNhapSo(dg.phai, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 9) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (!dg.ho.empty() && !dg.ten.empty() && (dg.phai == 1 || dg.phai == 2) && pointer2 == toadoX + 15)
						{
							DinhDangChuoi(dg.ho);
							DinhDangChuoi(dg.ten);

							ThemDocGia(dsDG.tree,dg);
							dsDG.sl++;
							soLgSoConLai--;
							GiaoDienThongBao("THEM THANH CONG");
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						else
						{
							gotoXY(90, 30);
							textcolor(112);
							cout << "VUI LONG DIEN DAY DU THONG TIN";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = toadoY;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
					}
				}

				SetColor(4);
				gotoXY(pointer2, pointer1 + 1);
				if (pointer2 == toadoX + 15)
				{
					cout << "XAC NHAN";
					textcolor(112);
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "HUY";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "HUY";
					textcolor(112);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "XAC NHAN";
				}
			}
		}
	}
}
void XuatThongTinDG(DocGia dg, int toadoX, int toadoY)
{
	ToMauHCN(5, 7, 200, 44, 112);
	GiaoDienXuatDSDocGia(toadoX, toadoY, 1);
	
	textcolor(112);
	gotoXY(toadoX, toadoY-2);
	cout << "THONG TIN DOC GIA";

	gotoXY(toadoX + 1, toadoY + 4);
	cout << "1";
	gotoXY(toadoX +7+ 1, toadoY + 4 );
	cout << dg.maDG;
	gotoXY(toadoX + 17 + 1, toadoY + 4);
	cout << dg.ho + " " + dg.ten;
	gotoXY(toadoX + 57 + 1, toadoY + 4 );
	cout << TrangThaiGioiTinh(dg.phai);
	gotoXY(toadoX + 67 + 1, toadoY + 4 );
	cout << TrangThaiDocGia(dg.trangthai);
	gotoXY(toadoX + 80 + 1, toadoY + 4 );
	cout << dg.soSachDangmuon;
	
	ToMauHCN(toadoX + 20, toadoY + 8, 52, 4, 96);
	gotoXY(toadoX+22, toadoY + 10);
	cout << "VUI LONG KIEM TRA LAI THONG TIN ( ECS: De Thoat )";
}
void XuatDSDG(NodeDG* t, int& n, int toadoX, int toadoY)
{
	if (t == NULL)
	{
		return;
	}

	XuatDSDG(t->pleft, n, toadoX, toadoY);

	gotoXY(toadoX + 1, toadoY + 4 + n * 2);
	cout << n + 1;
	gotoXY(toadoX +7 + 1, toadoY + 4 + n * 2);
	cout << t->data.maDG;
	gotoXY(toadoX + 17 + 1, toadoY + 4 + n * 2);
	cout << t->data.ho + " " + t->data.ten;
	gotoXY(toadoX + 57 + 1, toadoY + 4 + n * 2);
	cout << TrangThaiGioiTinh(t->data.phai);
	gotoXY(toadoX + 67 + 1, toadoY + 4 + n * 2);
	cout << TrangThaiDocGia(t->data.trangthai);
	gotoXY(toadoX + 80 + 1, toadoY + 4 + n * 2);
	cout << t->data.soSachDangmuon;

	n++;
	XuatDSDG(t->pright, n, toadoX, toadoY);
}
void XuatDSDG(DSDocGia dsDG, int x, int y) {
	if (dsDG.sl > 15) {
		VeKhung(5, 1, 200, y + 3 + (2 * dsDG.sl + 3) + 3, 7);
		ToMauHCN(5, 7, 200, y + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}
	gotoXY(x + 40, y + 1);
	textcolor(96);
	cout << "DANH SACH DOC GIA";
	int n = 0;
	textcolor(112);
	XuatDSDG(dsDG.tree, n, x, y + 3);
	GiaoDienXuatDSDocGia(x, y + 3, n);
}
void XoaDocGia(DSDocGia& dsDG, int toadoX, int toadoY)//55,13
{
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(97, 4);
	textcolor(96);
	cout << "XOA DOC GIA";
	XuatDSDG(dsDG, toadoX, toadoY);

	textcolor(112);
	int maDG = 0;
	NodeDG* nodeDG = NULL;
	do
	{
		VeHCN(toadoX + 35, toadoY - 4, 50, 2);
		gotoXY(toadoX, toadoY - 3);
		cout << "NHAP MA DOC GIA(ESC:De Thoat): ";

		gotoXY(toadoX + 37, toadoY-3);
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		nodeDG = timMaDG(dsDG.tree, maDG);
		if (nodeDG == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			textcolor(112);
			gotoXY(toadoX + 37, toadoY - 3);
			cout << "                                        ";
			XuatDSDG(dsDG, toadoX, toadoY);
		}
	} while (nodeDG == NULL);

	if (nodeDG->data.soSachDangmuon > 0)
	{
		GiaoDienThongBao("DOC GIA CON DANG MUON SACH");
		return;
	}
	if (dsDG.sl > 15) {
		ToMauHCN(5,7, 200, toadoY + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5,7, 200, 44, 112);
	}
	XuatThongTinDG(nodeDG->data, 55, toadoY);
	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == 27)
			{
				return;
			}
			else
				break;
		}
	}

	XoaDocGiaTheoMaDG(dsDG.tree, maDG);
	dsDG.sl--;
	GiaoDienThongBao("XOA THANH CONG");
}
void SuaDocGia(DSDocGia& dsDG, int toadoX, int toadoY)
{
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(95, 4);
	textcolor(96);
	cout << "HIEU CHINH DOC GIA";
	int x = 55, y = 13;
	XuatDSDG(dsDG,x,y);
	textcolor(112);
	int maDG = 0;
	NodeDG* temp = NULL;
	do
	{
		VeHCN(x + 35, y - 4, 50, 2);
		gotoXY(x, y - 3);
		cout << "NHAP MA DOC GIA(ESC:De Thoat): ";

		gotoXY(x + 37, y - 3);
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		temp = timMaDG(dsDG.tree, maDG);
		if (temp == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			textcolor(112);
			gotoXY(x + 37, y - 3);
			cout << "                                        ";
			XuatDSDG(dsDG, x, y);
		}
	} while (temp == NULL);

	if (dsDG.sl > 15) {
		ToMauHCN(5, 7, 200, y + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}

	DocGia dg = temp->data;
	ToMauHCN(5, 7, 200, 44, 112);
	int pointer1 = toadoY;
	GiaoDienThemDocGia(toadoX, toadoY);
	gotoXY(toadoX + 2, toadoY - 2);
	cout << dg.maDG;
	gotoXY(toadoX + 2, toadoY + 1);
	cout << dg.ho;
	gotoXY(toadoX + 2, toadoY + 4);
	cout << dg.ten;
	gotoXY(toadoX + 2, toadoY + 7);
	cout << dg.phai;

	while (true)
	{
		if (pointer1 == toadoY) 
		{
			gotoXY(toadoX + 2 + dg.ho.length(), pointer1 + 1);
			XuLyNhapChu(dg.ho, toadoX + 2, pointer1, 30);
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 9;
			}
		}
		else if (pointer1 == toadoY + 3) 
		{
			gotoXY(toadoX + 2 + dg.ten.length(), pointer1 + 1);
			XuLyNhapChu(dg.ten, toadoX + 2, pointer1, 8);
		}
		else if (pointer1 == toadoY + 6) 
		{
			gotoXY(toadoX + 3, pointer1 + 1);
			XuLyNhapSo(dg.phai, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 9) 
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (!dg.ho.empty() && !dg.ten.empty() && (dg.phai == 1 || dg.phai == 2) && pointer2 == toadoX + 15)
						{
							DinhDangChuoi(dg.ho);
							DinhDangChuoi(dg.ten);
							temp->data = dg;
							GiaoDienThongBao("HIEU CHINH THANH CONG");
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						else
						{
							gotoXY(90, 30);
							textcolor(112);
							cout << "VUI LONG DIEN DAY DU THONG TIN";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(112);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = toadoY;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
					}
				}

				SetColor(4);
				gotoXY(pointer2, pointer1 + 1);
				if (pointer2 == toadoX + 15)
				{
					cout << "XAC NHAN";
					textcolor(112);
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "HUY";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "HUY";
					textcolor(112);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "XAC NHAN";
				}
			}
		}
	}
}

void XuatDSDGBangMang(DocGia a[], int n, int toadoX, int toadoY)
{
	int j = 0;
	textcolor(112);
	for (int i = 0; i < n; i++)
	{
		gotoXY(toadoX + 1, toadoY + 4 + j);
		cout << i + 1;
		gotoXY(toadoX + 7 + 1, toadoY + 4 + j);
		cout << a[i].maDG;
		gotoXY(toadoX + 17 + 1, toadoY + 4 + j);
		cout << a[i].ho + " " + a[i].ten;
		gotoXY(toadoX + 57 + 1, toadoY + 4 + j);
		cout << TrangThaiGioiTinh(a[i].phai);
		gotoXY(toadoX + 67 + 1, toadoY + 4 + j);
		cout << TrangThaiDocGia(a[i].trangthai);
		gotoXY(toadoX + 80 + 1, toadoY + 4 + j);
		cout << a[i].soSachDangmuon;

		j = j + 2;
	}
	GiaoDienXuatDSDocGia(toadoX, toadoY, n);
	getch();
}
void XuatDSDGTheoHoTen(DSDocGia& dsDG, int toadoX, int toadoY)
{
	int n = 0;
	DocGia* a = new DocGia[dsDG.sl];
	chuyenCaySangMang(dsDG.tree, a, n);
	sapXepDGTheoHoTenBangMang(a, n);
	
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(90, 4);
	cout << "DANH SACH DOC GIA THEO HO + TEN";
	if (n > 18) {
		VeKhung(5, 1, 200, 7 + (2 * n + 3) + 5, 7);
		ToMauHCN(5, 7, 200,(2*n+3)+6, 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}
	
	textcolor(112);
	XuatDSDGBangMang(a, n, toadoX - 20, toadoY);
	delete[]a;

	if (n > 18) {
		ToMauHCN(3, 51, 204, (2 * n + 3) + 6 - 43, 240);
	}
}
void XuatDSDGTheoMaDGTangDan(DSDocGia& dsDG, int toadoX, int toadoY)
{
	int n = 0;
	
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(90, 4);
	cout << "DANH SACH DOC GIA THEO MA DOC GIA";
	if (dsDG.sl > 18) {
		VeKhung(5, 1, 200, 7 + (2 * dsDG.sl + 3) + 5, 7);
		ToMauHCN(5, 7, 200, (2 * dsDG.sl + 3) + 6, 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}

	textcolor(112);
	XuatDSDG(dsDG.tree, n, toadoX-20, toadoY);
	GiaoDienXuatDSDocGia(toadoX-20, toadoY, n);
	getch();
	
	if (dsDG.sl > 18) {
		ToMauHCN(3, 51, 204, (2 * n + 3) + 6 - 43, 240);
	}
}
void xuatDSDGMuonTheoQuaHanGiamDan(DSDocGia dsDG, int toadoX, int toadoY) {
	NodeMuonTra* mangMtQuaHan[100];
	DocGia mangDG[100];
	int n = 0;

	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(95, 4);
	cout << "DANH SACH DOC GIA MUON QUA HAN";
	ToMauHCN(5, 7, 200, 44, 112);

	XuLiMuonTraTheoTGGiamDan(dsDG.tree, mangMtQuaHan, mangDG, n);

	if (n == 0) {
		GiaoDienThongBao("CHUA CO DOC GIA MUON QUA HAN");
		return;
	}

	XuatDSDGBangMang(mangDG, n, toadoX-20, toadoY);
}
void MenuXuatDG(string menuXuatDG[],int toadoX,int toadoY) {
	textcolor(112);
	GiaoDienMenu(toadoX, toadoY,4,menuXuatDG,6);
}
void RunXuatDSDG(string menuXuatDG[],DSDocGia dsDg, int toadoX, int toadoY,int &pointer1,bool &kt) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				MenuXuatDG(menuXuatDG,toadoX, toadoY);
				if (pointer1 == 13)
				{
					pointer1 = 16;
				}
				else
				{
					pointer1--;
				}
			}
			else if (c == 80) //xuong
			{
				MenuXuatDG(menuXuatDG, toadoX, toadoY);
				if (pointer1 == 16)
				{
					pointer1 = 13;
				}
				else
				{
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer1) {
			case 13: {
				XuatDSDGTheoHoTen(dsDg, 85, 10);
				break;
			}
			case 14: {
				XuatDSDGTheoMaDGTangDan(dsDg, 85, 10);
				break;
			}
			case 15: {
				xuatDSDGMuonTheoQuaHanGiamDan(dsDg, 85, 17);
				break;
			}
			case 16: {
				kt = false;
				break;
			}
			}
			if (pointer1 != 16) {
				VeKhung(5, 1, 200, 50, 7);
				ToMauHCN(5, 1, 200, 6, 96);
				gotoXY(95, 4);
				cout << "XUAT DANH SACH DOC GIA";
				ToMauHCN(5, 7, 200, 44, 112);
				MenuXuatDG(menuXuatDG, toadoX, toadoY);
			}
		}
		ToMauHCN(toadoX, 13 + (pointer1 - 13) * 8, 50,6, 96);
		gotoXY(toadoX + (50 - menuXuatDG[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 8);
		cout << menuXuatDG[pointer1 - 13];
	}
}
void InDanhSachDocGia(DSDocGia dsDg,int toadoX, int toadoY) {
	string menuXuatDG[] = {
		"XUAT DANH SACH DOC GIA THEO TEN",
		"XUAT DANH SACH DOC GIA THEO MA DOC GIA",
		"XUAT DANH SACH DOC GIA MUON QUA HAN",
		"THOAT"
	};
	int pointer1 = toadoY;
	bool kt = true;
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(95,4);
	cout << "XUAT DANH SACH DOC GIA";
	ToMauHCN(5, 7, 200, 44, 112);
	MenuXuatDG(menuXuatDG, toadoX, toadoY);
	ToMauHCN(toadoX, toadoY, 50, 6, 96);
	gotoXY(toadoX + (50 - menuXuatDG[0].length()) / 2, toadoY + 3);
	textcolor(96);
	cout << menuXuatDG[0];
	
	while (kt) {
		RunXuatDSDG(menuXuatDG, dsDg, toadoX, toadoY, pointer1,kt);
	}
}

//Xu Li Sach
void NhapDauSach(DSDauSach& dsDs, int toadoX, int toadoY)
{
	DAUSACH ds;
	ds.soLanMuon = 0;
	string vitri = "";

	int pointer1 = toadoY;
	GiaoDienNhapDauSach(toadoX, toadoY);
	textcolor(112);
	ShowCur(1);

	while (true)
	{
		if (pointer1 == toadoY)
		{
			gotoXY(toadoX + 2 + ds.ISBN.length(), pointer1 + 1);
			XuLyNhapMa(ds.ISBN,toadoX+2,pointer1,10);
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 24;
			}
		}
		else if (pointer1 == toadoY + 3) 
		{
			gotoXY(toadoX + 2 + ds.tensach.length(), pointer1 + 1);
			XuLyNhapChu(ds.tensach, toadoX + 2, pointer1, 35);
		}
		else if (pointer1 == toadoY + 6) 
		{
			gotoXY(toadoX + 2 + DemChuSo(ds.sotrang), pointer1 + 1);
			XuLyNhapSo(ds.sotrang, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 9)
		{
			gotoXY(toadoX + 2 + ds.tacgia.length(), pointer1 + 1);
			XuLyNhapChu(ds.tacgia, toadoX + 2, pointer1, 24);
		}
		else if (pointer1 == toadoY + 12) 
		{
			gotoXY(toadoX + 2 + DemChuSo(ds.nxb), pointer1 + 1);
			XuLyNhapSo(ds.nxb, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 15)
		{
			gotoXY(toadoX + 2 + ds.theloai.length(), pointer1 + 1);
			XuLyNhapChu(ds.theloai, toadoX + 2, pointer1, 20);
		}
		else if (pointer1 == toadoY + 18)
		{
			gotoXY(toadoX + 2 +vitri.length(), pointer1 + 1);
			XuLyNhapChu(vitri, toadoX + 2, pointer1, 20);
		}
		else if (pointer1 == toadoY + 21)
		{
			gotoXY(toadoX + 2 + DemChuSo(ds.dms.sl), pointer1 + 1);
			XuLyNhapSo(ds.dms.sl, toadoX + 2 , pointer1);
		}
		else if (pointer1 == toadoY + 24)
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						DAUSACH* temp = timDauSach(dsDs, ds.ISBN);

						if (!ds.ISBN.empty() && temp==NULL && !ds.tensach.empty() && (ds.sotrang>0) && !ds.tacgia.empty()
													&& ds.nxb>0 && !ds.theloai.empty() && !vitri.empty()
															&& (ds.dms.sl>0) && pointer2 == toadoX + 15)
						{
							DinhDangChuoi(ds.tensach);
							DinhDangChuoi(ds.tacgia);
							DinhDangChuoi(ds.theloai);
							DinhDangChuoi(vitri);

							for (int i = 1; i <= ds.dms.sl; i++) {
								Sach sach;
								sach.masach = NoiChuoi(ds.ISBN, i);
								sach.trangthai = 0;
								sach.vitri = vitri;
								themSach(ds.dms, sach);
							}
							themDauSach(dsDs, ds);

							GiaoDienThongBao("THEM THANH CONG");
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						else
						{
							if (temp != NULL)
							{
								gotoXY(107, 46);
								cout << "                                 ";
								gotoXY(107, 46);
								cout << "MA DAU SACH DA TON TAI";
							}
							else
							{
								gotoXY(107, 46);
								cout << "VUI LONG DIEN DAY DU THONG TIN";
							}
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							gotoXY(toadoX + 30, toadoY + 25);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 25);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{

							gotoXY(toadoX + 30, toadoY + 25);
							cout << "HUY";
							gotoXY(toadoX + 15, toadoY + 25);
							cout << "XAC NHAN";
							ShowCur(1);
							pointer1 = toadoY;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
					}
				}

				SetColor(4);
				gotoXY(pointer2, pointer1 + 1);
				if (pointer2 == toadoX + 15)
				{
					cout << "XAC NHAN";
					textcolor(112);
					gotoXY(toadoX + 30, toadoY + 25);
					cout << "HUY";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "HUY";
					textcolor(112);
					gotoXY(toadoX + 15, toadoY + 25);
					cout << "XAC NHAN";
				}
			}
		}
	}
}

void XuatDanhSachDMS(DMSach dsSach, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (NodeSach* k = dsSach.phead; k != NULL; k = k->pNext)
	{
		gotoXY(toadoX + 1, toadoY + 4 + j);
		cout << k->data.masach;
		gotoXY(toadoX + 26 + 1, toadoY + 4 + j);
		cout << TrangThaiSach(k->data.trangthai);
		gotoXY(toadoX + 51 + 1, toadoY + 4 + j);
		cout << k->data.vitri;

		j = j + 2;
	}
	GiaoDienXuatDSDMS(toadoX, toadoY, dsSach.sl);
}
void XuatThongTinSach(DAUSACH* nodeDauSach, int toadoX, int toadoY) {
	system("cls");
	system("color F0");
	VeKhung(5, 1, 200, 50, 7);
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(98, 4);
	textcolor(96);
	cout << "THONG TIN SACH";
	if (nodeDauSach->dms.sl > 12)
	{
		ToMauHCN(5, 7, 200, (nodeDauSach->dms.sl * 2 + 3) + 16, 112);
		VeKhung(5, 1, 200, (nodeDauSach->dms.sl * 2 + 3) + 22, 7);
	}
	else
	{
		ToMauHCN(5, 7, 200, 44, 112);
	}

	int toadoYTemp = toadoY - 5;
	gotoXY(toadoX, toadoYTemp++);
	toadoYTemp++;
	textcolor(112);
	cout << "THONG TIN SACH";
	GiaoDienXuat1DauSach(toadoX, toadoYTemp);
	toadoYTemp += 4;

	gotoXY(toadoX + 1, toadoYTemp);
	cout << nodeDauSach->ISBN;
	gotoXY(toadoX + 12 + 1, toadoYTemp);
	cout << nodeDauSach->tensach;
	gotoXY(toadoX + 53 + 1, toadoYTemp);
	cout << nodeDauSach->tacgia;
	gotoXY(toadoX + 79 + 1, toadoYTemp);
	cout << nodeDauSach->nxb;
	gotoXY(toadoX + 89 + 1, toadoYTemp);
	cout << nodeDauSach->theloai;
	toadoYTemp += 3;
	XuatDanhSachDMS(nodeDauSach->dms, toadoX, toadoYTemp++);
}
void xuLiXuatDSDS(DSDauSach dsds, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (int i = 0; i < dsds.sl; i++) {
		gotoXY(toadoX + 2, toadoY + j + 4);
		cout << i + 1;
		gotoXY(toadoX + 7, toadoY + j + 4);
		cout << dsds.data[i]->ISBN;
		gotoXY(toadoX + 17 + 1, toadoY + j + 4);
		cout << dsds.data[i]->tensach;
		gotoXY(toadoX + 54 + 2, toadoY + j + 4);
		cout << dsds.data[i]->sotrang;
		gotoXY(toadoX + 61 + 1, toadoY + j + 4);
		cout << dsds.data[i]->tacgia;
		gotoXY(toadoX + 87 + 3, toadoY + j + 4);
		cout << dsds.data[i]->nxb;
		gotoXY(toadoX + 96 + 1, toadoY + j + 4);
		cout << dsds.data[i]->theloai;
		gotoXY(toadoX + 118 + 2, toadoY + j + 4);
		cout << dsds.data[i]->dms.sl;
		j = j + 2;
	}
	GiaoDienXuatDSDauSach(toadoX, toadoY, dsds.sl);
}
void menuMaDauSach(DSDauSach dsDs, int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (int i = 0; i < dsDs.sl; i++) {
		ToMauHCN(toadoX +7, toadoY +j- 1, 10, 2, 112);
		gotoXY(toadoX +7, toadoY + j);
		cout << dsDs.data[i]->ISBN;
		j += 2;
	}
}
void GiaoDienMaDauSach(DSDauSach dsds, int toadoX, int toadoY) {
	if (dsds.sl > 17) {
		VeKhung(5, 1, 200, toadoY + (dsds.sl * 2 + 3), 7);
		ToMauHCN(5, 7, 200, toadoY + (dsds.sl * 2 + 3) -6, 112);
		textcolor(112);
		xuLiXuatDSDS(dsds, toadoX, toadoY);
	}
	else
	{
		textcolor(112);
		VeKhung(5, 1, 200, 50, 7);
		xuLiXuatDSDS(dsds, toadoX, toadoY);
	}
	gotoXY(toadoX + 50, toadoY - 4);
	textcolor(96);
	cout << "DANH SACH CAC DAU SACH";
	textcolor(112);
	gotoXY(toadoX, toadoY - 3);
	cout << "Nhan ENTER De Xem Thong Tin Sach";
	gotoXY(toadoX, toadoY - 2);
	cout << "Nhan ESC De Thoat";
}
void RunMenuMaDauSach(DSDauSach dsDs, int toadoX, int toadoY, int &pointer1, bool &kt) {//12
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == toadoY)//12
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 = toadoY + (dsDs.sl - 1) * 2;//12+ 8=20;
				}
				else
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 -= 2;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == toadoY + (dsDs.sl - 1) * 2 )
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 = toadoY;
				}
				else
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 += 2;
				}
			}
		}
		else if (c == 13)
		{
			for (int i = 0; i < dsDs.sl; i++) {
				if (pointer1 - toadoY - i * 2 == 0) {
					XuatThongTinSach(dsDs.data[i], toadoX-7, toadoY);
					getch();
					if (dsDs.data[i]->dms.sl > 12)
					{
						ToMauHCN(5, 7, 200, (dsDs.data[i]->dms.sl * 2 + 3) + 16, 112);
						ToMauHCN(3, 51, 204, (dsDs.data[i]->dms.sl * 2 + 3) + 16 - 43, 240);
					}
					else
					{
						ToMauHCN(5, 7, 200, 44, 112);
					}
					break;
				}
			}
			GiaoDienMaDauSach(dsDs, toadoX, toadoY -4);
		}
		else if (c == 27) {
			kt = false;
		}

		// to mau 
		ToMauHCN(toadoX +7, pointer1 - 1, 10, 2, 96);
		gotoXY(toadoX +7, pointer1);//17
		textcolor(96);
		cout << dsDs.data[(pointer1 - toadoY) / 2]->ISBN;
	}
}
void xuatThongTinDSDS(DSDauSach dsds, int toadoX, int toadoY)
{
	int pointer1 = toadoY + 4;
	bool kt = true;
	GiaoDienMaDauSach(dsds, toadoX, toadoY);
	ToMauHCN(toadoX + 7, toadoY + 3, 10, 2, 96);
	gotoXY(toadoX + 7, toadoY + 4);
	cout << dsds.data[0]->ISBN;
	textcolor(112);

	while (kt) {
		RunMenuMaDauSach(dsds, toadoX, toadoY + 4, pointer1, kt);
	}
}

void xuLiXuatDSDSTheoTheLoai(DSDauSach dsDauSachTemp,int toadoX,int toadoY)
{
	int j = 0;
	textcolor(112);
	GiaoDenXuatDauSachTheoTheLoai(toadoX + 2, toadoY + 1, dsDauSachTemp.sl);
	for (int k = 0; k < dsDauSachTemp.sl; k++)
	{
		gotoXY(toadoX + 1 + 2, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->ISBN;
		gotoXY(toadoX + 12 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->tensach;
		gotoXY(toadoX + 52 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->sotrang;
		gotoXY(toadoX + 59 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->tacgia;
		gotoXY(toadoX + 87 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->nxb;
		gotoXY(toadoX + 95 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->dms.phead->data.vitri;
		gotoXY(toadoX + 122 + 3, toadoY + 5 + j);
		cout << dsDauSachTemp.data[k]->dms.sl;
		j = j + 2;
	}
}
void MenuDSTheLoai(string *dsTheLoai,int n,int toadoX,int toadoY) {//80,10
	GiaoDienMenu(toadoX, toadoY, n, dsTheLoai,4);
	ToMauHCN(80,toadoY + n*5, 50, 4, 240);
	gotoXY(toadoX+22,toadoY + n*5 +2);
	cout << "Thoat";
}
void RunDSTheLoai(DSDauSach dsDs, string* dsTheLoai, int n, int toadoX, int toadoY, int& pointer2, bool& kt2) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer2 == 10)
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2 = 10 + n;
				}
				else
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2--;
				}
			}
			else if (c == 80)
			{
				if (pointer2 == 10 + n)
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2 = 10;
				}
				else
				{
					MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
					pointer2++;
				}
			}
		}
		else if (c == 13)
		{
			if (pointer2 == 10 + n)
			{
				delete[] dsTheLoai;
				kt2 = false;
				return;
			}
			else
			{
				for (int i = 0; i < n ; i++) {
					if (pointer2 == 10 + i ) {
						DSDauSach dsDauSachTemp = layDSDauSachTheoTheLoai(dsDs, dsTheLoai[i]);
						sapXepDSDauSachTheoTen(dsDauSachTemp);

						int x = toadoX - 40;
						ToMauHCN(5, 7, 200, (n + 1) * 5 + 4, 112);
						textcolor(96);
						gotoXY(80 + (50-dsTheLoai[i].length())/2,11);
						cout <<dsTheLoai[i];
						xuLiXuatDSDSTheoTheLoai(dsDauSachTemp, x, toadoY+2);
						getch();
					}
				}
			}
			ToMauHCN(5, 7, 200, (n + 1) * 5 + 4, 112);
			MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY);
		}

		textcolor(96);
		ToMauHCN(toadoX, 10 + (pointer2 - 10) * 5, 50, 4, 96);
		if (pointer2 == 10 + n) {
			gotoXY(toadoX + 22, 12 + (pointer2 - 10) * 5);
			cout << "Thoat";
		}
		else
		{
			gotoXY(toadoX + (50 - dsTheLoai[pointer2 - 10].length()) / 2, 12 + (pointer2 - 10) * 5);
			textcolor(96);
			cout << dsTheLoai[pointer2 - 10];
		}
	}
}
void XuatDSDauSachTheoTheLoai(DSDauSach dsDs, int toadoX, int toadoY) {
	int n = 0, pointer2 = toadoY;
	string* dsTheLoai = layDanhSachTheLoai(dsDs, n);
	ShowCur(0);
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(85, 4);
	textcolor(96);
	cout << "GIAO DIEN XUAT SACH THEO THE LOAI";
	if (n > 7) {
		ToMauHCN(5, 7, 200, (n + 1) * 5 + 4, 112);
		VeKhung(5, 1, 200, 6 + (n + 1) * 5 + 4, 7);
	}
	else
	{
		ToMauHCN(5, 7, 200, 44, 112);
	}
	
	
	MenuDSTheLoai(dsTheLoai, n, toadoX, toadoY); 
	ToMauHCN(toadoX, toadoY, 50, 4, 96);
	textcolor(96);
	gotoXY(toadoX + (50 - dsTheLoai[0].length()) / 2, toadoY + 2);
	cout << dsTheLoai[0];

	bool kt2 = true;
	
	while (kt2) {
		RunDSTheLoai(dsDs, dsTheLoai, n, toadoX, toadoY, pointer2,kt2);
	}
	if (n > 7) {
		ToMauHCN(3, 51, 204, (n + 1) * 5 + 4 - 44 + 1, 240);
		textcolor(112);
	}
}

void In10SachCoSoLanMuonNhieuNhat(DSDauSach dsDs, int toadoX, int toadoY) {

	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(90, 4);
	textcolor(96);
	cout << "10 DAU SACH DUOC MUON NHIEU NHAT";
	ToMauHCN(5, 7, 200, 44, 112);

	DSDauSach dsTemp = dsDs;

	sapXepTheoSoLuotMuon(dsTemp);

	int n = 10;

	if (dsTemp.sl < 10) {
		n = dsTemp.sl;
	}

	int j = 0;
	textcolor(112);

	for (int i = 0; i < n; i++) {
		gotoXY(toadoX + 2, toadoY + j + 4);
		cout << dsTemp.data[i]->ISBN;
		gotoXY(toadoX + 2 + 16, toadoY + j + 4);
		cout << dsTemp.data[i]->tensach;
		gotoXY(toadoX + 2 + 57, toadoY + j + 4);
		cout << dsTemp.data[i]->sotrang;
		gotoXY(toadoX + 2 + 67, toadoY + j + 4);
		cout << dsTemp.data[i]->tacgia;
		gotoXY(toadoX + 2 + 100, toadoY + j + 4);
		cout << dsTemp.data[i]->soLanMuon;

		j = j + 2;
	}

	GiaoDienXuat10DauSachMuonMax(toadoX, toadoY, n);

	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == 27)
			{
				return;
			}
			else
				break;
		}
	}
}

void RunXuatDSDS(DSDauSach dsDs, string menuXuatDSDS[], int toadoX, int toadoY,int& pointer1, bool& kt1) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == 13)
				{
					GiaoDienMenu(toadoX, toadoY, 4, menuXuatDSDS, 6);
					pointer1 = 13 - 1 + 4;
				}
				else
				{
					GiaoDienMenu(toadoX, toadoY, 4, menuXuatDSDS, 6);
					pointer1--;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 13 - 1 + 4)
				{
					GiaoDienMenu(toadoX, toadoY, 4, menuXuatDSDS, 6);
					pointer1 = 13;
				}
				else
				{
					GiaoDienMenu(toadoX, toadoY, 4, menuXuatDSDS, 6);
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer1)
			{
			case 13: {//xuat theo the loai
				XuatDSDauSachTheoTheLoai(dsDs, toadoX, toadoY-3);
				break;
			}
			case 14: {//xuat max
				In10SachCoSoLanMuonNhieuNhat(dsDs, toadoX-30, toadoY+3);
				break;
			}
			case 15: {//xuat tat ca
				ToMauHCN(5, 7, 200, 44, 112);
				xuatThongTinDSDS(dsDs, toadoX-40, toadoY);
				if (dsDs.sl > 15) {
					ToMauHCN(3, 51, 204, toadoY + (dsDs.sl * 2 + 3) - 43, 240);
				}
				break;
			}
			case 16: {
				kt1 = false;
				break;
			}
			}
			if (pointer1 != 16) {
				GiaoDienMain();
				GiaoDienMenu(toadoX, toadoY, 4, menuXuatDSDS, 6);
			}
		}

		// to mau 
		ToMauHCN(80, 13 + (pointer1 - 13) * 8, 50,6, 96);//180//7
		gotoXY(80 + (50 - menuXuatDSDS[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 8);
		textcolor(96);//180
		cout << menuXuatDSDS[pointer1 - 13];
	}
}
void MenuXuatDSDS(DSDauSach dsDs,int toadoX, int toadoY) {
	string menuXuatDSDS[] = {
		"XUAT DAU SACH THEO THE LOAI",
		"XUAT 10 DAU SACH DUOC MUON NHIEU NHAT",
		"XUAT TAT CA DAU SACH",
		"THOAT"
	};
	ToMauHCN(5, 7, 200, 44, 112);
	GiaoDienMenu(toadoX, toadoY, 4, menuXuatDSDS, 6);
	ToMauHCN(toadoX, toadoY, 50, 6, 96);
	gotoXY(toadoX + (50 - menuXuatDSDS[0].length()) / 2, toadoY + 3);
	textcolor(96);
	cout << menuXuatDSDS[0];
	textcolor(112);
	int pointer1 = toadoY;
	bool kt1 = true;
	while (kt1) {
		RunXuatDSDS(dsDs, menuXuatDSDS, toadoX, toadoY, pointer1, kt1);
	}
}

void TimThongTinSachDuaVaoTenSach(DSDauSach dsDs, int toadoX, int toadoY) {
	ToMauHCN(5, 1, 200, 7, 96);
	ToMauHCN(5, 7, 200, 44, 112);
	VeKhung(5, 1, 200, 50, 7);
	gotoXY(92, 4);
	textcolor(96);
	cout << "GIAO DIEN TIM SACH";

	string tenSach;
	DSDauSach dsDSTemp;
	textcolor(112);
	do
	{
		gotoXY(toadoX - 25, toadoY);
		cout << "NHAP TEN SACH CAN TIM( Nhan ESC De Thoat ): ";
		VeHCN(toadoX + 18, toadoY - 1, 51, 2);
		gotoXY(toadoX + 20, toadoY);
		tenSach = XuLyNhapChu();
		if (!tenSach.empty())
			DinhDangChuoi(tenSach);
		if (tenSach.empty())
		{
			return;
		}

		dsDSTemp = timTenSach(dsDs, tenSach);
		if (dsDSTemp.sl <= 0)
		{
			GiaoDienThongBao("TEN SACH KHONG TON TAI");
			ToMauHCN(5, 7, 200, 44, 112);
		}
	} while (dsDSTemp.sl <= 0);

	int pointer1 = toadoY + 4;
	bool kt = true;
	ToMauHCN(toadoX - 27, toadoY - 2, 100, 4, 112);
	GiaoDienMaDauSach(dsDSTemp, toadoX, toadoY);
	ToMauHCN(toadoX + 7, toadoY + 3, 10, 2, 96);
	gotoXY(toadoX + 7, toadoY + 4);
	cout << dsDSTemp.data[0]->ISBN;
	textcolor(112);

	while (kt) {
		RunMenuMaDauSach(dsDSTemp, toadoX, toadoY + 4, pointer1, kt);
	}
}

//Xu Li Muon Tra
void XuatDSSachDangMuon(NodeDG* nodeDG,int toadoX, int toadoY) {
	int j = 0;
	textcolor(112);
	for (NodeMuonTra* k = nodeDG->data.mt.phead; k != NULL; k = k->pNext) {
		if (k->data.trangthai == 0) {
			gotoXY(toadoX + 1, toadoY + 4 + j);
			cout << k->data.masach;
			gotoXY(toadoX + 16+1, toadoY + 4 + j);
			cout << k->data.ngaymuon.ngay << "/" << k->data.ngaymuon.thang << "/" << k->data.ngaymuon.nam;
			gotoXY(toadoX + 27 +1, toadoY + 4 + j);
			cout << TrangThaiMuonTra(k->data.trangthai);
			j = j + 2;
		}
	}
	GiaoDienXuatDanhSachMuon(toadoX, toadoY, nodeDG->data.soSachDangmuon);
}
void xuatGiaoDienMuonSach(DSDauSach dsDs,NodeDG *nodeDG,int toadoX, int toadoY) {
	if (dsDs.sl > 18) {
		VeKhung(5, 1, 200, 10 + (2 * dsDs.sl + 3) + 3, 7);
		ToMauHCN(5, 7, 200, 4 + (2 * dsDs.sl + 3) + 3, 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}

	if (nodeDG->data.soSachDangmuon > 0)
	{
		gotoXY(toadoX - 15, toadoY - 8);
		textcolor(96);
		cout << "DANH SACH SACH DOC GIA DANG MUON";
		XuatDSSachDangMuon(nodeDG, toadoX - 18, toadoY - 7);
	}

	gotoXY(toadoX + 80, toadoY - 8);
	textcolor(96);
	cout << "DANH SACH CAC DAU SACH";
	xuLiXuatDSDS(dsDs, toadoX + 25, toadoY - 7);
}
void nhapMaDauSach(DSDauSach dsDs, DAUSACH*& nodeDauSach, NodeSach*& nodeSach, NodeDG* nodeDG, int toadoX, int toadoY, bool &kt1) {
	int k = toadoY - 7 + 3 + nodeDG->data.soSachDangmuon * 2;
	string maDauSach;
	do
	{
		if (nodeDauSach == NULL || dieuKienMuonSach(nodeDG, nodeDauSach) == false || nodeSach == NULL) {
			gotoXY(100, k + 2);
			ToMauHCN(toadoX - 18, k + 10, 40, 10, 112);
			textcolor(112);
		}

		gotoXY(toadoX - 48, k + 2);
		cout << "NHAP MA DAU SACH(ESC:De Thoat): ";

		maDauSach = XuLyNhapMa(10);
		if (maDauSach.empty())
		{
			kt1 = false;
			return;
		}

		nodeDauSach = timDauSach(dsDs, maDauSach);
		if (nodeDauSach == NULL)
		{
			GiaoDienTam(toadoX - 18, k + 10, 95, 7, "MA DAU SACH KHONG TON TAI");
			textcolor(112);
			gotoXY(toadoX - 48, k + 2);
			cout << "                                                              ";
		}
		else if (dieuKienMuonSach(nodeDG, nodeDauSach) == false)
		{
			GiaoDienTam(toadoX - 18, k + 10, 95, 7, "BAN KHONG THE MUON SACH NAY");
			textcolor(112);
			gotoXY(toadoX - 48, k + 2);
			cout << "                                                                 ";
		}
		else if (nodeDauSach != NULL)
		{
			nodeSach = laySachMuon(nodeDauSach);
			if (nodeSach == NULL) {
				GiaoDienTam(toadoX - 18, k + 10, 95, 7, "SACH NAY DA HET");
				textcolor(112);
				gotoXY(toadoX - 48, k + 2);
				cout << "                                                                 ";
			}
		}
	} while (nodeDauSach == NULL || dieuKienMuonSach(nodeDG, nodeDauSach) == false || nodeSach == NULL);
}
void RunNhapMaDauSach(DSDauSach &dsDs,DSDocGia &dsDG,NodeDG *nodeDG,int toadoX,int toadoY) {
	if (dsDG.sl > 15) {
		ToMauHCN(5, 7, 200, 13 + (2 * dsDG.sl + 3), 112);
	}
	else {
		ToMauHCN(5, 7, 200, 44, 112);
	}
	XuatThongTinDG(nodeDG->data, 55, 17);
	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == 27)
			{
				return;
			}
			else
				break;
		}
	}

	if (nodeDG->data.trangthai == 0)
	{
		GiaoDienTam(toadoX + 23, 29, 95, 7, "THE DA BI KHOA");
		ToMauHCN(5, 7, 200, 44, 112);
		return;
	}
	if (nodeDG->data.soSachDangmuon >= 3)
	{
		GiaoDienThongBao("MOI DOC GIA CHI DUOC MUON TOI DA 3 QUYEN");
		ToMauHCN(5, 7, 200, 44, 112);
		return;
	}
	
	DAUSACH* nodeDauSach = NULL;
	NodeSach* nodeSach = NULL;
	bool kt1 = true;
	while (kt1) {
		xuatGiaoDienMuonSach(dsDs, nodeDG, toadoX, toadoY);
		if (nodeDG->data.soSachDangmuon >= 3)
		{
			GiaoDienThongBao("MOI DOC GIA CHI DUOC MUON TOI DA 3 QUYEN");
			ToMauHCN(5, 7, 200, 44, 112);
			return;
		}
		nhapMaDauSach(dsDs, nodeDauSach, nodeSach, nodeDG, toadoX, toadoY, kt1);
		if (nodeDauSach != NULL && nodeSach != NULL && kt1 != false) {
			xuLiMuonSach(nodeDG, nodeDauSach, nodeSach);
			GiaoDienThongBao("MUON SACH THANH CONG");
		}
	}
}
void MuonSach(DSDocGia &dsDG, DSDauSach &dsDs, int toadoX, int toadoY) {
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(97, 4);
	cout << "MUON SACH";
	ToMauHCN(5, 7, 200, 44, 112);
	
	int x = 55, y = 13;

	NodeDG* nodeDG = NULL;
	textcolor(112);
	int maDG = 0;

	do
	{
		XuatDSDG(dsDG, x, y);
		VeHCN(x + 35, y - 4, 50, 2);
		gotoXY(x, y - 3);
		cout << "NHAP MA DOC GIA(ESC:De Thoat): ";

		gotoXY(x + 37, y - 3);
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		nodeDG = timMaDG(dsDG.tree, maDG);
		if (nodeDG == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			textcolor(112);
			gotoXY(x + 37, y - 3);
			cout << "                                        ";
		}
		else
		{
			RunNhapMaDauSach(dsDs, dsDG, nodeDG, toadoX, toadoY);
			if (dsDG.sl > 15) {
				ToMauHCN(5, 7, 200, y + (2 * dsDG.sl + 3) , 112);
			}
			else {
				ToMauHCN(5, 7, 200, 44, 112);
			}

			if (dsDs.sl > 18) {
				ToMauHCN(5, 7, 200, 4 + (2 * dsDs.sl + 3) + 3, 112);
				ToMauHCN(3, 51, 204, 4 + (2 * dsDs.sl + 3) + 3 - 43, 240);
			}
			else if (dsDG.sl > 15) {
				ToMauHCN(3, 51, 204, 13 + (2 * dsDG.sl + 3) - 43, 240);
			}
			textcolor(112);
			nodeDG = NULL;
			maDG = 0;
		}
	} while (nodeDG == NULL);
}

void menuMaSachDangMuon(NodeDG* t,string layDSMaSachMuon[],int n, int toadoX, int toadoY){
	int j = 0;
	textcolor(112);
	for (int i=0;i<n;i++) {
		ToMauHCN(toadoX, toadoY +j -1, 15, 2, 112);
		gotoXY(toadoX + 1, toadoY + j );
		cout << layDSMaSachMuon[i];
		j+=2;
	}
}
void RunMenuTraSach(NodeDG* t, string * layDSMaSachMuon,int n, int toadoX, int toadoY,int &pointer1, int &vt, bool &kt) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == 23)
				{
					menuMaSachDangMuon(t, layDSMaSachMuon,n,toadoX,toadoY);
					pointer1 = 23 + (n-1)*2;
				}
				else
				{
					menuMaSachDangMuon(t, layDSMaSachMuon, n, toadoX, toadoY);
					pointer1-=2;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 23 + (n-1)*2)
				{
					menuMaSachDangMuon(t, layDSMaSachMuon, n, toadoX, toadoY);
					pointer1 = 23;
				}
				else
				{
					menuMaSachDangMuon(t, layDSMaSachMuon, n, toadoX, toadoY);
					pointer1+=2;
				}
			}
		}
		else if (c == 13)
		{
			for (int i = 0; i < n; i++) {
				if (pointer1 - 23 - i*2==0) {
					vt = i;
					kt = false;
					break;
				}
			}
		}
		else if (c == 27) {
			vt = -1;
			kt = false;
			return;
		}

		ToMauHCN(toadoX,pointer1-1, 15, 2, 96);
		gotoXY(toadoX + 1, pointer1);
		textcolor(96);
		cout << layDSMaSachMuon[(pointer1-23)/2];
	}
}
void XuatGiaoDienTraSach(DSDauSach &dsDs, NodeDG *nodeDG, int toadoX, int toadoY, bool &kt1) {
	string* layDSMaSachMuon = new string[3];
	int n = 0;
	for (NodeMuonTra* k = nodeDG->data.mt.phead; k != NULL; k = k->pNext) {
		if (k->data.trangthai == 0)
			layDSMaSachMuon[n++] = k->data.masach;
	}
	ToMauHCN(5, 7, 200, 44, 112);

	GiaoDienXuatDSDocGia(toadoX, toadoY-7, 1);
	textcolor(112);
	gotoXY(toadoX, toadoY - 6 - 2);
	cout << "THONG TIN DOC GIA";
	gotoXY(toadoX + 1, toadoY - 6 + 3);
	cout << "1";
	gotoXY(toadoX + 7 + 1, toadoY - 6 + 3);
	cout << nodeDG->data.maDG;
	gotoXY(toadoX + 17 + 1, toadoY - 6 + 3);
	cout << nodeDG->data.ho + " " + nodeDG->data.ten;
	gotoXY(toadoX + 57 + 1, toadoY - 6 + 3);
	cout << TrangThaiGioiTinh(nodeDG->data.phai);
	gotoXY(toadoX + 67 + 1, toadoY - 6 + 3);
	cout << TrangThaiDocGia(nodeDG->data.trangthai);
	gotoXY(toadoX + 80 + 1, toadoY - 6 + 3);
	cout << nodeDG->data.soSachDangmuon;

	if (nodeDG->data.soSachDangmuon > 0)
	{
		gotoXY(toadoX + 30, toadoY);
		textcolor(96);
		cout << "DANH SACH SACH DOC GIA DANG MUON";
		XuatDSSachDangMuon(nodeDG, toadoX + 25, toadoY + 2);
		textcolor(112);
		gotoXY(toadoX + 25, toadoY + 2 + nodeDG->data.soSachDangmuon * 2 + 5);
		cout << "Nhan: ENTER De Tra Sach";
		gotoXY(toadoX + 25, toadoY + 2 + nodeDG->data.soSachDangmuon * 2 + 6);
		cout << "Nhan: ESC De Thoat";
	}

	int y = toadoY + 5 + 2 * nodeDG->data.soSachDangmuon;
	string maSach;

	menuMaSachDangMuon(nodeDG, layDSMaSachMuon, n, toadoX + 25, 23);
	ToMauHCN(toadoX + 25, 22, 15, 2, 96);
	gotoXY(toadoX + 26, 23);
	cout << layDSMaSachMuon[0];

	textcolor(112);
	bool kt = true;
	int pointer1 = 23;
	int vt = 0;
	while (kt) {
		RunMenuTraSach(nodeDG, layDSMaSachMuon, n, toadoX + 25, 23, pointer1, vt, kt);
	}
	if (vt != -1)
	{
		xuliTraSach(dsDs, nodeDG, layDSMaSachMuon, vt);
		GiaoDienThongBao("TRA SACH THANH CONG");
	}
	else
		kt1 = false;
	delete[] layDSMaSachMuon;
}
void TraSach(DSDocGia &dsDG,DSDauSach& dsDs, int toadoX, int toadoY)
{
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(97, 4);
	cout << "TRA SACH";

	int maDG = 0;
	NodeDG* nodeDG = NULL;
	do
	{
		ToMauHCN(5, 7, 200, 44, 112);
		gotoXY(toadoX - 48, toadoY);
		cout << "NHAP MA DOC GIA ( ESC:De Thoat ): ";
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		nodeDG = timMaDG(dsDG.tree, maDG);
		if (nodeDG == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			ToMauHCN(5, 7, 200, 44, 112);
		}
		else
		{
			bool kt1 = true;
			while (kt1) {
				if (nodeDG->data.soSachDangmuon == 0)
				{
					GiaoDienThongBao("DOC GIA KHONG CO SACH DANG MUON");
					kt1 = false;
				}
				else
				{
					XuatGiaoDienTraSach(dsDs, nodeDG, toadoX, toadoY, kt1);
				}
			}
			textcolor(112);
			nodeDG = NULL;
			maDG = 0;
		}
	} while (nodeDG == NULL);
}

void lietKeCacSachDGDangMuon(DSDocGia dsDG, int toadoX, int toadoY) {
	ToMauHCN(5, 1, 200, 6, 96);
	gotoXY(90, 4);
	cout << "LIET KE SACH DOC GIA DANG MUON";
	ToMauHCN(5, 7, 200, 44, 112);

	int maDG = 0;
	NodeDG* nodeDG = NULL;
	do
	{
		gotoXY(toadoX - 48, toadoY);
		cout << "NHAP MA DOC GIA( ESC:De Thoat ): ";
		maDG = XuLyNhapSo();
		if (maDG == -1)
		{
			return;
		}

		nodeDG = timMaDG(dsDG.tree, maDG);
		if (nodeDG == NULL)
		{
			GiaoDienThongBao("MA DOC GIA KHONG TON TAI");
			ToMauHCN(5, 7, 200, 44, 112);
		}
	} while (nodeDG == NULL);

	ToMauHCN(5, 7, 200, 44, 112);
	//XuatThongTinDG(nodeDG->data, toadoX +10, toadoY);
	GiaoDienXuatDSDocGia(toadoX + 10, toadoY,1);
	textcolor(112);
	gotoXY(toadoX + 10, toadoY - 2);
	cout << "THONG TIN DOC GIA";

	gotoXY(toadoX + 11, toadoY + 4);
	cout << "1";
	gotoXY(toadoX + 7 + 11, toadoY + 4);
	cout << nodeDG->data.maDG;
	gotoXY(toadoX + 17 + 11, toadoY + 4);
	cout << nodeDG->data.ho + " " + nodeDG->data.ten;
	gotoXY(toadoX + 57 + 11, toadoY + 4);
	cout << TrangThaiGioiTinh(nodeDG->data.phai);
	gotoXY(toadoX + 67 + 11, toadoY + 4);
	cout << TrangThaiDocGia(nodeDG->data.trangthai);
	gotoXY(toadoX + 80 + 11, toadoY + 4);
	cout << nodeDG->data.soSachDangmuon;

	if (nodeDG->data.soSachDangmuon > 0)
	{
		gotoXY(toadoX + 10, toadoY + 8);
		textcolor(96);
		cout << "DANH SACH SACH DOC GIA DANG MUON";
		XuatDSSachDangMuon(nodeDG, toadoX + 10, toadoY + 10);
	}
	else
	{
		GiaoDienThongBao("DOC GIA KHONG CO SACH DANG MUON");
		return;
	}
	char c;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == 27)
			{
				return;
			}
			else
				break;
		}
	}
}

void XuLiXoaSach(DAUSACH *&ds,int toadoX, int toadoY,bool &kt1) {
	string masach = "";
	NodeSach* nodeSach = NULL;
	do
	{
		if (ds->dms.sl <= 0) {
			kt1 = false;
			return;
		}
		XuatThongTinSach(ds, toadoX - 7, toadoY);
		textcolor(112);
		gotoXY(toadoX - 7, 10);
		cout << "Nhap Ma Sach Can Xoa (Nhan ESC: De Thoat) : ";
		gotoXY(92, 10);
		masach = XuLyNhapMa(15);
		if (masach.empty())
		{
			kt1 = false;
			return;
		}
		else
			nodeSach = laySachXoa(ds, masach);
		if (nodeSach == NULL)
		{
			GiaoDienTam(85, toadoY,95, 7, "MA SACH KHONG TON TAI");
			textcolor(112);
			gotoXY(92, 10);
			cout << "                                ";
		}
		else if (nodeSach != NULL && nodeSach->data.trangthai != 0)
		{
			GiaoDienTam(85,toadoY, 95, 7, "BAN KHONG THE XOA SACH NAY");
			textcolor(112);
			gotoXY(92, 10);
			cout << "                                ";
		}
		else if (nodeSach != NULL && nodeSach->data.trangthai ==0)
		{
			string s = "Ban Co Chac Chan Xoa " + nodeSach->data.masach + " ?";
			char c;
			while (1) {
				if (kbhit()) {
					GiaoDienThongBao(s);
					c = getch();
					if (c == 27) {
						return;
					}
					else if (c == 13) {
						Xoa1Sach(ds->dms, masach);
						ds->dms.sl--;
						GiaoDienThongBao("XOA SACH THANH CONG");
						return;
					}
				}
			}
		}
	} while (nodeSach == NULL);
}
void RunMenuXoaSach(DSDauSach &dsDs, int toadoX, int toadoY, int& pointer1, bool& kt) {
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer1 == toadoY)
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 = toadoY + (dsDs.sl - 1) * 2;
				}
				else
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 -= 2;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == toadoY + (dsDs.sl - 1) * 2)
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 = toadoY;
				}
				else
				{
					menuMaDauSach(dsDs, toadoX, toadoY);
					pointer1 += 2;
				}
			}
		}
		else if (c == 13)
		{
			for (int i = 0; i < dsDs.sl; i++) {
				if (pointer1 - toadoY - i * 2 == 0) {
					bool kt1 = true;
					while (kt1) {
						if (dsDs.data[i]->dms.sl <= 0)
						{
							delete dsDs.data[i];
							dsDs.sl--;
							GiaoDienThongBao("DAU SACH RONG");
							kt = false;
							return;
						}
						else
							XuLiXoaSach(dsDs.data[i], toadoX, toadoY,kt1);
					}
					if (dsDs.data[i]->dms.sl > 0) {
						if (dsDs.data[i]->dms.sl > 12)
						{
							ToMauHCN(5, 7, 200, (dsDs.data[i]->dms.sl * 2 + 3) + 16, 112);
							ToMauHCN(3, 51, 204, (dsDs.data[i]->dms.sl * 2 + 3) + 16 - 43, 240);
						}
						else
						{
							ToMauHCN(5, 7, 200, 44, 112);
						}
					}
					break;
				}
			}
			GiaoDienMaDauSach(dsDs, toadoX, toadoY - 4);
		}
		else if (c == 27) {
			kt = false;
		}

		// to mau 
		ToMauHCN(toadoX + 7, pointer1 - 1, 10, 2, 96);
		gotoXY(toadoX + 7, pointer1);//17
		textcolor(96);
		cout << dsDs.data[(pointer1 - toadoY) / 2]->ISBN;
	}
}
void XoaSach(DSDauSach& Dsds, int toadoX, int toadoY) {
	int pointer1 = toadoY + 4;
	bool kt = true;
	ToMauHCN(5, 7, 200, 44, 112);
	GiaoDienMaDauSach(Dsds, toadoX, toadoY);
	ToMauHCN(toadoX + 7, toadoY + 3, 10, 2, 96);
	gotoXY(toadoX + 7, toadoY + 4);
	cout << Dsds.data[0]->ISBN;
	textcolor(112);

	while (kt) {
		RunMenuXoaSach(Dsds, toadoX, toadoY + 4, pointer1, kt);
	}
}