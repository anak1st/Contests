/**
 * @author: XiaFan
 * @date: 11-20 15:57
 **/
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    for (auto it : v) {
        os << it << " ";
    }
    return os;
}

template<typename T>
void print(const T& val) {
    std::cerr << val << "\n";
}

template<typename T, typename... Args>
void print(const T& val, const Args&... args) {
    std::cerr << val << " ";
    print(args...);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, t;
    std::cin >> n >> t;
    std::vector<std::pair<int, int>> a(t);
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < t; i++) {
        auto& [x, y] = a[i];
        std::cin >> x >> y;
        x--, y--;
        pos[x].push_back(i);
        pos[y].push_back(i);
    }

    std::vector<int> use(t, -1);
    std::vector<bool> vis(t, false);
    std::function<int (int)> find = [&](int x) -> int {
        if (vis[x]) {
            return -1;
        }

        for (auto ai : pos[x]) {
            if (use[ai] == -1) {
                return ai;
            }
        }
        
        for (auto ai : pos[x]) {
            int i = use[ai];
            vis[i] = true;
            int j = find(i);
            vis[i] = false;
            if (j != -1) {
                use[j] = i;
                return ai;
            }
        }

        return -1;
    };
    
    int ans = 1;
    for (; ans <= std::min(t, n); ans++) {
        vis[ans] = true;
        int j = find(ans);
        vis[ans] = false;
        if (j == -1) {
            break;
        }
        use[j] = ans;
    }
    std::cout << ans;
    
    return 0;
}