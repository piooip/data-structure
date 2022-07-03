#include"Queue.h"
//ɾ����ʱ��Ҫ�����Ƿ�Ϊ��
//�Ƿ������һ��
//�������
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
	if (ps->tail == NULL)//��psʲô��û��ָʾʱ��head��tailָ��ָ��
	{
		ps->tail = newnode;
		ps->head = newnode;
	}
	else
	{
		ps->tail->next = newnode;
		ps->tail = newnode;//tailָ��˳��
	}
}
void QueuePop(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	if (ps->head->next == NULL)//��ps->head��Ϊ�գ���ps->head->nextΪ��
	{
		free(ps->head);
		ps->head = ps->tail = NULL;
	}
	else//�������
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
bool QueueEmpty(Queue* ps)//ע�⣺������ps->head�Ƿ�Ϊ��
{
	assert(ps);
	return ps->head == NULL;
}
int QueueSize(Queue* ps)
{
	assert(ps);//ע�⣺��ʹ�õ�ps->head->next����ʱ����õĵ�����Ƿ�Ϊ��
	int size = 0;
	QN* cur = ps->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}