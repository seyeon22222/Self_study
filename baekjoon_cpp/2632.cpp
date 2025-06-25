#include <iostream>
#include <vector>
#include <map>
using namespace std;

int buy, m,n, ans;
int A[1004], B[1004];
vector<int>	sum_A;
vector<int>	sum_B;
map<int, int>	cnt_A;
map<int, int>	cnt_B;

void solve() {
	for (int i = 0; i < m; ++i) {
		int idx = i;
		int temp_sum = 0;
		for (int j = 1; j < m; ++j) {
			temp_sum += A[idx];
			sum_A.push_back(temp_sum);
			idx = (idx + 1) % m;
		}
	}

	for (int i = 0; i < n; ++i) {
		int idx = i;
		int temp_sum = 0;
		for (int j = 1; j < n; ++j) {
			temp_sum += B[idx];
			sum_B.push_back(temp_sum);
			idx = (idx + 1) % n;
		}
	}

	for (int i = 0; i < sum_A.size(); ++i) {
		cnt_A[sum_A[i]]++;
	}

	for (int i = 0; i < sum_B.size(); ++i) {
		cnt_B[sum_B[i]]++;
	}

	map<int, int>::iterator it = cnt_A.begin();
	int modulo = 0;
	for (; it != cnt_A.end(); ++it) {
		modulo = buy - it->first;
		if (it->first == buy) {
			ans += it->second;
		}
		else if (cnt_B[modulo]) {
			ans += (it->second * cnt_B[modulo]);
		}
		
	}

	it = cnt_B.begin();
	for (; it != cnt_B.end(); ++it) {
		if (it->first == buy)
			ans += it->second;
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> buy >> m >> n;

	int temp_sum = 0;
	for (int i = 0; i < m; ++i) {
		cin >> A[i];
		temp_sum += A[i];
	}
	sum_A.push_back(temp_sum);

	temp_sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> B[i];
		temp_sum += B[i];
	}
	sum_B.push_back(temp_sum);

	solve();
	cout << ans;
}