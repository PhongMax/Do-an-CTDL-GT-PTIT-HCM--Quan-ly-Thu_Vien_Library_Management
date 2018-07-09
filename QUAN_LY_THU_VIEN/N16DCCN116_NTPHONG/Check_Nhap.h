#pragma once
#include "Marcro.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "mylib.h"
#include "Ngay_Thang.h"
using namespace std;


// loai bo khang space ' ' thua trong string.
string ChuanHoaString(string result);

// ham ho tro nhap gioi tinh va trang thai the
void Nhap(uint &result, int choice, int &ordinal, bool &isSave, bool &isEscape);

// ham ho tro nhap ten
void NhapTen(string &result, int &ordinal, bool &isSave, bool &isEscape);

// ham ho tro Nhap Ho
void NhapHo(string &result, int &ordinal, bool &isSave, bool &isEscape);

// ham ho tro Nhap Ten Sach.
void NhapTenSach(string &result, int &ordinal, bool &isSave, bool &isEscape);

// ham ho tro Nhap Ten Tac Gia
void NhapTenTacGia(string &result, int &ordinal, bool &isSave, bool &isEscape);

// ham ho tro nhap The Loai Sach
void NhapTheLoaiSach(string &result, int &ordinal, bool &isSave, bool &isEscape);

// ham ho tro nhap so trang sach
void nhapSoTrang(uint &nTrang, int &ordinal, bool &isSave, bool &isEscape);


// nhập chữ và sô ibsm...  4 chư số.

// ................... ham ho tro nhap Nam XB.............................
void NhapNamXuatBan(uint &nam, int &ordinal, bool &isSave, bool &isEscape);


// ................ ham ho tro nhap Ma Dau Sach............................
void NhapISBN(string &result, int &ordinal, bool &isSave, bool &isEscape);

//................nhap so luong sach can nhap vao ..........................
int  ChonSoSachNhap();

//ham ho tro nhap trang thai sach

void NhapTrangThaiSach(uint &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b);
// ham ho tro nhap vi tri cua sach trong thu vien 
void NhapViTri(string &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b);

int NhapNgayThang(NGAY_THANG &nt, int x, int y);

// ham ho tro nhap ma dau sach trong danh muc sach
int NhapMaDauSach(string &result);

// ham ho tro nhap ten sach tu ban phim de tra cuu thong tin.
int  NhapTenSachTimKiem(string &result);

// ham ho tro nhap vao ma doc gia de muon sach.
int  NhapMaDocGia(uint &msdg);

