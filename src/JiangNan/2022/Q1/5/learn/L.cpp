#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

typedef long long i64;

struct ops {
    int op, pot;
    ops(int _op, int _pot) {
        op = _op, pot = _pot;
    }
    // 0 : FILL(i)
    // 1 : DROP(i)
    // 2 : POUR(i,j)
    void out() {
        switch(op) {
        case 0:
            std::cout << "FILL(" << pot + 1 << ")\n";
            break;
        case 1:
            std::cout << "DROP(" << pot + 1 << ")\n";
            break;
        case 2:
            std::cout << "POUR(" << pot + 1 << "," << 2 - pot << ")\n";
            break;
        }
    }
};
typedef std::vector<ops>::iterator v_ops_it;

struct pots {
    int pot[2];
    std::vector<ops> p;
    pots(int _a, int _b) {
        pot[0] = _a, pot[1] = _b;
    }
};

int vis[128][128];
int potmax[2], c;

void bfs() {
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            vis[i][j] = -1;
        }
    }

    std::queue<pots> q;
    q.push(pots(0, 0));
    vis[0][0] = 0;
    while(!q.empty()) {
        pots cur = q.front();
        q.pop();

        // std::cerr << cur.p.size() << '\n';
        if(cur.pot[0] == c || cur.pot[1] == c) {
            std::cout << cur.p.size() << '\n';
            for(v_ops_it it = cur.p.begin(); it < cur.p.end(); it++) {
                // std::cerr << it->op << '\n';
                it->out();
            }
            return;
        }

        for(int i = 0; i < 6; i++) {
            pots next = cur;
            int op = i / 2;
            int p = i % 2;
            if(op == 0) {
                next.pot[p] = potmax[p];
            } else if(op == 1) {
                next.pot[p] = 0;
            } else {
                if(next.pot[p] > potmax[!p] - next.pot[!p]) {
                    next.pot[p] -= (potmax[!p] - next.pot[!p]);
                    next.pot[!p] = potmax[!p];
                } else {
                    next.pot[!p] += next.pot[p];
                    next.pot[p] = 0;
                }
            }

            if(vis[next.pot[0]][next.pot[1]] != -1) {
                continue;
            }
            vis[next.pot[0]][next.pot[1]] = 1;
            // std::cerr << next.pot[0] << ' ' << next.pot[1] << '\n';

            next.p.push_back(ops(op, p));
            q.push(next);
        }
    }

    std::cout << "impossible\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> potmax[0] >> potmax[1] >> c;
    bfs();

    return 0;
}