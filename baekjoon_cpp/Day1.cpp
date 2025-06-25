#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

long cal1(long val) {
	return val * 2;
}

long cal2(long val) {
	return ((val * 10 )+ 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long A, B;

	cin >> A >> B;

	queue<pair<long, int>> q;
	q.push(make_pair(A, 1));
	
	int res = INT_MAX;
	while (!q.empty()) {
		long x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == B) {
			res = min(res, cnt);
			break;
		}
		if (x >= B)
			continue;
		long nx = cal1(x);
		long nx2 = cal2(x);
		if (nx <= 1000000000) {
			q.push(make_pair(nx, cnt + 1));
		}
		if (nx2 <= 1000000000) {
			q.push(make_pair(nx2, cnt + 1));
		}
		
	}
	if (res == INT_MAX)
		cout << -1;
	else
		cout << res;
}


