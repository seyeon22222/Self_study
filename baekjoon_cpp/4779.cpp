#include <iostream>
#include <algorithm>
using namespace std;

void cantor(int n) {
	int len = pow(3, n - 1);
	if (n == 0) {
		cout << "-";
		return ;
	}
	cantor(n - 1);
	for (int i = 0; i < len; ++i) {
		cout << " ";
	}
	cantor(n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int N;
	while (cin >> N) {
		cantor(N);
		cout << "\n";
	}
}