#include <iostream>

using namespace std;

long long n;

int main()
{
    cin>>n;
    long long a=1, b=1, c, tot=2;
    if (n==1 || n==2)
    {
        cout<<n;
        return 0;
    }
    for (int i=3; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
        tot+=c;
    }
    cout<<tot;
    return 0;
}