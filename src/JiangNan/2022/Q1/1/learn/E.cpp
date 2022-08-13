#include <iostream>

const int maxLen = 100000 * 2 + 114514;

int n, k;
int a[maxLen];

int find(int x) {
    if(a[x] != x) {
        a[x] = find(a[x]);
    }
    return a[x];
}

void unity(int x, int y) {
    int fx = find(a[x]);
    int fy = find(a[y]);
    a[fx] = fy;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        std::cin >> n >> k;
        for(int i = 1; i <= 2 * n; i++) a[i] = i;

        while(k--) {
            char op;
            int x, y;
            std::cin >> op >> x >> y;

            if(op == 'D') {
                unity(x + n, y);
                unity(x, y + n);
            } else {
                if(find(x) == find(y + n)) {
                    printf("In different gangs.\n");
                } else if(find(x) == find(y)) {
                    printf("In the same gang.\n");
                } else {
                    printf("Not sure yet.\n");
                }
            }
        }
    }

    return 0;
}