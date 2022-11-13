/**
 * @author: XiaFan
 * @date: 2022-04-09 23:17:32
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = 0, j = n - 1, k = 0; i <= j; i++) {
        while(i <= j && a[j] == k % 2) {
            j--;
        }
        if(a[i] != k % 2) {
            std::cout << "No\n";
            break;
        }
        k++;
    }
    std::cout << "Yes\n";
    return 0;
}