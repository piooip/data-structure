#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<time.h>
#include<corecrt.h>
void ShellSort(int* a, int n);
void PrintArray(int* a, int n);
void InsertSort(int* a, int n);
void SelectSort(int* a, int n);
void BubbleSort(int* a, int n);
void Swap(int* a, int* b);
void QuickSort(int* a, int n);
int Partsort1(int* a, int begin, int end);
int Partsort2(int* a, int begin, int end);
int Partsort3(int* a, int begin, int end);
//�ݹ�����⣺���������»����ջ���
//1.��ѭ��--쳲�����
//2.��ջģ��ݹ����
void QuickSortNonr(int* a, int begin, int end);//���ŷǵݹ�
void _MergeSort(int* a, int begin, int end, int* tmp);
void MergeSort(int* a, int n);
