// #include <stdio.h>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int i,n1,n2,n3,num;
//     for(i = 1;i <= n;i++)  // 0 1 1 2 3 5 8  13 21
//                            // 1 2 3 4 5 6 7  8  9
//     {
//         if(i <= 3)
//         {
//             n1 = 0;
//             n2 = 1;
//             n3 = 1;
//         }

//         if(i >= 4 && i % 3 == 1)
//         {
//             n1 = n2 + n3;
//             n2 = n3 + n1;
//             n3 = n1 + n2;
//         }

//     }
//     num = n % 3;
//     switch(num)
//     {
//         case 1 :
//             printf("%d",n1);
//             break;

//         case 2 :
//             printf("%d",n2);
//             break;
//         case 0 :
//             printf("%d",n3);
//             break;
//     }
//     return 0;
// }



