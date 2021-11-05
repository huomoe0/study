
#include <stdio.h>
int main()
{
    int num1 = 0;
    int num2 = 0;
    char ch = 0;
    scanf("%d%c%d", &num1, &ch, &num2);
    while (ch != '=')  //等号结束循环
    {
        switch (ch)
        {
        case '+':
            num1 = num1 + num2;
            break;
        case '-':
            num1 = num1 - num2;
            break;
        case '*':
            num1 = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
            {
                num1 = num1 / num2;
            }
            else
            {
                printf("ERROR");
                return 0;

            }
        case '=':
            break;
        default:
            printf("ERROR");
            return 0;
        }
        scanf("%c", &ch);
        if (ch == '=')  //等号结束循环
        {
            break;
        }
        scanf("%d", &num2);
    }
    printf("%d", num1);
    return 0;
}