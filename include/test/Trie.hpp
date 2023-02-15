#pragma once
#include <bits/extc++.h>

/**
 * @brief Trie Tree
 * 
 */
using Trie = __gnu_pbds::trie<
    std::string, 
    __gnu_pbds::null_type, 
    __gnu_pbds::trie_string_access_traits<>,
    __gnu_pbds::pat_trie_tag, 
    __gnu_pbds::trie_prefix_search_node_update>;
