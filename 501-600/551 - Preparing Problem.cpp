#include <bits/stdc++.h>
#define INF (1e9)+5

using namespace std;

typedef long long ll;

multiset <pair<ll, ll> > V;

ll n, x, y, nrtot, tim;

int main()
{
    cin>>n>>x>>y;
    V.insert({x, x});
    V.insert({y, y});
    while (nrtot<n)
    {
        ll a = V.begin()->first;
        ll who=V.begin()->second;
        V.erase(V.begin());
        if (V.begin()->first==a)
        {
            V.erase(V.begin());
            nrtot+=2;
            tim=a;
            if (nrtot<n)
            {
                V.insert({a+x, x});
                V.insert({a+y, y});
            }
        }
        else
        {
            nrtot++;
            tim=a;
            if (nrtot<n)
            {
                V.insert({a+who, who});
            }
        }
    }
    while (!V.empty())
    {
        nrtot++;
        tim=V.begin()->first;
        V.erase(V.begin());
    }
    cout<<nrtot<<" "<<tim;
    return 0;
}