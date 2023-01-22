/**
 * @author: XiaFan
 * @date: 2023-01-21 16:50
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
using i64 = long long;

/**
 * @fn find_by_order() find nth val
 * @fn order_of_key()  find pos of key
 */
template <typename T>
using Tree = __gnu_pbds::tree<
    T, 
    __gnu_pbds::null_type, 
    std::less<T>, 
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>;

constexpr i64 B = 1e8;

i64 fun(i64 x) {
    return (x + B) * B;
}
i64 revfun(i64 x) {
    return x / B - B;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Tree<i64> t;
    for (int i = 0; i < n; i++) {
        int op;
        i64 x;
        std::cin >> op >> x;
        if (op == 1) {
            x = fun(x) + i;
            t.insert(x);
        } else if (op == 2) {
            x = fun(x);
            t.erase(t.lower_bound(x));
        } else if (op == 3) {
            x = fun(x);
            i64 ans = t.order_of_key(x);
            ans++;
            std::cout << ans << "\n";
        } else if (op == 4) {
            i64 ans = *t.find_by_order(x - 1);
            ans = revfun(ans);
            std::cout << ans << "\n";
        } else if (op == 5) {
            x = fun(x);
            i64 ans = *(--t.lower_bound(x));
            ans = revfun(ans);
            std::cout << ans << "\n";
        } else if (op == 6) {
            x = fun(x) + n;
            i64 ans = *t.upper_bound(x);
            ans = revfun(ans);
            std::cout << ans << "\n";
        }
    }

    return 0;
}