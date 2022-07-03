#include"head.h"
void TestList()
{
	LTNode*phead=ListInit();
	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPushFront(phead, 5);
	ListPushFront(phead, 6);
	LTNode* mp = ListFind(phead, 3);
	ListInsert(mp, 10000);
	ListErase(mp);
	ListPrint(phead);
}
int main()
{
	TestList();
}