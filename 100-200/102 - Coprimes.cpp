#include <iostream>

using namespace std;

long long n;

int main()
{
    cin>>n;
    long long sus=n, jos=1;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            sus*=i-1;
            jos*=i;
        }
        while (n%i==0)
            n/=i;
    }
    if (n>1)
    {
        sus*=n-1;
        jos*=n;
    }
    cout<<sus/jos;
    return 0;
}