#include <bits/stdc++.h>
using namespace std;
int main()
{
	double m,n;
    cin >> m >> n;
    double bmi = m/(n*n);
    if(bmi < 18.5)  cout << "Underweight";
    else if(bmi >= 18.5 && bmi < 24)    cout << "Normal";
    else if(bmi >= 24)  cout << bmi << endl << "Overweight";
    return 0;
}