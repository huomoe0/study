//#include <stdio.h>
//int main()
//{
//    float km = 0; //起步里程
//    float fee = 0; //费用
//    int min = 0; //等待时间
//    scanf_s("%f %d", &km, &min);
//    int a = 0; //等待时间个数
//    a = min / 5;
//    int km1 = 0;
//    km1 = km - 3; //10公里内加收
//    int km2 = 0;
//    km2 = km1 - 10;
//    fee = 10 + a * 2 + km1 * 2 + km2 * 3;
//    //起步里程为3公里，起步费10元；
//    //超起步里程后10公里内，每公里2元；
//    //超过10公里以上的部分加收50%的回空补贴费，即每公里3元；
//    //营运过程中，因路阻及乘客要求临时停车的，按每5分钟2元计收（不足5分钟则不收费）。
//    if (km <= 3.0)
//    {
//        printf("%.0f",fee);
//    }
//    else if (km > 3.0 && km <= 10.0)
//    {
//        printf("%.0f",fee);
//    }
//    else if (km > 10)
//    {
//        printf("%.0f", fee);
//    }
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    float distance;//路程公里数
//    int time;//等待时间
//    scanf_s("%f %d", &distance, &time);
//    float price;//价钱
//    if (distance <= 3)
//        price = 10 + (time / 5) * 2;
//    else if (distance <= 10)
//        price = 10 + (distance - 3) * 2 + (time / 5) * 2;
//    else
//        price = 10 + (distance - 10) * 3 + 7 * 2 + (time / 5) * 2;
//    printf("%.0f", price);
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int year = 0;
//    int month = 0;
//    int day = 0;
//    int i = 0;
//    int b = 0;
//    scanf_s("%d/%d/%d", &year, &month, &day);
//    if (( year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//        b = 1;
//        for (i = 1; i < month; i++)
//        {
//            switch (i)
//            {
//            case 1:
//                day += 31;
//                break;
//            case 2:
//                if (b == 1)
//                {
//                    day += 29;
//                }
//                else
//                {
//                    day += 28;
//                }
//                break;
//            case 3:
//                day += 31;
//                break;
//            case 4:
//                day += 30;
//                break;
//            case 5:
//                day += 31; 
//                break;
//            case 6:
//                day += 30;
//                break;
//            case 7:
//                day += 31;
//                break;
//            case 8:
//                day += 31;
//                break;
//            case 9:
//                day += 30;
//                break;
//            case 10:
//                day += 31;
//                break;
//            case 11:
//                day += 30;
//                break;
//            case 12:
//                day += 31;
//                break;
//            }
//        }
//        printf("%d", day);
//        return 0;
//}

#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    scanf_s("%d+%d*%d-%d/%d=", &a, &b, &c, &d, &e);
    if (e == 0)
        printf("ERROR");
    else
        printf("%d", (((a + b) * c) - d) / 2);
        return 0;
}