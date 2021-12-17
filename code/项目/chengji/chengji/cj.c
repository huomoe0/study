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
	////创建链表，并输出
	//head = Create();
	//Print(head);
	/*
		//输入学生的信息，增加到链表尾部，并输出
		struct student *newNode;
		newNode=(struct student *)malloc(sizeof(struct student));
		printf("请输入学生的学号，姓名，成绩（以空格分开）:\n");
		scanf("%d%s%d",&newNode->num,newNode->name,&newNode->score);
		newNode->next = NULL;
		Insert(newNode,head);
		Print(head);


		//删除指定学号的节点，并输出
		int num;
		printf("请输入待删除学生的学号:\n");
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
//创建链表，返回创建后的头指针（头节点的地址）
//循环输入学生的各项信息，依次增加到链表中，从学号=0时，结束输入
stu* Create() 
{

	struct student* head;
	head = NULL;
	int num;
	char name[20];
	int score;

	struct student* newNode;

	printf("请输入学生的学号，姓名，成绩（以空格分开）:\n");
	while (~scanf("%d%s%d", &num, name, &score))
	{
		//申请地址
		newNode = (struct student*)malloc(sizeof(struct student));
		//成员赋值
		newNode->num = num;
		strcpy(newNode->name, name);
		newNode->score = score;
		newNode->next = NULL;

		//尾部增加
		head = Insert(newNode, head);
	}

	return head;
}

//将某个节点增加到给定的链表中,得到一个新链表(增加到尾部)
struct student* Insert(struct student* newNode, struct student* head)
{

	struct student* p; //循环变量
	if (head == NULL)
	{  //链表为空,newNode即首节点
		head = newNode;
		return head;
	}
	//从首节点开始循环遍历，
	//循环条件，循环变量赋初始值，改变循环变量
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	//循环结束后p即尾节点
	p->next = newNode;

	return head;
}

//从给定链表中删除给定条件（指定学号）的节点
void Delete(struct student* head, int num)
{



}

//输出给定链表所有节点的数据信息
void Print(struct student* head)
{
	//从首节点开始，一直到尾节点，输出每个节点的信息
	//循环变量（初值，改变），循环条件
	struct student* p;
	p = head;
	while (p != NULL)
	{
		printf("%d %s %d\n", p->num, p->name, p->score);
		p = p->next;
	}

}
