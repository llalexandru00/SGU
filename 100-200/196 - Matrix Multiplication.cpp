#include <bits/stdc++.h>

using namespace std;

int n, m;
vector < pair <int, int> > E;
int x, y, V[10005];
long long tot;

int main()
{
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        cin>>x>>y;
        V[x]++; V[y]++;
        E.push_back({x, y});
    }
    for (auto i : E)
        tot += V[i.first] + V[i.second];
    cout<<tot;
    return 0;
}
