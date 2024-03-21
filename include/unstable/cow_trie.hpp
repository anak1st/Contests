#include <map>
#include <memory>




struct cow_trie {
    std::map<char, std::shared_ptr<cow_trie>> children;
    int value = 0;
    bool has_value = false;
};


auto put(std::shared_ptr<cow_trie> root, std::string key, int value, int step) -> std::shared_ptr<cow_trie> {
    auto new_root = std::make_shared<cow_trie>(*root);
    
    if (step == key.size()) {
        new_root->value = value;
        new_root->has_value = true;
    }

    for (auto [k, v] : root->children) {
        if (step < key.size() && k == key[step]) {
            new_root->children[k] = put(v, key, value, step + 1);
        } else {
            new_root->children[k] = v;
        }
    }

    return new_root;
}