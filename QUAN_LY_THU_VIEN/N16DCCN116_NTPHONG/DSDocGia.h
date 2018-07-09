#pragma once
#include <iostream>
#include "XuLyTam.h"
#include "Muon_Tra.h"
#include <string>
#include "GlobalVariable.h"
#include "Check_Nhap.h"
#include "Ve_Hinh.h"
#include "mylib.h"

using std::cout;
using std::string;

struct DocGia
{
	
	uint MADG;
	// std::string ho;
	string ho;
	string ten;
	
	uint gioitinh;
	uint trangthaithe;
	
};
typedef struct DocGia DOC_GIA;

struct NodeDG
{
	DOC_GIA DG;
	struct NodeDG *pLeft;
	struct NodeDG *pRight;
	LIST_MT mt;
};
typedef struct NodeDG NODE_DG;
typedef NODE_DG* TREE_DG;



//................................
struct QuaHan
{
	uint MADG;
	int songayquahan;
};

//................................

// khoi tao
void initTREE_DG(TREE_DG &t);

// kiem tra rong
bool IsEmpty(TREE_DG t);

// get node
NODE_DG* GetNode_DG(DOC_GIA dg);

//  them node vao tree DG
void InsertDTtoTree(TREE_DG &t, DOC_GIA dg);

// dem so luong doc gia
int countDG(TREE_DG tree);

// kiem tra MSDG co ton tai hay khong.
bool Check_MADG(TREE_DG  t, uint MADG);

// tra ve 1 so nguyen ngau nhien tu dong;
uint Random();

// Ham tra ve  MSDG la so nguyen ngau nhien tu dong va khong trung.
uint Random_MADG(TREE_DG t);

// find Min
NODE_DG* FindMin(TREE_DG t);

// tim doc gia bang ma doc gia, co tra ve dia chi , khong tra ve NULL
NODE_DG* Find_DG(TREE_DG t, uint MADG);

// neu xoa dc, thuc hien xoa roi tra ve true , khong tra ve false
bool IsDeleted_DG(TREE_DG &t, DOC_GIA dg);

//xoa  Output mot doc gia.
void Xoa_OutDG_1line(int locate);

// xoa Output 29 doc gia
void Xoa_OutDg_29lines();

// xuat thong tin cua mot DG ra man hinh console
void Output_DG(NODE_DG* dg);

// lay ten va ho
string Get_TenHO(DOC_GIA dg);

//Ap dung duyet theo thu tu Inoder de cac phan tu trong mang theo thu tu tang dan.
void Create_ArrMADG(TREE_DG t, uint* arr);

void Create_ArrTenHo(TREE_DG t, TEN_HO* arr);

// tao danh sach tam de xu ly.
void Creat_TEMPLIST(TREE_DG t, LIST_TEMPLIST &l, int &index);

void Swap_TenHo(TEN_HO &a, TEN_HO &b);

void QuicKsort_ARRTenHo(TEN_HO *th, int left, int right);

// ham cap nhat thong tin DG
void Update_DG(TREE_DG &t, DOC_GIA &dg, bool isEdited = false);

// output
void OutputDG_PerPage1(TREE_DG t, TEN_HO *arr, int index);

//  ham xuat ds DG theo thu tu ten ho tang dan
void OutputDG_PerPage2(TREE_DG t, uint* arr, int index);

// ham xuat danh sach DG theo thu tu MADG tang dan
void Output_ListDG2(TREE_DG t, uint *arr);

void OutputDG_PerPage(TREE_DG t, LIST_TEMPLIST l, int index);

int ChooseItems(TREE_DG &t, LIST_TEMPLIST &l, int tttrang, int tongtrang);

// ham xuat thong tin DG 
int Output_ListDG(TREE_DG &t, LIST_TEMPLIST &l, DOC_GIA &dg, int &tttrang);

void Menu_DocGia(TREE_DG &t);

void InDocGia(TREE_DG t);

// quick sort mang theo thu tu keyword giam dan
void Sort_QuaHan(QuaHan *ArrQuaHan, int q, int r);

//Duyệt cây theo thứ tự NLR (Preorder): Giai thuat khong de quy.
void DanhSachQuaHan(TREE_DG t);