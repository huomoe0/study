#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char a[50] = { 0 }, b[50] = { 0 };
//    scanf("%s %s", a, b);
//    if (memcmp(a, b, 50) == 0)
//        printf("same\n");
//    else
//        printf("different\n");
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n, i, j;
//    int a[1001] = { 0 };
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//        scanf("%d", &a[i]);
//    for (i = 0; i < n; i++)
//    {
//        for (j = i + 1; j < n; j++)
//        {
//            if (a[i] == a[j])
//                a[j] = 0;
//            if (a[i] != 0)
//                printf("%d ", a[i]);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int m, n, i;
//    int a[1000] = { 0 }, b[1000] = { 0 };
//    scanf("%d %d", &n, &m);
//    for (i = 0; i < n; i++)
//        scanf("%d", &a[i]);
//    for (i = 0; i < m; i++)
//        scanf("%d", &b[i]);
//
//    int x = 0, y = 0;
//    while (y < m || x < n)
//    {
//        if (a[x] < b[y] && x < n)
//        {
//            printf("%d ", a[x]);
//            x++;
//        }
//        else if (y < m)
//        {
//            printf("%d ", b[y]);
//            y++;
//        }
//        else
//        {
//            printf("%d ", a[x]);
//            x++;
//        }
//    }
//    return 0;
//}

