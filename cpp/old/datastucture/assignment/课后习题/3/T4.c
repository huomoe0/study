#include "stack.h"
int lastorderexpression() // 234 34 + 2*$
{
	sqstack n;
	initsqstack(&n);
	int a,b;
	char c;
	c = getchar();
	while(c != '$')
	{
		int i = 0;
		if(c >= '0' && c <= '9')
		{
			b = 0;
			while(c >= '0' && c <= '9')
			{
				b = b*10 + c-'0';
				c = getchar();
			}
			push(&n,b);
		}
		switch(c)
		{
			case ' ':break;
			case '+':pop(&n,&b);pop(&n,&a);push(&n,a+b);break;
			case '-':pop(&n,&b);pop(&n,&a);push(&n,a-b);break;
			case '*':pop(&n,&b);pop(&n,&a);push(&n,a*b);break;
			case '/':
				if(b != 0)
				{
					pop(&n,&b);pop(&n,&a);push(&n,a/b);
				}
				else
				{
					printf("ERROR\n");
					exit(0);
				}
		}
		c = getchar();
	}
	pop(&n,&a);
	return a;
}
int main()
{
	printf("%d",lastorderexpression());
	return 0;
}
