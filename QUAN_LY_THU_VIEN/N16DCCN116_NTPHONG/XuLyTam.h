#pragma once
#include <iostream>
#include "Marcro.h"
using std::string;

struct TenHo
{
	string hoten;
	uint MADG;
};
typedef struct TenHo TEN_HO;

struct Temp_List
{
	uint index;
	uint MADG;
};
typedef struct Temp_List TEMP_LIST;

struct NodeTempList
{
	TEMP_LIST tl;
	struct NodeTempList * pNext;
};
typedef struct NodeTempList NODE_TEMPLIST;

struct ListTempList
{
	//so phan tu
	// int n;
	NODE_TEMPLIST *pHead;
	NODE_TEMPLIST *pTail;

};
typedef struct ListTempList LIST_TEMPLIST;

// ..... khoi tao........
void initList_TEMPLIST(LIST_TEMPLIST &l);

//.......get node.........
NODE_TEMPLIST* GetNode_TEMPLIST(uint index, uint MADG);

//...... add tail link list........
void AddTailList_TEMPLIST(LIST_TEMPLIST &l, uint index, uint MADG);

// function to find out middle element
NODE_TEMPLIST * Middle(NODE_TEMPLIST * start, NODE_TEMPLIST * last);

// Function for implementing the Binary Search on linked list
NODE_TEMPLIST * BinarySearch_TEMPLIST(LIST_TEMPLIST l, uint index);

//void XoaHead_TEMPLIST(LIST_TEMPLIST &l)
//{
//	NODE_TEMPLIST * p = l.pHead;
//	l.pHead = l.pHead->pNext;
//	delete p;
//}
//
//void XoaNodeBatKy_TEMPLIST(LIST_TEMPLIST &l, TEMP_LIST tl)
//{
//	if (tl.index == 0)
//	{
//		XoaHead_TEMPLIST(l);
//		return;
//	}
//	//  node p là node  truoc node can xoa.
//	NODE_TEMPLIST * p  = BinarySearch_TEMPLIST(l, tl.index -1);
//	if (p == NULL || p->pNext == NULL)
//		return;
//	
//	NODE_TEMPLIST * q = p->pNext->pNext;
//	delete (p->pNext); // free memory
//	p->pNext = q; 
//}
//

//............xoa list..................
void ClearAll_TEMPLIST(LIST_TEMPLIST &l);