/**
 * @author: XiaFan
 * @date: 05-24 00:13
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

string fun(string s, int x) {
    int j = 0;
    for (int i = 0; i < int(s.length()); i++) {
        j += x * (s[i] - '0');
        s[i] = '0' + j % 10;
        j /= 10;
    }
    if (j > 0) {
        s.push_back('0' + j);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    queue<pair<int, string>> q;
    set<string> st;
    q.push({0, s});
    while (!q.empty()) {
        auto [step, temp] = q.front();
        if (int(temp.length()) >= n) {
            break;
        }
        q.pop();
        for (auto c : temp) {
            if (c <= '1') {
                continue;
            }
            string next = fun(temp, c - '0');
            if (!st.count(next)) {
                st.insert(next);
                q.push({step + 1, next});
            }
        }
    }
    auto [ans, final] = q.front();
    if (int(final.length()) >= n) {
        cout << ans;
    } else {
        cout << -1;
    }

    return 0;
}