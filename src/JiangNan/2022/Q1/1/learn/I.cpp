#include <algorithm>
#include <iostream>
#include <vector>

// Computer
struct C {
    int x, y;
    int index;
    int good;
};

int n, d;
std::vector<C> c(2022);

int find(int x) {
    if(c[x].index != x) {
        c[x].index = find(c[x].index);
    }
    return c[x].index;
}

void unity(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    c[fx].index = fy;
}

int dist(int a, int b) {
    int judge = 0;
    judge += (c[a].x - c[b].x) * (c[a].x - c[b].x);
    judge += (c[a].y - c[b].y) * (c[a].y - c[b].y);
    judge -= d * d;

    if(judge <= 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        std::cin >> c[i].x >> c[i].y;
        c[i].index = i;
        c[i].good = 0;
    }

    char op;
    int r;
    int t1, t2;

    while(std::cin >> op) {
        if(op == 'O') {
            std::cin >> r;
            c[r].good = 1;

            for(int i = 1; i <= n; i++) {
                if(i == r) continue;

                if(c[i].good && dist(r, i)) {
                    unity(r, i);
                }
            }
        } else {
            std::cin >> t1 >> t2;

            if(find(t1) == find(t2)) {
                std::cout << "SUCCESS\n";
            } else {
                std::cout << "FAIL\n";
            }
        }
    }

    return 0;
}