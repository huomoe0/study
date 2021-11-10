#include <stdio.h>
int main()
{
	int a[20] = { 0 };
	int b[20] = { 0 };
	int c[40] = { 0 };
	char ch = 0;
	int i = 0,j = 0;
    //赋值
	while (ch != '\n')
	{
		scanf("%d" ,&a[i++]);
		ch = getchar();
	}
	ch = 0;
	while (ch != '\n')
	{
		scanf("%d", &b[j++]);
		ch = getchar();
	}
    //两序列合并
    int count = 0,x;
    for(x = 0;x < i;x++)
    {
        c[count] = a[x];
        count++;
    }
    for(x = 0;x < j;x++)
    {
        c[count] = b[x];
        count++;
    }
    //冒泡排序
    for(i = 0;i < count;i++)
    {
        for(j = 0;j < count-1-i;j++)
        {
            if(c[j] < c[j+1])
            {
                int t = c[j];
                c[j] = c[j+1];
                c[j+1] = t;
            }
        }
    }
    //输出
    for(i = 0;i < count;i++)
    {
        if(c[i] == x)
            continue;
        if(c[i] == c[i+1] && i < count - 1)
        {
             x = c[i];
            continue;
        }
        printf("%d ",c[i]);
    }
	return 0;
}