#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;

ll k, DP[50];

int main()
{
	cin >> k;
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= k; i++)
		for (int j = 0; j < i; j++)
			DP[i] += DP[i - j - 1] * DP[j];
	cout << DP[k] << " " << k + 1;
	return 0;
}