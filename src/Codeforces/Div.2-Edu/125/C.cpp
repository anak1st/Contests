#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string str;
    std::cin >> str;

    int ans = 0, p = -1;
    for(int i = 0; i + 1 < n; i += 2) {
        if(str[i] == str[i + 1]) {
            ans++;
            p = i + 1;
        } else if(str[i] == '(' && str[i + 1] == ')') {
            ans++;
            p = i + 1;
        } else if(str[i] == ')' && str[i + 1] == '(') {
            int good = 0;
            for(int j = i + 2; j < n; j++) {
                if(str[j] == ')') {
                    good = j;
                    break;
                }
            }
            if(good) {
                ans++;
                i = good - 1;
                // i = good + 1 after += 2 !!!
                p = good;
            } else {
                break;
            }
        }
    }

    std::cout << ans << ' ' << n - 1 - p << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}