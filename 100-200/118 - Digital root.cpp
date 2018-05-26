#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cstring>

using namespace std;
typedef long long ll;

ll t, n, x, tot=1;

ll f(ll x)
{
	while (x >= 10)
	{
		int sum = 0;
		while (x)
		{
			sum += x % 10;
			x /= 10;
		}
		x = sum;
	}
	return   x;
}

int main()
{
	ll sum = 0;
	cin >> t;
	while (t--)
	{
		cin >> n;
		sum = 0, tot = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			tot = f(f(x)*tot);
			sum += tot;
			sum = f(sum);
		}
		cout << sum << '\n';
	}
	return 0;
}