#include"sort.h"
#include"new stack.h"
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)//������ʹ��end+1������i<n-1
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
		}//����ѭ�������ֿ���
		//1.end<0�����㵽ͷ��
		//2.ͨ��break����
		a[end + 1] = tem;//����if����ж�a[end+1]������tem����a[end]
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
		gap = gap / 3 + 1;//��һ��Ŀ���������gap��ֵΪ1
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
		}//���begin��maxi�ص�����maxi��ֵ����miniȥ��
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
//keyiֵ�Ƚ�Ӱ����ŵ�Ч�ʣ���keyiֵ������λֵ����Ч�ʴﵽ���
//���Ե�����Ϊ������߽ӽ��������ʹЧ��ΪN^2������ʹջ���
//��������keyi��
//1.���ѡkeyi
//2.����ȡ��
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
//ѧϰ���
//һ�����ŵ���������
//	1.ԭ����
//  2.�ڿӷ�
//  3.ǰ��˫ָ�뷨
//�����ӿ��ŵ��Ż�
//  1.keyiֵ��ѡȡ--�����������ȡ�з�
//  2.������ĩβ�����N�������в������򣬼��ٵݹ����
//��������ջ�Ͷ���ʵ�ֿ��ţ�ԭ�򣺷�ֹ�ݹ���ų���ջ�����
int Partsort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end - 1;
	int keyi = left;
	int midi = GetMidIndex(a, begin, end);
	swap(a[midi], a[begin]);
	while (left < right)
	{
		//���ڱ���right���ܵ�ԭ��
		//��Ϊ��ѡ��keyֵ����ߵ�һλ��������right���ܾͿ���ʹ��
		//ÿ���ܵĹ����У�rightʼ�ձ�left��һ��
		//����ʹ������ֵ��С�ڿ���ֵ��
		//�������keyֵ��������ֵ����
		while (left < right && a[right] >= a[keyi])//���м����ѭ���У�right�����ܳ���left
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		//���������߶���ֵ����keyʱ������ѭ��������Ҫ����ѭ��
		//������������˳��ģ���right����Խ��a[0]��λ��
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}
int PartSort2(int* a, int begin, int end)//�ڿӷ�
{
	int piti = begin;
	int midi = GetMidIndex(a, begin, end);
	swap(a[midi], a[begin]);
	int keyi = a[begin];
	while (begin < end)
	{
		//�ȴ��ұ��ұ�keyiС��ֵ
		while (begin < end && a[end] >= a[piti])
		{
			end--;
		}
		a[piti] = a[end];
		piti = end;
		//�ٴ�����ұ�keyi���ֵ
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
	//curָ����С����cur�ҵ�ʱ
	//prevָ���Ҹ��ں����Ҵ󣬵�prev�ҵ�ʱ�����߽���
	int midi = GetMidIndex(a, begin, end);
	swap(a[midi], a[begin]);
	int cur = begin + 1;
	int prev = begin;
	int keyi = begin;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//��prev��cur֮���ֵһ����keyiֵ�󣬵�ǰ��һ���ж�Ϊ��ʱ������prevָ�벻������
		{
			swap(a[prev], a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int begin, int end)//ʱ�临�Ӷȣ��������logN��NlogN 
{
	if (begin >= end)
	{
		return;
	}
	//С�����Ż�
	//��������������ȥ��С�����������ò�������
	if (begin - end > 10)//���������10��Ԫ��ʹ�ò�������
	{
		int keyi = PartSort1(a, begin, end);
		QuickSort(a, begin, keyi - 1);//����ߵݹ�
		QuickSort(a, keyi + 1, end);//���ұߵݹ�
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

	// [begin, mid] [mid+1, end] ���εݹ飬������������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//�鲢 [begin, mid] [mid+1, end]
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

	// �ѹ鲢���ݿ�����ԭ����
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