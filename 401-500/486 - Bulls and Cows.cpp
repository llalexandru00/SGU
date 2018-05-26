#include <iostream>

using namespace std;


string a, b;
int bulls, cows, f[300];

int main()
{
    cin>>a>>b;
    for (int i=0; i<4; i++)
        if (a[i]==b[i])
            bulls++;
        else
            f[a[i]]++, f[b[i]]++;
    for (int i='0'; i<='9'; i++)
        if (f[i]==2)
            cows++;
    cout<<bulls<<" "<<cows;
    return 0;
}