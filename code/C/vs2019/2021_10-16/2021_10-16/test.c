#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#include <string.h>
int main()
{
    //int  a[2] = {'0'};
    //for (int i = 0; i <= 1; i++)
    //{
    //    printf("%d\a ",a[i]); ////
    //}


    //char s[] = "a0\0a0\0";//有个隐藏的\0
    //printf("%d\n", sizeof(s)); // 7
    //printf("%d\n", strlen(s)); // 检测到\0停止，不含\0

    int i = 5;
    int a = (++i) + (++i) + (++i);
    printf("%d",a);

    return 0;    
        

     









}