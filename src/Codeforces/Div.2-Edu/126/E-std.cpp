#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<string> s(3);
    for(int i = 0; i < 3; i++) {
        std::cin >> s[i];
    }
    std::vector<int> pr(n + 1);
    for(int i = 0; i < n; i++) {
        pr[i + 1] += pr[i];
        for(int j = 0; j < 3; j++) {
            pr[i + 1] += (s[j][i] - '0');
        }
    }

    std::vector<int> f(3 * n), rk(3 * n, 1);
    std::iota(f.begin(), f.end(), 0);

    std::function<int(int)> find = [&](int a) -> int {
        if(f[a] != a) {
            f[a] = find(f[a]);
        }
        return f[a];
    };

    auto unite = [&](int a, int b) -> bool {
        a = find(a), b = find(b);
        if(a == b) {
            return false;
        }
        if(rk[a] < rk[b]) {
            swap(a, b);
        }
        f[b] = a;
        rk[a] += rk[b];
        return true;
    };

    std::vector<int> prhe(n + 1), prve(n + 1);

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < 2; i++) {
            if(s[i][j] == '1' && s[i + 1][j] == '1' && unite(i * n + j, (i + 1) * n + j)) {
                prve[j + 1]++;
            }
        }
        for(int i = 0; i < 3; i++) {
            if(j > 0 && s[i][j] == '1' && s[i][j - 1] == '1' && unite(i * n + j, i * n + (j - 1))) {
                prhe[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        prve[i + 1] += prve[i];
        prhe[i + 1] += prhe[i];
    }

    std::vector<int> nxt(n + 1, 0);
    for(int i = n - 1; i >= 0; --i) {
        if(s[0][i] == '1' && s[1][i] == '0' && s[2][i] == '1') {
            nxt[i] = nxt[i + 1] + 1;
        } else {
            nxt[i] = 0;
        }
    }

    int q;
    std::cin >> q;
    while(q--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        int non101 = l + nxt[l];
        if(non101 > r) {
            cout << "2\n";
            continue;
        }
        int tot = pr[r + 1] - pr[non101];
        int in = (prve[r + 1] - prve[non101]) + (prhe[r] - prhe[non101]);
        int res = tot - in;
        if(non101 != l) {
            if(s[0][non101] == '1' && s[1][non101] == '1' && s[2][non101] == '1')
                ;
            else if(s[0][non101] == '0' && s[2][non101] == '0')
                res += 2;
            else
                res++;
        }
        cout << res << "\n";
    }

    return 0;
}