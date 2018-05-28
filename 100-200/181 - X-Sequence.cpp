#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
#include <functional> 

using namespace std;
typedef long long ll;

ll x, a, b, c, m, k, first, second, M[1005];

int main()
{
	cin >> x >> a >> b >> c >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		x = a * x*x + b * x + c;
		x %= m;
		if (M[x])
		{
			first = M[x];
			second = i;
			break;
		}
		M[x] = i;
	}
	if (second == 0)
		cout << x;
	else
	{
		k -= first;
		k %= second - first;
		for (int i = 1; i <= k; i++)
		{
			x = a * x*x + b * x + c;
			x %= m;
		}
		cout << x;
	}
	return 0;
}