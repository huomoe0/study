#include <bits/stdc++.h>
#define LL long long
using namespace std;
int a[100010];
void qsort(int a[],int l,int r)
{
    int i = l,j = r,flag = a[(l+r)/2];
    do
    {
        while(a[i] < flag)  i++;
        while(a[j] > flag)  j--;
        if(i <= j)
        {
            int tmp = a[i];
            a[i] = a[j],a[j] = tmp;
            i++,j--;
        }
    } while (i <= j);
    if(i < r)   qsort(a,i,r);
    if(l < j)   qsort(a,l,j);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    qsort(a,0,n-1);
    for(int i = 0;i < n-1;i++)
        cout << a[i] << " ";
    cout << a[n-1] << "\n";
    return 0;
}