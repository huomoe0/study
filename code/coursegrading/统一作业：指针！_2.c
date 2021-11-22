#include <stdio.h>
#include <string.h>

int main()  
{
      char str[5][100] = {0},t[100] = {0};
      for(int i = 0;i < 5;i++)
      {
          scanf("%s",str[i]);
      }
      for(int i = 0;i < 5;i++)
      {
          for(int j = 0;j < 5-i-1;j++)
          {
              if(strcmp(str[j],str[j+1]) < 0)
              {
                  strcpy(t,str[j]);
                  strcpy(str[j],str[j+1]);
                  strcpy(str[j+1],t);
              }
          }
      }
      for(int i = 0;i < 5;i++)
      {
          printf("%s\n",str[i]);
      }
      return 0;
} 