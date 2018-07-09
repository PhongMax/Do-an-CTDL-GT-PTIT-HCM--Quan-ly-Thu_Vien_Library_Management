#include "Ve_Hinh.h"

string keyMainMenu[5] = { " ***MENU CHINH*** ", "QUAN LY DOC GIA", "QUAN LY DAU SACH ", "QUAN LY SACH", "THOAT" };

string keySubMainMenu3[3] = { "      ~~~ TRA SACH ~~~      ",
								"~~~ SACH MUON NHIEU NHAT ~~~",
								"      ~~~ MUON SACH ~~~     " };
								
string keySubMainMenu2[3] = { "   ~~~ CAP NHAT DAU SACH ~~~  ",
							" ~~~ HIEN THI CAC DAU SACH ~~~" ,
							" ~~~CAP NHAT DANH MUC SACH ~~~"};


string keySubMainMenu1[3] = { "           ~~~ CAP NHAT DOC GIA ~~~                ",
							"    ~~~ HIEN THI DANH SACH TAT CA DOC GIA ~~~      ",
							" ~~~ HIEN THI DS CAC DOC GIA MUON SACH QUA HAN ~~~ " };


string keyBangNhapDauSach[14] = {   "               ~~~CAP NHAT DAU SACH~~~               ",
									"                                                     ",
									" Ten Sach     :",
									"                                                     ",
									" ISBN         :",
									"                                                     ",
									" Tac Gia      :",
									"                                                     ",
									" The Loai     :",
									"                                                     ",
									" So Trang     :",
									"                                                     ",
									" Nam Xuat Ban :",
									"                                                     " };


string keyBangNhapDanhMucSach[8] = {"                    ~~~CAP NHAT DANH MUC SACH~~~                   ",
								    "                                                                   ",
								   " Ma Sach           :",
								   "                                                                   ",
								   " Trang Thai[0,1,2] :",
								   "                                                                   ",
								   " Vi tri cua sach   :",
								   "                                                                   " };

string keyBangNhapDG[12] = { "               ~~~ CAP NHAT DOC GIA ~~~                     ",
							"                                                            ",
							" Ma Doc Gia   :",
							"                                                            ",
							" Ho Doc Gia   :",
							"                                                            ",
							" Ten Doc Gia  :",
							"                                                            ",
							" Phai [0, 1]  :",
							"                                                            ",
							" TT the [0, 1]:",
							"                                                            ", };



string keyDisplayDG[5] = { "MA DG", "     HO DG", "TEN DG", "PHAI  ", "TT THE" };

string keyDisplayDS[6] = {"        DAU SACH", "ISBN", "    TAC GIA", "  THE LOAI ", " SO TRG ", " NXB"};

string keyDisplayDMS[3] = { "MA SACH", "TRANG THAI", "            VI TRI" };

string keyDisplayMT[7] = { "          TEN SACH", "MA SACH", "   NGAY MUON", "   NGAY TRA", "SO NGAY DA MUON", "        VI TRI SACH", "  TRANG THAI"};

string keyDisplayTop10[3] = { "   SO THU TU", "          TEN SACH", " SO LUOT MUON SACH THUOC DAU SACH" };

string keyGuide1[6] = { "                       ~~~GUIDES~~~                         ",
						"-> MA DOC GIA    : Duoc chuong trinh lay ngau nhien.        ",
						"-> HO DOC GIA    : Toi da 16 ky tu, chi lay ky tu chu.      ",
						"-> TEN DOC GIA   : Toi da 7 ky tu, chi lay ky tu chu.       ",
						"-> PHAI          : 0 =  NAM, 1 = NU.                        ",
						"-> TRANG THAI THE: 0 = The bi khoa, 1 = The dang hoat dong. " };

string keyGuide2[7] = { "                     ~~~GUIDES~~~                   ",
						"-> TEN SACH     : Toi da 24 ky tu, gom co chu va so ",
						"-> ISBN         : Toi da 4 ky tu, chi lay ky tu chu ",
						"-> TAC GIA      : Toi da 17 ky tu, chi lay ky tu chu" ,
						"-> THE LOAI     : Toi da 11 ky tu, chi lay ky tu chu" ,
						"-> SO TRANG     : So trang khong qua 999999         " ,
						"-> NAM XUAT BAN : Nam XB khong lon hon nam hien tai " };


string keyGuide3[4] = { "                         ~~~GUIDES~~~                             ",
					   "-> MA SACH  :  Ma Sach duoc danh tu dong                           ",
					   "-> TT       :0  = cho muon duoc, 1 = da duoc muon, 2 = da thanh ly",
					   "-> VI TRI   : Toi da 17 ky tu, chi lay ky tu chu, so va dau phay   "};


int xDisplayDG[6] = { 3,13, 32,46,53,65 };
int xDisplayDS[7] = { 1, 29, 34, 53, 65, 72 , 78 };
int xDisplayDMS[4] = { 2, 14,29,64 };
int XDisplayMT[8] = { 2, 30, 39, 55, 70, 88, 115, 132};
int xDisplayTop10[4] = { 30, 45, 77, 112 };

int xMainMenus[5] = { 8,34,60, 89,113 };
int ySubMainMenus1[3] = { 20, 24, 28};
int ySubMainMenus2[3] = { 22, 26, 30 };
int ySubMainMenus3[3] = { 20,23,26 };

void CreateBox(int x, int y, string text, int length)
{
	gotoxy(x - 2, y - 1);
	cout << char(201) << setw(length) << setfill(char(205)) << char(205) << char(187);

	gotoxy(x - 2, y);
	cout << char(186) << text << setw(length - text.length() + 1) << setfill(' ') << char(186);

	gotoxy(x - 2, y + 1);
	cout << char(200) << setw(length) << setfill(char(205)) << char(205) << char(188);
}

void chuChay(char dChu[], int x, int y)
{
	SetColor(WHITE);
	ShowCur(false);
	char c[40];
	int length = (int)strlen(dChu);
	for (int i = 0; i < length; i++) {
		strncpy(c, dChu + i, 40);  // copy tu phan tu thu i den cuoi chuoi
		c[39] = '\0';
		Sleep(100);
		gotoxy(x, y);
		cout << "                                       ";
		gotoxy(x, y); // vi tri de in dong chu chay
		cout << c;
		if (i == length - 1) i = 0;  // chay vo han

		if (_kbhit()) {
			normalBGColor();
			return;  // Co phim nhan vao thi dung
		}
	}
}

void VeHinhBangNhap(int x, int y, int dorong, string str)
{
	SetBGColor(LIGHT_AQUA);
	SetColor(BLUE);
	gotoxy(x, y - 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y );
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x, y + 1);
	cout << setw(dorong) << setfill(' ') << " ";
	gotoxy(x + (int)str.length()/ 3, y + 1);
	cout << setw((int)str.length() / 3  + 3) << setfill('~') << "~";
	
	gotoxy(x, y );
	cout << str;
	gotoxy(x, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x + dorong - 4, y + 2);
	cout << setw(4) << setfill(' ') << " ";
	gotoxy(x, y + 3);
	cout << setw(dorong) << setfill(' ') << " ";
	normalBGColor();
}

void CayLoading(int Color)
{
	SetColor(Color);
	for (int i = xLoading; i <= xLoading + 100; i++)
	{
		gotoxy(i, yLoading);
		Sleep(15);
		cout << char(219);
	}
}

void VeKhungMenu()
{
	ShowCur(false);
	int i;
	gotoxy(xOrdinal, yOrdinal);
	// ve hang ngang tren
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}

	// ve hang ngang duoi
	gotoxy(xOrdinal, yOrdinal + 15);
	for (i = 0; i <= xMax; i++)
	{
		SetColor(WHITE);
		cout << char(219);
	}

	// ve hang doc trai
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xOrdinal, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "  ";
	}

	// ve hang doc phai
	for (int i = 0; i < yOrdinal + 15; i++)
	{
		gotoxy(xMax - 1, yOrdinal + i);
		SetBGColor(WHITE);
		cout << "   ";
	}
}

void XoaMotDong(int width)
{
	SetBGColor(AQUA);
	cout << " " << setw(width) << setfill(' ') << " ";
}

void XoaMotVung(int x, int y, int ndoc, int width)
{
	for (int i = 0; i < ndoc; i++)
	{
		gotoxy(x, y + i);
		XoaMotDong(width);
	}
}

void HighLight(string key, int index, int newColor, int oldColor)
{
	// den dia chi can highlight
	gotoxy(xMainMenus[index] - 1, yMainMenu);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}

void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor)
{
	// den dia chi can highlight
	gotoxy(x - 1, y[index]);
	SetBGColor(newColor);
	SetColor(WHITE);
	cout << key;
	SetBGColor(oldColor);
}

void MainMenu(string key[], int nKey)
{
	normalBGColor();
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xMainMenus[i], yMainMenu, key[i],(int)key[i].length());
	}
}

void SubMainMenu1(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus1, ySubMainMenus1[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu1[0], 0, xSubMainMenus1, ySubMainMenus1, GREEN, AQUA);
	ShowCur(false);
}

void SubMainMenu2(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus2, ySubMainMenus2[i], key[i], (int)key[i].length());
	}
	HighLight1(keySubMainMenu2[0], 0, xSubMainMenus2, ySubMainMenus2, GREEN, AQUA);
	ShowCur(false);
}

void SubMainMenu3(string key[], int nKey)
{
	normalBGColor();
	SetBGColor(BLACK);
	for (int i = 0; i < nKey; i++)
	{
		CreateBox(xSubMainMenus3, ySubMainMenus3[i], key[i],(int)key[i].length());
	}
	HighLight1(keySubMainMenu3[0], 0, xSubMainMenus3, ySubMainMenus3, GREEN, AQUA);
	ShowCur(false);
}

void EffectiveMenu(int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{
		ShowCur(false);
		gotoxy(xMainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << keyMainMenu[pos + 1];

		gotoxy(xMainMenus[(pos + 3) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 3) % 4 + 1];
	}
	else if (flag == 2) {

		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xMainMenus[pos + 1] - 1, yMainMenu);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << keyMainMenu[pos + 1];

		gotoxy(xMainMenus[(pos + 1) % 4 + 1] - 1, yMainMenu);
		normalBGColor();
		cout << keyMainMenu[(pos + 1) % 4 + 1];
	}
}

void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag)
{
	// 0 --> 3; 3 --> 2;   2---> 1;  1---> 0
	if (flag == 1)
	{
		ShowCur(false);

		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << key[pos];

		gotoxy(xSubMenu - 1, ykey[(pos + nkey - 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(LIGHT_YELLOW);
		cout << key[(pos + nkey - 1) % nkey];
	}
	else if (flag == 2) 
	{
		// 0 ---> 1; 1 ---> 2; 2 ----> 3 ; 3 ---> 0
		ShowCur(false);

		gotoxy(xSubMenu - 1, ykey[pos]);
		SetBGColor(GREEN);
		SetColor(WHITE);
		cout << key[pos];

		gotoxy(xSubMenu - 1, ykey[(pos + 1) % nkey]);
		SetBGColor(BLACK);
		SetColor(LIGHT_YELLOW);
		cout << key[(pos + 1) % nkey];
	}
}

int ChooseMainMenu(int nKey)
{
	int currposMainMenu = -1;
	ShowCur(false);

	int kb_hit;
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
			{
				kb_hit = _getch();
			}

			switch (kb_hit)
			{
			case KEY_LEFT:

				Beep(500, 50);
				if (currposMainMenu > 0)
				{
					currposMainMenu = currposMainMenu - 1;
				}
				else {
					currposMainMenu = nKey - 2;
				}

				EffectiveMenu(currposMainMenu, 2);
				break;

			case KEY_RIGHT: //key right
				Beep(400, 50);
				if (currposMainMenu < nKey - 2)
				{
					currposMainMenu = currposMainMenu + 1;
				}
				else {
					currposMainMenu = 0;//move to first value in menu system
				}
				EffectiveMenu(currposMainMenu, 1);
				break;

			case ENTER: //enter
				Beep(600, 50);
				return currposMainMenu;

			}
		}
	}

}


int ChooseSubMenu(string key[], int xSubMenu, int ykey[], int nkey)
{
	int currposSubMainMenu = 0;
	ShowCur(false);

	int kb_hit;
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				if (currposSubMainMenu > 0)
				{
					currposSubMainMenu = currposSubMainMenu - 1;
				}
				else {
					currposSubMainMenu = nkey - 1;
				}

				EffectiveSubMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 2);
				Beep(300, 10);
				break;

			case KEY_DOWN:
				if (currposSubMainMenu < nkey - 1)
				{
					currposSubMainMenu = currposSubMainMenu + 1;
				}
				else {
					currposSubMainMenu = 0;
				}

				EffectiveSubMenu(key, xSubMenu, ykey, nkey, currposSubMainMenu, 1);
				Beep(250, 10);
				break;

			case ESC:

				return -1;

			case ENTER:
				Beep(600, 10);
				return currposSubMainMenu;
			}
		}
	}
}

// ham hien thi bang thong tin
void DisplayDG(string key[], int nKey, int xDisplay[])
{
	ShowCur(true);
	normalBGColor();

	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xDisplay[i] + 3, yDisplay + 1);
		cout << key[i];
	}

	//hien thi cot hai ben 
	SetColor(WHITE);
	for (int j = yDisplay; j <= yDisplay + 32; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);

			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{
		gotoxy(i, yDisplay);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 32);
		if (i == xDisplay[nKey])
		{
			cout << char(188); //nga 3 sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4])
			cout << char(202);
		else if (i == xDisplay[0])
			cout << char(200); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}

void DisplayDS(string key[], int nKey, int xDisplay[])
{
	normalBGColor();

	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xDisplay[i] + 1, yDisplay + 1);
		cout << key[i];
	}

	//hien thi cot hai ben 
	SetColor(WHITE);
	for (int j = yDisplay; j <= yDisplay + 32; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);

			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{

		gotoxy(i, yDisplay);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4]  || i == xDisplay[5])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 32);
		if (i == xDisplay[0])
		{
			cout << char(200); //qeo sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(188); //qeo sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5])
			cout << char(202);
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}

// ham hien thi bang thong tin
void DisplayDMS(string key[], int nKey, int xDisplay[])
{
	ShowCur(true);
	normalBGColor();

	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xDisplay[i] + 3, yDisplay + 1);
		cout << key[i];
	}

	//hien thi cot hai ben 
	SetColor(WHITE);
	for (int j = yDisplay; j <= yDisplay + 32; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);

			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{

		gotoxy(i, yDisplay);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplay + 32);
		if (i == xDisplay[nKey])
		{
			cout << char(188); //nga 3 sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(202);
		else if (i == xDisplay[0])
			cout << char(200); //nga 3 sang phai
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}

void DisplayMT(string key[], int nKey, int xDisplay[])
{
	normalBGColor();
	ShowCur(false);
	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xDisplay[i] + 1, yDisplayMT + 1);
		cout << key[i];
	}

	//hien thi cot hai ben 
	SetColor(WHITE);
	for (int j = yDisplayMT; j <= yDisplayMT + 6; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);
			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{

		gotoxy(i, yDisplayMT);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplayMT + 2);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplayMT + 6);
		if (i == xDisplay[0])
		{
			cout << char(200); //qeo sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(188); //qeo sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] || i == xDisplay[4] || i == xDisplay[5] || i == xDisplay[6])
			cout << char(202);
		else
		{
			cout << char(205); //duong thang ngang
		}
	}
}

void DisplayTop10(string key[], int nKey, int xDisplay[], int ndoc)
{
	normalBGColor();
	ShowCur(false);
	// hien thi cac danh muc trong bang hien thi
	for (int i = 0; i < nKey; i++)
	{
		gotoxy(xDisplay[i] + 1, yDisplayTop10 );
		cout << key[i];
	}

	//hien thi cot hai ben 
	SetColor(WHITE);
	for (int j = yDisplayTop10; j <= yDisplayTop10 + ndoc; j++)
	{
		for (int i = 0; i < nKey + 1; i++)
		{
			gotoxy(xDisplay[i], j);
			cout << char(186);
		}
	}

	//hien thi dong hai ben
	for (int i = xDisplay[0]; i <= xDisplay[nKey]; i++)
	{

		gotoxy(i, yDisplayTop10 - 1);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(203);//nga 3
		else if (i == xDisplay[0])
		{
			cout << char(201); //moc phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(187);//moc trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplayTop10 + 1);
		if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(206); //nga 4
		else if (i == xDisplay[0])
		{
			cout << char(204); //nga 3 sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(185);//nga 3 sang trai
		}
		else
		{
			cout << char(205); //duong thang ngang
		}

		gotoxy(i, yDisplayTop10 + ndoc);
		if (i == xDisplay[0])
		{
			cout << char(200); //qeo sang phai
		}
		else if (i == xDisplay[nKey])
		{
			cout << char(188); //qeo sang trai
		}
		else if (i == xDisplay[1] || i == xDisplay[2] || i == xDisplay[3] )
			cout << char(202);
		else
		{
			cout << char(205); //duong thang ngang
		}

	}
}

void BangNhap(int x, int y, int nngang, string key[], int nkey)
{
	int i;
	// ve khung
	SetBGColor(BLACK);
	SetColor(WHITE);
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(245);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(245);
		}
	}
	normalBGColor();
}

void BangGuides(int x, int y, int nngang, string key[], int nkey)
{
	int i;
	// ve khung
	SetBGColor(BLACK);
	SetColor(GREEN);
	for (i = 0; i < nkey + 2; i++)
	{
		gotoxy(x, y + i);
		if (i == 0)
		{
			cout << char(218) << setw(nngang) << setfill(char(196)) << char(191);
		}
		else if (i == nkey + 1)
		{
			cout << char(192) << setw(nngang) << setfill(char(196)) << char(217);
		}
		else {
			cout << char(245);
			cout << key[i - 1];
			gotoxy(x + nngang, y + i);
			cout << char(245);
		}
	}
	normalBGColor();
}