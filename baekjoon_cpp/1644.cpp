#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<bool>	check;
vector<int>		prime;
int res;

void Eratos(int num)
{
	if (num <= 1)
		return ;
	check.resize(n + 1, true);
	for (int i = 2; i * i <= n; ++i)
	{
		if (check[i])
		{
			for (int j = i * i; j <= n; j += i)
				check[j] = false;
		}
	}
	check[0] = false;
	check[1] = false;
	for (int i = 0; i < check.size(); ++i)
	{
		if (check[i])
			prime.push_back(i);
	}
}

void TwoPointer(int num)
{
	if (num <= 1)
		return ;
	int start = 0;
	int end = 0;
	int sum = 0;
	cout << prime.size() << endl;
	for (; start <= prime.size(); start++)
	{
		sum = 0;
		end = start;
		while (sum < num && end <= prime.size())
		{
			sum += prime[end];
			end++;
		}
		if (sum == num)
			res++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	Eratos(n);
	TwoPointer(n);
	cout << res;	
}