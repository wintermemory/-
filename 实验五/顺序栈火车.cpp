#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct sqstack
{
    int* top;
    int* base;
} sqstack;

void Initstack(sqstack& s);
bool Push(sqstack& s, int a);
bool Pop(sqstack& s);
int GetTop(sqstack& s);     //取栈顶元素

int main()
{
    int a[maxsize]; // 入栈序列
    int b[maxsize]; // 出栈序列
    int n;          // 火车数量

    printf("请输入火车数:");
    scanf("%d", &n);
    while (n--)
    {
        int num;         //火车车厢节数
        int count1 = 0;  //计入栈次数
        int count2 = 0;  //计出栈次数

        printf("请输入火车车厢节数:");
        scanf("%d", &num);

        sqstack s;
        Initstack(s);

        for (int i = 0; i < num; i++)   //进栈前
        {
            a[i] = i + 1;               //a[0]开始入栈
        }

        printf("输入出栈顺序\n");
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &b[i]);
        }


        while (true)
        {
            if (a[count1] <= b[count2])
            {
                Push(s, a[count1++]);
            }

            while (1)       //栈顶元素与出栈元素一致则弹出元素
            {
                if (GetTop(s) == b[count2])
                {
                    Pop(s);
                    count2++;
                }
                else
                {
                    break;
                }
            }

            if (count1 == num)
            {
                break;
            }
        }

        if (s.top == s.base)
        {
            printf("Yes\n\n");
        }
        else
        {
            printf("No\n\n");
        }

        free(s.base);
    }
    system("pause");
    return 0;
}

void Initstack(sqstack& s)
{

    s.base = (int*)malloc(sizeof(int) * maxsize); // 创建一个空栈,s.base->栈底
    s.top = s.base;                                //表示空栈
}

bool Push(sqstack& s, int a) // 入栈操作
{
    if (s.top - s.base > maxsize)
    {
        printf("栈满了\n");
        return false;
    }
    *s.top++ = a;
    return true;
}

bool Pop(sqstack& s) // 栈顶元素弹栈操作
{
    if (s.top != s.base) // 如果不是空栈
    {
        --s.top;
        return true;
    }
    else
    {
        return false;
    }
}

int GetTop(sqstack& s)
{
    if (s.base != s.top)      //栈不为空
    {
        return *(s.top - 1);
    }
    return 0;       //栈空返回0
}
