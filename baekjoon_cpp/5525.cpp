#include <iostream>
#include <string>
using namespace std;

int n, m;
string str, pattern;
int lps[1000001];
int ans;

void LPS(string pattern, int size)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < size)
	{
		if (pattern[i] == pattern[len])
		{
			++len;
			lps[i] = len;
			++i;
		}
		else
		{
			if (len != 0)
				len = lps[len - 1];
			else
			{
				lps[i] = 0;
				++i;
			}
		}
	}
}

void KMP(string str, string pattern)
{
	int N = str.length();
	int M = pattern.length();
	LPS(pattern, M);
	int i = 0;
	int j = 0;
	while (i < N)
	{
		if (pattern[j] == str[i])
		{
			i++;
			j++;
			if (j == M)
			{
				j = lps[j - 1];
				ans++;
			}
		}
		else
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> str;
	for (int i = 0; i < n; ++i)
	{
		pattern.insert(pattern.end(),'I');
		pattern.insert(pattern.end(),'O');
		if (i == n - 1)
			pattern.insert(pattern.end(),'I');
	}
	KMP(str, pattern);
	for (int i = 0; i < pattern.size(); ++i)
		cout << lps[i] << " ";
	cout << endl;
	cout << ans << "\n";
}
