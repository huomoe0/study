#define _CRT_SECURE_NO_WARNINGS 1

#include "add.h"

int main() 
{
	int id;
	stu* head;
	do
	{
		
		menu();
		scanf("%d", &id);
		switch (id)
		{
		case 0:break;
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		default:
			break;
		}
	} while (id);
	////�������������
	//head = Create();
	//Print(head);
	/*
		//����ѧ������Ϣ�����ӵ�����β���������
		struct student *newNode;
		newNode=(struct student *)malloc(sizeof(struct student));
		printf("������ѧ����ѧ�ţ��������ɼ����Կո�ֿ���:\n");
		scanf("%d%s%d",&newNode->num,newNode->name,&newNode->score);
		newNode->next = NULL;
		Insert(newNode,head);
		Print(head);


		//ɾ��ָ��ѧ�ŵĽڵ㣬�����
		int num;
		printf("�������ɾ��ѧ����ѧ��:\n");
		scanf("%d",&num);
		Delete(head,num);
		Print(head);
	*/

	return 0;
}

void menu()
{
	printf("");
}
//�����������ش������ͷָ�루ͷ�ڵ�ĵ�ַ��
//ѭ������ѧ���ĸ�����Ϣ���������ӵ������У���ѧ��=0ʱ����������
stu* Create() 
{

	struct student* head;
	head = NULL;
	int num;
	char name[20];
	int score;

	struct student* newNode;

	printf("������ѧ����ѧ�ţ��������ɼ����Կո�ֿ���:\n");
	while (~scanf("%d%s%d", &num, name, &score))
	{
		//�����ַ
		newNode = (struct student*)malloc(sizeof(struct student));
		//��Ա��ֵ
		newNode->num = num;
		strcpy(newNode->name, name);
		newNode->score = score;
		newNode->next = NULL;

		//β������
		head = Insert(newNode, head);
	}

	return head;
}

//��ĳ���ڵ����ӵ�������������,�õ�һ��������(���ӵ�β��)
struct student* Insert(struct student* newNode, struct student* head)
{

	struct student* p; //ѭ������
	if (head == NULL)
	{  //����Ϊ��,newNode���׽ڵ�
		head = newNode;
		return head;
	}
	//���׽ڵ㿪ʼѭ��������
	//ѭ��������ѭ����������ʼֵ���ı�ѭ������
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	//ѭ��������p��β�ڵ�
	p->next = newNode;

	return head;
}

//�Ӹ���������ɾ������������ָ��ѧ�ţ��Ľڵ�
void Delete(struct student* head, int num)
{



}

//��������������нڵ��������Ϣ
void Print(struct student* head)
{
	//���׽ڵ㿪ʼ��һֱ��β�ڵ㣬���ÿ���ڵ����Ϣ
	//ѭ����������ֵ���ı䣩��ѭ������
	struct student* p;
	p = head;
	while (p != NULL)
	{
		printf("%d %s %d\n", p->num, p->name, p->score);
		p = p->next;
	}

}
