#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
map<string, string> _map;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string site, pass;
		cin >> site >> pass;
		_map[site] = pass;
	}
	for (int i = 0; i < m; ++i)
	{
		string input;
		cin >> input;
		map<string, string>::iterator it = _map.find(input);
		if (it != _map.end())
			cout << it->second << "\n";
	}
}