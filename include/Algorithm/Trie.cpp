#pragma once

#include <cassert>
#include <iostream>
#include <vector>

using i64 = long long;

struct Trie {
    struct Node {
        Node *next[26];
        int c;
        int prefix;
        int index;
        Node() {
            for (int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            c = 0;
            prefix = 0;
            index = -1;
        }
        void clear() {
            for (int i = 0; i < 2; i++) {
                if (next[i] != NULL) {
                    next[i]->clear();
                }
            }
            c = 0;
            prefix = 0;
            index = -1;
        }
    };

    Node *root;
    int num;

    Trie() {
        root = new Node;
        num = 0;
    }

    void clear() {
        root->clear();
        num = 0;
    }

    int insert(const std::string &s) {
        Node *r = root;
        r->prefix++;
        for (int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            if (r->next[id] == NULL) {
                r->next[id] = new Node;
            }
            r = r->next[id];
            r->prefix++;
        }
        r->c++;

        if (r->index == -1) {
            r->index = num;
            num++;
        }
        return r->index;
    }

    int count(const std::string &s) {
        Node *r = root;
        for (int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            r = r->next[id];
            if (r == NULL) {
                return 0;
            }
        }
        return r->c;
    }

    int prefix_count(const std::string &s) {
        Node *r = root;
        for (int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            r = r->next[id];
            if (r == NULL) {
                return 0;
            }
        }
        return r->prefix;
    }

    void dfs(Node *r) {
        for (int i = 0; i < 26; i++) {
            if (r->next[i] != NULL) {
                dfs(r->next[i]);
            }
        }
    }
};
