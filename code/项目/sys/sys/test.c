#include "sys.h"

int main()
{
	enum choice T = 0;

	LinkList h = (LinkList)malloc(sizeof(Node)); //创建链表头结点
	if (!h)
	{
		printf("程序出现异常，请重新启动\n");
		return -1;
	}
	h->next = NULL;

	load(h);//从文件中读取数据
	
	do
	{
		menu();
		printf("请选择:> \n");
		scanf("%d", &T);
		putchar('\n');
		switch (T)
		{
		case EXIT:
			break;
		case ADD:
			add(h); break;
		case DELETE:
			del(h); break;
		case SEARCH:
			search(h); break;
		case CHANGE:
			change(h); break;
		case PRINT:
			print(h); break;
		default:
			printf("输出错误，请重新输入\n");
			break;
		}
	} while (T);

	save(h);//将数据保存到文件中

	return 0;
}