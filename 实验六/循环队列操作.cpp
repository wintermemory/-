#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct sqQueue
{
    int* data;
    int front;    //头指针出队    数组下标指向方式
    int rear;     //尾指针入队
    int size;     // 空间大小
}sqQueue;

bool InitsqQueue(sqQueue& q,int num)
{
    q.size = num;
    q.data = (int*)malloc(sizeof(int)*q.size);
    if (NULL == q.data)
    {
        return false;
    }
    q.rear = 0;
    q.front = q.rear;
    return true;
}

bool EnQueue(sqQueue& q, int elem)
{
    if ((q.rear + 1) % q.size==q.front)    // 判满
    {
        printf("队列已满\n");
        return false;
    }
    else
    {
        q.data[q.rear] = elem;
        q.rear = (q.rear + 1) % q.size;
        return true;
    }
}

bool DeQueue(sqQueue& q)
{
    if (q.front==q.rear)    //判空
    {
        printf("队列空,删除失败\n");
        return false;
    }
    else
    {
        q.front = (q.front + 1) % q.size;
        return true;
    }
}

void print_Queue(sqQueue& q)
{
    while (true)
    {
        if (q.front != q.rear)
        {
            printf("%d ",q.data[q.front]);
            q.front = (q.front + 1) % q.size;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    sqQueue q;
    int num;
    char choice[10];
    int elem;

    printf("输入顺序循环队列空间总数:");
    scanf("%d",&num);
    InitsqQueue(q, num);

    printf("请输入插入删除次数:");
    scanf("%d", &num);

    printf("请输入操作(in/out)\n");
    while (num--)
    {
        
        scanf("%s", choice);
        while (1)
        {
            if (strcmp(choice,"in") == 0 )
            {  
                break;
            }
            else if (strcmp(choice, "out") == 0)
            {
                break;
            }
            else
            {
                printf("请重试\n");
                scanf("%s",choice);
            }
        }
        
        if (strcmp(choice, "in") == 0)
        {
            scanf("%d",&elem);
            EnQueue(q, elem);
        }

        else
        {
            DeQueue(q);
        }
    }
    print_Queue(q);

    free(q.data);
    system("pause");
    return 0;
}
