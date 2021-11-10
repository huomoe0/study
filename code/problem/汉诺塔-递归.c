#include <stdio.h>
int count = 0;
void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        Move(n, a, c);
    }
    else
    {
        Hanoi(n - 1, a, c, b);
        Move(n, a, c);
        Hanoi(n - 1, b, a, c);
    }
}
void Move(int n, char a, char b)
{
    count++;
    printf("%d Move %d: Move from %c to %c !\n",count,n,a,b);
}

int main()
{
    int n;
    printf(":\n");
    scanf(" %d",&n);
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}
