#include <bits/stdc++.h>

typedef long long i64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b;
    c = b + a;

    std::vector<int> pa(a + 1), pc(c + 1);
    for(int i = a; i >= 0; i--) {
        std::cin >> pa[i];
    }
    for(int i = c; i >= 0; i--) {
        std::cin >> pc[i];
    }

    std::vector<int> pb(b + 1);
    for(int i = 0; i <= b; i++) {
        pb[i] = pc[i] / pa[0];
        for(int j = 0; j <= a; j++) {
            pc[i + j] -= pa[j] * pb[i];
        }
    }

    for(int i = b; i >= 0; i--) {
        std::cout << pb[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}