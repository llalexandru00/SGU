#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct outpost{ll x, y;} V[16005];

ll nr, R[16005], n;

bool comp(outpost a, outpost b)
{
    return a.x<b.x;
}

int main()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
        cin>>V[i].x>>V[i].y;
    sort(V+1, V+n+1, comp);
    ll r=-1;
    for (ll i=1; i<=n; i++)
    {
        if (r<V[i].y)
            r=V[i].y;
        else
            R[i]=1;
    }
    for (ll i=1; i<=n; i++)
        if (R[i])
            nr++;
    cout<<nr;
    return 0;
}