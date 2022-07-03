#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"tree.h";
typedef BTNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QN;
typedef  struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;
void QueuePush(Queue* ps, QDataType x);
void QueuePop(Queue* ps);
void QueueInit(Queue* ps);
QDataType QueueFront(Queue* ps);
QDataType QueueBack(Queue* ps);
void QueueDestory(Queue* ps);
int QueueSize(Queue* ps);
bool QueueEmpty(Queue* ps);
QDataType QueueFront(Queue* ps);