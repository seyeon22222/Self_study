#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 2147483647

long n;
long arr[5002];
long comp = MAX;
long res, res1, res2;

void check(void)
{
    for (long i = 1; i <= n - 2; ++i)
    {
        long start = i + 1;
        long end = n;
        while (start < end)
        {
            long sum = arr[i] + arr[start] + arr[end];
            if (abs(sum) < comp)
            {
                comp = abs(sum);
                res = arr[i];
                res1 = arr[start];
                res2 = arr[end];
            }
            if (sum < 0)
                start++;
            else
                end--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (long i = 1; i <= n; ++i)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    check();

    vector<long> v = {res, res1, res2};
    sort(v.begin(), v.end());

    for (long i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    return 0;
}
