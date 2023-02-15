/**
 * @author: XiaFan
 * @date: 2023-02-05 20:37
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct Node {
    int id1, id2;
    char c1, c2;
    Node(int id1, char c1, int id2, char c2) : id1(id1), id2(id2), c1(c1), c2(c2) {}
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (auto &it : s) {
        std::cin >> it;
    }

    std::vector<Node> ans;
	// give to need
    std::map<std::pair<char, char>, std::vector<int>> a;
    std::string str = "win";

	auto fun = [&](int i) {
		int max = 0;
		for (auto c : str) {
			int cnt = std::count(s[i].begin(), s[i].end(), c);
			max = std::max(max, cnt);
		}
		if (max == 3) {
			for (auto c1 : str) {
				int cnt = std::count(s[i].begin(), s[i].end(), c1);
				if (cnt == 3) {
					for (auto c2 : str) {
						if (c1 == c2) {
							continue;
						}
						a[{c1, c2}].push_back(i);
					}
				}
			}
		}
		if (max == 2) {
			char c1, c2;
			for (auto c : str) {
				int cnt = std::count(s[i].begin(), s[i].end(), c);
				if (cnt == 2) {
					c1 = c;
				}
				if (cnt == 0) {
					c2 = c;
				}
			}
			a[{c1, c2}].push_back(i);
		}
	};
	for (int i = 0; i < n; i++) {
		fun(i);
	}

	for (auto c1 : str) {
		for (auto c2 : str) {
			if (c1 == c2) continue;
			auto &v1 = a[{c1, c2}];
			auto &v2 = a[{c2, c1}];
			while (!a[{c1, c2}].empty() && !a[{c2, c1}].empty()) {
				int id1 = a[{c1, c2}].back();
				int id2 = a[{c2, c1}].back();
				a[{c1, c2}].pop_back();
				a[{c2, c1}].pop_back();
				ans.emplace_back(id1, c1, id2, c2);
			}
		}
	}
	for (auto c1 : str) {
		for (auto c2 : str) {
			if (c1 == c2) continue;
			for (auto c3 : str) {
				if (c1 == c3 || c2 == c3) continue;
				while (!a[{c1, c2}].empty() && !a[{c2, c3}].empty()) {
					int id1 = a[{c1, c2}].back();
					int id2 = a[{c2, c3}].back();
					a[{c1, c2}].pop_back();
					a[{c2, c3}].pop_back();
					a[{c1, c3}].push_back(id2);
					ans.emplace_back(id1, c1, id2, c2);
				}
			}
		}
	}
	for (auto c1 : str) {
		for (auto c2 : str) {
			if (c1 == c2) continue;
			auto &v1 = a[{c1, c2}];
			auto &v2 = a[{c2, c1}];
			while (!a[{c1, c2}].empty() && !a[{c2, c1}].empty()) {
				int id1 = a[{c1, c2}].back();
				int id2 = a[{c2, c1}].back();
				a[{c1, c2}].pop_back();
				a[{c2, c1}].pop_back();
				ans.emplace_back(id1, c1, id2, c2);
			}
		}
	}

	std::cout << ans.size() << "\n";
	for (auto &it : ans) {
		std::cout << it.id1 + 1 << " " << it.c1 << " " << it.id2 + 1 << " " << it.c2 << "\n";
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}