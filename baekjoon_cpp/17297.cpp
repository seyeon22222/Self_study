#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int arr[41];
int M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> M;
	arr[0] = 0;
	arr[1] = 5;
	arr[2] = 13;
	for (int i = 3; i <= 40; ++i)
		arr[i] = arr[i - 1] + arr[i - 2] + 1;
	M -= 1;
	for (int i = 40; i >= 2; --i) {
		if (M >= arr[i])
			M -= (arr[i] + 1);
	}
	string str = "Messi Gimossi";
	if (M == 5 || M == -1)
		cout << "Messi Messi Gimossi";
	else
		cout << str[M];
}
