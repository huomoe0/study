#include "sys.h"

void menu()
{
	printf("                                \n");
	printf("           5. ��ӡ              \n");
	printf("           4. �޸�              \n");
	printf("           3. ��ѯ              \n");
	printf("           2. ɾ��              \n");
	printf("           1. ����              \n");
	printf("           0. �˳�(����)        \n");
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
			printf("�ļ���ȡʧ��\n");
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
	if (!p)	printf("ϵͳ��û������\n");
	else
	{
		printf("%15s %20s %10s %10s %10s %10s %10s\n","���","����","��������","���","����","����","�ܺ�");
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
	while (tail->next != NULL)	tail = tail->next;//βָ��

	int n = 0;
	do
	{
		p = (Node*)malloc(sizeof(Node));
		if (!p)
		{
			printf("����ʧ��\n");
			return;
		}
		printf("��������(11λ��11λ����������):> \n");
		while (scanf("%lld", &p->data.id) && (p->data.id <= 0 || p->data.id >= 100000000000))
		{
			printf("��ʽ��������������:> \n");
		}
		putchar('\n');
		getchar();
		printf("����������:> \n");
		fgets(p->data.name, 19, stdin);
		p->data.name[strlen(p->data.name) - 1] = 0;
		putchar('\n');
		printf("�������������:> \n");
		scanf("%lf", &p->data.base);
		putchar('\n');
		printf("���������:> \n");
		scanf("%lf", &p->data.up);
		putchar('\n');
		printf("�����뷣��:> \n");
		scanf("%lf", &p->data.down);
		putchar('\n');
		printf("�����뽱��:> \n");
		scanf("%lf", &p->data.bonus);
		putchar('\n');
		p->next = NULL;
		tail->next = p;
		tail = p;
		printf("�Ƿ��������(0/1):> \n");
		scanf("%d", &n);
		putchar('\n');
		while (n != 1 && n != 0)
		{
			printf("����������(0/1):> \n");
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
	printf("������Ҫ�޸ĵı��:> \n");
	scanf("%lld", &id);
	if (id <= 0 || id >= 100000000000)
	{
		printf("�ñ�Ų�����\n");
		return;
	}
	while (p && p->data.id != id)
	{
		p = p->next;
	}
	if(p == NULL)	printf("�ñ�Ų�����\n");
	else
	{
		printf("%15s %20s %10s %10s %10s %10s\n", "���", "����", "��������", "���", "����", "����");
		printf("%15lld %20s %10.2f %10.2f %10.2f %10.2f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, p->data.bonus);
		printf("�������µı��(11λ��11λ����������):> \n");
		while (scanf("%lld", &p->data.id) && (p->data.id <= 0 || p->data.id >= 100000000000))
		{
			printf("��ʽ��������������:> \n");
		}
		getchar();
		printf("����������:> \n");
		fgets(p->data.name, 19, stdin);
		p->data.name[strlen(p->data.name) - 1] = 0;
		putchar('\n');
		printf("�������������:> \n");
		scanf("%lf", &p->data.base);
		putchar('\n');
		printf("���������:> \n");
		scanf("%lf", &p->data.up);
		putchar('\n');
		printf("�����뷣��:> \n");
		scanf("%lf", &p->data.down);
		putchar('\n');
		printf("�����뽱��:> \n");
		scanf("%lf", &p->data.bonus);
		putchar('\n');
	}
	return;
}

void del(LinkList h)
{
	Node* p = h;
	long long id = 0;
	printf("������Ҫɾ�����ݵı��:> \n");
	scanf("%lld", &id);
	if (id <= 0 || id >= 100000000000)
	{
		printf("�ñ�Ų�����\n");
		return;
	}
	while (p->next && p->next->data.id != id)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		printf("�ñ�Ų�����\n");
		return;
	}
	else
	{
		Node* t = p->next;
		p->next = t->next;
		free(t);
		printf("ɾ���ɹ�\n");
	}
	return;
}

void search(LinkList h)
{
	Node* p = h;
	long long id = 0;
	printf("������Ҫ��ѯ���ݵı��:> \n");
	scanf("%lld", &id);
	if (id <= 0 || id >= 100000000000)
	{
		printf("�ñ�Ų�����\n");
		return;
	}
	while (p && p->data.id != id)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("�ñ�Ų�����\n");
		return;
	}
	else
	{
		printf("%15s %20s %10s %10s %10s %10s %10s\n", 
			"���", "����", "��������", "���", "����", "����", "�ܺ�");
		double sum = p->data.base + p->data.up - p->data.down + p->data.bonus;
		printf("%15lld %20s %10.2f %10.2f %10.2f %10.2f %10.2f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, p->data.bonus, sum);
	}
	return 0;
}