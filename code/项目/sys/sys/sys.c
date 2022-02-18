#include "sys.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu()
{
	printf("                                \n");
	printf("           5. ��ӡϵͳ�е�����  \n");
	printf("           4. �޸�              \n");
	printf("           3. ��ѯ              \n");
	printf("           2. ɾ��              \n");
	printf("           1. ����              \n");
	printf("           0. ���沢�˳�        \n");
	printf("                                \n");
}

void load(LinkList h)
{
	FILE* fp = fopen("data.txt", "r"); 
	if (!fp) //���ļ��������򴴽�һ���ļ�
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
	if (!p)	printf("ϵͳ��û������\n");
	else
	{
		printf("%20s %20s %10s %10s %10s %10s\n","���","����","��������","���","����","�ܺ�");
	}
	while (p != NULL)
	{
		n++;
		double sum = p->data.base + p->data.up - p->data.down;
		printf("%20s %20s %10.2f %10.2f %10.2f %10.2f\n",
			p->data.id, p->data.name, p->data.base, p->data.up, p->data.down,sum);
		p = p->next;
	}
	printf("��%d������\n", n);
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

		printf("��������:> \n");
		scanf(" %s", p->data.id);
		printf("����������:> \n");
		scanf(" %s", p->data.name);
		printf("�������������:> \n");
		scanf("%lf", &p->data.base);
		printf("���������:> \n");
		scanf("%lf", &p->data.up);
		printf("�����뷣��:> \n");
		scanf("%lf", &p->data.down);
		p->next = NULL;
		tail->next = p;
		tail = p;

		printf("�Ƿ��������(0/1):> \n");
		scanf("%d", &n);
		while (n != 1 && n != 0)
		{
			printf("����������(0/1):> \n");
			scanf("%d", &n);
		}
	} while (n);
}

void save(LinkList h) //�����ݱ��浽�ļ���
{
	FILE* fp = fopen("data.txt", "w");
	if (!fp)
	{
		printf("����ʧ��\n");
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
		printf("������Ҫ�޸ĵı��:> \n");
		scanf("%s", id);
		while (p && p->data.id != id && strcmp(id, p->data.id) != 0)
		{
			p = p->next;
		}
		if (p == NULL)	printf("�ñ�Ų�����\n");
		else
		{
			printf("%20s %20s %10s %10s %10s\n", "���", "����", "��������", "���", "����");
			printf("%20s %20s %10.2f %10.2f %10.2f\n",
				p->data.id, p->data.name, p->data.base, p->data.up, p->data.down);

			int n = 0;
			printf("ѡ��Ҫ�޸ĵ�����;> \n");
			printf("1.��� 2.���� 3.�������� 4.��� 5.����\n");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				printf("��������:> \n");
				scanf(" %s", p->data.id);
				break;
			case 2:
				printf("����������:> \n");
				scanf(" %s", p->data.name);
				break;
			case 3:
				printf("�������������:> \n");
				scanf("%lf", &p->data.base);
				break;
			case 4:
				printf("���������:> \n");
				scanf("%lf", &p->data.up);
				break;
			case 5:
				printf("�����뷣��:> \n");
				scanf("%lf", &p->data.down);
				break;
			default:
				break;
			}
		}
		printf("�Ƿ�����޸�(0/1):> \n");
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
		printf("������Ҫɾ�����ݵı��:> \n");
		scanf("%s", id);
		while (p->next && p->next->data.id != id && strcmp(id,p->next->data.id) != 0)
		{
			p = p->next;
		}
		if (p->next == NULL)
		{
			printf("�ñ�Ų�����\n");
		}
		else
		{
			printf("%20s %20s %10s %10s %10s\n", "���", "����", "��������", "���", "����");
			printf("%20s %20s %10.2f %10.2f %10.2f\n",
				p->next->data.id, p->next->data.name, p->next->data.base, 
				p->next->data.up, p->next->data.down);
			int cho = 0;
			printf("ȷ��ɾ��(0/1);> \n");
			scanf("%d", &cho);
			if (cho)
			{
				Node* t = p->next;
				p->next = t->next;
				free(t);
				printf("ɾ���ɹ�\n");
			}
		}
		printf("�Ƿ����ɾ��(0/1):> \n");
		scanf("%d", &n);
	} while (n);
}

void search(LinkList h)
{
	int n = 0;
	do
	{
		Node* p = h->next;
		printf("��ѡ��:> \n");
		printf("1. ����Ų�ѯ(��ȷ)\n");
		printf("2. ��������ѯ(ģ��)\n");
		scanf("%d", &n);
		while (n != 1 && n != 2)	printf("����������:> \n");
		switch (n)
		{
		case 1:
		{
			char id[ID_LEN];
			printf("��������:> \n");
			scanf(" %s", id);
			while (p && strcmp(id,p->data.id) != 0)
			{
				p = p->next;
			}
			if (!p)
			{
				printf("δ�ҵ��ñ��\n");
				break;
			}
			else
			{
				printf("�ҵ���\n");
			}
			printf("%20s %20s %10s %10s %10s %10s\n",
				"���", "����", "��������", "���", "����", "�ܺ�");
			double sum = p->data.base + p->data.up - p->data.down;
			printf("%20s %20s %10.2f %10.2f %10.2f %10.2f\n",
				p->data.id, p->data.name, p->data.base, p->data.up, p->data.down, sum);
		}
		break;
		case 2:
		{
			int n = 0,first = 1;
			char name[NAME_LEN];
			printf("����������:> \n");
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
									"���", "����", "��������", "���", "����", "�ܺ�");
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
			printf("�ҵ�%d������\n", cnt);
		}
		break;
		default:	break;
		}
		printf("�Ƿ��������(0/1):> \n");
		scanf("%d", &n);
	} while (n);
}