#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

int N, L, R;
int map[51][51];
int visited[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int sum, ans;
bool flag = true;
vector<pair<int, int>> v;

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
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && 
			abs(map[nx][ny] - map[tempX][tempY]) >= L && abs(map[nx][ny] - map[tempX][tempY]) <= R) {
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				v.push_back(make_pair(nx, ny));
				sum += map[nx][ny];
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
		
	while (flag) {
		flag = false;
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visited[i][j]) {
					v.clear();
					v.push_back(make_pair(i, j));
					visited[i][j] = 1;
					sum = map[i][j];
					bfs(i, j);
				}
				if (v.size() >= 2) {
					flag = true;
					for (int i = 0; i < v.size(); ++i) {
						map[v[i].first][v[i].second] = sum / v.size();
					}
				}
			}
		}
		if (flag)
			ans++;
	}
	cout << ans;
}