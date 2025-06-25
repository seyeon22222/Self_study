#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	cout << &v[1] << " " << v[1] << "\n";
	v.erase(v.begin() + 1);
	cout << &v[1] << " " << v[1] << "\n";

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";
}