#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n;
vector<pair<double, double>> vec;
double ans;

double cal(int i, int j)
{
	
	int x1 = vec[0].first; // a
	int x2 = vec[i].first; // c
	int x3 = vec[j].first; // e

	int y1 = vec[0].second; // b
	int y2 = vec[i].second; // d
	int y3 = vec[j].second; // f

	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		double x, y;
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	for (int i = 1; i < n - 1; ++i)
		ans += cal(i, i + 1);	
	cout << fixed;
	cout.precision(1);
	cout << abs(ans) << endl;
}