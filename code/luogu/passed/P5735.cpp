#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double dis = sqrt(pow(x2-x1,2) + pow(y1-y2,2)) + sqrt(pow(x3-x1,2) + pow(y1-y3,2)) + sqrt(pow(x2-x3,2) + pow(y3-y2,2));
    printf("%.2f",dis);
	return 0;
}
