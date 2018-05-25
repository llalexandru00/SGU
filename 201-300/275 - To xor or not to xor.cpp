#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, n, Viz[1063], V[105][100], x, maxim;

void xorline(ll a, ll b)
{
    for (ll j=0; j<=63; j++)
        V[a][j]=(V[a][j]^V[b][j]);
}

int main()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        cin>>x;
        for (ll j=0; j<=63; j++)
        {
            V[i][j] = (x>>j)%2;
            maxim=max(maxim, j);
        }
    }
    for (ll j=63; j>=0; j--)
    {
        for (ll i=1; i<=n; i++)
        {
            if (Viz[i]==0 && V[i][j])
            {
                Viz[i]=1;
                Viz[i]=1;
                for (ll k=1; k<=n; k++)
                    if (V[k][j] && k!=i)
                        xorline(k, i);
                break;
            }
        }
    }
    for (ll j=0; j<=63; j++)
    {
        ll x=0;
        for (ll i=1; i<=n; i++)
            x ^= V[i][j];
        a += x<<j;
    }
    cout<<a;
    return 0;
}
