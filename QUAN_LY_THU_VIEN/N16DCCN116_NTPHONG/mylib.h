#pragma once
#include <Windows.h>
#include "Marcro.h"
#include "GlobalVariable.h"


// thay doi kich thuoc cua so console
void resizeConsole(int width, int height);

//tra ve vi tri toa do x hien tai cua con tro dang dung(tren cot doc)
int wherex(void);

// tra ve vi tri toa do y hien tai cua con tro dang dung(tren cot ngang)
int wherey(void);

// ....... set mau cua nen chu....................
void SetBGColor(WORD color);

// dua con tro den toa do x:y
void gotoxy(int x, int y);

// An/ Hien con tro nhap nhay trong console
void ShowCur(bool CursorVisibility);

// Dat mau cho chu
void SetColor(WORD color);

//Xoa toan bo noi dung cua so console
void cls(HANDLE hConsole);

void clrscr();


// chu chuyen ve mau vang
void normalTextColor();
 
// nen chu chuyen ve xanh  va chu chuyen ve mau vang
void normalBGColor();


/// Function which returns character on console's cursor position 
char getCursorChar();    


/// Function which reads character at specific coordinates
char readChar(int x, int y); 
