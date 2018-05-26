#include <iostream>

using namespace std;

int n;
string s;

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>s;
        int l=s.size()-1;
        if (s[l-1]=='c' && s[l]=='h' || s[l]=='x' || s[l]=='s' || s[l]=='o')
            cout<<s<<"es";
        else if (s[l]=='f')
        {
            for (int j=0; j<l; j++)
                cout<<s[j];
            cout<<"ves";
        }
        else if (s[l-1]=='f' && s[l]=='e')
        {
            for (int j=0; j<l-1; j++)
                cout<<s[j];
            cout<<"ves";
        }
        else if (s[l]=='y')
        {
            for (int j=0; j<l; j++)
                cout<<s[j];
            cout<<"ies";
        }
        else
            cout<<s<<"s";
        cout<<'\n';
    }
    return 0;
}