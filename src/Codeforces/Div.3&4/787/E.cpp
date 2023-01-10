/**
 * @author: XiaFan
 * @date: 05-07 19:27
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        set<char> st;
        for (int i = 0; i < n; i++) {
            while (s[i] > 'a' && m > 0) {
                if (!st.count(s[i])) {
                    st.insert(s[i]);
                    m--;
                }
                s[i]--;
            }
            while (st.count(s[i])) {
                s[i]--;
            }
        }
        cout << s << "\n";
    }

    return 0;
}