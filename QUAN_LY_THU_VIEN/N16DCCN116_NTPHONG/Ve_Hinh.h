#pragma once

#include <iostream>
#include "Marcro.h"
#include "mylib.h"
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>      // std::setw, setfill

using std::string;  
using std::cout;
using std::setw;
using std::setfill;
	
// Ten cac danh muc trong Menu chinh
extern string keyMainMenu[5];
// Ten cac danh muc trong Menu con
extern string keySubMainMenu3[3];
extern string keySubMainMenu2[3];
extern string keySubMainMenu1[3];
extern string keyBangNhapDauSach[14];
extern string keyBangNhapDanhMucSach[8];
extern string keyBangNhapDG[12];

// ten cac danh muc hien thi  trong bang hien thi doc gia
extern string keyDisplayDG[5];

// ten cac danh muc hien thi trong bang hien thi dau sach
extern string keyDisplayDS[6];

// ten cac danh muc hien thi trong bang hien thi danh muc sach.
extern string keyDisplayDMS[3];

// ten cac danh muc hien thi trong bang hien thi danh sach muon tra.
extern string keyDisplayMT[7];

// ten cac danh muc hien thi trong bang hien thi Top10
extern string keyDisplayTop10[3];

// ten cac danh muc trong muc Guides
extern string keyGuide1[6];
extern string keyGuide2[7];
extern string keyGuide3[4];

// Cac diem toa do x trong bang hien thi doc gia
extern int xDisplayDG[6];

//Cac diem toa do x trong bang hien thi dau sach
extern int xDisplayDS[7];

//Cac diem toa do x trong bang hien thi danh muc sach
extern int xDisplayDMS[4];

//cac diem toa do x trong bang hien thi danh sach muon tra.
extern int XDisplayMT[8];

// cac diem toa do x trong bang hien thi Top10
extern int xDisplayTop10[4];

// Cac diem toa do x trong main menu
extern int xMainMenus[5];

// Cac diem toa do y trong  menu con
extern int ySubMainMenus1[3];
extern int ySubMainMenus2[3];
extern int ySubMainMenus3[3];

// tao o hinh chu nhat thay doi theo chieu dai text truyen vao
void CreateBox(int x, int y, string text, int length);

// in ra dong chu chay vao console
void chuChay(char dChu[], int x, int y);

// ve hinh bang nhap.
void VeHinhBangNhap(int x, int y, int dorong, string str);

//ve cay loading
void CayLoading(int Color);

//ve khung vien
void VeKhungMenu();

// xoa mot dong
void XoaMotDong(int width);

// xoa mot phan man hinh
void XoaMotVung(int x, int y, int ndoc, int width);

// highlight o Main Menu
void HighLight(string key, int index, int newColor, int oldColor);

// highlight o Menu con
void HighLight1(string key, int index, int x, int y[], int newColor, int oldColor);

// ve Menu chinh
void MainMenu(string key[], int nKey);

// ve cac Menu con
void SubMainMenu1(string key[], int nKey);

void SubMainMenu2(string key[], int nKey);

void SubMainMenu3(string key[], int nKey);

void EffectiveMenu(int pos, int flag);

void EffectiveSubMenu(string key[], int xSubMenu, int ykey[], int nkey, int pos, int flag);

//hieu ung chon cac muc trong MainMenu
int ChooseMainMenu(int nKey);

//hieu ung chon cac muc trong SubMenu
int ChooseSubMenu(string key[], int xSubMenu, int ykey[], int nkey);

// ham hien thi bang thong tin dau sach
void DisplayDS(string key[], int nKey, int xDisplay[]);

// ham hien thi bang thong tin doc gia
void DisplayDG(string key[], int nKey, int xDisplay[]);

//   ham hien thi bang thong tin danh muc sach
void DisplayDMS(string key[], int nKey, int xDisplay[]);

//  ham hien thi bang thong tin danh sach muon tra.
void DisplayMT(string key[], int nKey, int xDisplay[]);


// ham hien thi bang thong tin Top10
void DisplayTop10(string key[], int nKey, int xDisplay[], int ndoc);

// ve bang nhap thong tin
void BangNhap(int x, int y, int nngang, string key[], int nkey);

// ve bang huong dan Guides
void BangGuides(int x, int y, int nngang, string key[], int nkey);

