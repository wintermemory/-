#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max 100

//边结点
typedef struct ArcNode
{
    int adjvex;     //所指向结点在数组中的位置
    ArcNode* nextarc;   //指向下一个结点的指针
}ArcNode;

// 顶点信息
typedef struct  VNode
{
    char data;
    ArcNode* firstarc;  //指向第一个结点的指针
}VNode;

//图
typedef struct ALGragh
{
    VNode elem[max];
    int vexnum; //图的当前顶点数
    int arcnum; //图的当前边数
}ALGragh;

//辅助队列
typedef struct queue
{
    int top;
    int base;
    int *data;
}Queue;

void creatgragh(ALGragh& g);
int LocateVex(ALGragh g, char u);
void BFS(ALGragh g,Queue& q);    //广度优先遍历
void DFS(ALGragh g,int a);            //深度优先遍历
int FirstNeighbor(ALGragh g, int x); //求图G中顶点的第一个邻接点
int NextNeighbor(ALGragh g, int x, int y);
void visit(ALGragh g,int x);
void Initqueue(Queue &Q,ALGragh g);
void Enqueue(Queue& q, int x);   //辅助队列入队
void Dequeue(Queue& q,int &x);   //出队
bool visited[max] = { false };  //访问状态

int main()
{
    int a;  //元素c对应的位置
    char c;
    ALGragh g;
    Queue Q;
    creatgragh(g);
    BFS(g, Q);

    printf("\n选择深度优先遍历起点:");
    scanf("%c",&c);
    a = LocateVex(g,c);
    DFS(g, a);

    system("pause");
    return 0;
}

void creatgragh(ALGragh& g)
{
    ArcNode* p1; // 边结点指针
    ArcNode* p2; // 边结点指针
    char A, B;  //数据A、B
    int a, b;   //与数据A、B对应的位置

    printf("请输入顶点个数：");
    scanf("%d", &g.vexnum);
    printf("请输入边个数：");
    scanf("%d", &g.arcnum);
    printf("请输入顶点数据\n");

    //创建顶点
    for (int i = 0; i < g.vexnum; i++)
    {
        rewind(stdin);
        printf("第%d个:",i+1);
        scanf("%c", &g.elem[i].data);
        g.elem[i].firstarc = NULL;
    }

    //创建边
    for (int i = 0; i < g.arcnum; i++)
    {
        rewind(stdin);
        printf("请输入一个顶点:");
        scanf("%c", &A);
        rewind(stdin);
        printf("请输入与之对应的另一个顶点:");
        scanf("%c", &B);

        a = LocateVex(g, A);
        b = LocateVex(g, B);

        p1 = (ArcNode*)malloc(sizeof(ArcNode));  //申请一个边结点
        p1->adjvex = b;
        //头插法
        p1->nextarc = g.elem[a].firstarc;
        g.elem[a].firstarc = p1;

       //同理
        p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex = a;

        //头插法

        p2->nextarc = g.elem[b].firstarc;
        g.elem[b].firstarc = p2;
        rewind(stdin);
    }
}

int LocateVex(ALGragh g, char u)
{
    if (g.vexnum == 0)
    {
        printf("图空\n");
        return -1;
    }

    for (int i = 0; i < g.vexnum; i++)
    {
        if (g.elem[i].data == u)
        {
            return i;
        }

    }

    printf("不存在\n");
    return -1;
}

//广度优先遍历
void BFS(ALGragh g,Queue &q)
{
    char s;
    int b;
    int out;  //接收出队元素
   

    Initqueue(q,g);
    printf("请输入广度优先遍历起点:A~F:");
    scanf("%c",&s);
    b = LocateVex(g, s);
    rewind(stdin);

    visit(g, b);    //访问b位置对应的顶点
    visited[b] = true;
    Enqueue(q,b);   //入队

    while (q.base!=q.top)   //队列不为空,出队
    {
        Dequeue(q, out);
        for (int w = FirstNeighbor(g, out); w >= 0; w = NextNeighbor(g, out, w))
        {
            if (visited[w] == false)
            {
                visit(g, w);
                visited[w] = true;
                Enqueue(q, w);
            }
        }
    }
    free(q.data);
    for (int i = 0; i < g.vexnum; i++)
    {
        visited[i] = false;
    }
}

//深度优先遍历
void DFS(ALGragh g,int a)
{

    visit(g, a);
    visited[a] = true;

    for (int w = FirstNeighbor(g, a); w >= 0; w = NextNeighbor(g, a, w))
    {
        if (visited[w] == false)    //如果没有被访问
        {
            DFS(g, w);
        }
    }

}

//找指定起始位置x的第一个元素
int FirstNeighbor(ALGragh g, int x)
{
    if (g.elem[x].firstarc == NULL)
    {
        return -1;
    }
    else
    {
        return g.elem[x].firstarc->adjvex;
    }
}

//找出元素x对应的下一个元素y
int NextNeighbor(ALGragh g,int x, int y)
{
    ArcNode* p;

    //将指针指向含y的空间
    for (p=g.elem[x].firstarc;;p=p->nextarc)
    {
        if (p==NULL)
        {
            return -1;
        }
        if (p->adjvex==y)
        {
            break;
        }
    }  
    //若y是x的最后一个邻接点,则返回-1
    if (p->nextarc == NULL)
    {
        return -1;
    }
    //返回x的下一个邻接点的顶点号
    else
    {
        return p->nextarc->adjvex;
    }
}

void visit(ALGragh g, int x)
{
    printf("%c ",g.elem[x].data);
}

void Initqueue(Queue& q,ALGragh g)
{
    q.base = 0;
    q.top = 0;
    q.data = (int*)malloc(sizeof(int) * g.vexnum);
}

void Enqueue(Queue& q, int x)
{
    q.data[q.top++] = x;
}

void Dequeue(Queue& q,int &x)
{
    x=q.data[q.base++];
}
