#include <iostream>
using namespace std;

int n,m;
int arr[5][5];
bool visited[5][5];
int min_val = 0;


// x,y 는 항상 중앙
// 1 1
//   1
int shape1(int y, int x)
{return ((arr[y][x] * 2) + arr[y + 1][x] + arr[y][x - 1]);}
// 1 1
// 1
int shape2(int y, int x)
{return ((arr[y][x] * 2) + arr[y][x + 1] + arr[y + 1][x]);}
// 1
// 1 1
int shape3(int y, int x)
{return ((arr[y][x] * 2) + arr[y - 1][x] + arr[y][x + 1]);}
//   1
// 1 1
int shape4(int y, int x)
{return ((arr[y][x] * 2) + arr[y - 1][x] + arr[y][x - 1]);}



void back(int y, int x, int val)
{
	if (x == m)
	{
		x = 0;
		y++;
	}
	if (y == n)
	{
		min_val = max(min_val, val);
		return ;
	}
	if (!visited[y][x])
	{
		// 1 1
		//   1
		if (x - 1 >= 0  && y + 1 < n && !visited[y + 1][x] && !visited[y][x - 1])
		{
			visited[y][x] = true;
			visited[y + 1][x] = true;
			visited[y][x - 1] = true;
			back(y, x + 1, val + shape1(y, x));
			visited[y][x] = false;
			visited[y + 1][x] = false;
			visited[y][x - 1] = false;
		}
		// 1 1
		// 1
		if (x + 1 < m && y + 1 < n && !visited[y][x + 1] && !visited[y + 1][x]) 
		{
			visited[y][x] = true;
			visited[y + 1][x] = true;
			visited[y][x + 1] = true;
			back(y, x + 1, val + shape2(y, x));
			visited[y][x] = false;
			visited[y + 1][x] = false;
			visited[y][x + 1] = false;
		}
		// 1
		// 1 1
		if (x + 1 < m && y - 1 >= 0 && !visited[y - 1][x] && !visited[y][x + 1])
		{
			visited[y][x] = true;
			visited[y - 1][x] = true;
			visited[y][x + 1] = true;
			back(y, x + 1, val + shape3(y, x));
			visited[y][x] = false;
			visited[y - 1][x] = false;
			visited[y][x + 1] = false;
		}
		//   1
		// 1 1
		if (x - 1 >= 0 && y - 1 >= 0 && !visited[y - 1][x] && !visited[y][x - 1])
		{
			visited[y][x] = true;
			visited[y - 1][x] = true;
			visited[y][x - 1] = true;
			back(y, x + 1, val + shape4(y, x));
			visited[y][x] = false;
			visited[y - 1][x] = false;
			visited[y][x - 1] = false;
		}
	}
	back(y, x + 1, val);
	return;
}

int main()
{
	clock_t start = clock();
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// n -> 세로
	// m -> 가로
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	if (n == 1 || m == 1)
	{
		cout << "0";
		exit(0);
	}
	back(0, 0, 0);
	cout << min_val << endl;
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;
}