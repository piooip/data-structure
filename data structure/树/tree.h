#pragma once
#include<stdio.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;
void InOrder(BTNode* root);//中序遍历
void PreOrder(BTNode* root);//前序遍历
void PostOrder(BTNode* root);//后序遍历
void TreeSize(BTNode* root);
int TreeSize2(BTNode* root);
void LevelOrder(BTNode* root);//层序遍历
int TreeLeafSize(BTNode* root);
int TreeKLevel(BTNode* root, int k);
BTNode* TreeFind(BTNode* root, BTDataType x);
int TreeDepth(BTNode* root);
void TreeDestroy(BTNode* root);//销毁树（后序遍历），原因：
int BinaryTreeComplete(BTNode* root);