#pragma once
#include "XCPC.h"

template <typename T> struct SegTreeNode {
    int l, r;
    T val, tag;
    SegTreeNode() : val(0), tag(0) {}
    int mid() { return (l + r) / 2; }
};

// Segment Tree
template <typename T, typename Node = SegTreeNode<T>> struct SegTree {
    int n;
    std::vector<Node> tree;
    constexpr int ls(int root) { return root * 2 + 1; }
    constexpr int rs(int root) { return root * 2 + 2; }
    SegTree(int size) : SegTree(std::vector<T>(size, 0)) {}
    SegTree(const std::vector<T> &num) : n(num.size()), tree(n * 4) {
        tree[0].l = 0;
        tree[0].r = n - 1;
        build(0, num);
    }

    void push_up(int root) { tree[root].val = tree[ls(root)].val + tree[rs(root)].val; }
    void build(int root, const std::vector<T> &num) {
        if (tree[root].l == tree[root].r) {
            tree[root].val = num[tree[root].l];
            return;
        }
        int mid = tree[root].mid();
        tree[ls(root)].l = tree[root].l;
        tree[ls(root)].r = mid;
        tree[rs(root)].l = mid + 1;
        tree[rs(root)].r = tree[root].r;

        build(ls(root), num);
        build(rs(root), num);
        push_up(root);
    }
    void change(int root, T val) {
        tree[root].tag += val;
        tree[root].val += (val * (tree[root].r - tree[root].l + 1));
    }
    void push_down(int root) {
        change(ls(root), tree[root].tag);
        change(rs(root), tree[root].tag);
        tree[root].tag = 0;
    }
    void update(int root, int left, int right, int val) {
        if (left <= tree[root].l && tree[root].r <= right) {
            change(root, val);
            return;
        }
        push_down(root);
        int mid = tree[root].mid();
        if (left <= mid) update(ls(root), left, right, val);
        if (mid < right) update(rs(root), left, right, val);
        push_up(root);
    }
    T query(int root, int left, int right) {
        if (left <= tree[root].l && tree[root].r <= right) {
            return tree[root].val;
        }
        T ans = 0;
        push_down(root);
        int mid = tree[root].mid();
        if (left <= mid) ans += query(ls(root), left, right);
        if (mid < right) ans += query(rs(root), left, right);
        return ans;
    }
    void update(int left, int right, int val) { update(0, left, right, val); }
    T query(int left, int right) { return query(0, left, right); }
};