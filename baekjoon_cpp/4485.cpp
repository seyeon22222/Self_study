#include <iostream>
#include <queue>
#include <ctype.h>
#include <algorithm>
using namespace std;

int N;
int _map[126][126];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


void bfs(int cnt) {
	queue<pair<int, int>> q;
	int visited[126][126];
	fill(&visited[0][0], &visited[0][0] + 126 * 126, 987654321);
	q.push(make_pair(0, 0));
	visited[0][0] = _map[0][0];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (visited[nx][ny] > visited[x][y] + _map[nx][ny]) {
					visited[nx][ny] = visited[x][y] + _map[nx][ny];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	cout << "Problem " << cnt << ": " << visited[N - 1][N - 1] << "\n";
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int cnt = 1;
	while (1) {
		cin >> N;
		if (N == 0) {
			break;
		}
		else {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					cin >> _map[i][j];
				}
			}
		}
		bfs(cnt);
		cnt++;
	}
}


/*
3
5 5 4
3 9 1
3 2 7
0
*/