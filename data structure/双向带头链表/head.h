#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;
LTNode* BuyListNode(LTDataType x);
LTNode* ListInit();
void ListErase(LTNode* pos);//删除pos位置的元素
void ListInsert(LTNode* pos, LTDataType x);//插入到pos的前一个元素
void ListPopFront(LTNode* phead);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPushBack(LTNode* phead, LTDataType x);
void Listprint(LTNode* phead);
LTNode* ListFind( LTNode* phead, LTDataType x);