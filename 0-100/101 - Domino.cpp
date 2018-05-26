#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;

set< pair<int, int> > M[10][10];
int Grad[10];
ll n, x, y;

vector <pair<int, int> > DFS(int x)
{
	stack <int> S;
	vector < pair< pair<int, int> , pair<int, int> > > Ans;
	vector <pair<int, int> > F;
	int act = 0;

	for (int i = 0; i <= 7; i++)
		if (M[x][i].size())
		{
			S.push(i);
			pair<int, int> p = *(M[x][i].begin());
			pair<int, int> q = { p.first, (p.second ^ 1) };
			Ans.push_back({ {x, i}, p });
			M[i][x].erase(M[i][x].find(q));
			M[x][i].erase(M[x][i].begin());
			Grad[i]--;
			Grad[x]--;
			break;
		}

	if (S.empty())
		return F;

	while (true)
	{
		act = S.top();
		if (act == x)
			break;
		for (int i = 0; i <= 7; i++)
			if (M[act][i].size())
			{
				S.push(i);
				pair<int, int> p = *(M[act][i].begin());
				pair<int, int> q = { p.first, (p.second ^ 1) };
				Ans.push_back({ { act, i }, p });
				M[i][act].erase(M[i][act].find(q));
				M[act][i].erase(M[act][i].begin());
				Grad[i]--;
				Grad[act]--;
				break;
			}
	}

	for (int i = 0; i<Ans.size(); i++)
	{
		if (Grad[Ans[i].first.first])
		{
			vector<pair<int, int> > G = DFS(Ans[i].first.first);
			for (auto i : G)
				F.push_back(i);
		}
		F.push_back(Ans[i].second);
	}

	return F;
}

int main()
{
	int x, y, start;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		Grad[x]++;
		Grad[y]++;
		M[x][y].insert({ i, 0 });
		M[y][x].insert({ i, 1 });
	}
	for (int i = 0; i <= 6; i++)
		if (Grad[i] % 2 == 1)
		{
			M[7][i].insert({ -100, 0 });
			M[i][7].insert({ -100, 1 });
			Grad[7]++;
			Grad[i]++;
		}

	if (Grad[7] != 2 && Grad[7] != 0)
	{
		cout << "No solution";
		return 0;
	}
	if (Grad[7] == 0)
	{
		for (int i = 0; i <= 6; i++)
			if (Grad[i])
				start = i;
		vector< pair<int, int> > Ans = DFS(start);
		if (Ans.size() < n)
		{
			cout << "No solution";
			return 0;
		}
		for (auto i : Ans)
		{
			if (i.second == 0)
				cout << i.first << " " << '+';
			else
				cout << i.first << " " << '-';
			cout << '\n';
		}
	}
	else
	{
		vector< pair<int, int> > Ans = DFS(7);
		if (Ans.size() < n)
		{
			cout << "No solution";
			return 0;
		}
		for (auto i : Ans)
		{
			if (i.first<0) continue;
			if (i.second == 0)
				cout << i.first << " " << '+';
			else
				cout << i.first << " " << '-';
			cout << '\n';
		}
	}
	return 0;
}