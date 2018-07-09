#pragma once

#include <time.h>
#include <iostream>
#include "mylib.h"
#include "Marcro.h"
using std::cout;

// 1800 <  NAM < 9999
const int MAX_NAM = 9999;
const int MIN_NAM = 1800;

struct NgayThang
{
	uint ngay;
	uint thang;
	uint nam;
};
typedef struct NgayThang NGAY_THANG;

// kiem tra nam nhuan
bool namNhuan(int year);

// kiem tra ngay hop format hay khong?
int ngayHopLe(NGAY_THANG nt);

//xuat ngay thang
void xuatNgayThang(NGAY_THANG dt, int x, int y);

//  lay ngay gio he thong
void LayNgayGioHT(NGAY_THANG &d);

// lay nam tu he thong
int LayNamHT();

//ham tra ve  so ngay 
// nguon: http://mathforum.org/library/drmath/view/66535.html
int tinhNgay(NGAY_THANG dt);

// ham tinh khoang cach so ngay giua hai ngay da cho.
int KhoangCachNgay(NGAY_THANG nt1);


int SoSanhNgay(NGAY_THANG nt1, NGAY_THANG nt2);