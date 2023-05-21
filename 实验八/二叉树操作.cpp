#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct bitnode
{
    char data;
    bitnode* lchild, * rchild;    //左孩子右孩子

}bitnode, * bitree;

//创建二叉树T
void CreatBiTree(bitree& root)
{
    char c;

    printf("请输入一个字符:");
    scanf(" %c", &c);

    if ( c== '!')
    {
        return;
    }
    //建立根结点
    root = (bitree)malloc(sizeof(bitnode));
    root->lchild = NULL;
    root->rchild = NULL;
    root->data = c;
    CreatBiTree(root->lchild);
    CreatBiTree(root->rchild);
}

//先序遍历
void PreOrder(bitree root)
{
    if (root!=NULL)
    {
        printf("%c ", root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }

}

//中序遍历
void InOrder(bitree root)
{
    if (root!=NULL)
    {
        InOrder(root->lchild);
        printf("%c ", root->data);
        InOrder(root->rchild);
    }
}

//后序遍历
void PostOrder(bitree root)
{
    if (root!=NULL)
    {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%c ", root->data);
    }
}

//求二叉树的深度
int PostTreeDepth(bitree root)
{
    int l, r;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        l = PostTreeDepth(root->lchild)+1;
        r = PostTreeDepth(root->rchild)+1;
    }

    if (l > r)
        return l;
    else
        return r;
}

int main()
{
    bitree root = NULL;    //建立空树

    CreatBiTree(root);
    printf("二叉树的先序:");
    PreOrder(root);
    printf("\n");
    printf("二叉树的中序:");
    InOrder(root);
    printf("\n");
    printf("二叉树的后序:");
    PostOrder(root);
    printf("\n");
    printf("二叉树的深度=%d\n", PostTreeDepth(root));

    system("pause");
    return 0;
}
