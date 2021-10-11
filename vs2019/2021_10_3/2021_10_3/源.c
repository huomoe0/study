#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//    int m = 0;
//    int n = 0;
//    scanf("%d %d", &m, &n);
//    int i = 0;
//    int count = 0;
//    int sum = 0;
//    for (i = m; i <= n; i++)
//    {
//        if (i == 2)
//        {
//            count++;
//            sum += i;
//        }
//        int a = 0;
//        for (a = 2; a < i; a++)
//        {
//            if (i > 2)
//            {
//
//                if (i % a == 0)
//                {
//                    break;
//                }
//                else if(a == i - 1)
//                {
//                    count++;
//                    sum += i;
//                    break;
//                }
//            }
//        }
//    }
//    printf("%d %d", count, sum);
//    return 0;
//}//

//#include <stdio.h>
//int main()
//{
//    double a = 2;
//    double b = 1;
//    int n = 0;
//    scanf("%d", &n);
//    double sum = 0;
//    int i = 0;
//    for (i = 1; i <= n; i++)
//    {
//        if (i == 1)
//        {
//            sum = 2.00;
//        }
//        else if (i >= 2)
//        {
//            double t = 0;
//            t = b;
//            b = a;
//            a = a + t;
//            sum += 1.0 * a / b;
//        }
//    }
//    printf("%.2lf", sum);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char n[10] = {0};
//    scanf("%s", n);
//    int b = 0;
//    b = strlen(n);
//    int i = 1;
//    for (i = 1; i <= b; i++)
//    {
//        printf("%d ", n[i - 1] - 48);
//    }
//    return 0;
//}

#include <stdio.h>
#include <math.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0");
	}
	else if(n >= 2)
	{
		double a = 0;
		double b = (1.0 + sqrt(5)) / 2;
		double c = (1.0 - sqrt(5)) / 2;
		a = (1.0 / sqrt(5)) * (pow(b, n) - pow(c, n));
		printf("%.0lf", a);
	}
	return 0;
}