#include <iostream>
#include <algorithm>
using namespace std;

int n,m, total_val;
int ray[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		ray[i] = x;
		total_val += x;
	}
	int max_val = *max_element(ray, ray + n);
	while (max_val <= total_val) {
		int mid = (max_val + total_val) / 2;
		int sum = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (sum + ray[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += ray[i];
		}
		if (sum != 0)
			cnt++;
		if (cnt > m) {
			max_val = mid + 1;
		}
		else
			total_val = mid - 1;
	}
	cout << max_val << "\n";
}