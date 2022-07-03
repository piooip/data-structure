#include"new stack.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;//ע��
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDatatybe x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDatatybe newcapsity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDatatybe* tmp = (STDatatybe*)realloc(ps->a, newcapsity * sizeof(STDatatybe));
		if (tmp == NULL)//�ж�malloc�Ƿ񿪱ٳɹ�
		{
			printf("malloc fail");
			exit(-1);
		}
		ps->capacity = newcapsity;
		ps->a = tmp;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
STDatatybe StackTop(ST* ps)//��ջ
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}