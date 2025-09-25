#include<bits/stdc++.h>
using namespace std;

int number_of_digit(int n)
{
    int count = 0;
    while (n >= 1){
        count ++;
        n  = (int)n/10;
    }
    return count;
}
int pagesNumbering(int n)
{
    int m = number_of_digit(n);
    int sum1 = 0;
    for(int i = 1; i < m; i++)
    {
        sum1 += 9 * pow(10,i-1) *i;
    }
    int sum2 = (n-pow(10,m-1)+1) * m;

    return sum1+sum2;
}

int main()
{
    int n;
    cin >> n;
    cout << pagesNumbering(n);
    return 0;
}