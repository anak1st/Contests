/**
 * @author: XiaFan
 * @date: 2023-05-04 21:22
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5;
std::vector<int> primes;
int minp[N + 1];  // minp[i] = min prime factor of i
int num[N + 1];   // num[i] = number of prime factors of i

void init() {
    for (int i = 2; i <= N; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
            num[i] = 1;
        }
        for (auto p : primes) {
            if (i * p > N) break;
            minp[i * p] = p;
            num[i * p] = num[i] + 1;
            if (i % p == 0) break;
        }
    }
}
bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    return minp[x] == x;
}
std::vector<int> get_facts(int x) {
    std::vector<int> facts;
    int t = x;
    while (t > 1) {
        if (facts.empty() || facts.back() != minp[t]) {
            facts.push_back(minp[t]);
        }
        t /= minp[t];
    }
    return facts;
}

std::vector<std::vector<int>> divs;
void init_divs() {
    divs.resize(N + 1);
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 x = a[i];
        i64 s = 1;
        for (auto p : primes) {
            if (1LL * p * p * p > x) {
                break;
            }
            int t = 0;
            while (x % p == 0) {
                x /= p;
                t++;
                if (t % 2 == 0) {
                    s *= p;
                }
            }
        }
        if (x > 1) {
            int u = std::sqrt(x);
            if (u * u == x) {
                s *= u;
            }
        }

        for (auto b : divs[s]) {
            auto [l1, r1] = std::equal_range(a.begin(), a.end(), a[i] / b);
            auto [l2, r2] = std::equal_range(a.begin(), a.end(), a[i] / (b * b));

            ans += 1LL * (r1 - l1) * (r2 - l2);
        }
    }

    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && a[i] == a[j]) {
            j++;
        }
        i64 len = j - i;
        ans += len * (len - 1) * (len - 2);
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();
    init_divs();
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}