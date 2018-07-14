#include <bits/stdc++.h>

using namespace std;

int n, x, d, DP2[10005], Ans[10005];
struct {int max1, wh1, max2, wh2;} DP1[10005];
bool Vis[10005];
vector < pair<int, int> > V[10005];

void DFS1(int x)
{
    Vis[x] = 1;
    DP1[x].max1 = 0;
    DP1[x].max2 = 0;
    for (auto i : V[x])
        if (!Vis[i.first])
        {
            DFS1(i.first);

            if (DP1[i.first].max1 + i.second > DP1[x].max1)
            {
                DP1[x].max2 = DP1[x].max1;
                DP1[x].wh2 = DP1[x].wh1;
                DP1[x].max1 = DP1[i.first].max1 + i.second;
                DP1[x].wh1 = i.first;
            }
            else if (DP1[i.first].max1 + i.second > DP1[x].max2)
            {
                DP1[x].max2 = DP1[i.first].max1 + i.second;
                DP1[x].wh2 = i.first;
            }
        }
}

void DFS2(int x, int father, int dist)
{
    Vis[x] = 1;
    DP2[x] = 0;
    if (father!=0)
    {
        if (DP1[father].wh1 == x)
            DP2[x] = max(dist + DP2[father], dist + DP1[father].max2);
        else
            DP2[x] = max(dist + DP2[father], dist + DP1[father].max1);
    }
    for (auto i : V[x])
        if (!Vis[i.first])
            DFS2(i.first, x, father, i.second);
}

void DFS3(int x)
{
    Ans[x]=max(DP1[x].max1, DP2[x]);
    Vis[x] = 1;
    for (auto i : V[x])
        if (!Vis[i.first])
            DFS3(i.first);
}

int main()
{
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        cin>>x>>d;
        V[i].push_back({x, d});
        V[x].push_back({i, d});
    }

    memset(Vis, 0, sizeof(Vis));
    DFS1(1);

    memset(Vis, 0, sizeof(Vis));
    DFS2(1, 0, 0);

    memset(Vis, 0, sizeof(Vis));
    DFS3(1);

    for (int i=1; i<=n; i++)
        cout<<Ans[i]<<'\n';
    return 0;
}
