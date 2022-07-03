#include"tree.h"
#include"Queue.h"
void InOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);//���������е�����ʱ���Զ�return
}
void PreOrder(BTNode* root)//ǰ�����
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
void PostOrder(BTNode* root)//�������
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}


void LevelOrder(BTNode* root)//�������(ʹ�ö���)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q,root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//û�̱�����Ҫ����һ��ɾ����0~2�β���
		if (front->left)
		{
			QueuePush(&q, root->left);
		}
		if (front->right)
		{
			QueuePush(&q, root->right);
		}//���ַ����ѿ��ų��ڶ�������
	}
	QueueDestory(&q);
}


int count;
void TreeSize(BTNode*root)
{
	if (root == NULL)
	{
		return;
	}
	count++;//countΪȫ�ֱ���
	TreeSize(root->left);
	TreeSize(root->right);
}


int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}


int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


int TreeKLevel(BTNode* root, int k)
{
	assert(k >= 1);
	if (k == 1)
		return 1;//�����k��
	if (root == NULL)
		return 0;//û����
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}


BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
	return NULL;
}


int TreeDepth(BTNode* root)
{
	if (root == NULL)//��д��������
		return 0;
	return max(TreeDepth(root->left) + 1, TreeDepth(root->right) + 1);
}


void TreeDestroy(BTNode* root)//�������������������ԭ��
{
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}
int BinaryTreeComplete(BTNode* root)
{
	//˼·�����ݲ�������������������ȫ�����������������Ľ���У���ֻ�������ĩβ
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//û�̱�����Ҫ����һ��ɾ����0~2�β���
		if (front)//
		{
			QueuePush(&q, root->left);
			QueuePush(&q, root->right);
		}//���ַ���ʹ�տ��Խ��������
		else
		{
			break;
		}//�����������վ��˳�
	}
	//1.��������ȫ�ǿգ���Ϊ��ȫ������
	//2.��֮������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//�����Ǵ�ͷ��ɾ������
		if (front)
		{
			QueueDestory(&q);
			return false;
		}
	}
	QueueDestory(&q);
	return true;
}
