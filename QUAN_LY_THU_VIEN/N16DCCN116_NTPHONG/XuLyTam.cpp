#include "XuLyTam.h"

void initList_TEMPLIST(LIST_TEMPLIST &l)
{
	l.pHead = l.pTail = NULL;

}

NODE_TEMPLIST* GetNode_TEMPLIST(uint index, uint MADG)
{
	NODE_TEMPLIST *p = new NODE_TEMPLIST;
	if (p == NULL) {
		return NULL;
	}
	p->tl.index = index;
	p->tl.MADG = MADG;
	p->pNext = NULL;
	return (p);
}

void AddTailList_TEMPLIST(LIST_TEMPLIST &l, uint index, uint MADG)
{
	// tao Node
	NODE_TEMPLIST *p = GetNode_TEMPLIST(index, MADG);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;

	}
}

NODE_TEMPLIST * Middle(NODE_TEMPLIST * start, NODE_TEMPLIST * last)
{
	if (start == NULL)
		return NULL;
	NODE_TEMPLIST * slow = start;
	NODE_TEMPLIST * fast = start->pNext;

	while (fast != last)
	{
		fast = fast->pNext;
		if (fast != last)
		{
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}
	return slow;
}

// ne su dung tim kiem tuyen tinh vi cai nao cung bigO(n)
NODE_TEMPLIST * BinarySearch_TEMPLIST(LIST_TEMPLIST l, uint index)
{
	NODE_TEMPLIST *start = l.pHead;
	NODE_TEMPLIST *last = NULL;
	do
	{	//Find middle
		NODE_TEMPLIST * mid = Middle(start, last);
		// if middle is empty
		if (mid == NULL)
			return NULL;

		// if value is present at middle
		if (mid->tl.index == index)
			return mid;
		// if value is more than mid
		else if (mid->tl.index < index)
			start = mid->pNext;
		// if value is less than mid
		else
			last = mid;
	} while (last == NULL || last->pNext != start);
	return NULL; // value not present;
}

void ClearAll_TEMPLIST(LIST_TEMPLIST &l)
{
	NODE_TEMPLIST *p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
