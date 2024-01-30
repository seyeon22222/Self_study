#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	int a[100] = {0, };
	int count;
	int max_n = 0;
	string str;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		cin >> str;
		for (size_t j = 0; j < str.size(); j++)
		{
			if (str[j] == 'O')
				count++;
		}
		if (count > m / 2)
			a[i] = 1;
	}
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i])
			count++;
	}
	cout << count;
}
