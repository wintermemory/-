#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
	char name[20];
	char num[20];
	int score;

}Student;

struct SeqList
{
	Student* data;//学生数据
	int length;   //表长=当前长度
};

typedef struct SeqList SeqList;

void PrintList(SeqList l);
void LocateElement(SeqList l);
void InsertElement(SeqList &l);
void DeleteElement(SeqList& l);
void InitList(SeqList& l);
void Menu(SeqList& l);

int main()
{
	SeqList l;
	InitList(l);
	
	Menu(l);

	free(l.data);
	l.data = NULL;
	system("pause");
	return 0;
}

void InitList(SeqList& l)
{
	printf("输入学生人数:");
	scanf("%d", &l.length);

	printf("\t学号\t姓名\t成绩\n");

	l.data = (Student*)malloc(sizeof(Student) * l.length);//初始化
	Student* p = l.data;

	if (NULL == l.data)
	{
		printf("error\n");
		return ;
	}

	for (int i = 0; l.data < p + l.length; l.data++)	 //输入元素
	{
		printf("第%d位", ++i);
		scanf("%s%s%d", l.data->num, l.data->name, &l.data->score);
		//	scanf("%s%s%d", l.data[i].num, l.data[i].name, &l.data[i].score); // warning C6385
	}
	l.data = p;
}

void PrintList(SeqList l)//指针操作
{
	int i;
	
	printf("\n\n当前学生人数:%d\n",l.length);
	printf("   学号\t姓名\t成绩\n");
	for (i=0;i<l.length;i++)
	{
		printf("%s\t%s\t%d\n", l.data[i].num, l.data[i].name,l.data[i].score);
	}
	printf("\n\n");

	
}

void LocateElement(SeqList l)
{
	int i;
	int count=0;
	char input[20];
	int record;

	printf("输入学生学号/姓名:");
	scanf("%s", input);

	for (i = 0; i < l.length; i++)
	{


		if(strcmp(l.data[i].num,input)==0)
		{
			count++;
			record = i+1;
		}

		else if (strcmp(l.data[i].name, input) == 0)
		{
			count++;
			record = i + 1;
		}

}

		if (count == 1)
		{
			printf("在表中第%d位\n",record);
		}

		else
		{
			printf("查无此人\n");
		}

	

}

void InsertElement(SeqList &l)
{
	int n;
	Student* p=l.data;
	Student* q = p;

	PrintList(l);

	for (int i = 0;; i++)
	{
		
		printf("\n插入到几号位:");
		scanf("%d", &n);
		if (n<=0 || n>l.length + 1)
		{
			printf("插入错误,请重新输入\n");
			continue;
		}
		break;
	}

	l.data = (Student*)malloc(sizeof(Student) * (l.length+1));//可用realloc函数
	
	if (NULL == l.data)//判断是否成功分配
	{
		printf("\nerror\n");
		return;
	}
	else
	{
		l.length++;
	}


	printf("\n总人数=%d人\n",l.length);

	for (; p < q + l.length - 1; p++, l.data++)//数据转移
	{
		strcpy(l.data->num, p->num);
		strcpy(l.data->name, p->name);
		l.data->score = p->score;
	}
	l.data = l.data - l.length + 1;//指向初始位置
	p = q;//指向初始位置

	if (n == l.length)//插入在表尾
	{ 
		printf("\n输入学号\t姓名\t成绩\n");
		scanf("%s%s%d", l.data[n - 1].num, l.data[n - 1].name, &l.data[n - 1].score);
		
		//scanf("%s%s%d", l.data[1].num, l.data[1].name, &l.data[1].score);//warning C6385
	}
			
	else if(n<l.length&&n>0)//插入在表中
	{
		
		printf("\n输入学号\t姓名\t成绩\n");
		
		for (int i = l.length-1; i>=n; i--)//下标最大值应为l.length-1
		{
			l.data[i] = l.data[i-1];	//同类型结构体之间可直接赋值操作
		}

		scanf("%s%s%d", l.data[n-1].num, l.data[n-1].name, &l.data[n-1].score);
		
		
	}

	p = NULL;
	free(q);
	p = NULL;

	PrintList(l);


}

void DeleteElement(SeqList& l)
{
	int n;
	Student* p;
	
	p = l.data;


	PrintList(l);

	for(int i=0;;)
	{	printf("删除几号记录:");
		scanf("%d",&n);
		if (n <= l.length && n > 0)
		{
			break;
		}
		else 
		{
			printf("数据不存在，请重试\n");
			continue;
		}
	}
	
	l.data =(Student*) malloc(sizeof(Student) * (l.length - 1));

	if (NULL == l.data)
	{
		printf("error\n");
		return ;
	}

	else
	{
		l.length--;
	}

	if(n>1)
	{
	
		for (int i=0;i<n-1;i++)
		{
			l.data[i] = p[i];
		}


		for (int i=l.length-1;i>=n;i--)
		{
			l.data[i] = p[i + 1];  //warning c6386缓冲区溢出
		}
	}

	else if (n == 1)
	{
		for (int i = l.length - 1;i>=n-1;i--)
		{
			l.data[i] = p[i + 1];
		}
	}

	else
	{
		printf("删除错误\n");
	}

	free(p);
	p = NULL;
	PrintList(l);

}

void Menu(SeqList& l)//将各项功能整合到菜单
{
	int input;
	
	for (int i = 0;; i++)
	{
		printf("\n\t********** 选择功能 *********\n");
		printf("\t*********1(打印元素)*********\n");
		printf("\t*********2(查找元素)*********\n");
		printf("\t*********3(插入元素)*********\n");
		printf("\t*********4(删除元素)*********\n");
		printf("\t*********5(结束程序)*********\n");
		printf("\n选择功能:");
		scanf("%d", &input);

		if (input < 1 || input>5)
		{

			for (int i = 0;; i++)
			{
				printf(" 输入错误,请重新输入\n选择功能:");
				scanf("%d", &input);
				if (input >= 1 && input <= 5)
					break;
			}
		}
			
		switch (input)
		{
			case 1:PrintList(l); continue;
			case 2:LocateElement(l); continue;
			case 3:InsertElement(l); continue;
			case 4:DeleteElement(l); continue;
			case 5:return;
			default:printf("请重试\n"); continue;
	}

	}
		
}
