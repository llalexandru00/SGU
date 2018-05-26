#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int n, m, day;

int D[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	cin >> n >> m;
	day = 0;
	if (m>12)
	{
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int lim;
		if (i == m)
		{
			if (n > D[i])
			{
				cout << "Impossible\n";
				return 0;
			}
			lim = n;
		}
		else
			lim = D[i];
		for (int j = 1; j <= lim; j++)
		{
			day++;
			if (day == 8)
				day = 1;
		}
	}
	cout << day<<'\n';
	return 0;
}