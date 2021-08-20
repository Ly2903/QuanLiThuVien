#pragma once
int length = 4;

string menuMain[] = {
	"QUAN LI SACH",
	"QUAN LI DOC GIA",
	"MUON TRA SACH",
	"THOAT"
};
string menuDS[] = {
	"THEM DAU SACH",
	"TIM THONG TIN SACH",
	"XOA SACH",
	"XUAT DANH SACH DAU SACH",
	"THOAT"
};
string menuDG[] = {
	"THEM DOC GIA",
	"XOA DOC GIA",
	"HIEU CHINH DOC GIA",
	"IN DANH SACH DOC GIA",
	"THOAT"
};
string menuMT[] = {
	"MUON SACH",
	"TRA SACH",
	"LIET KE SACH DOC GIA DANG MUON",
	"THOAT"
};

void Menu()
{
	textcolor(240);
	int j = 13;
	for (int i = 0; i < length; i++)
	{
		ToMauHCN(80, j, 50, 6, 240);
		gotoXY(80 + (50 - menuMain[i].length()) / 2, j + 3);
		cout << menuMain[i];
		j = j + 9;
	}
}
void MenuDauSach() {
	textcolor(240);
	int j = 13;
	for (int i = 0; i < 5; i++)
	{
		ToMauHCN(80, j, 50, 6, 240);
		gotoXY(80 + (50 - menuDS[i].length()) / 2, j + 3);
		cout << menuDS[i];
		j = j + 7;
	}
}
void MenuDocGia() {
	textcolor(240);
	int j = 13;
	for (int i = 0; i < 5; i++) {
		ToMauHCN(80, j, 50, 6, 240);
		gotoXY(80 + (50 - menuDG[i].length()) / 2, j + 3);
		cout << menuDG[i];
		j = j + 7;
	}
}
void MenuMuonTra()
{
	textcolor(240);
	int j = 13;
	for (int i = 0; i < 4; i++)
	{
		ToMauHCN(80, j, 50, 6, 240);
		gotoXY(80 + (50 - menuMT[i].length()) / 2, j + 3);
		cout << menuMT[i];
		j = j + 9;
	}
}

void RunDS(DSDocGia& dsDG, DSDauSach& dsDS, int& pointer1, bool& kt)
{
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
					MenuDauSach();
					pointer1 = 13 - 1 + 5;
				}
				else
				{
					MenuDauSach();
					pointer1--;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 13 - 1 + 5)
				{
					MenuDauSach();
					pointer1 = 13;
				}
				else
				{
					MenuDauSach();
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer1)
			{
			case 13: {
				NhapDauSach(dsDS, 95, 17);
				ghiFileDSVaDMSach(dsDS);
				break;
			}
			case 14: {
				TimThongTinSachDuaVaoTenSach(dsDS, 40, 13);
				break;
			}
			case 15: {
				if (dsDS.sl > 0) {
					XoaSach(dsDS, 55, 13);
					ghiFileDSVaDMSach(dsDS);
				}
				else {
					ToMauHCN(5, 7, 200, 44, 112);
					GiaoDienThongBao("THU VIEN CHUA CO SACH");
				}
				break;
			}
			case 16: {
				if (dsDS.sl > 0)
					MenuXuatDSDS(dsDS, 80, 13);
				else {
					ToMauHCN(5, 7, 200, 44, 112);
					GiaoDienThongBao("THU VIEN CHUA CO SACH");
				}
				break;
			}
			case 17: {
				kt = false;
				break;
			}
			}
			if (pointer1 != 17) {
				GiaoDienMain();
				MenuDauSach();
			}
		}

		ToMauHCN(80, 13 + (pointer1 - 13) * 7, 50, 6, 96);
		gotoXY(80 + (50 - menuDS[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 7);
		textcolor(96);
		cout << menuDS[pointer1 - 13];
	}
}
void RunDG(DSDocGia& dsDG, DSDauSach& dsDS, int& pointer1, bool& kt) {
	if (kbhit()) {
		char c = getch();
		if (c == -32) {
			c = getch();
			if (c == 72) {
				if (pointer1 == 13) {
					MenuDocGia();
					pointer1 = 13 - 1 + 5;
				}
				else
				{
					MenuDocGia();
					pointer1--;
				}
			}
			else if (c == 80) {
				if (pointer1 == 13 - 1 + 5) {
					MenuDocGia();
					pointer1 = 13;
				}
				else
				{
					MenuDocGia();
					pointer1++;
				}
			}
		}
		else if (c == 13) {

			switch (pointer1) {
			case 13://Them Doc Gia
			{
				NhapDocGia(dsDG, 85, 17);
				ghiFileDGVaMT(dsDG);
				ghiFileRanDomMaTheDG();
				break;
			}
			case 14://Xoa Doc Gia
			{
				XoaDocGia(dsDG, 55, 13);
				if (dsDG.sl > 15) {
					ToMauHCN(3, 51, 204, 13 + (2 * dsDG.sl + 3) - 43, 240);
				}
				ghiFileDGVaMT(dsDG);
				break;
			}
			case 15://Hieu Chinh Doc Gia
			{
				SuaDocGia(dsDG, 85, 17);
				if (dsDG.sl > 15) {
					ToMauHCN(3, 51, 204, 13 + (2 * dsDG.sl + 3) - 43, 240);
				}
				ghiFileDGVaMT(dsDG);
				break;
			}
			case 16://In Danh Sach Doc Gia
			{
				if(dsDG.sl>0)
					InDanhSachDocGia(dsDG, 80, 13);
				else {
					ToMauHCN(5, 7, 200, 44, 112);
					GiaoDienThongBao("DANH SACH DOC GIA TRONG");
				}
				break;
			}
			case 17:
			{
				kt = false;
				break;
			}
			}
			if (pointer1 != 17) {
				GiaoDienMain();
				MenuDocGia();
			}
		}
		ToMauHCN(80, 13 + (pointer1 - 13) * 7, 50, 6, 96);
		gotoXY(80 + (50 - menuDG[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 7);
		textcolor(96);
		cout << menuDG[pointer1 - 13];
	}
}
void RunMT(DSDocGia& dsDG, DSDauSach& dsDS, int& pointer1, bool& kt)
{
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
					MenuMuonTra();
					pointer1 = 13 - 1 + 4;
				}
				else
				{
					MenuMuonTra();
					pointer1--;
				}
			}
			else if (c == 80)
			{
				if (pointer1 == 13 - 1 + 4)
				{
					MenuMuonTra();
					pointer1 = 13;
				}
				else
				{
					MenuMuonTra();
					pointer1++;
				}
			}
		}
		else if (c == 13)
		{
			switch (pointer1)
			{
			case 13: {//Muon Sach
				MuonSach(dsDG, dsDS, 55, 17);
				ghiFileDGVaMT(dsDG);
				ghiFileDSVaDMSach(dsDS);
				
				break;
			}
			case 14: {//Tra Sach
				TraSach(dsDG, dsDS, 55, 17);
				ghiFileDGVaMT(dsDG);
				ghiFileDSVaDMSach(dsDS);
				break;
			}
			case 15: {//Liet Ke Cac Sach Doc Gia Dang Muon
				lietKeCacSachDGDangMuon(dsDG, 55, 13);
				break;
			}
			case 16: {
				kt = false;
				break;
			}
			}
			if(pointer1!=16){
				GiaoDienMain();
				MenuMuonTra();
			}
		}

		// to mau 
		ToMauHCN(80, 13 + (pointer1 - 13) * 9, 50, 6, 96);//180//7
		gotoXY(80 + (50 - menuMT[pointer1 - 13].length()) / 2, 16 + (pointer1 - 13) * 9);
		textcolor(96);//180
		cout << menuMT[pointer1 - 13];
	}
}
void Run(DSDocGia& dsDG, DSDauSach& dsDS)
{
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer == 13)
				{
					Menu();
					pointer = 13 - 1 + length;
				}
				else
				{
					Menu();
					pointer--;
				}
			}
			else if (c == 80)
			{
				if (pointer == 13 - 1 + length)
				{
					Menu();
					pointer = 13;
				}
				else
				{
					Menu();
					pointer++;
				}
			}
		}
		else if (c == 13)
		{
			ToMauHCN(5, 7, 200, 44, 112);
			switch (pointer)
			{
			case 13: {
				int pointer1 = 13;
				bool kt = true;
				
				MenuDauSach();
				ToMauHCN(80, 13 + (pointer1 - 13) * 9, 50, 6, 96);
				gotoXY(80 + (50 - menuDS[0].length()) / 2, 16 + (pointer1 - 13) * 9);
				textcolor(96);
				cout << menuDS[0];
				while (kt) {
					RunDS(dsDG, dsDS, pointer1, kt);
				}
				break;
			}
			case 14: {
				int pointer1 = 13;
				bool kt = true;

				MenuDocGia();
				ToMauHCN(80, 13 + (pointer1 - 13) * 7, 50, 6, 96);
				gotoXY(80 + (50 - menuDG[0].length()) / 2, 16 + (pointer1 - 13) * 7);
				textcolor(96);
				cout << menuDG[0];
				while (kt) {
					RunDG(dsDG, dsDS, pointer1, kt);
				}
				break;
			}
			case 15: {
				int pointer1 = 13;
				bool kt = true;

				MenuMuonTra();
				ToMauHCN(80, 13 + (pointer1 - 13) * 9, 50, 6, 96);//180
				gotoXY(80 + (50 - menuMT[0].length()) / 2, 16 + (pointer1 - 13) * 9);
				textcolor(96);
				cout << menuMT[0];
				while (kt) {
					RunMT(dsDG, dsDS, pointer1, kt);
				}
				break;
			}
			case 16: {
				xoaDSDSach(dsDS);
				xoaDSDocGia(dsDG);
				delete[]mangRanDomMaTheDG;
				exit(0);
			}
			}
			GiaoDienMain();
			Menu();
		}

		// to mau 
		ToMauHCN(80, 13 + (pointer - 13) * 9, 50, 6, 96);
		gotoXY(80 + (50 - menuMain[pointer - 13].length()) / 2, 16 + (pointer - 13) * 9);
		textcolor(96);
		cout << menuMain[pointer - 13];
	}
}

void Init(DSDauSach& dsDS, DSDocGia& dsDG)
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("color F0");

	//xuLiRanDomMaTheDG();

	loadFileRanDomMaTheDG();
	loadFileDSVaDMSach(dsDS);
	loadFileDGVaMT(dsDG, dsDS);  
	
	ShowCur(0);
	GiaoDienMain();
	Menu();

	ToMauHCN(80, 13 + (pointer - 13) * 9, 50, 6, 96);
	gotoXY(80 + (50-menuMain[0].length())/2, 16 + (pointer - 13) * 9);
	textcolor(96);
	cout << menuMain[0];
}


