//#include <stdio.h>
//int main()
//{
//	const int AMOUNT = 100;
//	AMOUNT = 10;
//	return 0;
//
//}
#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int a;
//	int b;
//
//	printf("请输入两个整数：");
//	scanf("%d %d",&a,&b);
//	printf("%d + %d = %d\n", a, b, a + b);
//
//	return 0;
////}
//
//
//
//#include <stdio.h>

////int main()
//{
//	printf("请分别输入身高的英尺和英寸，""如输入\"5 7\"表示5英尺7英寸：");
//
//	double foot;
//	double inch;
//
//	scanf("%lf %lf", &foot, &inch);
//
//	printf("身高是%f米。\n",
//		((foot + inch / 12) * 0.3048));
//
//	return 0;
//}
//
//
//
//
//
//#include <stdio.h>
//int main()
//{}
//#include <stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    scanf("%d", &a);
//    b = a / 30.48;
//    c = (a - b * 30.48) / 30.48 * 12;
//    printf("%d %d", b,c);
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int c = 0;
//    int f = 0;
//    scanf("%d", &f);
//    c = 5 * (f - 32) / 9;
//    printf("Celsius = %d", c);
//    return 0;
//}


#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    double a4 = 0;
    a1 = a + b;
    a2 = a - b;
    a3 = a * b;
    a4 = a / (b / 1.00);
    printf("%d + %d = %d\n", a, b, a1);
    printf("%d - %d = %d\n", a, b, a2);
    printf("%d * %d = %d\n", a, b, a3);
    if (a % b == 0)
    {
        printf("%d / %d = %.0f\n", a, b, a4);
    }
    else
    {
        printf("%d / %d = %.2f\n", a, b, a4);
    }
    return 0;
}