#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 1000

int main()
{
	int n;		//n组测试数据

	printf("请输入数据组数(1~5)：");
	scanf("%d",&n);

	while (n--)
	{
		char ch[maxsize + 1];
		int length;	//字符串长度
		int a = 0;
		int b = 1;

		printf("请输入中括号、小括号:");
		printf("\"[\",\"]\",\"(\",\")\":\n");

		scanf("%s", ch);
		int num = strlen(ch);
		length = num;

		if (num%2!=0)		//括号对为奇数 无法配对
		{
			printf("No\n");
			continue;
		}

		for (int i = 0; i < num/2;)	//判断次数=length/2
		{
			
			if (ch[a] - ch[b] == -1 || ch[a] - ch[b] == -2)
			{
				for (int j = a; j+2 <= length ; j++)	//ch[length]='\0'
				{
					ch[j] = ch[j + 2];
				}
				a = 0;
				b = 1;
				i++;	//配对成功才算次数				
			}
			else
			{
				a++;
				b++;
				
			}

			length = strlen(ch);
		}

		if (length == 0)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}		
	}

	system("pause");
	return 0;
}
