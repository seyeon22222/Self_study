#include <iostream>
#include <algorithm>
using namespace std;

int a, k;
int *A;
int *tmp;
int cnt = 0;

void merge(int A[], int p, int q, int r) {

	int i = p;
	int j = q + 1;
	int t = 1;
	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}

	while (i <= q)
		tmp[t++] = A[i++];
	while (j <= r)
		tmp[t++] = A[j++];
	i = p;
	t = 1;
	while (i <= r) {
		A[i++] = tmp[t++];
		cnt++;
		if (cnt == k) {
			cout << A[i - 1];
		}
	}
}


void merge_sort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	
	cin >> a >> k;

	A = new int[a + 1];
	tmp = new int[a + 1];
	for (int i = 0; i < a; ++i) {
		cin >> A[i];
	}
	merge_sort(A, 0, a - 1);

	if (cnt < k)
		cout << -1;
}