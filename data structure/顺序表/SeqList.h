#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType*a;
	int size;//由于数组是从0开始计数的，所以size位是最后一位的下一位
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
