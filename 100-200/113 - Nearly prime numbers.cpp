#include <bits/stdc++.h>
#define INF (1e9)+5

using namespace std;

typedef long long ll;

vector <ll> V;
bool P[2000005];
ll n;

void Ciur()
{
    P[0]=P[1]=1;
    for (ll i=2; i<=2000000; i++)
    {
        if (P[i]==0)
        {
            for (ll j=i*i; j<=2000000; j+=i)
                P[j]=1;
            V.push_back(i);
        }
    }
}

int main()
{
    ll x;
    Ciur();
    cin>>n;
    while (n--)
    {
        cin>>x;
        int ok=1, nr=0;
        for (int i=0; V[i]*V[i]<=x; i++)
        {
            if (V[i]*V[i]==x)
            {
                nr+=2;
                x=1;
                break;
            }
            if (x%V[i]==0)
            {
                nr++;
                x/=V[i];
            }
            if (x%V[i]==0)
            {
                ok=0;
                break;
            }
        }
        if (x>1)
            nr++;
        if (nr==2 && ok)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        cout<<'\n';
    }

    return 0;
}