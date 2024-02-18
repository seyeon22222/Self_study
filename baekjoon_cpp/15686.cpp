#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int board[54][54];
vector<pair<int , int>> h, ch, selected;
bool visited[13];
int totalD = 10000;

void cal()
{
	int dis = 0;	
	for (int i = 0; i < h.size(); ++i) {
		int minD = 10000;
		for (int j = 0; j < selected.size(); ++j) {
			int tempD = abs(h[i].first - selected[j].first) + abs(h[i].second - selected[j].second);
			minD = min(tempD, minD);
		}
		dis += minD;
	}
	totalD = min(totalD, dis);
}

void solve(int x, int y)
{
	if (y == m)
		cal();
	for (int i = x; i < ch.size(); ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		selected.push_back(make_pair(ch[i].first, ch[i].second));
		solve(i, y + 1);
		visited[i] = false;
		selected.pop_back();
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				h.push_back(make_pair(i, j));
			if (board[i][j] == 2)
				ch.push_back(make_pair(i, j));
		}
	}
	solve(0, 0);
	cout << totalD;
}