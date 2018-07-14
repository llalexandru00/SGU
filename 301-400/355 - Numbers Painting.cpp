#include <iostream>

using namespace std;

int n, C[10005], maxim;

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int c=1;
        for (int d=1; d*d<=i; d++)
        {
            while (i%d==0 && C[d]>=c)
                c++;
            while (i%d==0 && C[i/d]>=c)
                c++;

        }
        C[i]=c;
        if (c>maxim)
            maxim=c;
    }
    cout<<maxim<<'\n';
    for (int i=1; i<=n; i++)
        cout<<C[i]<<" ";
    return 0;
}
