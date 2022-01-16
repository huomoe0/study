#include "sys.h"

void menu()
{
	printf("                                \n");
	printf("           5. 打印              \n");
	printf("           4. 修改              \n");
	printf("           3. 查询              \n");
	printf("           2. 删除              \n");
	printf("           1. 增加              \n");
	printf("           0. 退出(保存)        \n");
	printf("                                \n");
}

void load(LinkList h)
{
	FILE* fp = fopen("data.txt", "r");
	if (!fp)
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
		if (!(~fscanf(fp, "%lld\n", &p->data.id)))	break;
		fgets(p->data.name, 19, fp);
		p->data.name[strlen(p->data.name) - 1] = 0;
		fscanf(fp, "%lf\n%lf\n%lf\n%lf\n",&p->data.base, &p->data.up, &p->data.down, &p->data.bonus);
		tail->next = p;
		tail = p;
		tail->next = NULL;
	} while (p);

	fclose(fp);
	return;
}

void print(LinkList h)
{
	Node* p = h->next;
	if (!p)	printf("系统中没有数据\n");
	else
	{
		printf("%15s %20s %10s %10s %10s %10s %10s\n","编号","姓名","基本工资","提成","罚金","奖金","总和");
	}
	while (p != NULL)
	{
		double sum = p->data.base + p->data.up - p->data.down + p->data.bonus;
		printf("%15lld %20s %10.2f %10.2f %10.2f %10.2f %10.2f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, p->data.bonus,sum);
		p = p->next;
	}
	return;
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
		printf("请输入编号(11位或11位以下正整数):> \n");
		while (scanf("%lld", &p->data.id) && (p->data.id <= 0 || p->data.id >= 100000000000))
		{
			printf("格式有误，请重新输入:> \n");
		}
		putchar('\n');
		getchar();
		printf("请输入姓名:> \n");
		fgets(p->data.name, 19, stdin);
		p->data.name[strlen(p->data.name) - 1] = 0;
		putchar('\n');
		printf("请输入基本工资:> \n");
		scanf("%lf", &p->data.base);
		putchar('\n');
		printf("请输入提成:> \n");
		scanf("%lf", &p->data.up);
		putchar('\n');
		printf("请输入罚金:> \n");
		scanf("%lf", &p->data.down);
		putchar('\n');
		printf("请输入奖金:> \n");
		scanf("%lf", &p->data.bonus);
		putchar('\n');
		p->next = NULL;
		tail->next = p;
		tail = p;
		printf("是否继续增加(0/1):> \n");
		scanf("%d", &n);
		putchar('\n');
		while (n != 1 && n != 0)
		{
			printf("请重新输入(0/1):> \n");
			scanf("%d", &n);
			putchar('\n');
		}
	} while (n);
}

void save(LinkList h)
{
	FILE* fp = fopen("data.txt", "w");
	if (!fp)	return;
	Node* p = h->next;
	while (p)
	{
		fprintf(fp, "%lld\n%s\n%f\n%f\n%f\n%f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, p->data.bonus);
		p = p->next;
	}
	return;
}


void change(LinkList h)
{
	Node* p = h->next;
	long long id = 0;
	printf("请输入要修改的编号:> \n");
	scanf("%lld", &id);
	if (id <= 0 || id >= 100000000000)
	{
		printf("该编号不存在\n");
		return;
	}
	while (p && p->data.id != id)
	{
		p = p->next;
	}
	if(p == NULL)	printf("该编号不存在\n");
	else
	{
		printf("%15s %20s %10s %10s %10s %10s\n", "编号", "姓名", "基本工资", "提成", "罚金", "奖金");
		printf("%15lld %20s %10.2f %10.2f %10.2f %10.2f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, p->data.bonus);
		printf("请输入新的编号(11位或11位以下正整数):> \n");
		while (scanf("%lld", &p->data.id) && (p->data.id <= 0 || p->data.id >= 100000000000))
		{
			printf("格式有误，请重新输入:> \n");
		}
		getchar();
		printf("请输入姓名:> \n");
		fgets(p->data.name, 19, stdin);
		p->data.name[strlen(p->data.name) - 1] = 0;
		putchar('\n');
		printf("请输入基本工资:> \n");
		scanf("%lf", &p->data.base);
		putchar('\n');
		printf("请输入提成:> \n");
		scanf("%lf", &p->data.up);
		putchar('\n');
		printf("请输入罚金:> \n");
		scanf("%lf", &p->data.down);
		putchar('\n');
		printf("请输入奖金:> \n");
		scanf("%lf", &p->data.bonus);
		putchar('\n');
	}
	return;
}

void del(LinkList h)
{
	Node* p = h;
	long long id = 0;
	printf("请输入要删除数据的编号:> \n");
	scanf("%lld", &id);
	if (id <= 0 || id >= 100000000000)
	{
		printf("该编号不存在\n");
		return;
	}
	while (p->next && p->next->data.id != id)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		printf("该编号不存在\n");
		return;
	}
	else
	{
		Node* t = p->next;
		p->next = t->next;
		free(t);
		printf("删除成功\n");
	}
	return;
}

void search(LinkList h)
{
	Node* p = h;
	long long id = 0;
	printf("请输入要查询数据的编号:> \n");
	scanf("%lld", &id);
	if (id <= 0 || id >= 100000000000)
	{
		printf("该编号不存在\n");
		return;
	}
	while (p && p->data.id != id)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("该编号不存在\n");
		return;
	}
	else
	{
		printf("%15s %20s %10s %10s %10s %10s %10s\n", 
			"编号", "姓名", "基本工资", "提成", "罚金", "奖金", "总和");
		double sum = p->data.base + p->data.up - p->data.down + p->data.bonus;
		printf("%15lld %20s %10.2f %10.2f %10.2f %10.2f %10.2f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, p->data.bonus, sum);
	}
	return 0;
}