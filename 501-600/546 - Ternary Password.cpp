#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <string>

using namespace std;
typedef long long ll;

ll n, a, b, zrs, ons, needz, needons, onstogo, ztogo, nr;
string s;

inline ll min(ll a, ll b) { return a < b ? a : b; }

int main()
{
	cin >> n >> a >> b;
	cin >> s;
	for (int i = 0; i<s.size(); i++)
	{
		if (s[i] == '0')
			zrs++;
		if (s[i] == '1')
			ons++;
	}
	if (a > zrs)
		needz = a - zrs;
	if (a < zrs)
		ztogo = zrs - a;
	if (b > ons)
		needons = b - ons;
	if (b < ons)
		onstogo = ons - b;
	if (a + b > n)
	{
		cout << -1<<'\n';
		return 0;
	}
	for (int i=0; i<s.size(); i++)
	{
		if (s[i] == '0')
		{
			if (ztogo && needons)
			{
				needons--;
				ztogo--;
				s[i] = '1';
				nr++;
			}
			else if (ztogo && !needons)
			{
				ztogo--;
				s[i] = '2';
				nr++;
			}
		}
		else if (s[i]=='1')
		{
			if (onstogo && needz)
			{
				needz--;
				onstogo--;
				s[i] = '0';
				nr++;
			}
			else if (onstogo && !needz)
			{
				onstogo--;
				s[i] = '2';
				nr++;
			}
		}
	}
	for (int i = 0; i<s.size(); i++)
	{
		if (s[i] == '2')
		{
			if (needz)
			{
				needz--;
				s[i] = '0';
				nr++;
			}
			else if (needons)
			{
				needons--;
				s[i] = '1';
				nr++;
			}
		}
	}
	cout << nr<<'\n'<< s;
	return 0;
}