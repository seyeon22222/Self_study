#include <iostream>
#include <queue>
using namespace std;

int r,c;
int map[1001][1001] = {0, };
int visited[1001][1001] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > f_q;
queue<pair<int, int> > p_q;
void bfs_f(void)
{
    while (!f_q.empty())
    {
        int a = f_q.front().first;
        int b = f_q.front().second;
        f_q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + a;
            int ny = dy[i] + b;
            if (nx < r && nx >= 0 && ny < c && ny >= 0 &&
            !visited[nx][ny])
            {
                visited[nx][ny] = visited[a][b] + 1;
                f_q.push({nx, ny});
            }
        }
    }
}

int bfs_p(void)
{
    while (!p_q.empty())
    {
        int a = p_q.front().first;
        int b = p_q.front().second;
        p_q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + a;
            int ny = dy[i] + b;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                return (map[a][b]);
            if (nx < r && nx >= 0 && ny < c && ny >= 0 && !map[nx][ny]
             && (!visited[nx][ny] || map[a][b] + 1 < visited[nx][ny]))
            {
                map[nx][ny] = map[a][b] + 1;
                p_q.push({nx, ny});
            }
        }
    }
    return (-1);
}

int main()
{
    cin >> r >> c;
    string str;
    for (int i = 0; i < r; i++)
    {
        std::cin >> str;
        for (int j = 0; j < c; j++)
        {
            if (str[j] == '#')
            {
                map[i][j] = -1;
                visited[i][j] = -1;
            }
            else if (str[j] == 'J')
            {
                p_q.push({i, j});
                map[i][j] = 1;
            }
            else if (str[j] == 'F')
            {
                f_q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    bfs_f();
    int res = bfs_p();
    if (res == -1)
    {
        cout << "IMPOSSIBLE";
        return (0);
    }
    cout << res;
    return (0);
}