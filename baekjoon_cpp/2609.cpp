#include <iostream>
#include <algorithm>
using namespace std;

int a,b;

int gcb(int x, int y)
{
	int c;
	while (y)
	{
		c = x % y;
		x = y;
		y = c;
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b;
	cout << gcb(a,b) << "\n";
	cout << (a * b) / gcb(a,b);
}