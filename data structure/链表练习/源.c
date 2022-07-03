#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
// struct Listnode
//{
//	int val;
//	struct Listnode* next;
//};
// int main()//尾插的题用哨兵位
// {
//	 int k = 0;
//	 struct Listnode* greaterhead,* greatertail, * lesshead, * lesstail;
//	 greaterhead =greatertail= (struct Listnode*)malloc(sizeof(struct Listnode));
//	 lesshead = lesstail = (struct Listnode*)malloc(sizeof(struct Listnode));
//	 lesshead->next = NULL;
//	 greaterhead->next = NULL;
//	 struct Listnode* cur = head;
//	 while (cur)
//	 {
//		 if (cur->val > k)
//		 {
//			 greatertail->next = cur;
//			 greatertail = greatertail->next;
//		 }
//		 else if(cur->val < k)
//		 {
//			 lesstail->next = cur;
//			 lesstail = lesstail->next;
//		 }
//		 cur = cur->next;
//	 }
//	 lesstail->next = NULL;
//	 lesstail->next = greaterhead->next;
//	 struct Listnode* m = lesshead;
//	 free(greaterhead);
//	 free(lesshead);
//	 return m->next;
// }
typedef char STDatatybe;
typedef struct Stack
{
	STDatatybe* a;
	int top;
	int capacity;
}ST;
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;//注意
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
		if (tmp == NULL)//判断malloc是否开辟成功
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
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
STDatatybe StackTop(ST* ps)//出栈
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[--ps->top];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool isValid(char* s) {
	ST ps;
	StackInit(&ps);
	if (s == NULL)
		return false;//情况1
	for (int i = 0;s[i] != '\0';i++)
	{
		char m = s[i];
		if (m == '(' || m == '[' || m == '{')
		{
			StackPush(&ps, m);
		}
		else
		{
			if (StackEmpty(&ps))//情况2
			{
				return false;
			}
			char s = StackTop(&ps);
			if ((m == ')' && s == '(') || (m == ']' && s == '[') || (m == '}' && s == '{'))
			{
				;
			}
			else
			{
				return false;
			}
		}
	}
	if (StackEmpty(&ps))//情况3
		return true;
	else
		return false;
}
//int main()
//{
//	char s[99] = "[](){{{{}}}";
//	if (isValid(s))
//	{
//		printf("1");
//	}
//}