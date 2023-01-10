/**
 * @author: XiaFan
 * @date: 11-27 20:37
 **/
#include <bits/stdc++.h>

using i64 = long long;

struct node {
    int id, x, y, z;
    node(int _id, int _x, int _y) : id(_id), x(_x), y(_y), z(y - x) {}
};

// p: problems
void solve(int p) {
    int a, t;
    std::cin >> a >> t;
    int nowa = 0, nowt = 0;
    std::vector<std::string> s(p);
    std::vector<node> q;
    
    std::cin.get();
    for (int i = 0; i < p; i++) {
        std::getline(std::cin, s[i]);

        char op = s[i][0];
        std::string res;
        
        if (s[i].size() > 1) res = s[i].substr(2);
        
        if (op == '+') {
            int sp = res.find('/');
            res[sp] = ' ';
            std::stringstream ss(res);
            int x, y;
            ss >> x >> y;
            nowa++;
            nowt += 20 * (x - 1) + y;
        } else if (op == '?') {
            std::stringstream ss(res);
            int x, y;
            ss >> x >> y;
            q.push_back(node(i, x, y));
        }
    }

    int fac = a - nowa; // frozen ac
    
    std::vector<int> select; // size: fac
    auto judge = [&]() -> bool {
        int left = t - nowt; // left time
        for (auto i : select) left -= q[i].z * 20 + 240;
        if (left < 0) return false;

        std::vector<std::pair<int, int>> temp(fac, {1, 240});

        for (int i = 0; i < fac; i++) {
            int j = select[i];
            int x = std::min(left / 20, q[j].x - 1);
            left -= 20 * x;
            temp[i].first += x;
        }

        for (int i = 0; i < fac; i++) {
            int j = select[i];
            int cost = std::min(left, 59);
            left -= cost;
            temp[i].second += cost;
        }

        if (left != 0) return false;

        for (int i = 0; i < fac; i++) {
            int j = select[i];
            auto [rx, rt] = temp[i];
            
            int rsub = rx + q[j].z;
            assert(q[j].z + 1 <= rsub && rsub <= q[j].y);
            // assert(240 <= rt && rt <= 299);
            
            int id = q[j].id;
            s[id] = "+ " + std::to_string(rsub) + '/' + std::to_string(rt);
        }

        return true;
    };

    bool ok = false;
    std::function<void(int, int)> dfs = [&](int step, int ac) {
        if (ac == fac) {
            ok |= judge();
            return;
        }
        if (step == (int)q.size()) {
            return;
        }

        select.push_back(step);
        dfs(step + 1, ac + 1);
        select.pop_back();
        if (ok) return;

        dfs(step + 1, ac);
    };

    dfs(0, 0);

    if (!ok) {
        std::cout << "No\n";
        return;
    }

    for (int i = 0; i < p; i++) {
        if (s[i][0] == '?') {
            std::stringstream ss;
            ss << s[i].substr(2);
            int x, y;
            ss >> x >> y;
            s[i] = "- " + std::to_string(y);
        }
    }

    std::cout << "Yes\n";
    for (const auto& it : s) {
        assert(!it.empty());
        std::cout << it << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    while (n--) {
        solve(m);
    }

    return 0;
}