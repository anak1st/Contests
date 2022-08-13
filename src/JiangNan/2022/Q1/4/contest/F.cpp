#include <bits/stdc++.h>

typedef long long i64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a;
    i64 b = 1;
    for(int i = 0; i < n; i++) {
        if(std::gcd(i, n) == 1) {
            a.push_back(i);
            b = (b * i) % n;
        }
    }

    if(b % n == 1) {
        std::cout << a.size() << '\n';
        for(auto it : a) {
            std::cout << it << ' ';
        }
    } else {
        std::cout << a.size() - 1 << '\n';
        int remove = b % n;
        for(auto it : a) {
            if(it == remove) {
                continue;
            }
            std::cout << it << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}