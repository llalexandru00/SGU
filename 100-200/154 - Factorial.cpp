#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll V[200];

void init()
{
    V[0]=1;
    for (ll i=1; V[i-1]<=1e9; i++)
        V[i]=V[i-1]*5;
}

ll test(ll x)
{
    ll tot=0;
   for (ll i=1; V[i]<=x; i++)
        tot+=x/V[i];
    return tot;
}

int main()
{
    cin>>n;
    init();
    int st=1, dr=1e9;
    while (st<=dr)
    {
        int mijl=(st+dr)/2;
        if (test(mijl)<n)
            st=mijl+1;
        else
            dr=mijl-1;
    }
    if (test(st)==n)
        cout<<st;
    else if (test(dr)==n)
        cout<<dr;
    else
        cout<<"No solution";
    return 0;
}
