#include"Heap.h"
void Heapsort(int* a, int n)
{
	//for (int i = 1;i < n;i++)//������   O(N*logN)
	//{
	//	Adjustup(a, i);//�ӿ�ͷ������Ϊadjustup��Ҫ�����Ԫ�ض�Ϊ��
	//}
	for (int i = n - 1;i >= 0;i--)//������  O(N)
	{
		AdjustDown(a, n, i);//�����������Ϊ�������Ԫ�ص����Ҷ���С���󣩶�
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);//���ѵĵ�һ��Ԫ�أ���������С�������һ��Ԫ�ؽ������൱�������ֵ��
		AdjustDown(a, end, 0);//���ڳ��˸��ڵ���������ҶѶ���С���󣩶ѣ�ʹ��adjustdown���ɻ�ԭ�ѣ�O(log(N))
		end--;//���ų������ݷ����������
	}
}
void PtintfTopk(int* a, int n, int k)//һ����n������������k��С�Ķ�
{
	int* kmintop = (int*)malloc(sizeof(int) * k);
	assert(kmintop);
	for (int i = 0;i < k; i++)
	{
		kmintop[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2;i >= 0;i--)//�������ɶ�
	{
		AdjustDown(kmintop, k, i);
	}
	for (int i = k;i < n;i++)//��k��С�Ķ�Ϊ���ݵأ������n-k�����Ƚ�
	{
		if (a[i] > kmintop[0])
		{
			swap(&a[i], &kmintop[0]);
			AdjustDown(kmintop, k, 0);
		}
	}
	for (int i = k-1;i > 0;i--)//������
	{
		swap(&kmintop[i], &kmintop[0]);
		AdjustDown(kmintop, i, 0);
	}
}
void testtopk()
{

}
int main()
{
	int a[50] = { 11,66,21,6,8,9 };
	Heapsort(a, 6);
}