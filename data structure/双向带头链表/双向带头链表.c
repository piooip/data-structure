#include "head.h"
LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListErase(LTNode* pos)//ɾ��posλ�õ�Ԫ��
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
void ListInsert(LTNode* pos,LTDataType x)//���뵽pos��ǰһ��Ԫ��
{
	LTNode* newnode = BuyListNode(x);
	newnode->data = x;
	newnode->next = pos;
	pos->prev->next = newnode;
	newnode->prev = pos->prev;//������pos->prev�ٸı���
	pos->prev = newnode;
}
void ListPopFront(LTNode*phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListErase(phead->next);
}
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListErase(phead);
}
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead->next, x);
}
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListPushBack(phead, x);
}
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf(" %d ", cur->data);
		cur = cur->next;
	}
}
LTNode* ListFind(LTNode*phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur=cur->next;
	}
	return NULL;
}
int ListSize(LTNode* phead)
{
	LTNode* cur = phead->next;
	int count = 0;
	while (phead != phead)
	{
		cur = cur->next;
		count++;
	}
	return count;
}
void LisDestory(LTNode* phead)//�ݻ�����
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		ListErase(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}