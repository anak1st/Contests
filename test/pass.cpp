#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int node_cnt = 0;

/**
 * @brief Node of Binary Sort Tree
 */
template <typename T>
struct BSTNode {
    typedef BSTNode* Pointer;

    Pointer left, right;
    T key;

    BSTNode(int _key) : left(nullptr), right(nullptr), key(_key) {}

    ~BSTNode() {}

    friend std::ostream& operator<<(std::ostream& OS, const BSTNode& N) {
        OS << N.key;
        return OS;
    }
};

enum class Order {
    Pre,
    In,
    Post,
};

/**
 * @brief Binary Sort Tree
 *
 * @tparam node
 */
template <typename T, typename Node = BSTNode<T>>
class BST {
private:
    typedef typename Node::Pointer Pointer;
    Pointer root;

    Pointer delete_subtree(Pointer head) {
        if (!head) return nullptr;
        head->left = delete_subtree(head->left);
        head->right = delete_subtree(head->right);
        delete head;
        return nullptr;
    }

    Pointer insert_node(Pointer head, int key) {
        if (!head) {
            Pointer temp = new Node(key);
            return temp;
        }
        if (key < head->key) {
            head->left = insert_node(head->left, key);
        } else if (key > head->key) {
            head->right = insert_node(head->right, key);
        }
        return head;
    }

    Pointer erase_node(Pointer head, T x) {
        if (!head) return nullptr;

        if (x < head->key) {
            head->left = erase_node(head->left, x);
        } else if (x > head->key) {
            head->right = erase_node(head->right, x);
        } else {
            Pointer l = head->left;
            if (!l) {
                Pointer r = head->right;
                delete head;
                head = r;
            } else if (!head->right) {
                delete head;
                head = l;
            } else {
                while (l->right) l = l->right;
                head->key = l->key;
                head->right = erase_node(head->right, l->key);
            }
        }

        return head;
    }

    Pointer search_node(Pointer head, int x) {
        if (!head) return nullptr;

        if (x < head->key) {
            return search_node(head->left, x);
        } else if (x > head->key) {
            return search_node(head->right, x);
        } else {
            return head;
        }
    }

    void traverse_dfs(Pointer head, Order o) const {
        if (!head) return;
        if (o == Order::Pre) std::cout << *head;
        if (!head->left && !head->right) return;
        std::cout << "(";
        traverse_dfs(head->left, o);
        // if (o == Order::In) std::cout << *head;
        std::cout << ",";
        traverse_dfs(head->right, o);
        // if (o == Order::Post) std::cout << *head;
        std::cout << ")";
    }

    std::pair<int, bool> dfs(Pointer head) {
        if (!head) return {0, true};

        std::pair<int, bool> resl = dfs(head->left);
        std::pair<int, bool> resr = dfs(head->right);
        int dif = std::abs(resl.first - resr.first);
        bool ok = resl.second && resr.second && dif <= 1;
        return {std::max(resl.first, resr.first) + 1, ok};
    }

public:
    BST() : root(nullptr) {}

    ~BST() { clear(); }

    void clear() { root = delete_subtree(root); }
    void insert(int key) { root = insert_node(root, key); }
    void erase(int key) { root = erase_node(root, key); }

    Pointer search(int key) { return search_node(root, key); }

    void traverse(Order o) {
        traverse_dfs(root, o);
        std::cout << "\n";
    }

    bool dfs() {
        return dfs(root).second;
    }
};

int main() {
    BST<int> T;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int key;
        std::cin >> key;
        T.insert(key);
    }
    
    if (T.dfs()) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    return 0;
}
