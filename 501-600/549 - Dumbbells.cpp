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

ll n, k;
struct obj { int m, c; }V[4005];
multiset < int, greater<int> >  F[4005];
vector < int > A[4005];
int tot;

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> V[i].m >> V[i].c;
		A[V[i].m].push_back(V[i].c);
	}
	for (int i = 1; i <= 4000; i++)
	{
		sort(A[i].begin(), A[i].end(), greater<int>());
		int sum = 0;
		for (int j = 0; j < A[i].size(); j++)
		{
			sum += A[i][j];
			F[j+1].insert(sum);
		}
	}

	for (int i = 4000; i >= 1; i--)
	{
		if (F[i].size()<k) continue;
		cout << i << " ";
		for (int j = 0; j < k; j++)
		{
			tot += *(F[i].begin());
			F[i].erase(F[i].begin());
		}
		break;
	}
	if (tot == 0)
		cout << "0 0";
	else
		cout << tot;
	return 0;
}