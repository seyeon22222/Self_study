#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

void check(int num)
{
    if (num <= 1)
        return ;
    for (int i = 2; i * i <= num; ++i)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= num; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> m >> n;
    fill(arr, arr + 1000001, 1);
    check(n);
    for (int i = m; i <= n; ++i)
    {
        if (i == 1)
            continue;
        if (arr[i])
            cout << i << "\n";
    }
}