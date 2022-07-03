#include"stack.h"
void test()
{
	ST ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 1);
	StackPush(&ps, 1);
	StackPop(&ps);
	StackTop(&ps);
	int p=StackSize(&ps);
	for (int i = 0;i < ps.top;i++)
	{
		printf("%d", ps.a[i]);
	}
}

int main()
{
	test();
}