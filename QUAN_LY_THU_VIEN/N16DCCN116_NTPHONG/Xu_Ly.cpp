#include "Xu_Ly.h"


char dongChuChay[] = "   HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO THANH PHO HO CHI MINH";

void Introduce()
{
	system("color 3E");
	ShowCur(false);
	string a;

	// lay tu file o che do chi doc
	ifstream inFile("introduce.txt", ios::in);
	if (inFile.good())  // Kiem tra xem file co ket noi duoc hay khong?
	{
		while (!inFile.eof()) {
			getline(inFile, a);
			SetColor(LIGHT_AQUA);
			Sleep(100);
			cout << a << endl;
		}
	}
	else  //Tra ve loi
	{
		cout << "Lien ket voi File introduce khong thanh cong! " << "\n";
	}

	SetColor(LIGHT_GREEN);
	gotoxy(xTen, yTen);
	cout << "HOTEN : NGUYEN THANH PHONG";
	gotoxy(xTen, yTen + 1);
	cout << "MSSV  : N16DCCN116";
	gotoxy(xTen, yTen + 2);
	cout << "LOP   : D16CQCN02-N";
	CayLoading(LIGHT_YELLOW);
	ShowCur(false);

	// nhan enter de thoat vong lap
	gotoxy(45, 35);
	SetBGColor(BLUE);
	cout << "Please ! Press ENTER to continue. ";
	normalBGColor();

	while (!_kbhit()) {
		gotoxy(35, 30);
		SetColor(1 + rand() % 15);
		Sleep(100);
		cout << "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TP HO CHI MINH";
	}

	SetBGColor(AQUA);
	SetColor(AQUA);
	cin.ignore();

	// am thanh
	Beep(600, 200);
	return;
}

void ManHinhChinh()
{
	system("color 3E");
	clrscr();
	normalTextColor();
	ShowCur(false);
	VeKhungMenu();

	normalBGColor();
	MainMenu(keyMainMenu, 5);
	normalBGColor();

	string a;
	int y = 0;

	// lay tu file va chi doc
	ifstream inFile("QuanLyThuVien.txt", ios::in);

	// Kiem tra xem file co ket noi duoc hay khong?
	if (inFile.good())              
	{
		while (!inFile.eof()) {
			getline(inFile, a);
			SetColor(11);
			Sleep(100);
			gotoxy(25, y++);
			cout << a << endl;
		}
	}
	else  //Tra ve loi
	{
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
	}

	normalBGColor();
	SetBGColor(BLACK);
	
	// set khung
	gotoxy(xOrdinal + 44, yOrdinal + 34);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);

	gotoxy(xOrdinal + 44, yOrdinal + 35);
	cout << char(186) << setw(40) << setfill(' ') << char(186);

	gotoxy(xOrdinal + 44, yOrdinal + 36);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);

	chuChay(dongChuChay, xOrdinal + 45, yOrdinal + 35);
	return;
}

void Save(TREE_DG t, fstream &file)
{
	
	file << t->DG.MADG << endl;
	file << t->DG.ho << endl;
	file << t->DG.ten << endl;
	file << t->DG.gioitinh << endl;
	file << t->DG.trangthaithe << endl;

	file << t->mt.n << endl;
	for (NODE_MT* p = t->mt.pHead ; p != NULL; p = p->pNext )
	{
		file << p->data.MASACH << endl;

		file << p->data.ngaymuon.ngay << endl;
		file << p->data.ngaymuon.thang << endl;
		file << p->data.ngaymuon.nam << endl;

		file << p->data.ngaytra.ngay << endl;
		file << p->data.ngaytra.thang << endl;
		file << p->data.ngaytra.nam << endl;

		file << p->data.tensach << endl;
		file << p->data.trangthai << endl;
		file << p->data.vitrisach << endl;
	}
}

// ouput tree vao file theo kieu duyet tin thu tu...
void OutFile_DG(TREE_DG t, fstream &file)
{
	if (t != NULL)
	{
		Save(t, file);
		OutFile_DG(t->pLeft, file);
		OutFile_DG(t->pRight, file);	
	}
}

void Save_DG(TREE_DG t)
{
	fstream outFile;
	outFile.open("DocGia.txt", ios::out);
	if (outFile.is_open())
	{
		// so doc gia..
		outFile << countDG(t) << endl;
		OutFile_DG(t, outFile);
	}
	else
	{
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}
	outFile.close();
}

void Save_DS(LIST_DAUSACH lDS)
{
	fstream outFile;
	outFile.open("DauSach.txt", ios::out );
	if (outFile.is_open())
	{
		outFile << lDS.n + 1 << endl;
		for (int i = 0; i <= lDS.n; i++)
		{
			outFile << lDS.ListDS[i]->info.tensach << endl;
			outFile << lDS.ListDS[i]->info.ISBN << endl;
			outFile << lDS.ListDS[i]->info.tacgia << endl;
			outFile << lDS.ListDS[i]->info.theloai << endl;
			outFile << lDS.ListDS[i]->info.sotrang << endl;
			outFile << lDS.ListDS[i]->info.namSB << endl;
			
			outFile << lDS.ListDS[i]->dms.n << endl;
			for (NODE_DMS* p  = lDS.ListDS[i]->dms.pHead ; p != NULL ;  p = p->pNext )
			{
				outFile << p->data.maSach << endl;
				outFile << p->data.ttSach << endl;
				outFile << p->data.viTri << endl;
			}
		}
	}
	else
	{
		cout << "KET NOI VOI FILE DauSach THAT BAI! ";
	}
	outFile.close();
}

void Load_DS(LIST_DAUSACH &lDS)
{
	fstream inFile;
	dauSach info;
	inFile.open("DauSach.txt", ios::in);
	pDAU_SACH pDS;
	DMS dms;
	int sodausach, sosach;
	if (inFile.is_open())
	{
		string temp;
		inFile >> sodausach;
		getline(inFile, temp);

		for (int i = 0; i < sodausach; i++)
		{
			pDS = new DAU_SACH;
			if (pDS == NULL) continue;

			// load thong tin vao bien tam.

			getline(inFile, info.tensach);
			getline(inFile, info.ISBN);
			getline(inFile, info.tacgia);
			getline(inFile, info.theloai);
			inFile >> info.sotrang;
			inFile >> info.namSB;

			// load thong tin vao dau sach
			pDS->info = info;

			inFile >> sosach;
			getline(inFile, temp);
			initList_DMS(pDS->dms);
			for (int j = 0; j < sosach; j++)
			{
				getline(inFile, dms.maSach);
				inFile >> dms.ttSach;
				getline(inFile, temp);
				getline(inFile, dms.viTri);
				AddTailList_DMS(pDS->dms, dms);
			}

			Insert_DauSach(lDS, pDS);
		}
	}
	else {
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}

	inFile.close();
}

void Load_DG(TREE_DG &t)
{
	// khoi tao cay doc gia
	initTREE_DG(t);

	fstream inFile;
	NODE_DG* pDG = NULL;
	DOC_GIA dg;
	MUON_TRA mt;
	inFile.open("DocGia.txt", ios::in);
	int sodocgia, sosachmuontra;

	if (inFile.is_open())
	{
		string temp;
		inFile >> sodocgia;

		for (int i = 0 ; i < sodocgia; i++)
		{
			inFile >> dg.MADG;

			getline(inFile, temp);
			getline(inFile, dg.ho);
			getline(inFile, dg.ten);
			inFile >> dg.gioitinh;
			inFile >> dg.trangthaithe;

			// them data vao cay doc gia.
			InsertDTtoTree(t, dg);
			pDG = Find_DG(t, dg.MADG);

			
			inFile >> sosachmuontra;
			getline(inFile, temp);

			for (int j = 0; j <  sosachmuontra; j++)
			{
				getline(inFile, mt.MASACH);
				inFile >> mt.ngaymuon.ngay;
				inFile >> mt.ngaymuon.thang;
				inFile >> mt.ngaymuon.nam;
				inFile >> mt.ngaytra.ngay;
				inFile >> mt.ngaytra.thang;
				inFile >> mt.ngaytra.nam;

				getline(inFile, temp);
				getline(inFile, mt.tensach);
				inFile >> mt.trangthai;
				getline(inFile, temp);
				getline(inFile, mt.vitrisach);

				// cap nhat du lieu vao
				AddHeadList_MT(pDG->mt, mt);
			}
		}
	}
	else {
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}

	inFile.close();
}

int Menu_MuonSach(LIST_DAUSACH &lDS, NODE_DG* nDG)
{
	int choose1, choose2;
	bool check;
	char thongbao1[] = "            Sach da co DOC GIA muon. Moi ban chon cuon sach khac!";
	char thongbao2[] = "              Sach da duoc THANH LY. Moi ban chon cuon sach khac!";
	char thongbao3[] = "                 DOC GIA da muon sach thuoc Dau Sach nay!     ";
	normalBGColor();

	// nDs : so luong dau sach.
	int nDS = lDS.n + 1;
	int tttrang, tongtrang;
	pDAU_SACH pDS = NULL;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	int temp = 1;

label:
	do
	{
		// hien thi bang chua thong tin dau sach
		DisplayDS(keyDisplayDS, 6, xDisplayDS);

		OutputDS_PerPage(lDS, tttrang);

		gotoxy(23, 1);
		SetBGColor(GREEN);
		cout << "CHON 1 DAU SACH DE TIEN HANH MUON SACH ";
		normalBGColor();

		// chon dau sach muon nhap sach vao
		choose1 = ChooseItems(lDS, tttrang, tongtrang);

		// check cac truong hop ...
		if (choose1 == -1)
		{
			return -1;
		}
		else if (choose1 > lDS.n)
		{
			gotoxy(2, yDisplay + 3 + choose1 % NUMBER_LINES);
			cout << setw(27) << setfill(' ') << ' ';
			continue;
		}

		pDS = lDS.ListDS[choose1];

		// lay ten sach.
		tensach = pDS->info.tensach;

		check = SearchTenSach_MT(nDG->mt, tensach);

		// check cac truong hop
		if (check == true)
		{
			chuChay(thongbao3, 90, 24);
			_getch();
			gotoxy(90, 24);
			cout << "                                                       ";
		}
		else
		{
			XoaMotVung(1, 1, 35, 79);
			// thoat vong lap
			temp = 2;
		}
	
	} while (temp == 1);


label1:

	temp = 1;
	tttrang = 1;
	tongtrang = (pDS->dms.n / NUMBER_LINES) + 1;

	gotoxy(15, 1);
	SetBGColor(GREEN);
	cout << "CHON 1 CUON SACH DE TIEN HANH MUON SACH";
	normalBGColor();

	do
	{

		// hien thi bang chua thong tin danh muc sach
		DisplayDMS(keyDisplayDMS, 3, xDisplayDMS);
		OutputDMS_PerPage(pDS, tttrang);
		choose2 = ChooseItems1(pDS, tttrang, tongtrang);
		if (choose2 == -1)
		{
			temp = 1;
			tttrang = 1;
			gotoxy(15, 1);
			cout << "                                       ";
			goto label;
		}
		else if (choose2 + 1 > pDS->dms.n)
		{

			// xem thử chỗ đầu sách có quay lại ngay cái trang hầu nảy luôn kko
			gotoxy(2, yDisplay + 3 + choose2 % NUMBER_LINES);
			cout << setw(12) << setfill(' ') << ' ';
			continue;
		}
		else
		{
			NODE_DMS* dms = Search_DMS2(pDS->dms.pHead, choose2);

			// trang thai sach = 1, sach da co nguoi muon, nen se khong muon sach nay duoc.
			if (dms->data.ttSach == 1)
			{
				chuChay(thongbao1, 88, 24);
				_getch();
				gotoxy(88, 24);
				cout << "                                                                     ";
				goto label1;
			}
			// trang thai sach = 2 , sach da thanh ly, nen se khong muon sach duoc
			else if (dms->data.ttSach == 2)
			{
				chuChay(thongbao2, 88, 24);
				_getch();
				gotoxy(88, 24);
				cout << "                                                                      ";
				goto label1;
			}
			// trang thai sach = 0 cho muon duoc, nen se tien hanh muon sach.
			else if (dms->data.ttSach == 0)
			{
				// lay ma sach va vi tri sach... cap nhap trang thai sach da duoc muon.
				masach = dms->data.maSach;
				vitrisach = dms->data.viTri;
				dms->data.ttSach = 1;

			}

			// xoa dong tieu de di.
			gotoxy(15, 1);
			cout << "                                       ";
			temp = 0;
		}
	} while (temp);
	return 1;
}

void XuLyMuonSach(TREE_DG &t, LIST_DAUSACH &lDS)
{
	clrscr();
	system("color 3E");
	uint msdg =  0;
	int check1, check2, check3 = 0; 
	MUON_TRA mt;
	NODE_DG* temp;
	char thongbao1[] = "             DOC GIA chi duoc muon toi da 3 cuon !";
	char thongbao2[] = "           DOC GIA bi khoa the nen khong duoc muon sach !";
	char thongbao3[] = "         DOC GIA khong duoc muon sach vi da giu sach qua han 15 ngay!";
	char thongbao4[] = "         DOC GIA khong duoc muon sach vi da lam mat sach ^_^ ";

label:
	VeHinhBangNhap(83, 3, 50, "        HAY NHAP VAO MA DOC GIA DE MUON SACH");
	gotoxy(103, 5);
	check1 = NhapMaDocGia(msdg);

	// kiem tra ca truong hop
	if (check1 == -1)
	{
		gotoxy(91, 10);
		cout << "BAN VUA HUY TAC VU MUON SACH !!!";
		_getch();
	}
	else if (check1 == 1)
	{
		temp = Find_DG(t, msdg);
		if (temp == NULL)
		{
			gotoxy(82, 10);
			cout << "BAN VUA NHAP MA DOC GIA KHONG CO TRONG THU VIEN !!!";
			_getch();
			gotoxy(82, 10);
			cout << "                                                   ";
			goto label;
		}
		else
		{
			// in thong tin doc gia.
		label1:
			gotoxy(95, 9);
			cout << "~~~THONG TIN DOC GIA~~~";
			gotoxy(93, 11);
			cout << "- Ho va ten: " << temp->DG.ho << " "<< temp->DG.ten;

			gotoxy(93, 12);
			cout << "- Trang thai the : ";
			(temp->DG.trangthaithe == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(93, 13);
			cout << "- Phai: ";
			(temp->DG.gioitinh == 0) ? cout << "NAM" : cout << "NU";
			gotoxy(93, 14);
			cout << "- So sach  da muon : " << temp->mt.n;
			gotoxy(93, 15);
			cout << "- So sach chua tra : " << SoSachDangMuon(temp->mt);
			
			// in danh sach cac sach dang muon trong list MUONTRA cua doc gia.
			gotoxy(95, 17);
			cout << "___CAC SACH DANG MUON___";
			gotoxy(85, 18);
			cout << "__Ten Sach__________________________";
			gotoxy(118, 18);
			cout << "_Ngay Muon__";
			int i =  0; 
			for (NODE_MT * p = temp->mt.pHead; p != NULL ; p = p->pNext)
			{
				// truong hop dang muon chua tra, va truong hop dang muon nhung bi mat sach.
				if (p->data.trangthai == 0  || p->data.trangthai == 2)
				{
					// nap vao so sach muon cua doc gia qua bien i
					
					gotoxy(87 , 20 + i);    
					cout << "                                           ";
					gotoxy(87, 20 + i);
					cout << p->data.tensach;
					xuatNgayThang(p->data.ngaymuon, 118, 20 + i);
					i++;
					if (i == 3)
					{
						chuChay(thongbao1, 90, 24);
						_getch();
						return;
					}
				}
			}

			// xu ly truong hop khong cho muon sach khi trang thai the da bi khoa.
			if (temp->DG.trangthaithe == 0)
			{
				chuChay(thongbao2, 90, 24);
				_getch();
				return;
			}

			// xu ly truong hop khong cho muon sach khi doc gia lam mat sach.
			if (MatSach(temp->mt))
			{
				chuChay(thongbao4, 90, 24);
				_getch();
				return;
			}

			// xu ly truong hop muon sach qua han 15 ngay.
			if (SoNgayMuon_Max(temp->mt) > 15)
			{
				chuChay(thongbao3, 90, 24);
				_getch();
				return;

			}

			// in ra dong thong bao
			chuChay(dongthongbao, 90, 35);
			_getch();
			gotoxy(88, 35);
			cout << "                                                  ";

			// xu ly thao tac muon tra.
			check2 = Menu_MuonSach(lDS, temp);

			// check cac truong hop
			if (check2 == -1)
			{
				return;
			}
			else if (check2 == 1)
			{

				// nap thong tin vao cau truc muon tra bao gom ten sach, ngay muon, ngay tra..v.v.v
				mt.tensach = tensach;
				mt.ngaytra.nam = 0;
				mt.ngaytra.thang = 0;
				mt.ngaytra.ngay = 0;
				mt.MASACH = masach;
				mt.vitrisach = vitrisach;
			
				mt.trangthai = 0;


				// nhap thong tin ngay muon va xu ly truong hop nhap ngay muon lon hon ngay he thong;
				do
				{
					gotoxy(83, 28);
					cout << "Nhap vao ngay muon. Nhan F10 de luu, ESC de huy !";
					check3 = NhapNgayThang(mt.ngaymuon, 100, 30);

					// check cac truong hop
					if (check3 == -1)
					{
						return;
					}
					else if (check3 == 2)
					{
						AddHeadList_MT(temp->mt, mt);
						goto label1;
					}
				} while (check3 );		
			}
		}
	}	
}

void XuLyTraSach(TREE_DG &t, LIST_DAUSACH &lDS)
{
	clrscr();
	system("color 3E");
	uint msdg = 0;
	char thongbao[] = "         Doc Gia chua muon sach !  ";
	char thongbao1[] = "    Thong tin da duoc cap nhat. Bao mat sach thanh cong !";
	int check, check1 = 0;
	NODE_DG* temp;
	NGAY_THANG ngaytra;
	int choose1, choose2, i1, i2, condition = 1;

label:
	VeHinhBangNhap(40, 3, 50, "        HAY NHAP VAO MA DOC GIA DE TRA SACH");
	gotoxy(63, 5);
	check = NhapMaDocGia(msdg);

	// kiem tra ca truong hop
	if (check == -1)
	{
		gotoxy(50, 10);
		cout << "BAN VUA HUY TAC VU TRA SACH !!!";
		_getch();
	}
	else if (check == 1)
	{
		temp = Find_DG(t, msdg);
		if (temp == NULL)
		{
			gotoxy(40, 10);
			cout << "BAN VUA NHAP MA DOC GIA KHONG CO TRONG THU VIEN !!!";
			_getch();
			gotoxy(40, 10);
			cout << "                                                   ";
			goto label;
		}
		else
		{
			gotoxy(52, 9);
			cout << "~~~THONG TIN DOC GIA~~~";
			gotoxy(52, 11);
			cout << "- Ho va ten: " << temp->DG.ho << " " << temp->DG.ten;

			gotoxy(52, 12);
			cout << "- Trang thai the : ";
			(temp->DG.trangthaithe == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(52, 13);
			cout << "- Phai: ";
			(temp->DG.gioitinh == 0) ? cout << "NAM" : cout << "NU";
			gotoxy(52, 14);
			cout << "- So sach  da muon : " << temp->mt.n;
			gotoxy(35, 25);
			cout << "Hotkey:  F3 -  Tra Sach,  F4  -  Bao mat sach,  ESC - thoat";
	
		label1:
			gotoxy(52, 15);
			cout << "- So sach chua tra : " << SoSachDangMuon(temp->mt);
			gotoxy(37, 17);
			cout << "________________CAC SACH DANG MUON___________________";

			DisplayMT(keyDisplayMT, 7, XDisplayMT);
			OutputList_MT(temp->mt);

			do
			{
				while (_kbhit())
				{
					int kb_hit = _getch();
					if (kb_hit == 224 || kb_hit == 0)
						kb_hit = _getch();

					switch (kb_hit)
					{
					case  KEY_F3:
						Beep(600, 100);
						choose1 = chonItem_MT(temp->mt);
						if (choose1 == -1)
						{
							chuChay(thongbao, 50, 30);
							return;
						}
						i1 = -1;
						for (NODE_MT * pMT = temp->mt.pHead; pMT != NULL; pMT = pMT->pNext)
						{
							if (pMT->data.trangthai == 0 || pMT->data.trangthai == 2)
							{
								i1++;
								if (i1 == choose1)
								{
									// chuc nang nhap thong tin ngay tra.
									do
									{										
										gotoxy(40, 28);
										cout << "Nhap vao ngay tra. Nhan F10 de luu, ESC de huy !";
										check1 = NhapNgayThang(ngaytra, 55, 30);

										// check cac truong hop
										 if (check1 == 2)
										 {
											 if (SoSanhNgay(pMT->data.ngaymuon, ngaytra) < 0)
											 {
												 check1 = 1;
											 }
											 else
											 {
												 // thay doi trang thai sang da tra sach.
												 pMT->data.trangthai = 1;
												 pMT->data.ngaytra = ngaytra;
			
												 // tim kiem dau sach ma doc gia da muon
												 pDAU_SACH pDS = SearchTen_DS(lDS, pMT->data.tensach);

					
												 // tim kiem sach co ma dau sach ma doc gia da muon.
												 NODE_DMS* pDMS = Search_DMS1(pDS, pMT->data.MASACH);

												 // thay doi trang thai sach tu da co nguoi muon sang chua co nguoi muon
												 pDMS->data.ttSach = 0;
												 goto label1;
											 }
										 }
										 else if (check1 == -1)
										 {
											 goto label1;
									     }
										
									} while (check1);
								}
							}
						}
						goto label1;

					case KEY_F4: 
						Beep(600, 100);
						choose2 = chonItem_MT(temp->mt);
						if (choose2 == -1)
						{
							chuChay(thongbao, 50, 30);
							return;
						}
						i2 = -1;
						for (NODE_MT * pMT = temp->mt.pHead; pMT != NULL; pMT = pMT->pNext)
						{
							if (pMT->data.trangthai == 0 || pMT->data.trangthai == 2)
							{
								i2++;
								if (i2 == choose2)
								{
									// thay doi trang thai sang da lam mat sach.
									pMT->data.trangthai = 2;
									chuChay(thongbao1, 45, 30);
									gotoxy(45, 30);
									cout << "                                                ";
								}
							}
						}
						goto label1;

					case ESC:
						Beep(600, 100);
						condition = 0;
						break;
					}
				}
			}while (condition);
		}
	}
}

void MainMenu(TREE_DG &t, LIST_DAUSACH &lDS)
{
	int result;

	// set console window.
	SetConsoleTitle(_T("QUAN LY THU VIEN"));
	resizeConsole(GWIDTH, GHEIGHT);

	// load data from File.
	Load_DG(t);
	Load_DS(lDS);
	
	// hieu ung introduce.
	Introduce();
	clrscr();

	// vong lap vo han de xu ly.
	while (true)
	{	
		ManHinhChinh();
		int type = ChooseMainMenu(5);
		gotoxy(55, 32);
		cout << " ESC: Ve Menu Chinh";

		switch (type)
		{
		case 0:
			SubMainMenu1(keySubMainMenu1, 3);
			result = ChooseSubMenu(keySubMainMenu1, xSubMainMenus1, ySubMainMenus1, 3);
			if (result == 0)
			{
				Menu_DocGia(t);
			}
			else if (result == 1)
			{
				InDocGia(t);	
			}
			else if (result == 2)
			{
				DanhSachQuaHan(t);
			}
			break;

		case 1:
			SubMainMenu2(keySubMainMenu2, 3);
			result = ChooseSubMenu(keySubMainMenu2, xSubMainMenus2, ySubMainMenus2, 3);
			if (result == 0)
			{
				Menu_DauSach(lDS);
			}
			else if (result == 1)
			{
				Output_ListDStheoTT(lDS);
			}
			else if (result == 2)
			{
				Menu_DMS(lDS);
			}
			break;

		case 2:

			SubMainMenu3(keySubMainMenu3, 3);
			result = ChooseSubMenu(keySubMainMenu3, xSubMainMenus3, ySubMainMenus3, 3);
			if (result == 0)
			{
				XuLyTraSach(t, lDS);
			}
			else if (result == 1)
			{
				Top10Sach(lDS);
			}
			else if (result == 2)
			{
				XuLyMuonSach(t, lDS);
			}
			break;

		case 3:

			// luu data tu chuong trinh vao file.
			Save_DS(lDS);
			Save_DG(t);
			return;
		}
	}
}
