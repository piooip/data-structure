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
void HeapPop(HP* ps)//ɾ���Ѷ�����
{
	//��ͷ��β�����ݽ���
	//�����һ������ɾ��
	//���µ����㷨������ͷ����������ΪС�ѣ�
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
	ps->a[ps->size] = x;//��x�������һ��λ�ã������ڵ���adjustup����
	ps->size++;
	Adjustup(ps->a, ps->a[ps->size - 1]);
}
void Adjustup(HPDataType* a, int child)//�б𱻲����ֵ����ĸ����Ƚϣ��ж����ڵ�λ��
{
	int parent = (child - 1) / 2;
	while (child > 0)//��child=parrent=0�Ǵﵽ�Ѷ�������
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
void AdjustDown(HPDataType*a, int size, int parent)//aΪ���飬sizeΪ����Ĵ�С��parentΪ���������
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
