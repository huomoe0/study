#include <stdio.h>
#include <stdlib.h>
int a[10][10] = {0};
int Ack_1(int m,int n)
{
    if(m == 0)  return n+1;
    if(m != 0 && n == 0)    return Ack_1(m-1,1);
    return Ack_1(m-1,Ack_1(m,n-1));
}
int Ack_2(int m,int n)
{
    
    for(int i = 0;i <= n;i++)
        a[0][i] = i+1;
    for(int i = 1;i <= m;i++)
    {
        a[i][0] = a[i-1][1];
        for(int j = 1;j <= n;j++)
            a[i][j] = a[i-1][a[i][j-1]];
    }
    return a[m][n];
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d %d\n",Ack_1(m,n),Ack_2(m,n));
    
    return 0;
}