#include <iostream>
using namespace std;


int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    int cnt = 0;
    cnt = (n / 5) + (n / 25) + (n / 125);
    cout << cnt;
}