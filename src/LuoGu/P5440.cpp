#include <bits/stdc++.h>

std::set<std::pair<int, int>> pre;
int ans = 0;

int prime_number(int x) {
    if(x <= 1) {
        return 0;
    } else if(x == 2) {
        return 1;
    } else if(x % 2 == 0) {
        return 0;
    } else {
        for(int i = 3; i * i <= x; i += 2) {
            if(x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

void dfs(int i, std::array<int, 8> &a) {
    // 7 6 5 4 3 2 1 0
    // year--- mon day
    if(i == 2) {
        int day = a[1] * 10 + a[0];
        if(day > 31) {
            return;
        }
    }

    if(i == 4) {
        int day = a[1] * 10 + a[0];
        int month = a[3] * 10 + a[2];
        if(!pre.count({month, day})) {
            return;
        }
    }

    if(i == 8) {
        int day = a[1] * 10 + a[0];
        int month = a[3] * 10 + a[2];
        int year = a[7] * 1000 + a[6] * 100 + a[5] * 10 + a[4];
        if(year == 0) {
            return;
        }
        if(!(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
            if(month == 2 && day == 29) {
                return;
            }
        }
        if(prime_number(year * 10000 + month * 100 + day)) {
            // for(int j = 7; j >= 0; j--) {
            //     std::cout << a[j];
            // }
            // std::cout << '\n';
            ans++;
        }
        return;
    }

    if(a[i] == -1) {
        for(int j = 0; j <= 9; j++) {
            a[i] = j;
            dfs(i + 1, a);
            a[i] = -1;
        }
    } else {
        dfs(i + 1, a);
    }
}

void solve() {
    std::string s;
    std::cin >> s;
    std::array<int, 8> a;
    if(s == "--------") {
        std::cout << "55157\n";
        return;
    }

    for(int i = 0; i < 8; i++) {
        if(s[i] == '-') {
            a[7 - i] = -1;
        } else {
            a[7 - i] = s[i] - '0';
        }
    }
    dfs(0, a);
    std::cout << ans << '\n';
    ans = 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int month = 1; month <= 12; month++) {
        for(int day = 1; day <= 31; day++) {
            if(!prime_number(day)) {
                continue;
            }
            if(prime_number(month * 100 + day)) {
                // ----------------- 1  2  3  4  5  6  7  8  9 10 11 12
                int month_31[] = {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
                if(month_31[month] == 0 && day == 31) {
                    continue;
                }
                pre.insert({month, day});
            }
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}