#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
const int MAX = 501;
int map[MAX][MAX] = {0 ,};
int visited[MAX][MAX] = {0 ,};
int max_v = 0;
int n, m;

void bfs(int x, int y)
{
    int max = 0;

    queue<pair<int, int> >  q;
    q.push({x, y});
    visited[x][y] = 1;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        max += 1;
        for (int j = 0; j < 4; j++)
        {
            int nx = dx[j] + a;
            int ny = dy[j] + b;
            if ((nx < n && nx >= 0) && (ny < m && ny >= 0)
            && visited[nx][ny] == 0 && map[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
                
        }
    }
    max_v = std::max(max, max_v);
}

int main()
{
    
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] && !visited[i][j])
            {
                cnt++;
                bfs(i, j);
            }
    cout << cnt << endl << max_v << endl;
}