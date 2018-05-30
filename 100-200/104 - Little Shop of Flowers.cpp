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

int n, m, M[105][105], DP[105][105];
pair<int, int> B[105][105];
vector <int> Sol;

 ll max(ll a, ll b) {
	return a < b ? b : a;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> M[i][j];

	for (int i = 1; i <= n+1; i++)
		for (int j = 0; j <= m+1; j++)
			DP[i][j] = -1e9;

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= m; j++)
		{
			DP[i][j] = DP[i][j-1];
			B[i][j] = { i, j - 1 };
			for (int k = j - 1; k >= 0; k--)
			{
				if (DP[i][j] < M[i][j] + DP[i - 1][k])
				{
					DP[i][j] = M[i][j] + DP[i - 1][k];
					B[i][j] = { i - 1, k };
				}
			}
		}

	cout << DP[n][m]<<'\n';
	int i = n;
	int j = m;
	while (B[i][j].second != 0)
	{
		if (i != B[i][j].first)
			Sol.push_back(j);
		i = B[i][j].first;
		j = B[i][j].second;
	}
	if (i != B[i][j].first)
		Sol.push_back(j);
	for (int i = Sol.size() - 1; i >= 0; i--)
		cout << Sol[i] << " ";
	return 0;
}