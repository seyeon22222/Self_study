using namespace std;
#include <iostream>
#include <algorithm>

int main()
{
	int num[3];

	for (int i=0; i< 3; i++)
		cin >> num[i];
	sort(num, num + 3);
	for (int i=0; i< 3; i++)
		cout << num[i] << " ";
}