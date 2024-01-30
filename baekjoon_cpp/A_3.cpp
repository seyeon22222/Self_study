#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int cnt_a = 0;
	int cnt_b = 0;
	int cnt_c = 0;
	int res = 0;
	int sol = 100000000;
	int ptr1 = 0;
	int ptr2 = 0;
	cin >> n;
	vector<pair <int, int> > a;
	pair<int, int> b;
	for (int i = 0; i < n; i++)
	{
		cin >> b.first >> b.second;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	ptr1 = 0;
	ptr2 = 0;
	int temp_bot = 0;
	int temp_middle = 0;
	int temp_val = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		if (a[i + 1].second > a[i].second)
		{
			ptr2 = i;
		}
		if (a[i + 1].second < a[i].second)
		{
			ptr1 = i;
		}
		// if (ptr1 > ptr2)
		// 	continue;
		cnt_a = ptr1;
		cnt_b = ptr2 - ptr1;
		cnt_c = n - cnt_a - cnt_b;
		// if (cnt_a == 0 || cnt_b == 0 || cnt_c == 0)
		// 	sol = -1;
		cout << "ptr : " << ptr1 << " " << ptr2 << endl;
		cout << "cnt : "<< cnt_a << " " << cnt_b << " " << cnt_c <<endl;
		res = max(max(cnt_a, cnt_b), cnt_c) - min(min(cnt_a, cnt_b), cnt_c);
		sol = min(sol, res);
	}
	cout << sol;
}
