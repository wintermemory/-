#include<stdio.h>
#include<string.h>

struct Student
{
	char name[20];
	char num[20];
	char ID[20];
	int age;
	char sex[5];
};

typedef struct Student Student;


void input(Student* p, int a);
void print(Student* p, int b);
void search(Student* p, int c);

int main()
{
	int n;
	Student st[5];


	printf("输入学生信息人数(3~5):");
	scanf("%d", &n);


	input(st, n);
	print(st, n);
	search(st, n);

	return 0;
}


void input(Student* p, int a)
{
	int i = 0;
	printf("请输入学生的基本信息\n");
	printf("姓名\t\t学号\t\t身份证号\t\t年龄\t\t性别(m为男，f为女)\n\n");
	for (i; i < a; i++)
	{
		printf("第%d位:", i + 1);
		scanf("%s%s%s%d%s", p[i].name, p[i].num, p[i].ID, &p[i].age, p[i].sex);
	}

	printf("\n\n\n\n");

}


void print(Student* p, int b)
{
	Student* q;

	printf("姓名\t\t\t学号\t\t\t身份证号\t\t\t年龄\t\t\t性别\n\n");

	for (q = p; q < p + b; q++)//将m改为男,n改为女。直接输入男女可省略此步。
	{
		if (strcmp(q->sex, "m") == 0)
		{
			strcpy(q->sex, "男");
		}

		if (strcmp(q->sex, "f") == 0)
		{
			strcpy(q->sex, "女");
		}

	}


	for (q = p; q < p + b; q++)//打印信息
	{
		printf("%-22s%-24s%-35s%-24d%s\n", q->name, q->num, q->ID, q->age, q->sex);

	}

	printf("\n\n");

}


void search(Student* p, int c)
{

	char name[20];
	int i;
	int d;


	for (i = 0, d = 0;; d = 0)
	{

		printf("\n输入检索\n名字(输入*结束检索):");
		i++;
		scanf("%s", name);


		for (int a = 0; a < c; a++)//查人
		{
			if (strcmp(name, p[a].name) == 0)
			{
				printf("姓名:%s\t\t学号:%s\t\t身份证号:%s\t\t年龄:%d\t\t性别:%s\n\n", p[a].name, p[a].num
					, p[a].ID, p[a].age, p[a].sex);

				d++;
			}
		}

		if (strcmp(name, "*") == 0)
		{
			break;
		}

		if (d == 0)//输错重查
		{
			printf("该学生信息不存在,请重新输入\n\n");
			i--;
			continue;
		}

	}

}
