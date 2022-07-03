#include"Queue.h"
//删除的时候要考虑是否为空
//是否是最后一个
//大众情况
void QueuePush(Queue* ps, QDataType x)
{
	QN* newnode = (QN*)malloc(sizeof(QN));
	if (newnode == NULL)
	{
		printf("error");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (ps->tail == NULL)//当ps什么都没有指示时，head和tail指针指空
	{
		ps->tail = newnode;
		ps->head = newnode;
	}
	else
	{
		ps->tail->next = newnode;
		ps->tail = newnode;//tail指针顺移
	}
}
void QueuePop(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	if (ps->head->next == NULL)//当ps->head不为空，但ps->head->next为空
	{
		free(ps->head);
		ps->head = ps->tail = NULL;
	}
	else//大众情况
	{
		QN* cur = ps->head->next;
		free(ps->head);
		ps->head = cur;
	}
}
void QueueInit(Queue* ps)
{
	assert(ps);
	ps->head = ps->tail = NULL;
}
QDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->head->data;
}
QDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return  ps->tail->data;
}
void QueueDestory(Queue* ps)
{
	assert(ps);
	QN* cur = ps->head;
	while (cur)
	{
		QN* next = cur->next;
		free(cur);
		cur = next;
	}
	ps->head = ps->tail = NULL;
}
bool QueueEmpty(Queue* ps)//注意：检查的是ps->head是否为空
{
	assert(ps);
	return ps->head == NULL;
}
int QueueSize(Queue* ps)
{
	assert(ps);//注意：当使用到ps->head->next的是时候才用的到检查是否为空
	int size = 0;
	QN* cur = ps->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}