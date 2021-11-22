#include <stdio.h>
void move(int a[],int n,int m)
{
    int i,t,b[10000];
    for(i = 0;i < n-m;i++)
    {
       b[i+m] = a[i];
    }
    for(i = n-m;i < n;i++)
    {
       b[i-n+m] = a[i]; 
    }
    for(i = 0;i < n;i++)
    {
        a[i] = b[i];
    }
}
int main()
{
    int n,m,a[10005] = {0},i;
    scanf("%d %d",&n,&m);
    m %= n;
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    move(a,n,m);
    for(i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}