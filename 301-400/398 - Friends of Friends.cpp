#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

queue < pair<int, int> > Q;
set <int> V[55], Sol;
int n, x, a, y, Viz[55];

int main()
{
    cin>>n>>x;
    for (int i=1; i<=n; i++)
    {
        cin>>a;
        for (int j=1; j<=a; j++)
        {
            cin>>y;
            V[i].insert(y);
        }
    }
    Q.push({x, 0});
    Viz[x] = 1;
    while (!Q.empty())
    {
        int a = Q.front().first;
        int y = Q.front().second;
        if (y==2 && V[x].find(a)==V[x].end())
            Sol.insert(a);
        if (y>2)
            break;
        Q.pop();
        Viz[a] = 1;
        for (auto i : V[a])
            if (!Viz[i])
                Q.push({i, y+1});
    }
    cout<<Sol.size()<<'\n';
    for (auto i : Sol)
        cout<<i<<" ";
    return 0;
}
