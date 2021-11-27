#include<stdio.h>  
int main (void)
{
	int n, value, value1, value2, sum=0, x, value3, qian=1000, y=0, jishuqi=0;
	scanf("%d", &n);
	value=n/100000000;
	if(value!=0){
		printf("%cY", 'a'+value);                      /*输出亿位*/
	}
        value1=n%100000000;
	value2=value1/10000;                                 /*得到万位数字*/
	while(qian!=0){                                            /*输出万位*/
		if(value2==0){
			break;
		}
		x=value2/qian;
		value2=value2%qian;
		qian=qian/10;
		y++;
		if(value==0&&x==0){                
			if(jishuqi!=1){
				continue;
			}
		}
		if(x==0){
			sum++;
			if(sum<=1) {
				if(y!=4){
					printf("%c", 'a');
				}	
			}
		}
		if(x!=0){
			sum=0;
			jishuqi=1;
			printf("%c", 'a'+x);
			switch(y){
				case 1: printf("Q"); break;
				case 2: printf("B"); break;
				case 3: printf("S"); break;
			}
		}
	}
	if(y!=0){
		printf("W");                                      /*输出万位结束*/
	}
	sum=0;                                                    /*输出千位以下需要重新赋初始值，因为在万位运算的时候值变化了*/
	qian=1000;
	y=0;
	jishuqi=0;
	value3=n%10000;                                    /*得到千以及以下数字*/
	while(qian!=0){
		x=value3/qian;
		value3=value3%qian;
		qian=qian/10;
		y++;
		if((n%100000000)/10000==0&&x==0){
			if(jishuqi!=1){
				continue;
			}
		}
		if(value3!=0){
			if(x==0){
			    sum++;
			    if(sum<=1) {
				    printf("%c", 'a');
			    }
		    }
		}
		if(x!=0){
			sum=0;
			jishuqi=1;
			printf("%c", 'a'+x);
			switch(y){
				case 1: printf("Q"); break;
				case 2: printf("B"); break;
				case 3: printf("S"); break;
			}
		}
	}
        if(n==0){
		printf("%c", 'a');
	}	
} 