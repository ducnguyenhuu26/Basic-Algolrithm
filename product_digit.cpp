#include<bits/stdc++.h>
using namespace std;

int product_digit(int n)
{
    if(n == 0) return 0;
    int ans = 1;
    while (n >= 1){
        ans *= n % 10;
        n /= 10;        
    }
    return ans;
}

bool isPrime(int n)
{
    if(n < 2) return false;
    for(int j = 2; j <= sqrt(n); j++)
    {
        if(n % j == 0 ) return false;
    }
    return true;
}


int digitsProduct(int product)
{
        for(int i = 2; i <= product; i++)
        {
            if(product % i ==0 && isPrime(i) && i > 10)
            {
                return -1;
            }
        }
        int n = 1;
        while(n <= 690000)
        {
        if(product_digit(n) == product)
        {
            return n;
        }
        n++;
        }
        return -1;
}

int main(){
    int n;
    cin >> n;
    int answer = digitsProduct(n);
    cout << answer;
    return 0;
}