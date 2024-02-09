#include <iostream>
#include <stack>
using namespace std;

int T;
string vps;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> vps;
        stack<char> st;
        bool is_valid = true;
        for (int a = 0; a < vps.length(); ++a) {
            if (vps[a] == '(') {
                st.push(vps[a]);
            } else {
                if (st.empty()) {
                    is_valid = false;
                    break;
                }
                st.pop();
            }
        }
        if (is_valid && st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
