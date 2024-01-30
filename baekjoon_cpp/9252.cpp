#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];
string str = "";
string f_str;
string lcs;
int idx;

void print_LCS(int i, int j) {
    if(!dp[i][j]) return;
    if(f_str[i-1] == lcs[j-1]) {
        print_LCS(i-1, j-1);
        cout << f_str[i-1];
    }
    else {
        if(dp[i-1][j] > dp[i][j-1]) print_LCS(i-1, j);
        else print_LCS(i, j-1);
    }
}
int main()
{
	cin >> f_str >> lcs;
	for (int i = 1; i <= f_str.length(); i++)
	{
		for (int j = 1; j <= lcs.length(); j++)
		{
			if (f_str[i - 1] == lcs[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				
		}
	}
	cout << dp[f_str.length()][lcs.length()] << endl;
	print_LCS(f_str.length(), lcs.length());
}