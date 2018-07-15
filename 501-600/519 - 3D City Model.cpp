#include <iostream>

using namespace std;

int n, m, tot;
char M[105][105];

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>M[i][j], M[i][j]-='0';
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (M[i][j]==0) continue;
            tot += 2;
            tot += max(0, M[i][j]-M[i-1][j]);
            tot += max(0, M[i][j]-M[i+1][j]);
            tot += max(0, M[i][j]-M[i][j-1]);
            tot += max(0, M[i][j]-M[i][j+1]);
        }
    }
    cout<<tot;
    return 0;
}
