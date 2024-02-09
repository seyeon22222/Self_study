#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> arr;

void func()
{
	int num;
	int cnt = 0;
	while (!arr.empty())
	{
		if (arr.size() == 1)
		{
			num = arr.front();
			arr.pop();
			cout << num;
			return ;	
		}
		num = arr.front();
		arr.pop();
		cnt++;
		if (cnt == k)
		{
			cnt = 0;
			cout << num << ", ";
		}
		else
			arr.push(num);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		arr.push(i);
	cout << "<";
	func();
	cout << ">";
}
