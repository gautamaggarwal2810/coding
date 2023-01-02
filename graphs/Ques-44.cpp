#include<bits/stdc++.h>
using namespace std;

int isStepNum(int n)
{
   if(n<10)
    return true;

    while(n)
    {
    int currDigit=n%10;
    int prevDigit=(n/10)%10;

    if(abs(currDigit-prevDigit)!=1 && prevDigit!=0)
     return false;

    n=n/10;
    }
    return true;
}


void displaySteppingNumbers(int n, int m)
{
    for (int i=n; i<=m; i++)
        if (isStepNum(i))
            cout << i << " ";
}

int main()
{
    int n = 1000, m = 1022;
    displaySteppingNumbers(n, m);
    return 0;
}