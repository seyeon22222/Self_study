#include <iostream>
using namespace std;

int a,b,c;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	a = 1;
	b = 1;
	c = 1;
	while (a != 0 && b != 0 && c != 0)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			continue;
		if (a * a + b * b == c * c)
			cout << "right\n";
		else if (a * a == b * b + c * c)
			cout << "right\n";
		else if (a * a + c * c == b * b)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}