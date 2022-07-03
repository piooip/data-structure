#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    BTDataType data;
}BTNode;
BTNode* BuyNode(BTDataType x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);

    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}
BTNode* CreatPreTree(int* i, char* p)
{
    if (p[*i] == '#')
        return NULL;
    BTNode* root = BuyNode(p[(*i)++]);
    root->left = CreatPreTree(&i, p);
    root->right = CreatPreTree(&i, p);
    return root;
}
void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("#");
        return;
    }
    InOrder(root->left);
    printf("%c\n", root->data);
    InOrder(root->right);
    return;
}
int main()
{
    char arr[100] = "";
    scanf_s("%s", arr);
    int i = 0;
    BTNode* root = CraetPreTree(&i, arr);
    InOrder(root);
}