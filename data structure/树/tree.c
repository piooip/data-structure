#include"tree.h"
#include"Queue.h"
void InOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);//当程序运行到这里时会自动return
}
void PreOrder(BTNode* root)//前序遍历
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
void PostOrder(BTNode* root)//后序遍历
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


void LevelOrder(BTNode* root)//层序遍历(使用队列)
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
		QueuePop(&q);//没刺遍历都要经历一次删除，0~2次插入
		if (front->left)
		{
			QueuePush(&q, root->left);
		}
		if (front->right)
		{
			QueuePush(&q, root->right);
		}//此种方法把空排除在队列以外
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
	count++;//count为全局变量
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
		return 1;//到达第k层
	if (root == NULL)
		return 0;//没到达
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
	if (root == NULL)//先写返回条件
		return 0;
	return max(TreeDepth(root->left) + 1, TreeDepth(root->right) + 1);
}


void TreeDestroy(BTNode* root)//销毁树（后序遍历），原因：
{
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}
int BinaryTreeComplete(BTNode* root)
{
	//思路：根据层序遍历，如果该树是完全二叉树，则层序遍历的结果中，空只会出现在末尾
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//没刺遍历都要经历一次删除，0~2次插入
		if (front)//
		{
			QueuePush(&q, root->left);
			QueuePush(&q, root->right);
		}//这种方法使空可以进入队列里
		else
		{
			break;
		}//若队列遇到空就退出
	}
	//1.若队列里全是空，则为完全二叉树
	//2.反之，则不是
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//队列是从头部删除数据
		if (front)
		{
			QueueDestory(&q);
			return false;
		}
	}
	QueueDestory(&q);
	return true;
}
