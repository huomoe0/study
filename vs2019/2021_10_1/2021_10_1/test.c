#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//    int num = 0;
//    scanf("%d", &num);
//    int num1 = num;
//    int n = 0;
//    int sum = 0;
//    int a = 0;
//    while (1)
//    {
//        a = num1 % 10;
//        num1 = num1 / 10;
//        n++;
//        sum += a;
//        if (num1 == 0)
//        {
//            break;
//        }
//    }
//    printf("%d %d", n, sum);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    double a3 = 0;
//    double a2 = 0;
//    double a1 = 0;
//    double a0 = 0;
//    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
//    double root = 0;
//    double a = 0;
//    double b = 0;//大
//    double n = 0;
//    scanf("%lf %lf", &a, &b); //区间范围
//    if (a > b)
//    {
//        double t = 0;
//        t = a;
//        a = b;
//        b = t;
//    }
//    while (b - a >= 0.01)
//    {
//        n = (a + b) / 2;
//        root = a3 * pow(n, 3) + a2 * pow(n, 2) + a1 * n + a0;
//        double fa = a3 * pow(a, 3) + a2 * pow(a, 2) + a1 * a + a0;
//        double fb = a3 * pow(b, 3) + a2 * pow(b, 2) + a1 * b + a0;
//
//        //如果f(a)f(b) < 0，则计算中点的值f((a + b) / 2)；
//        //如果f((a + b) / 2)正好为0，则(a + b) / 2就是要求的根；否则
//        //如果f((a + b) / 2)与f(a)同号，则说明根在区间[(a + b) / 2, b]，令a = (a + b) / 2，重复循环；
//        //如果f((a + b) / 2)与f(b)同号，则说明根在区间[a, (a + b) / 2]，令b = (a + b) / 2，重复循环。
//        if (b - a < 0.01)
//        {
//            break;
//        }
//        else if (root == 0)
//        {
//            break;
//        }
//        else if (root * fa > 0)
//        {
//            a = (a + b) / 2;
//        }
//        else if (root * fb > 0)
//        {
//            b = (a + b) / 2;
//        }
//    }
//    printf("%.2lf", (a + b) / 2);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	for (int i = 10; i > 1; i /= 2) 
//	{
//		printf("%d ", i++);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	int h = 0;
//	int min = 0;
//	scanf("%d", &num);
//	h = num / 100;
//	min = num % 100;
//	int h1 = 0;
//	if (h >= 8)
//	{
//		h1 = h - 8;
//	}
//	else
//	{
//		h1 = h + 16;
//	}
//
//	if (h1 == 0 && min < 10)
//	{
//		printf("%d", min);
//	}
//	else if (h1 == 0 && min >= 10)
//	{
//		printf("%02d", min);
//	}
//	else
//	{
//		printf("%d%02d", h1, min);
//	}
//	return 0;

//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int i = 0;
//	printf("1");
//	for (i = 3; i <= num; i += 2)
//	{
//		printf(" %d", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char num[10] = {'0'};
//    scanf("%s", num);
//    int n = sizeof(num) - 1;
//    int i = 0;
//    
//    for (i = 0; i < n; i++)
//    {
//        switch (num[i])
//        {
//
//            case '-':
//                printf("fu");
//                break;
//            case '0':
//                printf("ling");
//                break;
//            case '1':
//                printf("yi");
//                break;
//            case '2':
//                printf("er");
//                break;
//            case '3':
//                printf("san");
//                break;
//            case '4':
//                printf("si");
//                break;
//            case '5':
//                printf("wu");
//                break;
//            case '6':
//                printf("liu");
//                break;
//            case '7':
//                printf("qi");
//                break;
//            case '8':
//                printf("ba");
//                break;
//            case '9':
//                printf("jiu");
//                break;
//        }
//        if (num[i + 1] != 0)
//        {
//            putchar(' ');
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n0 = 0;
//    scanf("%d", &n0);
//    int a = 0;
//    //int n = 0;
//    int sum = 0;
//    int i = 0;
//    int b = 0;
//    a = n0;
//    while(1)
//    {
//        sum = 0;
//        while (a > 0)
//        {
//            sum += a % 10;
//            a = a / 10;
//        }
//        a = sum * 3 + 1;
//        if (a == n0)
//        {
//            break;
//        }
//        if (b == a)
//        {
//            break;
//        }
//        b = a;
//        i++;
//        printf("%d:%d\n", i, a);
//    }
//    printf("%d:%d", i + 1, a);
//    return 0;
//}

#include <stdio.h>
int main()
{
    int num = 0;
    int life = 0;
    int i = 0;
    scanf("%d %d", &num, &life);
    if (num < 0 || life <= 0)
    {
        printf("Game Over");
        return 0;
    }
    for (i = 1; i <= life + 1; i++)
    {
        int input = 0;
        scanf("%d", &input);
        if (input < 0)
        {
            goto exit;
        }
        if (i > life)
        {
            exit:
            printf("Game Over");
            break;
        }
        if (input == 0)
        {
            printf("Game Over");
            goto a;
        }
        else if (input == num)
        {
            if (i == 1)
            {
                printf("Bingo!");
                goto a;
            }
            else if (i <= 3)
            {
                printf("Lucky You!");
                goto a;
            }
            else if (i > 3)
            {
                printf("Good Guess!");
                goto a;
            }
        }
        else if (input > num)
        {
            printf("Too big\n");
            continue;
        }
        else if (input < num)
        {
            printf("Too small\n");
            continue;
        }
    }
a:
    return 0;
}