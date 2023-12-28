#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sudoku[9][9] = {0};
int pair_size = 0;
bool finish = false;
vector<pair<int, int> > blank;

bool check(int i, int j, int value)
{
    // 행, 열 확인
    for (int a = 0; a < 9; a++)
    {
        if (sudoku[a][j] == value)
            return false;
        if (sudoku[i][a] == value)
            return false;
    }
    // 3X3 정사각형 확인
    int div_x = i / 3;
    int div_y = j / 3;
    div_x = div_x * 3;
    div_y = div_y * 3;
    for (int a = div_x; a < div_x + 3; a++)
        for (int b = div_y; b < div_y + 3; b++)
            if (sudoku[a][b] == value)
                return false;
    return true;
}

void back(int position)
{
    if (position == pair_size)
    {
        finish = true;
        return ;
    }
    int nx = blank[position].first;
    int ny = blank[position].second;
    for (int i = 1; i <= 9; i++)
    {
        if (check(nx, ny, i))
        {
            sudoku[nx][ny] = i;
            back(position + 1);
            if (finish)
                return ;
            sudoku[nx][ny] = 0;
        }
    }
}

int main()
{
    
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                blank.push_back( {i, j} );
        }
    pair_size = blank.size();
    back(0);
    // 출력
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
        cout << endl;
    }
}