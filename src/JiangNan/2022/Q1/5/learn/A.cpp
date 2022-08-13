#include <bitset>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

typedef long long i64;
typedef std::bitset<20> bit;

struct quantum {
    bit w;
    int c;
    quantum(bit _w, int _c) : w(_w), c(_c) {}
    friend bool operator<(const quantum &lhs, const quantum &rhs) {
        return lhs.c > rhs.c;
    }
};

struct op {
    std::string s;
    int c;
};

const int len = 1 << 20;
const int inf = 1e9;
int mnc[len];
bool vis[len];

int count(int n, int np, std::vector<op> &p) {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    bit w1(s1), w2(s2);

    std::priority_queue<quantum> q;
    q.push(quantum(w1, 0));

    for(int i = 0; i < len; i++) {
        mnc[i] = inf;
        vis[i] = false;
    }

    while(!q.empty()) {
        quantum t = q.top();
        q.pop();

        if(t.w == w2) {
            return t.c;
        }
        vis[t.w.to_ulong()] = true;

        for(int i = 0; i < np; i++) {
            bit nw = t.w;
            int nc = t.c + p[i].c;

            for(int j = 0; j < n; j++) {
                char ss = p[i].s[n - 1 - j];
                if(ss == 'F') {
                    nw[j] = !nw[j];
                } else if(ss == 'S') {
                    nw[j] = 1;
                } else if(ss == 'C') {
                    nw[j] = 0;
                }
            }

            int num = nw.to_ulong();
            if(!vis[num] && mnc[num] > nc) {
                mnc[num] = nc;
                q.push(quantum(nw, nc));
            }
        }
    }
    return -1;
}

void solve() {
    int n, np, nw;
    std::cin >> n >> np >> nw;

    std::vector<op> p(np);
    for(int i = 0; i < np; i++) {
        std::string top;
        std::cin >> p[i].s >> p[i].c;
    }

    for(int i = 0; i < nw; i++) {
        int c = count(n, np, p);
        if(c == -1) {
            std::cout << "NP ";
        } else {
            std::cout << c << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}