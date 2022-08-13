#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

typedef long long i64;

struct game {
    int s[9];
    int space;
    std::string op;
    game(int _space, int _s[9], std::string _op) : op(_op) {
        for(int i = 0; i < 9; i++) {
            s[i] = _s[i];
        }
        space = _space;
    }
};

const int hash_size = 362880;
int vis[hash_size] = {0};
const int factory[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool cantor(int s[9]) {
    long result = 0;
    for(int i = 0; i < 9; i++) {
        int counted = 0;
        for(int j = i + 1; j < 9; j++) {
            if(s[i] > s[j]) {
                counted++;
            }
        }
        result += counted * factory[8 - i];
    }
    if(vis[result]) {
        return false;
    } else {
        vis[result] = true;
        return true;
    }
}

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
char ops[4] = {'u', 'd', 'l', 'r'};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a[9], b[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int start = 0;
    for(int i = 0; i < 9; i++) {
        char c;
        std::cin >> c;
        if(c == 'x') {
            a[i] = 0;
            start = i;
        } else {
            a[i] = (c - '0');
        }
    }

    int cnt = 0;
    for(int i = 0; i < 9; i++) {
        if(a[i] == 0) continue;
        for(int j = i + 1; j < 9; j++) {
            if(a[j] == 0) continue;
            if(a[j] < a[i]) {
                cnt++;
            }
        }
    }
    if(cnt % 2 == 1) {
        std::cout << "unsolvable\n";
        return 0;
    }

    for(int i = 0; i < hash_size; i++) {
        vis[i] = 0;
    }

    cantor(a);
    std::queue<game> q;
    q.push(game(start, a, ""));
    while(!q.empty()) {
        game t = q.front();
        q.pop();

        bool ok = true;
        for(int i = 0; i < 9; i++) {
            if(t.s[i] != b[i]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            std::cout << t.op << '\n';
            return 0;
        }

        int x = t.space / 3;
        int y = t.space % 3;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) {
                continue;
            }

            int ns[9];
            for(int i = 0; i < 9; i++) {
                ns[i] = t.s[i];
            }
            int new_space = nx * 3 + ny;
            std::swap(ns[t.space], ns[new_space]);

            if(cantor(ns)) {
                q.push(game(new_space, ns, t.op + ops[i]));
            }
        }
    }
    return 0;
}