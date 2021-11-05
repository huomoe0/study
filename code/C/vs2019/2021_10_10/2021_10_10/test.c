#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    if (a + b <= c || a + c <= b || b + c <= a)
//    {
//        printf("These sides do not correspond to a valid triangle\n");
//        return 0;
//    }
//    double s = (a + b + c) / 2.0;
//    double area = sqrt(s * (s - a) * (s - b) * (s - c));
//    double perimeter = a + b + c;
//    printf("area = %.2lf; perimeter = %.2lf", area, perimeter);
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int m, n;
//    scanf("%d %d", &m, &n);
//    double sum = 0;
//    int i;
//    for (i = m; i <= n; i++)
//    {
//        sum += pow(i, 2);
//        sum += pow(i, -1);
//    }
//    printf("sum = %.6lf", sum);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int day;
//    scanf("%d", &day);
//    int flag = 0;
//    int m, i = 1;
//    while(1)
//    {
//        if (flag == 0)
//        {
//            for (m = 1; m <= 3; m++)
//            {
//                if (i == day)
//                {
//                    printf("Fishing in day %d", i);
//                    return 0;
//                }
//                i++;
//            }
//            flag = 1;
//        }
//
//        if (flag == 1)
//        {
//            for (m = 1; m <= 2; m++)
//            {
//                if (i == day)
//                {
//                    printf("Drying in day %d", i);
//                    return 0;
//                }
//                i++;
//            }
//            flag = 0;
//        }
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int x1, x2, x3, y1, y2, y3;
//    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
//    double l1, l2,l3;
//    l1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
//    l2 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
//    l3 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
//    if (l1 + l2 <= l3 || l1 + l3 <= l2 || l2 + l3 <= l1)
//    {
//        printf("Impossible");
//        return 0;
//    }
//    double l, a, s;
//    l = l1 + l2 + l3;
//    s = l / 2.0;
//    a = sqrt(s * (s - l1) * (s - l2) * (s - l3));
//    printf("L = %.2lf, A = %.2lf", l, a);
//    return 0;
//}

#include <stdio.h>
#include <math.h>
int min(int m, int n)
{
    if (m < n)
    {
        return m;
    }
    else
    {
        return n;
    }
}

int main()
{
    int x, i;
    scanf("%d", &x);
    int m ,n,cm = 1,cn = 1,count = 0;
    for (i = 1; i <= x; i++)
    {
        scanf("%d/%d", &m, &n);
        cm *= m;
        cn *= n;
    }
    for (int j = 2; j < min(cm, cn); j++)
    {
        if (cm % j == 0 && cn % j == 0)
        {
            cm = cm / j;
            cn = cn / j;
        }
    }
    if (cm > cn && cm % cn == 0)
    {
        while (cm / cn > 0)
        {
            cm = cm / cn;
            count++;
        }
    }
    if (cm * cn >= 0)
    {
        printf("%d %d/%d",count, cm, cn);
    }
    else
    {
        printf("%d -%d/%d",count, labs(cm),labs(cn));
    }
        
    return 0;
}