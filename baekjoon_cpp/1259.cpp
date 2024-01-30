#include <iostream>
#include <string>
using namespace std;

bool check(string str)
{
	size_t slen = str.length();
	for (int i = 0; i < slen / 2; i++)
	{
		if (str[i] != str[slen - i - 1])
			return false;
	}
	return true;
}


int main()
{
	string n;
	while (1)
	{
		cin >> n;
		if (n == "0")
			break;
		if (check(n))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}