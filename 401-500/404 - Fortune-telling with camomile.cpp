#include <iostream>

using namespace std;

int n, k;
string s[105];

int main()
{
    cin>>k>>n;
    for (int i=0; i<n; i++)
        cin>>s[i];
    k--;
    k=k%n;
    cout<<s[k];
    return 0;
}