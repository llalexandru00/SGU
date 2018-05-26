#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c, x, y, z;

int main()
{
    cin>>a>>b>>c;
    cin>>x>>y>>z;
    cout<<min(a/x, min(b/y, c/z));
    return 0;
}