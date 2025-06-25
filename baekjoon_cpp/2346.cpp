#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	int temp_val;
	for (int i = 0; i < N; ++i) {
		cin >> temp_val;
		v.push_back(temp_val);
	}

	vector<bool> check(N, false);
	int index = 0;
	int cnt = 0;
	while (cnt < N) {
		cout << index + 1 << " ";
		int m = v[index];
		check[index] = true;
		cnt++;

		if (cnt == N)
			break;
		
		if (m > 0) {
			for (int i = 0; i < m;) {
				index = (index + 1) % N;
				if (!check[index])
					i++;
			}
		} else {
			for (int i = 0; i < abs(m);) {
				index = (index - 1 + N) % N;
				if (!check[index])
					i++;
			}
		}
	}	

}