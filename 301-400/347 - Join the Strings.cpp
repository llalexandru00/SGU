#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s[105];

bool comp(string a, string b)
{
    string x = a+b;
    string y = b+a;
    return x<y;
}

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>s[i];
    sort(s+1, s+n+1, comp);
    for (int i=1; i<=n; i++)
        cout<<s[i];
    return 0;
}
