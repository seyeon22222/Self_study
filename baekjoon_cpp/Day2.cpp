#include <iostream>
using namespace std;

string A;
string B;
string temp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> A >> B;
	
	for (int i = 0; i < A.length(); ++i) {
		temp += A[i];
		if (temp.length() >= B.length() && temp.substr(temp.length() - B.length()) == B) {
			temp.erase(temp.length() - B.length(), B.length());
		}
	}

	if (temp.length() == 0)
		cout << "FRULA";
	else
		cout << temp;
}