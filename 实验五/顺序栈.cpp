#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct sqstack 
{
    int* top;
    int* base;
    int stacksize; // 栈内车箱数
} sqstack;

void Initstack(sqstack& s);
bool Push(sqstack& s,int a);
int Pop(sqstack& s);
int GetTop(sqstack& s);     //取栈顶元素

int main()
{
    int a[maxsize]; // 入栈序列
    int b[maxsize]; // 出栈序列
    int n;
    int num;

    printf("请输入火车数:");
    scanf("%d", &n);
    while (n--)
{
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
        for (int i = 0; i < num; i++)
        {
            if (a[count1] <= b[i])  
            {   
                if (a[count1] < b[i])
                {
                    i--;
                }

                Push(s,a[count1]);
                count1++;                
            }
            if (GetTop(s) == b[i])
            {
                Pop(s);
                count2++;
            }
            if (count1 == 5)
            {
                break;
            }

        }
            if (count1 == 5)
            {
                break;
            }
        
    }

    for (int i = count2; i < num; i++)
    {
        if (GetTop(s) == b[i])
        {
            Pop(s);
        }
    }

    if (s.base == s.top)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
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
    s.stacksize = maxsize;

}

bool Push(sqstack& s,int a) // 入栈操作
{
    if (s.top-s.base > maxsize)
    {
        printf("栈满了\n");
        return false;
    }
    *s.top++ = a;
    return true;
}

int Pop(sqstack& s) // 栈顶元素弹栈操作
{
    int elem;
    if (s.top != s.base) // 如果不是空栈
    {
        elem = *--s.top; // 同优先度从右往左结合
        return elem;
    }
}

int GetTop(sqstack& s) 
{
    if (s.base!=s.top)      //栈不为空
    {
        return *(s.top - 1);
    }
}
