#include <iostream>
using namespace std;


int n, k;

int factorial(int num)
{
	if (num == 0)
		return 1;
	int sum = 1;
	for (int i = 1; i <= num; i++)
		sum *= i;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	cout << factorial(n) / (factorial(k) * factorial(n - k));
}