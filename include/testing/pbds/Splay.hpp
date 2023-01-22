#pragma once
#include <bits/extc++.h>

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