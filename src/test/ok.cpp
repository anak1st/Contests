//
// Created by meiru on 2022/12/11.
//
#include <bits/stdc++.h>

using i64 = long long;

const int mod = 998244353;

int to(char x) {
	if (x >= 'a' && x <= 'z') {
		return x - 'a';
	}
	if (x >= 'A' && x <= 'Z') {
		return x - 'A' + 26;
	}
	return x - '0' + 52;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;
	int n = s.length();

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = to(s[i]);
	}

	std::vector<std::array<i64, 62>> cnt1(n), cnt2(n);
	std::vector<i64> sum1(n), sum2(n);

	auto C2 = [&](i64 x) {
		return (x * (x - 1) / 2) % mod;
	};

	for (int i = 0; i < n; ++i) {
		cnt1[i][a[i]] = (cnt1[i][a[i]] + 1) % mod;
		for (int j = 0; j < 62; ++j) {
			if (i) (cnt1[i][j] += cnt1[i - 1][j]) %= mod;
			cnt2[i][j] = C2(cnt1[i][j]);
			(sum1[i] += cnt1[i][j]) %= mod;
			(sum2[i] += cnt2[i][j]) %= mod;
		}
	}
	auto get = [&](int pos, int x, int y) {
		return (C2(sum1[pos] - cnt1[pos][x] - cnt1[pos][y]) % mod - (sum2[pos] - cnt2[pos][x] - cnt2[pos][y]) % mod + mod) % mod;
	};

	std::vector<i64> dp1(62);
	std::vector dp2(62, std::vector<i64>(62)), dp3(dp2);

	i64 ans = 0;
	for (int i = n - 1; i > 1; i--) {
		int c = a[i];
		for (int j = 0; j < 62; j++) {
			if (j != c) {
				ans = (ans + dp3[j][c] * get(i - 1, c, j) % mod) % mod;
				dp3[c][j] = (dp3[c][j] + dp2[j][c]) % mod;
				dp2[c][j] = (dp2[c][j] + dp1[j]) % mod;
			}
		}
		dp1[c]++;
	}

	std::cout << ans << "\n";

	return 0;
}