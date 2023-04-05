#define _CRT_SECURE_NO_WARNINGS
#define maxsize 1000
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	LNode* next;
}LNode, * LinkList; //增加代码可读性


typedef struct List
{
	int length; //当前表长
	LinkList head;//头指针
}List;


//typedef struct LNode LNode;
//typedef struct LNode* LinkList;

//Linklist 强调单链表
//LNode* 强调结点
bool CreatList(List &L);
void print(List& L);
void Delete(List& L);
void Free(List& L);

int main()
{
	List L;
	
	CreatList(L);
	Delete(L);

	Free(L);
	return 0;
}

bool CreatList(List& L) //采用尾插法(后插法)
{
	LNode* p;    //指针
	LNode* tail; //尾指针

	printf("请输入表长:");
	for(;;)
	{
		scanf("%d", &L.length);
		if (L.length < maxsize&&L.length>=2)
		{
			break;
		}

		else
		{
			printf("请重试\n");
		}
	}

	L.head = (LinkList)malloc(sizeof(LNode)); //创建头结点
	tail = L.head; //尾指针指向头结点
	if (NULL == L.head)
	{
		printf("error\n");
		return false;
	}

	printf("请输入数据:");
	
	for (int i = 0; i < L.length; i++)
	{
		p = (LNode*)malloc(sizeof(LNode)); //创建结点
		if (NULL == p)
		{
			printf("error\n");
			return false;
		}

		scanf("%d",&p->data);

		tail->next=p; //尾指针指向的结点与下一个结点连接
		tail = p; //尾指针指向下一个结点

	}
	tail->next = NULL; //尾指针指空

	return true;
}

void print(List& L)
{
	LNode* p = L.head->next; //指向首元结点

	printf("\n当前表长 %d\n",L.length);
	for (;p!=NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
}

void Delete(List& L)
{
	LNode* cmp1 = L.head->next;
	LNode* tcmp3=cmp1;
	LNode* cmp2;
	
	for (; cmp1 != NULL; cmp1 = cmp1->next)
	{
		for (tcmp3 = cmp1; tcmp3->next != NULL; )
		{
			cmp2 = tcmp3->next;

			if (cmp1->data == cmp2->data)
			{

			tcmp3->next = cmp2->next;
			free(cmp2);
			L.length--;

			}
			else
			{
				tcmp3 = tcmp3->next;
			}
		}
	}
	print(L);
}

void Free(List& L)
{
	LNode* p=L.head;
	LNode* p1;
	for (; p->next != NULL; )
	{
		p1 = p->next;
		free(p);
		p = p1;
	}
}
