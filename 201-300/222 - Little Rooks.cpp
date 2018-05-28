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

ll fact(ll x)
{
	ll a = 1;
	for (ll i = 1; i <= x; i++)
		a *= i;
	return a;
}

ll comb(ll n, ll k)
{
	return fact(n) / (fact(k)*fact(n - k));
}

int main()
{
	cin >> n >> k;
	if (k > n)
		cout << 0;
	else
		cout << comb(n, k)*(fact(n)/fact(n-k));
	return 0;
}