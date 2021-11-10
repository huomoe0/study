#include <vector>
#include <cstdio>
using namespace std;
int main()
{
    vector<int> arr(5);
    arr.insert(arr.begin() + 1,5);
    bool flag = arr.empty();
    
    int i;
    for(i = 0;i < 6;i++)
    
        printf("%d",arr[i]);
    
    return 0;
}