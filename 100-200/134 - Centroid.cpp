#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int n, x, y, minim=1e9;
vector <int> V[16005], Sol;
bool Viz[16005];

inline int max(int a, int b) { return a > b ? a : b; }

int DFS(int x)
{
	int nr = 1, maxim=-1e9;
	Viz[x] = 1;
	for (auto i : V[x])
	{
		if (!Viz[i])
		{
			int val = DFS(i);
			nr += val;
			maxim = max(maxim, val);
		}
	}
	if (max(maxim, n-nr) < minim)
	{
		minim = max(maxim, n - nr);
		Sol.clear();
		Sol.push_back(x);
	}
	else if (max(maxim, n - nr) == minim)
	{
		Sol.push_back(x);
	}
	return nr;
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	DFS(1);
	cout << minim << " " << Sol.size()<<'\n';
	sort(Sol.begin(), Sol.end());
	for (auto i : Sol)
		cout << i << " ";
	return 0;
}