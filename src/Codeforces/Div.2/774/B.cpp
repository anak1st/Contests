#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    std::cin >> test_cases;
    while(test_cases--) {
        int n;
        std::cin >> n;
        std::vector<int> input(n);
        for(auto &it : input) std::cin >> it;

        std::sort(input.begin(), input.end());

        i64 a = 0, b = 0;

        int c = n / 2;
        int d = c + 1;

        if(n % 2 == 0) c--;

        for(int i = 0; i <= c; i++) a += input[i];
        for(int i = d; i < n; i++) b += input[i];

        if(a < b) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}