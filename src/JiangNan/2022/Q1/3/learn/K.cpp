#include <bits/stdc++.h>

bool judge(int time, std::string t, std::string &p, std::vector<int> &a) {
    int lent = t.length();
    int lenp = p.length();
    for(int i = 0; i < time; i++) {
        t[a[i] - 1] = '*';
    }
    // std::cerr << t << ':' << time << '\n';
    for(int i = 0, j = 0; i < lent && j < lenp; i++) {
        if(t[i] == p[j]) {
            j++;
        }
        if(j == lenp) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string t, p;
    std::cin >> t >> p;
    int lent = t.length();
    std::vector<int> a(lent);
    for(int i = 0; i < lent; i++) {
        std::cin >> a[i];
    }
    int left = 0, right = lent, ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(judge(mid, t, p, a)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    std::cout << ans << '\n';

    return 0;
}