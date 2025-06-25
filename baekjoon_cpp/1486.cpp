#include <iostream>
using namespace std;

int map[26][26];
int N, M, T, D;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 높이가 낮거나 같은곳 -> 1
// 높이가 높은 곳 (낮은곳 - 높은곳)^2
// 인접합 곳에서 T보다 차이가 적으면 이동 가능

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char a;
			cin >> a;
			if ('A' <= a  && a <= 'Z')
				map[i][j] = a - 65;
			else if ('a' <= a && a <= 'z')
				map[i][j] = a - 71;
		}
	}

}
