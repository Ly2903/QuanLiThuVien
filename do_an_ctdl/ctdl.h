#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<conio.h>
#include <string>
#include<fstream>
#include <dos.h>
#include <Windows.h>
#include <stdio.h>
#define MAX 100

int pointer = 13;
const int MaxRanDom = 10000;
int* mangRanDomMaTheDG;
int soLgSoConLai = 0;

using namespace std;

struct Sach {
	string masach;
	//0:cho muon duoc 
	//1:da co doc gia muon 
	//2:sach da thanh li
	int trangthai;
	string vitri;
};

struct NodeSach {
	Sach data;
	NodeSach* pNext = NULL;
};

struct DMSach {
	NodeSach* phead = NULL;
	int sl = 0;
};

struct DAUSACH {
	string ISBN;
	string tensach;
	int sotrang;
	string tacgia;
	int nxb;
	string theloai;
	int soLanMuon = 0;
	DMSach dms;
};

struct DSDauSach {
	DAUSACH *data[MAX];
	int sl = 0;
};

struct Date {
	int ngay;
	int thang;
	int nam;
};

struct MUONTRA {
	string masach;
	Date ngaymuon;
	Date ngaytra;
	//0:dang muon
	//1:da tra
	//2:lam mat sach
	int trangthai;
};

struct NodeMuonTra
{
	MUONTRA data;
	NodeMuonTra* pNext=NULL;
};

struct DSMuonTra {
	NodeMuonTra* phead = NULL;
	int sl = 0;
};

struct DocGia{
	int maDG;
	string ho;
	string ten;
	int phai;//1:nam
			//2:nu
	int trangthai;//0:the bi khoa 
				  //1:dang hoat dong
	int soSachDangmuon = 0;
	DSMuonTra mt;
};
struct NodeDG{
	DocGia data;
	NodeDG* pleft;
	NodeDG* pright;
};

struct DSDocGia {
	NodeDG *tree = NULL;
	int sl = 0;
};