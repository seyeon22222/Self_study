#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n, maxV;
int arr[1000001];
int ans[1000001];
stack<pair<int, int>> temp;

void check()
{
	temp.push(make_pair(arr[0], 0));
	for (int i = 1; i < n; ++i) {
		while (!temp.empty()) {
			int val = temp.top().first;
			int idx = temp.top().second;
			if (arr[i] > val) {
				temp.pop();
				ans[idx] = arr[i];
			}
			else
				break;
		}
		temp.push(make_pair(arr[i], i));
	}
	while (!temp.empty()) {
		int idx = temp.top().second;
		temp.pop();
		ans[idx] = -1;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	check();
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
}