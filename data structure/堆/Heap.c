#include"Heap.h"
void HeapInit(HP* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void HeapDestory(HP* ps)
{
	assert(ps);
	free(ps->a);
	ps->capacity = 0;
	ps->size = 0;
}
void HeapPop(HP* ps)//删除堆顶的数
{
	//把头和尾的数据交换
	//把最后一个数据删除
	//向下调整算法（除了头结点以外的数为小堆）
	swap(&ps->a[0], &ps->a[ps->size - 1]);
	AdjustDown(ps->a, ps->size, 0);
}
HPDataType HeapTop(HP* ps)
{
	assert(ps);
	return ps->a[0];
}
bool HeapEmpty(HP* ps)
{
	assert(ps);
	return ps->size == 0;
}
int HeapSize(HP* ps)
{
	assert(ps);
	return ps->size;
}
void swap(HPDataType* a, HPDataType* b)
{
	HPDataType p = *a;
	*a = *b;
	*b = p;
}
void HeapPush(HP* ps, HPDataType x)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		HPDataType* p = (HPDataType*)realloc(ps->a,sizeof(HPDataType) * newcapacity);
		if (p == NULL)
		{
			printf("error");
			exit(-1);
		}
		ps->capacity = newcapacity;
	}
	ps->a[ps->size] = x;//把x调到最后一个位置，后面在调用adjustup函数
	ps->size++;
	Adjustup(ps->a, ps->a[ps->size - 1]);
}
void Adjustup(HPDataType* a, int child)//判别被插入的值与其的父辈比较，判断其在的位置
{
	int parent = (child - 1) / 2;
	while (child > 0)//当child=parrent=0是达到堆顶，结束
	{
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType*a, int size, int parent)//a为数组，size为数组的大小，parent为待排序的数
{
	int child = 2*parent+1;
	while (child<size)
	{
		if (a[child + 1]<a[parent]&&child+1<size)
		{
			child = child + 1;
		}
		if ( a[child]<a[parent])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
