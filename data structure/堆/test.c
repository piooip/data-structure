#include"Heap.h"
void Heapsort(int* a, int n)
{
	//for (int i = 1;i < n;i++)//向上排   O(N*logN)
	//{
	//	Adjustup(a, i);//从开头排起，因为adjustup需要上面的元素都为堆
	//}
	for (int i = n - 1;i >= 0;i--)//向下排  O(N)
	{
		AdjustDown(a, n, i);//从最后排起，因为从最后排元素的左右都是小（大）堆
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);//将堆的第一个元素（最大或者最小）与最后一个元素交换（相当于提出最值）
		AdjustDown(a, end, 0);//由于除了根节点以外的左右堆都是小（大）堆，使用adjustdown即可还原堆，O(log(N))
		end--;//将排出的数据放在最后隐退
	}
}
void PtintfTopk(int* a, int n, int k)//一共有n个数，但建立k大小的堆
{
	int* kmintop = (int*)malloc(sizeof(int) * k);
	assert(kmintop);
	for (int i = 0;i < k; i++)
	{
		kmintop[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2;i >= 0;i--)//把数组变成堆
	{
		AdjustDown(kmintop, k, i);
	}
	for (int i = k;i < n;i++)//以k大小的堆为根据地，与后面n-k个数比较
	{
		if (a[i] > kmintop[0])
		{
			swap(&a[i], &kmintop[0]);
			AdjustDown(kmintop, k, 0);
		}
	}
	for (int i = k-1;i > 0;i--)//堆排序
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