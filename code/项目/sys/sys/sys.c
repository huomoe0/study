#include "sys.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu()
{
	printf("                                \n");
	printf("           5. 打印系统中的数据  \n");
	printf("           4. 修改              \n");
	printf("           3. 查询              \n");
	printf("           2. 删除              \n");
	printf("           1. 增加              \n");
	printf("           0. 保存并退出        \n");
	printf("                                \n");
}

void load(LinkList h)
{
	FILE* fp = fopen("data.txt", "r"); 
	if (!fp) //若文件不存在则创建一个文件
	{
		fp = fopen("data.txt", "w");
		fclose(fp);
		fp = fopen("data.txt", "r");
	}
	Node* tail = h, *p = NULL;
	
	do
	{
		p = (Node*)malloc(sizeof(Node));
		if (!p)
		{
			printf("文件读取失败\n");
			return;
		}
		if (fscanf(fp, " %s", p->data.id) == EOF)	break;
		fscanf(fp, " %s %lf %lf %lf", p->data.name ,&p->data.base, &p->data.up, &p->data.down);
		tail->next = p;
		tail = p;
		tail->next = NULL;
	} while (p);

	fclose(fp);
}

void print(LinkList h)
{
	int n = 0;
	Node* p = h->next;
	if (!p)	printf("系统中没有数据\n");
	else
	{
		printf("%20s %20s %10s %10s %10s %10s\n","编号","姓名","基本工资","提成","罚金","总和");
	}
	while (p != NULL)
	{
		n++;
		double sum = p->data.base + p->data.up - p->data.down;
		printf("%20s %20s %10.2f %10.2f %10.2f %10.2f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down,sum);
		p = p->next;
	}
	printf("共%d条数据\n", n);
}

void add(LinkList h)
{
	Node* tail = h ,*p = NULL;
	while (tail->next != NULL)	tail = tail->next;//尾指针

	int n = 0;
	do
	{
		p = (Node*)malloc(sizeof(Node));
		if (!p)
		{
			printf("增加失败\n");
			return;
		}

		printf("请输入编号:> \n");
		scanf(" %s", p->data.id);
		printf("请输入姓名:> \n");
		scanf(" %s", p->data.name);
		printf("请输入基本工资:> \n");
		scanf("%lf", &p->data.base);
		printf("请输入提成:> \n");
		scanf("%lf", &p->data.up);
		printf("请输入罚金:> \n");
		scanf("%lf", &p->data.down);
		p->next = NULL;
		tail->next = p;
		tail = p;

		printf("是否继续增加(0/1):> \n");
		scanf("%d", &n);
		while (n != 1 && n != 0)
		{
			printf("请重新输入(0/1):> \n");
			scanf("%d", &n);
		}
	} while (n);
}

void save(LinkList h) //将数据保存到文件中
{
	FILE* fp = fopen("data.txt", "w");
	if (!fp)
	{
		printf("保存失败\n");
		return;
	}
	Node* p = h->next;
	while (p)
	{
		fprintf(fp, "%s %s %f %f %f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down);
		p = p->next;
	}
}


void change(LinkList h)
{
	int m = 0;
	do
	{
		Node* p = h->next;
		char id[ID_LEN];
		printf("请输入要修改的编号:> \n");
		scanf("%s", id);
		while (p && p->data.id != id && strcmp(id, p->data.id) != 0)
		{
			p = p->next;
		}
		if (p == NULL)	printf("该编号不存在\n");
		else
		{
			printf("%20s %20s %10s %10s %10s\n", "编号", "姓名", "基本工资", "提成", "罚金");
			printf("%20s %20s %10.2f %10.2f %10.2f\n",
				p->data.id, p->data.name, p->data.base, p->data.up, p->data.down);

			int n = 0;
			printf("选择要修改的内容;> \n");
			printf("1.编号 2.姓名 3.基本工资 4.提成 5.罚金\n");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				printf("请输入编号:> \n");
				scanf(" %s", p->data.id);
				break;
			case 2:
				printf("请输入姓名:> \n");
				scanf(" %s", p->data.name);
				break;
			case 3:
				printf("请输入基本工资:> \n");
				scanf("%lf", &p->data.base);
				break;
			case 4:
				printf("请输入提成:> \n");
				scanf("%lf", &p->data.up);
				break;
			case 5:
				printf("请输入罚金:> \n");
				scanf("%lf", &p->data.down);
				break;
			default:
				break;
			}
		}
		printf("是否继续修改(0/1):> \n");
		scanf("%d", &m);
	} while (m);
}

void del(LinkList h)
{
	int n = 0;
	do
	{
		Node* p = h;
		char id[ID_LEN];
		printf("请输入要删除数据的编号:> \n");
		scanf("%s", id);
		while (p->next && p->next->data.id != id && strcmp(id,p->next->data.id) != 0)
		{
			p = p->next;
		}
		if (p->next == NULL)
		{
			printf("该编号不存在\n");
		}
		else
		{
			printf("%20s %20s %10s %10s %10s\n", "编号", "姓名", "基本工资", "提成", "罚金");
			printf("%20s %20s %10.2f %10.2f %10.2f\n",
				p->next->data.id, p->next->data.name, p->next->data.base, 
				p->next->data.up, p->next->data.down);
			int cho = 0;
			printf("确定删除(0/1);> \n");
			scanf("%d", &cho);
			if (cho)
			{
				Node* t = p->next;
				p->next = t->next;
				free(t);
				printf("删除成功\n");
			}
		}
		printf("是否继续删除(0/1):> \n");
		scanf("%d", &n);
	} while (n);
}

void search(LinkList h)
{
	int n = 0;
	do
	{
		Node* p = h->next;
		printf("请选择:> \n");
		printf("1. 按编号查询(精确)\n");
		printf("2. 按姓名查询(模糊)\n");
		scanf("%d", &n);
		while (n != 1 && n != 2)	printf("请重新输入:> \n");
		switch (n)
		{
		case 1:
		{
			char id[ID_LEN];
			printf("请输入编号:> \n");
			scanf(" %s", id);
			while (p && strcmp(id,p->data.id) != 0)
			{
				p = p->next;
			}
			if (!p)
			{
				printf("未找到该编号\n");
				break;
			}
			else
			{
				printf("找到了\n");
			}
			printf("%20s %20s %10s %10s %10s %10s\n",
				"编号", "姓名", "基本工资", "提成", "罚金", "总和");
			double sum = p->data.base + p->data.up - p->data.down;
			printf("%20s %20s %10.2f %10.2f %10.2f %10.2f\n",
				p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, sum);
		}
		break;
		case 2:
		{
			int n = 0,first = 1;
			char name[NAME_LEN];
			printf("请输入姓名:> \n");
			scanf(" %s",name);
			int len1 = strlen(p->data.name), len2 = strlen(name), cnt = 0;
			while (p)
			{
				for (int i = 0; i < len1 - len2; i++)
				{
					int j = 0;
					if(name[0] == p->data.name[i])
					{
						while (name[j] == p->data.name[i + j] && j < len2)
						{
							j++;
						}
						if (j == len2)
						{
							cnt++;
							if (first)
							{
								printf("%20s %20s %10s %10s %10s %10s\n", 
									"编号", "姓名", "基本工资", "提成", "罚金", "总和");
								first = 0;
							}
							double sum = p->data.base + p->data.up - p->data.down;
							printf("%20s %20s %10.2f %10.2f %10.2f %10.2f\n",
								p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, sum);
						}
					}
				}
				p = p->next;
			}
			printf("找到%d条数据\n", cnt);
		}
		break;
		default:	break;
		}
		printf("是否继续查找(0/1):> \n");
		scanf("%d", &n);
	} while (n);
}