#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
char map[51][51];
int visited[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	while (!q.empty()) {
		int tempX = q.front().first;
		int tempY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = tempX + dx[i];
			int ny = tempY + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && map[nx][ny] == 'L') {
				visited[nx][ny] = visited[tempX][tempY] + 1;
				q.push(make_pair(nx, ny));
				ans = max(ans, visited[nx][ny]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); ++j) {
			map[i][j] = str[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 'L') {
				fill(&visited[0][0], &visited[0][0] + 50 * 51, 0);
				bfs(i, j);
			}
		}
	}
	cout << ans - 1;
}