#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <map>
using namespace std;

int t;
long long dp_min[101];
long long dp_max[101];
// {2, 5, 5, 4, 5, 6, 3, 7, 6, 6};
void min_fill() {
	dp_min[2] = 1;
	dp_min[3] = 7;
	dp_min[4] = 4;
	dp_min[5] = 2;
	dp_min[6] = 6;
	dp_min[7] = 8;
	dp_min[8] = 10;
	dp_min[9] = 18;
	dp_min[10] = 22;
	dp_min[11] = 20;
	dp_min[12] = 28;
	dp_min[13] = 68;
	for (int i = 14; i < 101; ++i) {
		if (i % 7 == 0) {
			int cnt = i / 7;
			dp_min[i] = 8;
			for (int x = cnt - 1; x > 0 ; --x) {
				dp_min[i] *= 10;
				dp_min[i] += 8;
			}
		}
		else if (i % 7 == 1) {
			int cnt = i / 7;
			dp_min[i] = 10;
			for (int x = cnt - 1; x > 0; --x) {
				dp_min[i] *= 10;
				dp_min[i] += 8;
			}
		}
		else if (i % 7 == 2) {
			int cnt = i / 7;
			dp_min[i] = 1;
			for (int x = cnt; x > 0; --x) {
				dp_min[i] *= 10;
				dp_min[i] += 8;
			}
		}
		else if (i % 7 == 3) {
			int cnt = i / 7;
			dp_min[i] = 200;
			for (int x = cnt - 2; x > 0; --x) {
				dp_min[i] *= 10;
				dp_min[i] += 8;
			}
		}
		else if (i % 7 == 4) {
			int cnt = i / 7;
			dp_min[i] = 20;
			for (int x = cnt - 1; x > 0; --x) {
				dp_min[i] *= 10;
				dp_min[i] += 8;
			}
		}
		else if (i % 7 == 5) {
			int cnt = i / 7;
			dp_min[i] = 2;
			for (int x = cnt; x > 0; --x) {
				dp_min[i] *= 10;
				dp_min[i] += 8;
			}
		}
		else if (i % 7 == 6) {
			int cnt = i / 7;
			dp_min[i] = 6;
			for (int x = cnt; x > 0; --x) {
				dp_min[i] *= 10;
				dp_min[i] += 8;
			}
		}
	}
}

void max_fill(int n) {
	
	string str;

	if (n % 2) {
		str = "7";
		int cnt = n / 2;
		for (int i = 0; i < cnt - 1; ++i) {
			str += "1";
		}
	} else {
		int cnt = n / 2;
		for (int i = 0; i < cnt; ++i) {
			str += "1";
		}
	}
	cout << str << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> t;
	min_fill();
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		cout << dp_min[n] << " ";
		max_fill(n);
	}
}

