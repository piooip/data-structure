#pragma once
#include<stdio.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;
void InOrder(BTNode* root);//�������
void PreOrder(BTNode* root);//ǰ�����
void PostOrder(BTNode* root);//�������
void TreeSize(BTNode* root);
int TreeSize2(BTNode* root);
void LevelOrder(BTNode* root);//�������
int TreeLeafSize(BTNode* root);
int TreeKLevel(BTNode* root, int k);
BTNode* TreeFind(BTNode* root, BTDataType x);
int TreeDepth(BTNode* root);
void TreeDestroy(BTNode* root);//�������������������ԭ��
int BinaryTreeComplete(BTNode* root);