#include <bits/extc++.h>

template <typename T>
using SplayBase =
    __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>,
                     __gnu_pbds::splay_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

int main() {
    SplayBase<int> S;
    S.find_by_order(1);
    S.order_of_key(1);

    return 0;
}