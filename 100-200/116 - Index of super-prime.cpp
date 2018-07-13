#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

vector <int> Primes, SuperPrimes, Sol;
bool S[10005];
int n, DP[10005], Back[10005];

void Sieve()
{
    S[0]=S[1]=1;
    for (int i=2; i<=n; i++)
        if (S[i]==0)
        {
            for (long long j=i*i; j<=n; j+=i)
                S[j]=1;
            Primes.push_back(i);
        }
}

void SuperSieve()
{
    for (int i=0; i<Primes.size() && Primes[i]-1<Primes.size(); i++)
        SuperPrimes.push_back(Primes[Primes[i]-1]);
}

bool comp(int a, int b)
{
    return a>b;
}

int main()
{
    cin>>n;
    Sieve();
    SuperSieve();

    if (n<3)
    {
        cout<<0;
        return 0;
    }

    DP[1]=DP[2]=INF;
    for (int i=3; i<=n; i++)
    {
        DP[i]=INF;
        for (int j : SuperPrimes)
        {
            if (i-j<0) break;
            if (DP[i-j]+1<DP[i])
            {
                DP[i] = DP[i-j]+1;
                Back[i] = i-j;
            }
        }
    }

    if (DP[n]==INF)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<DP[n]<<'\n';
    int act=n;
    while (act>0)
    {
        Sol.push_back(act-Back[act]);
        act = Back[act];
    }
    sort(Sol.begin(), Sol.end(), comp);
    for (int i : Sol)
        cout<<i<<" ";
    return 0;
}
