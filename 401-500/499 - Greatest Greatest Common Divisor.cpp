#include <iostream>

using namespace std;

int n, x, maxim=-1, C[1000005];

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        if (x>maxim)
            maxim=x;
        for (int j=1; j*j<=x; j++)
        {
            if (x%j==0)
            {
                C[j]++;
                C[x/j]++;
            }
        }
    }
    for (int i=maxim; i>=1; i--)
    {
        if (C[i]>1)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}