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

#include <stdio.h>
#include <math.h>

int main()
{
    double a3 = 0;
    double a2 = 0;
    double a1 = 0;
    double a0 = 0;
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    double root = 0;
    double a = 0;
    double b = 0;//大
    double n = 0;
    scanf("%lf %lf", &a, &b); //区间范围
    if (a > b)
    {
        double t = 0;
        t = a;
        a = b;
        b = t;
    }
    while (b - a >= 0.01)
    {
        n = (a + b) / 2;
        root = a3 * pow(n, 3) + a2 * pow(n, 2) + a1 * n + a0;
        double fa = a3 * pow(a, 3) + a2 * pow(a, 2) + a1 * a + a0;
        double fb = a3 * pow(b, 3) + a2 * pow(b, 2) + a1 * b + a0;

        //如果f(a)f(b) < 0，则计算中点的值f((a + b) / 2)；
        //如果f((a + b) / 2)正好为0，则(a + b) / 2就是要求的根；否则
        //如果f((a + b) / 2)与f(a)同号，则说明根在区间[(a + b) / 2, b]，令a = (a + b) / 2，重复循环；
        //如果f((a + b) / 2)与f(b)同号，则说明根在区间[a, (a + b) / 2]，令b = (a + b) / 2，重复循环。
        if (b - a < 0.01)
        {
            break;
        }
        else if (root == 0)
        {
            break;
        }
        else if (root * fa > 0)
        {
            a = (a + b) / 2;
        }
        else if (root * fb > 0)
        {
            b = (a + b) / 2;
        }
    }
    printf("%.2lf", (a + b) / 2);
    return 0;
}