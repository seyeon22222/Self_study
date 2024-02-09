#include <iostream>
#include <map>
using namespace std;

int n, m;
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    int k;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        mp[k]++;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        cout << mp[k] << " ";
    }

    return 0;
}
