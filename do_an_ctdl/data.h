#pragma once

//cau a
void ThemDocGia(NodeDG*& tree, DocGia dg) {
	if (tree == NULL) {
		NodeDG* p = new NodeDG;

		p->data = dg;

		p->pleft = NULL;
		p->pright = NULL;

		tree = p;
	}
	else {
		if (dg.maDG < tree->data.maDG) {
			ThemDocGia(tree->pleft, dg);
		}
		else if (dg.maDG > tree->data.maDG) {
			ThemDocGia(tree->pright, dg);
		}
	}
}
NodeDG* timMaDG(NodeDG* tree, int maDg) {
	if (tree != NULL) {
		if (tree->data.maDG > maDg)
			return timMaDG(tree->pleft, maDg);
		else if (tree->data.maDG < maDg)
			return timMaDG(tree->pright, maDg);
		else
			return tree;
	}
	return NULL;
}
void XoaNode2Con(NodeDG*& temp, NodeDG*& Y) {
	//Y la node the mang can tim
	//node* Y=tree->pright
	if (Y->pleft != NULL) {
		XoaNode2Con(temp, Y->pleft);//node trai nhat
	}
	else
	{
		temp->data = Y->data;//cap nhat
		temp = Y;
		Y = Y->pright;
	}
}
void XoaDocGiaTheoMaDG(NodeDG*& tree, int maDg) {
	if (tree == NULL) {
		return;
	}
	else {
		if (maDg > tree->data.maDG) {
			XoaDocGiaTheoMaDG(tree->pright, maDg);
		}
		else if (maDg < tree->data.maDG) {
			XoaDocGiaTheoMaDG(tree->pleft, maDg);
		}
		else {
			NodeDG* temp = tree;

			if (tree->pleft == NULL) {
				tree = tree->pright;
			}
			else if (tree->pright == NULL) {
				tree = tree->pleft;
			}
			else {
				//tim node trai nhat cua cay con phai
				NodeDG* Y = tree->pright;
				XoaNode2Con(temp, Y);
			}
			delete temp;
		}
	}
}

//cau b
void chuyenCaySangMang(NodeDG* t, DocGia dg[], int& n) {
	if (t != NULL) {
		chuyenCaySangMang(t->pleft, dg, n);
		chuyenCaySangMang(t->pright, dg, n);

		dg[n++] = t->data;
	}
	
}
void sapXepDGTheoHoTenBangMang(DocGia dg[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dg[i].ten + dg[i].ho > dg[j].ten + dg[j].ho) {
				DocGia temp = dg[i];
				dg[i] = dg[j];
				dg[j] = temp;
			}
		}
	}
}

//cau c
void themSach(DMSach& dsSach, Sach sach) {
	NodeSach* nodeSach = new NodeSach;  
	nodeSach->data = sach;
	if (dsSach.phead == NULL)
	{
		dsSach.phead = nodeSach;
	}
	else {
		NodeSach* pTail = dsSach.phead;

		while (pTail->pNext != NULL) {
			pTail = pTail->pNext;
		}

		pTail->pNext = nodeSach;
	}
}
DAUSACH* timDauSach(DSDauSach dsDauSach, string maDauSach) {
	for (int i = 0; i < dsDauSach.sl; i++) {
		if (dsDauSach.data[i]->ISBN == maDauSach)
			return dsDauSach.data[i];
	}
	return NULL;
}
void themDauSach(DSDauSach& dsDauSach, DAUSACH dauSach) {
	DAUSACH* nodeDauSach = new DAUSACH;
	*nodeDauSach = dauSach;

	dsDauSach.data[dsDauSach.sl] = nodeDauSach;
	dsDauSach.sl++;
}

//cau d
DSDauSach layDSDauSachTheoTheLoai(DSDauSach dsDauSach, string theLoai) {
	DSDauSach dsDauSachTemp;

	for (int i = 0; i < dsDauSach.sl; i++) {
		if (theLoai == dsDauSach.data[i]->theloai) {
			dsDauSachTemp.data[dsDauSachTemp.sl++] = dsDauSach.data[i];
		}
	}

	return dsDauSachTemp;
}
string* layDanhSachTheLoai(DSDauSach dsDauSach, int& n) {
	string* dsTheLoai = new string[dsDauSach.sl];

	for (int i = 0; i < dsDauSach.sl; i++) {
		bool kt = true;
		for (int j = 0; j < n; j++) {
			if (dsTheLoai[j] == dsDauSach.data[i]->theloai) {
				kt = false;
				break;
			}
		}
		if (kt)
			dsTheLoai[n++] = dsDauSach.data[i]->theloai;
	}

	return dsTheLoai;
}
void sapXepDSDauSachTheoTen(DSDauSach& dsDauSach) {
	for (int i = 0; i < dsDauSach.sl - 1; i++) {
		for (int j = i + 1; j < dsDauSach.sl; j++) {
			if (dsDauSach.data[i]->tensach > dsDauSach.data[j]->tensach) {
				DAUSACH tmp = *dsDauSach.data[i];
				*dsDauSach.data[i] = *dsDauSach.data[j];
				*dsDauSach.data[j] = tmp;
			}
		}
	}
}

//cau e
DSDauSach timTenSach(DSDauSach dsDs, string tenSach) {
	DSDauSach dsDSTemp;
	for (int i = 0; i < dsDs.sl; i++) {
		if (strstr(dsDs.data[i]->tensach.c_str(), tenSach.c_str()) != NULL) {
			dsDSTemp.data[dsDSTemp.sl++]=dsDs.data[i];
		}
	}
	return dsDSTemp;
}

//cau f
void themMuonTra(DSMuonTra& dsmt, MUONTRA mt) {
	NodeMuonTra* nodemt = new NodeMuonTra;

	nodemt->data = mt;

	if (dsmt.phead == NULL) {
		dsmt.phead = nodemt;
	}
	else
	{
		NodeMuonTra* ptail = dsmt.phead;
		while (ptail->pNext != NULL) {
			ptail = ptail->pNext;
		}
		ptail->pNext = nodemt;
	}
}
NodeSach* laySachMuon(DAUSACH* dauS) {
	for (NodeSach* k = dauS->dms.phead; k != NULL; k = k->pNext) {
		if (k->data.trangthai == 0) {
			return k;
		}
	}
	return NULL;
}
bool KiemTraQuaHan(Date ngayMuon)
{
	ngayMuon = CongNgay(ngayMuon, 7);
	Date ngayHienTai = LayNgayHienTai();
	if (SoSanhNgay(ngayHienTai, ngayMuon) == 1)
	{
		return true;
	}
	return false;
}
bool dieuKienMuonSach(NodeDG*& t, DAUSACH* nodeDauSach) {
	for (NodeMuonTra* k = t->data.mt.phead; k != NULL; k = k->pNext) {
		string maDauSach = TachLayMaDauSach(k->data.masach);
		if (nodeDauSach->ISBN == maDauSach) {
			if (k->data.trangthai == 0) {
				return false;
			}
		}
	}
	return true;
}
void xuLiMuonSach(NodeDG *&nodeDG,DAUSACH *&nodeDauSach,NodeSach *&nodeSach) {

	nodeDG->data.soSachDangmuon++;

	nodeDG->data.mt.sl++;

	nodeDauSach->soLanMuon++;

	nodeSach->data.trangthai = 1;

	MUONTRA mt;

	mt.masach = nodeSach->data.masach;
	mt.trangthai = 0;
	Date ngayTra;
	ngayTra.ngay = 0;
	ngayTra.thang = 0;
	ngayTra.nam = 0;
	mt.ngaymuon = LayNgayHienTai();
	mt.ngaytra = ngayTra;

	themMuonTra(nodeDG->data.mt, mt);
}

//cau g
NodeMuonTra* timSachTra(NodeDG *nodeDG,string maSach) {
	for (NodeMuonTra* k = nodeDG->data.mt.phead; k != NULL; k = k->pNext) {
		if (k->data.masach == maSach && k->data.trangthai==0) {
			return k;
		}
	}
	return NULL;
}
NodeSach* laySachTra(DAUSACH* dauS,string maSach) {
	for (NodeSach* k = dauS->dms.phead; k != NULL; k = k->pNext) {
		if (k->data.masach == maSach && k->data.trangthai == 1)
		{
			return k;
		}
	}
	return NULL;
}
void xuliTraSach(DSDauSach &dsDs,NodeDG *&nodeDG,string layDSMaSachMuon[], int vt) {

	NodeMuonTra* nodeMt = timSachTra(nodeDG, layDSMaSachMuon[vt]);
	DAUSACH* dauS = timDauSach(dsDs, TachLayMaDauSach(layDSMaSachMuon[vt]));

	if (KiemTraQuaHan(nodeMt->data.ngaymuon) == true && nodeDG->data.trangthai == 0)
		nodeDG->data.trangthai = 1;

	nodeDG->data.soSachDangmuon--;

	nodeMt->data.trangthai = 1;
	nodeMt->data.ngaytra = LayNgayHienTai();

	NodeSach* nodeSach = laySachTra(dauS, layDSMaSachMuon[vt]);

	nodeSach->data.trangthai = 0;

}

//cau i
NodeMuonTra* layMuonTraQuaHan(NodeDG* t) {
	NodeMuonTra* nodeMt = NULL;

	Date hanDau;
	hanDau.ngay = 0;
	hanDau.thang = 0;
	hanDau.nam = 0;

	for (NodeMuonTra* k = t->data.mt.phead; k != NULL; k = k->pNext) {
		if (k->data.trangthai == 0) {
			Date hanMuon = CongNgay(k->data.ngaymuon, 7);
			if (SoSanhNgay(LayNgayHienTai(), hanMuon) == 1)
			{
				if (SoSanhNgay(hanMuon, hanDau) == 1) {
					hanDau = k->data.ngaymuon;
					nodeMt = k;
				}
			}
		}
	}
	return nodeMt;
}
void xuLiQuaHan(NodeDG* t, NodeMuonTra* mangMtQuaHan[], DocGia mangDG[], int& n) {
	if (t == NULL)
		return;
	mangMtQuaHan[n] = layMuonTraQuaHan(t);
	if (mangMtQuaHan[n] != NULL) {
		mangDG[n] = t->data;
		n++;
	}

	xuLiQuaHan(t->pleft, mangMtQuaHan, mangDG, n);
	xuLiQuaHan(t->pright, mangMtQuaHan, mangDG, n);
}
void XuLiMuonTraTheoTGGiamDan(NodeDG* t, NodeMuonTra* mangMtQuaHan[100], DocGia mangDG[100], int& n)
{
	xuLiQuaHan(t, mangMtQuaHan, mangDG, n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (SoSanhNgay(mangMtQuaHan[i]->data.ngaymuon, mangMtQuaHan[j]->data.ngaymuon) == 1)
			{
				NodeMuonTra* tmp = mangMtQuaHan[i];
				mangMtQuaHan[i] = mangMtQuaHan[j];
				mangMtQuaHan[j] = tmp;

				DocGia dg = mangDG[i];
				mangDG[i] = mangDG[j];
				mangDG[j] = dg;
			}
		}
	}
}

//cau j
void sapXepTheoSoLuotMuon(DSDauSach &dsTemp) {
	for (int i = 0; i < dsTemp.sl - 1; i++) {
		for (int j = i + 1; j < dsTemp.sl; j++) {
			if (dsTemp.data[i]->soLanMuon < dsTemp.data[j]->soLanMuon) {
				DAUSACH tmp = *dsTemp.data[i];
				*dsTemp.data[i] = *dsTemp.data[j];
				*dsTemp.data[j] = tmp;
			}
		}
	}
}

//Xoa Sach
NodeSach* laySachXoa(DAUSACH* ds, string maS) {
	for (NodeSach* k = ds->dms.phead; k != NULL; k = k->pNext) {
		if (k->data.masach == maS)
			return k;
	}
	return NULL;
}
void Xoa1Sach(DMSach& dms, string masach) {
	if (dms.phead == NULL)
		return;
	if (dms.phead->data.masach == masach) {
		NodeSach* tmp = dms.phead;
		dms.phead = dms.phead->pNext;
		delete tmp;
	}
	else
	{
		for (NodeSach* k = dms.phead; k->pNext != NULL; k = k->pNext) {
			if (k->pNext->data.masach == masach) {
				NodeSach* g = k->pNext;
				if (g->pNext == NULL) {
					delete g;
					k->pNext = NULL;
					return;
				}
				k->pNext = g->pNext;
				delete g;
			}
		}
	}
}


//Xu li load file
void loadFileDSVaDMSach(DSDauSach& dsDauSach) {
	ifstream filein;
	ifstream filein1;

	filein.open("inputDauSach.txt", ios_base::in);
	filein1.open("inputDMS.txt", ios_base::in);

	if (filein.fail() || filein1.fail())
		return;

	int n = 0;
	filein >> n;
	filein.ignore();

	for (int i = 1; i <= n; i++) {
		DAUSACH dauSach;

		getline(filein, dauSach.ISBN, ',');
		getline(filein, dauSach.tensach, ',');
		filein >> dauSach.sotrang;
		filein.ignore();

		getline(filein, dauSach.tacgia, ',');
		filein >> dauSach.nxb;
		filein.ignore();
		getline(filein, dauSach.theloai, ',');
		filein >> dauSach.dms.sl;
		filein.ignore();

		for (int j = 0; j < dauSach.dms.sl; j++) {
			Sach sach;
			getline(filein1, sach.masach, ',');
			getline(filein1, sach.vitri, ',');
			filein1 >> sach.trangthai;

			filein1.ignore();

			themSach(dauSach.dms, sach);
		}
		///them
		themDauSach(dsDauSach, dauSach);
	}

	filein.close();
	filein1.close();
}
void loadFileDGVaMT(DSDocGia& dsDg, DSDauSach& dsDs)  {
	ifstream Filein;
	ifstream Filein1;

	Filein.open("inputDocGia.txt", ios_base::in);
	Filein1.open("inputMuonTra.txt", ios_base::in);

	if (Filein.fail() || Filein1.fail())
		return;

	Filein >> dsDg.sl;
	Filein.ignore();

	for (int i = 0; i < dsDg.sl; i++) {
		DocGia dg;
		string tam;

		Filein >> dg.maDG;
		Filein.ignore();

		getline(Filein, tam, ',');
		tachLayTenVaHo(tam, dg.ten, dg.ho);

		Filein >> dg.phai;
		Filein.ignore();

		Filein >> dg.trangthai;
		Filein.ignore();

		Filein >> dg.mt.sl;
		Filein.ignore();

		for (int j = 0; j < dg.mt.sl; j++) {
			MUONTRA temp;

			getline(Filein1, temp.masach, ',');

			string maISBN = TachLayMaDauSach(temp.masach);

			for (int k = 0; k < dsDs.sl; k++) {
				if (dsDs.data[k]->ISBN == maISBN) {
					dsDs.data[k]->soLanMuon++;
					break;
				}
			}

			Date temp1;

			Filein1 >> temp1.ngay;
			Filein1.ignore();

			Filein1 >> temp1.thang;
			Filein1.ignore();

			Filein1 >> temp1.nam;
			Filein1.ignore();

			temp.ngaymuon = temp1;
			Date temp2;

			Filein1 >> temp2.ngay;
			Filein1.ignore();

			Filein1 >> temp2.thang;
			Filein1.ignore();

			Filein1 >> temp2.nam;
			Filein1.ignore();

			temp.ngaytra = temp2;

			Filein1 >> temp.trangthai;
			Filein1.ignore();

			if (temp.trangthai == 0) {
				dg.soSachDangmuon++;
			}
			if (KiemTraQuaHan(temp.ngaymuon) && temp.trangthai==0)
				dg.trangthai = 0;

			themMuonTra(dg.mt, temp);
		}
		ThemDocGia(dsDg.tree, dg);
	}

	Filein.close();
	Filein1.close();
}
void loadFileRanDomMaTheDG() {
	ifstream Filein;

	Filein.open("inputRanDomMaTheDG.txt", ios_base::in);

	Filein >> soLgSoConLai;
	Filein.ignore();

	mangRanDomMaTheDG = new int[soLgSoConLai];

	for (int i = 0; i < soLgSoConLai; i++) {
		Filein >> mangRanDomMaTheDG[i];
	}

	Filein.close();
}

//Xu li luu file
void ghiFileDSVaDMSach(DSDauSach dsdauSach) {
	ofstream fileout;
	ofstream fileout1;

	fileout.open("inputDauSach.txt", ios_base::out);
	fileout1.open("inputDMS.txt", ios_base::out);

	fileout << dsdauSach.sl << endl;

	for (int i = 0; i < dsdauSach.sl; i++) {
		fileout << dsdauSach.data[i]->ISBN << "," << dsdauSach.data[i]->tensach << "," << dsdauSach.data[i]->sotrang << "," << dsdauSach.data[i]->tacgia << "," <<
			dsdauSach.data[i]->nxb << "," << dsdauSach.data[i]->theloai << "," << dsdauSach.data[i]->dms.sl << endl;

		for (NodeSach* k = dsdauSach.data[i]->dms.phead; k != NULL; k = k->pNext) {
			fileout1 << k->data.masach << "," << k->data.vitri << "," << k->data.trangthai << endl;
		}
	}

	fileout.close();
	fileout1.close();
}
void XuLiGhiDSDGVaMT(NodeDG* t, ofstream& fileout, ofstream& fileout2) {
	if (t == NULL) {
		return;
	}
	else
	{
		XuLiGhiDSDGVaMT(t->pleft, fileout, fileout2);
		fileout << t->data.maDG << "," << t->data.ho << " "
			<< t->data.ten << "," << t->data.phai << ","
			<< t->data.trangthai << "," << t->data.mt.sl << endl;

		for (NodeMuonTra* k = t->data.mt.phead; k != NULL; k = k->pNext) {
			fileout2 << k->data.masach << ","
				<< k->data.ngaymuon.ngay << "/" << k->data.ngaymuon.thang << "/" << k->data.ngaymuon.nam << ","
				<< k->data.ngaytra.ngay << "/" << k->data.ngaytra.thang << "/" << k->data.ngaytra.nam << ","
				<< k->data.trangthai << endl;
		}

		XuLiGhiDSDGVaMT(t->pright, fileout, fileout2);
	}
}
void ghiFileDGVaMT(DSDocGia dsDg) {
	ofstream fileout;
	ofstream fileout2;

	fileout.open("inputDocGia.txt", ios_base::out);
	fileout2.open("inputMuonTra.txt", ios_base::out);

	fileout << dsDg.sl << endl;

	XuLiGhiDSDGVaMT(dsDg.tree, fileout, fileout2);

	fileout.close();
	fileout2.close();
}
void xuLiRanDomMaTheDG()
{
	ofstream fileOut;
	fileOut.open("inputRanDomMaTheDG.txt", ios::out);

	int count = 10000;
	const int maxNum = 32000;
	const int minNum=10000;
	bool a[maxNum]{ false };

	int i = 0;
	int value;
	fileOut << count << endl;
	while (i < count)
	{
		value = rand() % (maxNum - minNum + 1) + minNum;
		if (!a[value])
		{
			a[value] = true;
			fileOut << value << " ";
			i++;
		}
	}

	fileOut.close();
}
void ghiFileRanDomMaTheDG()
{
	ofstream fileOut("inputRanDomMaTheDG.txt", ios::out);

	fileOut << soLgSoConLai << endl;

	for (int i = 0; i < soLgSoConLai; i++)
	{
		fileOut << mangRanDomMaTheDG[i] << " ";
	}

	fileOut.close();
}

//Xu Li Xoa Danh Sach
void xoaDMSach(DMSach& dms) {
	if (dms.phead == NULL)
		return;
	else
	{
		while (dms.phead != NULL) {
			NodeSach* k = dms.phead;
			dms.phead = dms.phead->pNext;
			delete k;
		}
	}
}
void xoaDSDSach(DSDauSach& dsDs) {
	for (int i = 0; i < dsDs.sl; i++) {
		xoaDMSach(dsDs.data[i]->dms);
		delete dsDs.data[i];
	}
}
void xoaDSMuonTra(DSMuonTra& dsMt) {
	if (dsMt.phead == NULL)
		return;
	else
	{
		while (dsMt.phead != NULL) {
			NodeMuonTra* k = dsMt.phead;
			dsMt.phead = dsMt.phead->pNext;
			delete k;
		}
	}
}
void xuLiXoaDSDG(NodeDG *t) {
	if (t == NULL)
		return;
	else
	{
		xuLiXoaDSDG(t->pleft);
		xuLiXoaDSDG(t->pright);

		xoaDSMuonTra(t->data.mt);
		delete t;
	}
}
void xoaDSDocGia(DSDocGia& dsDg) {
	xuLiXoaDSDG(dsDg.tree);
}


