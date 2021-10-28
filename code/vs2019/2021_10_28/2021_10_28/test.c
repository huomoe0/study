#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    char ch;
//    while (scanf("%c", &ch) != EOF)
//    {
//        if (isalpha(ch))
//        {
//            switch (ch)
//            {
//            case 'A':case 'E':case 'I':case 'O':case 'U':case 'a':case 'e':case 'i':case 'o':case 'u':
//                printf("Vowel\n");
//                break;
//            default:printf("Consonant\n");
//            }
//        }
//
//    }
//    return 0;
//}
//
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    double a, b, c, delta;
//    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
//    {
//        if (a == 0)
//        {
//            printf("Not quadratic equation\n");
//            continue;
//        }
//        delta = pow(b, 2.0) - 4 * a * c;
//        if (delta == 0)
//            printf("x1=x2=%.2lf\n", -b / 2 * a);
//        else if (delta > 0)
//            printf("x1=%.2lf;x2=%.2lf\n", (-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
//        else
//        {
//            if (b != 0)
//                printf("x1=%.2lf-%.2lf%c;x2=%.2lf+%.2lf%c", -b / (2 * a), sqrt(-delta) / (2 * a),
//                    'i', -b / (2 * a), sqrt(-delta) / (2 * a), 'i');
//            else
//                printf("x1=0.00-%.2lf%c;x2=0.00+%.2lf%c", sqrt(-delta) / (2 * a),
//                    'i', sqrt(-delta) / (2 * a), 'i');
//        }
//
//    }
//    return 0;
//}

//#include <stdio.h>
//int day(int year, int month)
//{
//    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
//        return 29;
//    else
//    {
//        switch (month)
//        {
//        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
//            return 31;
//        case 2:
//            return 28;
//        case 4:case 6:case 9:case 11:
//            return 30;
//        }
//    }
//}
//
//int main()
//{
//    int year, month;
//    while (scanf("%d %d", &year, &month) != EOF)
//    {
//        printf("%d\n", day(year, month));
//    }
//    return 0;
//}


#include <stdio.h>
int main()
{
    int n, a[101], i, j;
    int count = 0;
    while (~scanf("%d", &n))
    {
        for (i = 0; i <= n; i++) //¸³Öµ
        {
            a[i] = i;
        }
        for (i = 2; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[j] % i == 0)
                {
                    count++;
                    a[j] = 0;
                }
            }
        }
        for (i = 2; i < n; i++)
        {
            if (a[i] != 0)
                printf("%d ", a[i]);
        }
    }
    printf("\n%d", count);
    return 0;
}