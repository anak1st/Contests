#include <iostream>

const int max_len = 500000 * 3 + 1;
// x      ->
// x +  n -> x 猎物
// x + 2n -> x 天敌

int n, k, fake = 0;
int a[max_len];

int find(int x) {
    if(a[x] != x) {
        a[x] = find(a[x]);
    }
    return a[x];
}

void unity(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    a[fx] = fy;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;
    for(int i = 1; i <= 3 * n; i++) a[i] = i;

    while(k--) {
        int p, x, y;
        std::cin >> p >> x >> y;

        if(x > n || y > n) {
            fake++;
            continue;
        }

        if(p == 1) {
            if(find(x + n) == find(y) || find(x + 2 * n) == find(y)) {
                fake++;
                continue;
            }

            unity(x, y);
            unity(x + n, y + n);
            unity(x + 2 * n, y + 2 * n);
        } else {
            if(x == y) {
                fake++;
                continue;
            }

            if(find(x) == find(y) || find(x + 2 * n) == find(y)) {
                fake++;
                continue;
            }

            unity(x + n, y);
            unity(x, y + 2 * n);
            unity(x + 2 * n, y + n);
        }
    }
    std::cout << fake << '\n';

    return 0;
}