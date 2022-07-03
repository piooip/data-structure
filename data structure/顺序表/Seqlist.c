#include "SeqList.h"
void SLinit(SL* ps)
{
	ps->a = NULL;
	ps->capsity = ps->size = 0;
}
void SLCheakcapsity(SL* ps)
{
	if (ps->capsity == ps->size)
	{
		int newcapsity = ps->capsity == 0 ? 4 : ps->capsity * 2;
		SLDataType* tem = (SLDataType*)realloc(ps->a,sizeof(SLDataType) * newcapsity);//使用realloc重新开辟空间
		if (tem == NULL)
		{
			printf("realloc error");
			return;
		}
		ps->capsity = newcapsity;
		ps->a = tem;
	}
}
void SLprint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SLpushfront(SL* ps,int x)
{
	
	 SLCheakcapsity(ps);
	 int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SLpushback(SL* ps, int x)
{
	SLCheakcapsity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SLerase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}
void SLinsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheakcapsity(ps);
	int end = ps->size - 1;
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->size++;
	ps->a[pos] = x;
}
void SLdestory(SL* ps)
{
	assert(ps);
	if (ps != NULL)
	{
		free(ps);
		ps->a = NULL;
		ps->capsity = 0;
		ps->size = 0;
	}
}
void SLpopback(SL* ps)
{
	assert(ps);
	SLerase(ps, ps->size - 1);
}
void SLpopfront(SL* ps)
{
	assert(ps);
	SLerase(ps, 0);
}