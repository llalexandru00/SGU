#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int n, m, k, x, tot;
vector < pair<int, int> > V;

int main()
{
	cin >> n >> m >> k;
	for (int i=2; i <= k; i++)
	{
		int nr = 0;
		while (k%i==0)
		{
			nr++;
			k /= i;
		}
		if (nr)
			V.push_back({ i, nr });
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		int ok = 1;
		for (auto j : V)
		{
			for (int k = 1; k <= j.second/m + (j.second%m>0); k++)
			{
				if (x%j.first == 0)
					x /= j.first;
				else
					ok = 0;
			}
		}
		tot += ok;
	}
	cout << tot;
	return 0;
}