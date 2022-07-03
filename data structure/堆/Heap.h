#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;//����ǶѶ�
	int size;//sizeλ�����һλ����һλ
	int capacity;
}HP;
void HeapInit(HP* ps);
void HeapDestory(HP* ps);
void HeapPop(HP* ps);//ɾ���Ѷ�����
HPDataType HeapTop(HP* ps);
bool HeapEmpty(HP* ps);
int HeapSize(HP* ps);
void HeapPush(HP* ps, HPDataType x);
void Adjustup(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int size, int parent);
void swap(HPDataType* a, HPDataType* b);