#define MaxSize 1000
#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int* data;//数据元素
    int length;//当前表长
}List;

void Init(List& l);
void Input(List& l);
void print(List l);
void Delete(List& l);

int main()
{
    List l;

    Init(l);
    Input(l);
    Delete(l);


    free(l.data);
    system("pause");
    return 0;
}

void Init(List& l)
{
    printf("请输入表长:");

    for (int i = 0;;)
    {
        scanf("%d", &l.length);
        if (l.length > MaxSize)
        {
            printf("请重新输入\n");
            continue;
        }
        
        else
        {
            break;
        }
    }
    
    l.data = (int*)malloc(sizeof(int) * l.length);
    if (NULL == l.data)
    {
        printf("error\n");
        free(l.data);
        exit(0);
    }
}

void Input(List& l)
{
    int i;

    printf("\n请输入%d个元素\n",l.length);
    for (i = 0; i < l.length; i++)
    {
        scanf("%d", &l.data[i]);
    }
    
}

void print(List l)
{
    printf("\n现表长%d\n", l.length);

    for (int i = 0; i < l.length; i++)
    {
        printf("%d ",l.data[i]);
    }

}

void Delete(List& l)
{
    int count = 0;//相同项个数计数
   

    printf("\n删除多余元素:");
    
 
//思路1
//把重复的数据不重复地记录下来
//多次进行单个重复数据删除操作

//思路2
//将每一项与后面所有项比较
//相同则执行删除操作


    for (int i = 0; i < l.length; i++)//采用思路2
    {
        for (int j = i+1; j < l.length; j++)//找相同项
        {
            if (l.data[i]==l.data[j])
            {
                for (int a = j; a < l.length - 1; a++)//删除操作
                {
                    l.data[a] = l.data[a + 1];
                   
                }

                j--;
                l.length--;
                             
            }
        
        }

        



    }
      
    print(l);

}
