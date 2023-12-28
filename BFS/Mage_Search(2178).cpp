#include <iostream>
#include <queue>

int n,m;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(int x, int y)
{
    std::queue<std::pair<int, int> >  q;

    q.push({x, y});
    visited[x][y] = 1;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i< 4; i++)
        {
            int nx = dx[i] + a;
            int ny = dy[i] + b;
            if (nx < n && nx >= 0 && ny < m && ny >= 0 && !visited[nx][ny]
            && map[nx][ny])
            {
                visited[nx][ny] = visited[a][b] + 1;
                q.push({nx, ny});
            }
        }
    }
    int res = visited[n - 1][m - 1];
    return (res);
}

int main()
{
    int cnt = 0;
    std::cin >> n >> m;
    std::string str;
    for (int i = 0; i < n; i++)
    {
        std::cin >> str;
        for (int j = 0; j < m; j++)
            map[i][j] = str[j] - 48;
    }
    cnt = bfs(0, 0);
    std::cout << cnt << std::endl;
}