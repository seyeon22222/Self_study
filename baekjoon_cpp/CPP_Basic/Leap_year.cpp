using namespace std;
#include <iostream>

int main()
{
	int a;

	cin >> a;
	if (a % 4 == 0)
	{
		if ((a % 100 != 0) || (a % 400 == 0))
		{
				cout << "1";
				return (0);		
		}
	}
	cout << "0";
}