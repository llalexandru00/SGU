#include <bits/stdc++.h>
#define INF (1e9)+5

using namespace std;

typedef long long ll;

vector <ll> V;
vector < pair<ll, ll> > A;
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
    Ciur();
    cin>>n;
    for (ll j=0; 2+V[j]<=n; j++)
        if (P[2+V[j]]==0)
            A.push_back({2, V[j]});

    cout<<A.size()<<'\n';
    for (ll i=0; i<A.size(); i++)
        cout<<A[i].first<<" "<<A[i].second<<'\n';
    return 0;
}