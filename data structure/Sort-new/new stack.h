#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDatatybe;
typedef struct Stack
{
	STDatatybe* a;
	int top;
	int capacity;
}ST;
void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDatatybe x);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
STDatatybe StackTop(ST* ps);//³öÕ»
int StackSize(ST* ps);
