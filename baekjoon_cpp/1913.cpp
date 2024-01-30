#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	int i,j,k;
	cin >> i;
	vector<pair<int , int>> room;
	int res = 1;
	for (int a = 0; a < i; a++)
	{
		cin >> j >> k;
		room.push_back(make_pair(k, j));
	}
	sort(room.begin(), room.end());
	int start = room[0].first;
	for (int a = 0; a < i; a++)
	{
		if (start <= room[a].second)
		{
			start = room[a].first;
			res++;
		}
	}
	cout << res;
}