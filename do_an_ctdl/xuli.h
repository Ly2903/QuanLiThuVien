#pragma once
int DemChuSo(int n)
{
	int dem = 0;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	return dem;
}
char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}
string ChuyenSoSangString(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
void DinhDangChuoi(string& str)
{
	//Xoa khoang trong
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + (str.length() - 1));
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	//Viet thuong all lai
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ')
		{
			str[i] = str[i] + 32;
		}
	}
	//Viet hoa
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122))
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i + 1] && str[i + 1] <= 122))
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}
}

string NoiChuoi(string str, int n)
{
	string str2;
	str2 = str;
	string str1 = ChuyenSoSangString(n);
	str2.push_back('_');
	for (int i = 0; i < str1.length(); i++)
	{
		str2.push_back(str1[i]);
	}
	return str2;
}
string TachLayMaDauSach(string str)
{
	string str1 = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return str1;
}
int TachLayMaSach(string str)
{
	string str1;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return atoi(str1.c_str());
}
void tachLayTenVaHo(string str, string& ten, string& ho)
{
	int k = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			k = i;
			break;
		}
	}

	for (int i = 0; i < k; i++)
	{
		ho += str[i];
	}

	for (int i = k + 1; i < str.length(); i++)
	{
		ten += str[i];
	}
}

// Xu Ly Ngay
int ChuyenThang(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}
Date LayNgayHienTai()
{
	Date d;
	time_t hientai = time(0);
	char* dt = ctime(&hientai);
	string str1, str2, str3;
	
	for (int i = 8; i < 10; i++)
	{
		str1.push_back(dt[i]);
	}
	d.ngay = atoi(str1.c_str());
	
	for (int i = 4; i < 7; i++)
	{
		str2.push_back(dt[i]);
	}
	d.thang = ChuyenThang(str2);
	
	for (int i = 20; i < 24; i++)
	{
		str3.push_back(dt[i]);
	}
	d.nam = atoi(str3.c_str());

	return d;
}
bool KTNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}
int SoSanhNgay(Date d1, Date d2)
{
	if (d1.nam == d2.nam)
	{
		if (d1.thang == d2.thang)
		{
			if (d1.ngay > d2.ngay)
			{
				return 1;
			}
			else if (d1.ngay < d2.ngay)
			{
				return -1;
			}
			else
				return 0;
		}
		else if (d1.thang > d2.thang)
		{
			return 1;
		}
		else
			return -1;
	}
	else if (d1.nam > d2.nam)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int SoNgayCuaThang(int thang)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KTNamNhuan)
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}
Date CongNgay(Date t, int SoNgay)
{
	Date d = t;
	d.ngay = d.ngay + SoNgay;
	if (d.ngay > SoNgayCuaThang(d.thang))
	{
		if (d.thang == 12)
		{
			d.thang = 1;
			d.nam = d.nam + 1;
		}
		else
		{
			d.thang = d.thang + 1;
		}
		d.ngay = d.ngay - SoNgayCuaThang(t.thang);
	}
	return d;
}

// Doc Trang Thai
string TrangThaiGioiTinh(int n)
{
	if (n == 1)
	{
		return "Nam";
	}
	return "Nu";
}
string TrangThaiDocGia(int n)
{
	if (n == 1)
		return "Hoat Dong";
	else
		return "Khoa";
}
string TrangThaiSach(int n)
{
	if (n == 1)
	{
		return "Da Muon";
	}
	else if (n == 0)
	{
		return "Duoc Muon";
	}
	else
		return "Da Thanh Li";
}
string TrangThaiMuonTra(int n)
{
	if (n == 0)
		return "Dang Muon";
	else if (n == 1)
		return "Da Tra";
	else if (n == 2)
		return "Da Mat";
}

//Xu Ly Nhap
string XuLyNhapMa(int length)
{
	string input;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || c == '_' || (c >= 65 && c <= 90)) && input.length() < length)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if ((c >= 97 && c <= 122)&& input.length() < length)
		{
			c = c - 32;
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)
		{
			ShowCur(0);
			return input;
		}
	}
}
string XuLyNhapChu()
{
	string input;
	ShowCur(1);

	gotoXY(whereX(), whereY());
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || c == '_' || (c >= 65 && c <= 90) && input.length() < 6) && input.length()<48)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 32 && input.length() != 0 && input[input.length() - 1] != ' ')
		{
			input.insert(input.begin() + input.length(), ' ');
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)
		{
			ShowCur(0);
			return input;
		}
	}
}
int XuLyNhapSo()
{
	int n;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	string x = "";
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && x.length()<5)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			ShowCur(0);
			return -1;
		}
		else if (c == 13 && x.length() > 0)
		{

			n = atoi(x.c_str());
			ShowCur(0);
			return n;
		}

	}
}
void XuLyNhapMa(string& input, int toadoX, int& toadoY, int lenghtMax )
{
	char c;
	ShowCur(1);
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && input.length() < lenghtMax)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if ((c >= 97 && c <= 122) && input.length() < lenghtMax)
		{
			c = c - 32;
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && input.length() > 0)
		{
			toadoY = toadoY + 3;
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
void XuLyNhapSo(int& n, int toadoX, int& toadoY)
{
	string x;
	x = ChuyenSoSangString(n);
	char c;
	ShowCur(1);
	while (true)
	{
		c = getch();
		if (c >= 48 && c <= 57 && x.length()<4)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && x.length() > 0)
		{
			toadoY = toadoY + 3;
			n = atoi(x.c_str());
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();

			if (c == 80)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
void XuLyNhapChu(string& input, int toadoX, int& toadoY, int lenghtMax)
{
	char c;
	ShowCur(1);
	while (true)
	{
		char c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) && input.length() < lenghtMax)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 32 && input.length() < lenghtMax && input.length() != 0 && input[input.length() - 1] != ' ')
		{
			input.insert(input.begin() + input.length(), ' ');
			cout << c;
		}
		else if (c == 13 && input.length() > 0)
		{
			toadoY = toadoY + 3;
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
