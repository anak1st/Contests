/**
 * @author: XiaFan
 * @date: 04-18 21:08
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int la, lb;
    std::cin >> la >> lb;
    std::string a, b;
    std::cin >> a >> b;
    std::vector<int> left(lb), right(lb);
    // a la i
    // b lb j
    for(int i = 0, j = 0; j < lb; i++, j++) {
        while(a[i] != b[j]) {
            i++;
        }
        left[j] = i;
    }

    for(int i = la - 1, j = lb - 1; j >= 0; i--, j--) {
        while(a[i] != b[j]) {
            i--;
        }
        right[j] = i;
    }

    int ans = 1;
    for(int i = 0; i < lb - 1; i++) {
        ans = std::max(ans, right[i + 1] - left[i]);
    }
    std::cout << ans << "\n";

    /*
    for(int i = 0; i < lb; i++) {
        std::cout << left[i] << " \n"[i == lb - 1];
    }
    for(int i = 0; i < lb; i++) {
        std::cout << right[i] << " \n"[i == lb - 1];
    }*/

    return 0;
}