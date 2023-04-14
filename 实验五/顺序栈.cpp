#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct sqstack // C站车厢
{
    int* top;
    int* base;
    int stacksize; // 车箱数
} sqstack;

void Initstack(sqstack& s);
bool Push(sqstack& s);
void Pop(sqstack& s, int& elem);

int main()
{

    int a[maxsize]; // 驶出C站后的车厢
    sqstack s;
    int num;
    int count=0;

    Initstack(s);
    printf("请输入车厢数目:");
    scanf("%d",&num);

    printf("输入车厢编号\n");

    for (int i = 0; i <num; i++)
    {
        Push(s);
        Pop(s, a[i]);
    }

    for (int i = 1; i < num; i++)
    {
        if (a[0] - a[i] == i || a[0] - a[i] == -i)
        {
            count++;
        }
    }

    if (count == num - 1)
    {
        printf("Yes\n");
    }

    else
    {
        printf("No\n");
    }
    system("pause");
    return 0;
}

void Initstack(sqstack& s)
{

    s.base = (int*)malloc(sizeof(int) * maxsize); // 创建一个空栈,s.base->栈底
    s.top = s.base;                                //表示空栈
    s.stacksize = 0;

}

bool Push(sqstack& s) // 入栈操作
{
    if (s.stacksize > maxsize)
    {
        printf("栈满了\n");
        return false;
    }

    scanf("%d", s.top++);    
    s.stacksize++;
    return true;
}

void Pop(sqstack& s, int& elem) // 栈顶元素弹栈操作
{
    if (s.top != s.base) // 如果不是空栈
    {
        elem = *--s.top; // 同优先度从右往左结合
        s.stacksize--;
    }
}
