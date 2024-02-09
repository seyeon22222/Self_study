#include <iostream>
#include <climits>
using namespace std;

// 블록 꺼내기 1초
// 블록 제거 2초


int n ,m, b;
int arr[501][501];
int ans = INT_MAX;
int res;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> b;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	for (int k = 0; k <= 256; ++k)
	{
		int stack = 0;
		int remove = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int temp_h = arr[i][j] - k;
				if (temp_h < 0)
					stack -= temp_h;
				else
					remove += temp_h;
			}
		}
		if (remove + b >= stack)
		{
			int temp_time = 2 * remove + stack;
			if (ans >= temp_time)
			{
				ans = temp_time;
				if (res < k)
					res = k;
			}
		}
	}
	cout << ans << " " << res;
}