#include <iostream>
#include <algorithm>
using namespace std;

int arr[10002];
int arr2[10002];
int ans[10002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	string A, B;
	cin >> A >> B;
	size_t A_len = A.length();
	size_t B_len = B.length();
	size_t long_len = max(A_len, B_len);
	
	for (size_t i = 0; i < A_len; ++i) {
		arr[A_len - i - 1] = A[i] - '0';
	}
	for (size_t i = 0; i < B_len; ++i) {
		arr2[B_len - i - 1] = B[i] - '0';
	}
	
	bool flag = false;
	for (size_t i = 0; i < long_len; ++i) {
		int temp_sum = arr[i] + arr2[i];
		if (flag) {
			flag = false;
			temp_sum++;
		}
		if (temp_sum >= 10) {
			flag = true;
			temp_sum -= 10;
		}
		ans[i] = temp_sum;
	}

	if (flag) {
		ans[long_len] = 1;
		++long_len;
	}

	for (int i = long_len - 1; i >= 0; --i) {
		cout << ans[i];
	}
	
}