//#include <stdio.h>
//int main()
//{
//    int a = 0; //month
//    int b = 0; //day
//    int c = 0; //year
//    scanf_s("%d-%d-%d", &a, &b, &c);
//    if (b < 10 && a > 9)
//    {
//        printf("%d-%d-%#o", c, a, b);
//    }
//    else if (b > 9 && < 10)
//    {
//        printf("%d-%#o-%d", c, a, b);
//    }
//    else if (a < 10 && b < 10)
//    {
//        printf("%d-%#o-%#o", c, a, b);
//    }
//    else
//    {
//        printf("%d-%d-%d", c, a, b);
//    }
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int year, month, day;
//    scanf_s("%d-%d-%d", &month, &day, &year);
//    printf("%04d-%2d-%2d\n", year, month, day);
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int a = 0;
//    scanf_s("%d", &a);
//    switch (a)
//    {
//    case 1:
//        printf("3");
//        break;
//    case 2:
//        printf("4");
//        break;
//    case 3:
//        printf("5");
//        break;
//    case 4:
//        printf("6");
//        break;
//    case 5:
//        printf("7");
//        break;
//    case 6:
//        printf("1");
//        break;
//    case 7:
//        printf("2");
//        break;
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    //输入时间
//    int time = 0;
//    int via = 0;
//    scanf_s("%d %d", &time, &via);
//    //将经过的时间转化为小时和分钟
//    int h1 = 0;
//    int m1 = 0;
//    h1 = via / 60;
//    m1 = via % 60;
//    //将原时间分为小时和分钟
//    int h2 = 0;
//    int m2 = 0;
//    h2 = time / 100;
//    m2 = time % 100;
//    //相加
//    int h3 = 0;
//    int m3 = 0;
//    h3 = h1 + h2;
//    m3 = m1 + m2;
//    if (m3 >= 60)
//    {
//        m3 -= 60;
//        h3++;
//        printf("%d%02d", h3, m3);
//    }
//    else if (m3 < 0)
//    {
//        m3 += 60;
//        h3--;
//        printf("%d%02d", h3, m3);
//    }
//    else
//    {
//        printf("%d%02d", h3, m3);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int h = 0;
//    int d = 0;
//    scanf_s("%d", &d);
//    printf("%x", d);
//    return 0;
//}

