#include <iostream>
using namespace std;

int arr[8];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7];
	if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5 && arr[5] == 6 && arr[6] == 7 && arr[7] == 8)
		cout << "ascending";
	else if (arr[0] == 8 && arr[1] == 7 && arr[2] == 6 && arr[3] == 5 && arr[4] == 4 && arr[5] == 3 && arr[6] == 2 && arr[7] == 1)
		cout << "descending";
	else
		cout << "mixed";
}