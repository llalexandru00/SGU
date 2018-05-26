#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cstring>

using namespace std;
typedef long long ll;

char s[100005];
int tot;

int main()
{
	cin.getline(s, 100005);
	int size = strlen(s), nr=0;
	for (int i = 0; i < size; i++)
	{
		if (s[i] == ')')
		{
			if (nr == 0)
				tot++;
			else
				nr--;
			continue;
		}
		if (!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || s[i] == ' '))
		{
			tot+=nr;
			nr = 0;
		}
		if (s[i] == '(')
		{
			nr++;
		}
	}
	cout << tot+nr;
	return 0;
}