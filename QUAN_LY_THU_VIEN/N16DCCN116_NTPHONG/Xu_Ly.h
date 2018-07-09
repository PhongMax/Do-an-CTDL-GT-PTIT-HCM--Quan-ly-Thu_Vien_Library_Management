#pragma once
#include <tchar.h>
#include "DSDocGia.h"
#include "DauSach.h"
#include <fstream>

void Introduce();

// hieu ung man hinh chinh
void ManHinhChinh();

void Save(TREE_DG t, fstream &file);

// duyet cay inoder de luu vao file.
void OutFile_DG(TREE_DG t, fstream &file);

// save tat ca doc gia vao file
void Save_DG(TREE_DG t);

// save tat ca dau sach vao file
void Save_DS(LIST_DAUSACH lDS);

//load du lieu dau sach tu file
void Load_DS(LIST_DAUSACH &lDS);

// load du lieu doc gia tu File 
void Load_DG(TREE_DG &t);

// Bang thao tac muon sach.
int Menu_MuonSach(LIST_DAUSACH &lDS, NODE_DG* nDG);

void XuLyMuonSach(TREE_DG &t, LIST_DAUSACH &lDS);

void XuLyTraSach(TREE_DG &t, LIST_DAUSACH &lDS);

// xu ly MeNu chinh
void MainMenu(TREE_DG &t, LIST_DAUSACH &lDS);