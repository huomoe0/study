#include "sys.h"

int main()
{
	enum choice T = 0;
	LinkList h = (LinkList)malloc(sizeof(Node));
	if (!h)	exit(1);
	h->next = NULL;
	load(h);
	
	do
	{
		menu();
		printf("��ѡ��:> \n");
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
			printf("�����������������\n");
			break;
		}
	} while (T);

	save(h);
	return 0;
}