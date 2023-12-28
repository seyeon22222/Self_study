#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n,m;
int map[1001][1001] = {0, };
int visited[1001][1001] = {0, };
queue<pair<int, int> > q;

void bfs(void)
{
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + a;
            int ny = dy[i] + b;
            if (nx < n && nx >= 0 && ny < m && ny >= 0
            && visited[nx][ny] == 0 && !map[nx][ny])
            {
                visited[nx][ny] = visited[a][b] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                q.push({i, j});
            else if (map[i][j] == -1)
                visited[i][j] = -1;
        }
    bfs();
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && map[i][j] == 0)
            {
                cout << "-1" << endl;
                return (-1);
            }
            cnt = max(cnt, visited[i][j]);
        }
    }
    cout << cnt << endl;
}

