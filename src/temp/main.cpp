/**
 * @author: XiaFan
 * @date: 2023-01-21 16:50
 **/
#include <bits/stdc++.h>
#include <bits/extc++.h>
using i64 = long long;

/**
 * @brief Splay Tree from pbds
 * @fn find_by_order() find nth val
 * @fn order_of_key()  find pos of key
 */
template <typename T> 
using Splay = __gnu_pbds::tree<
    T, 
    __gnu_pbds::null_type, 
    std::less<T>,
    __gnu_pbds::splay_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Splay<int> splay;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        splay.insert(x);
    }
    std::cout << "size: " << splay.size() << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << splay.order_of_key(i) << " ";
    }

    return 0;
}