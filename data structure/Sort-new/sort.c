#include"sort.h"
#include"new stack.h"
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)//后面有使用end+1，所以i<n-1
	{
		int end = i;
		int tem = a[end + 1];
		while (end >= 0)
		{
			if (tem < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}//跳出循环有两种可能
		//1.end<0，运算到头部
		//2.通过break跳出
		a[end + 1] = tem;//根据if语句判断a[end+1]到底是tem还是a[end]
	}
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//加一点目的是让最后gap的值为1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}

}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = end;
		int mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}//如果begin和maxi重叠，则maxi的值换到mini去了
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int exchange = 0;
		for (int m = i; m < n - i - 1; m++)
		{
			if (a[m] > a[m + 1])
			{
				Swap(&a[m], &a[m + 1]);
				exchange = 1;
			}
		}
		if (exchange = 0)
			break;
	}
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//keyi值比较影响快排的效率，若keyi值处于中位值，则效率达到最大
//所以当数组为有序或者接近有序，则会使效率为N^2，甚至使栈溢出
//？怎样找keyi？
//1.随机选keyi
//2.三数取中
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[end])
	{
		if (a[mid] > a[begin])
			return mid;
		else if (a[mid] > a[end])
			return end;
		else
			return begin;
	}
	else//a[begin]>a[end]
	{
		if (a[mid] > a[begin])
			return	begin;
		else if (a[mid] > a[end])
			return mid;
		else
			return end;
	}
}
//学习情况
//一：快排的三种类型
//	1.原方法
//  2.挖坑法
//  3.前后双指针法
//二：队快排的优化
//  1.keyi值的选取--随机法，三数取中法
//  2.利用在末尾对最后N个数进行插入排序，减少递归次数
//三：利用栈和队列实现快排（原因：防止递归快排出现栈溢出）
int Partsort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end - 1;
	int keyi = left;
	int midi = GetMidIndex(a, begin, end);
	swap(a[midi], a[begin]);
	while (left < right)
	{
		//关于必须right先跑的原因
		//因为所选的key值是左边第一位，所以让right先跑就可以使在
		//每次跑的过程中，right始终比left快一轮
		//最终使相遇的值是小于可以值的
		//方便后面key值与相遇数值交换
		while (left < right && a[right] >= a[keyi])//在中间这个循环中，right可能跑超过left
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		//当左右两边都有值等于key时，会死循环，所以要加上循环
		//但若从左到右是顺序的，则right可能越过a[0]的位置
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}
int PartSort2(int* a, int begin, int end)//挖坑法
{
	int piti = begin;
	int midi = GetMidIndex(a, begin, end);
	swap(a[midi], a[begin]);
	int keyi = a[begin];
	while (begin < end)
	{
		//先从右边找比keyi小的值
		while (begin < end && a[end] >= a[piti])
		{
			end--;
		}
		a[piti] = a[end];
		piti = end;
		//再从左边找比keyi大的值
		while (begin < end && a[begin] <= a[piti])
		{
			begin++;
		}
		a[piti] = a[begin];
		piti = begin;
	}
	a[piti] = keyi;
	return piti;
}
int partsort3(int* a, int begin, int end)
{
	//cur指针找小，当cur找到时
	//prev指针找跟在后面找大，当prev找到时，二者交换
	int midi = GetMidIndex(a, begin, end);
	swap(a[midi], a[begin]);
	int cur = begin + 1;
	int prev = begin;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//在prev和cur之间的值一定比keyi值大，当前面一个判断为假时，后面prev指针不再增加
		{
			swap(a[prev], a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int begin, int end)//时间复杂度：树的深度logN，NlogN 
{
	if (begin >= end)
	{
		return;
	}
	//小区间优化
	//考虑用其他排序去对小区间排序，利用插入排序
	if (begin - end > 10)//后面是最后10个元素使用插入排序
	{
		int keyi = PartSort1(a, begin, end);
		QuickSort(a, begin, keyi - 1);//从左边递归
		QuickSort(a, keyi + 1, end);//从右边递归
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}
}
void QuickSortNonr(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int keyi = Partsort3(a, right, left);
		if (keyi - 1 > left)
		{
			Stackpush(&st, begin);
			StackPush(&st, keyi - 1);
		}
		if (keyi + 1 < right)
		{
			Stackpush(&st, keyi + 1);
			StackPush(&st, end);
		}
	}
	StackDestory(&st);
}
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;

	// [begin, mid] [mid+1, end] 分治递归，让子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并 [begin, mid] [mid+1, end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// 把归并数据拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}