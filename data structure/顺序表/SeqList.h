#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType*a;
	int size;//���������Ǵ�0��ʼ�����ģ�����sizeλ�����һλ����һλ
	int capsity;
}SL;
void SLinit(SL*ps);
void SLCheakcapsity(SL* ps);
void SLpushfront(SL* ps, int x);
void SLpushback(SL* ps, int x);
void SLprint(SL* ps);
void SLinsert(SL* ps, int pos, SLDataType x);
void SLerase(SL* ps, int pos);
int SLfind(SL* ps, SLDataType x);
void SLmodify(SL* ps, int pos, SLDataType x);
void SLinsert(SL* ps, int pos, SLDataType x);
void SLdestory(SL* ps);
void SLpopback(SL* ps);
void SLpopfront(SL* ps);
