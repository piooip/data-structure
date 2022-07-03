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
//递归的问题：极端问题下会造成栈溢出
//1.改循环--斐波那契
//2.用栈模拟递归进程
void QuickSortNonr(int* a, int begin, int end);//快排非递归
void _MergeSort(int* a, int begin, int end, int* tmp);
void MergeSort(int* a, int n);
