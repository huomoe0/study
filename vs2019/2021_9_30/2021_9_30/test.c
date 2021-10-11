#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	char ch = 0;
//	int first = 1;
//	int k = 0;
//	printf("ENTER:");
//	for (k = 1; k < 8; k++)
//	{
//		ch = getchar();
//		if (first == 1)
//		{
//			putchar(ch);
//			first = 0;
//
//		}
//		else
//		{
//			putchar('-');
//			putchar(ch);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    char ch = 0;
//    scanf("%d%c%d", &num1, &ch, &num2);
//    while (ch != '=')
//    {
//        switch (ch)
//        {
//        case '+':
//            num1 = num1 + num2;
//            break;
//        case '-':
//            num1 = num1 - num2;
//            break;
//        case '*':
//            num1 = num1 * num2;
//            break;
//        case '/':
//            if (num2 != 0)
//            {
//                num1 = num1 / num2;
//            }
//            else
//            {
//                printf("ERROR");
//                goto err;
//
//            }
//        case '=':
//            break;
//        default:
//            printf("ERROR");
//            goto err;
//        }
//        scanf("%c", &ch);
//        if (ch == '=')
//        {
//            break;
//        }
//        scanf("%d", &num2);
//    }
//    printf("%d", num1);
//err:
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int num = 0;
//    int life = 0;
//    int i = 0;
//    scanf("%d %d", &num, &life);
//    if (num < 0 || life <= 0)
//    {
//        printf("Game Over");
//        return 0;
//    }
//    for (i = 1; i <= life + 1; i++)
//    {
//        int input = 0;
//        scanf("%d", &input);
//        if (i > life)
//        {
//            printf("Game Over");
//            break;
//        }
//        if (input == 0)
//        {
//            printf("Game Over");
//            goto a;
//        }
//        else if (input == num)
//        {
//            if (i == 1)
//            {
//                printf("Bingo!");
//                goto a;
//            }
//            else if (i <= 3)
//            {
//                printf("Lucky You!");
//                goto a;
//            }
//            else if (i > 3)
//            {
//                printf("Good Guess!");
//                goto a;
//            }
//        }
//        else if (input > num)
//        {
//            printf("Too big\n");
//            continue;
//        }
//        else if (input < num)
//        {
//            printf("Too small\n");
//            continue;
//        }
//    }
//a:
//    return 0;
//}

