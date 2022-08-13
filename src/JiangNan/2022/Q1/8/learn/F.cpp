/**
 * @author: XiaFan
 * @date: 04-26 09:22
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct trie {
    struct node {
        node *next[26];
        int count;
        int prefix_count;
        int index;
        node() {
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            count = 0;
            prefix_count = 0;
            index = -1;
        }
        void clear() {
            for(int i = 0; i < 2; i++) {
                if(next[i] != NULL) {
                    next[i]->clear();
                }
            }
            count = 0;
            prefix_count = 0;
            index = -1;
        }
    };

    node *root;
    int num;
    trie() {
        root = new node;
        num = 0;
    }
    void clear() {
        root->clear();
        num = 0;
    }

    int insert(string &s) {
        node *r = root;
        for(int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            if(r->next[id] == NULL) {
                r->next[id] = new node;
            }
            r = r->next[id];
            r->prefix_count++;
        }
        r->count++;
        if(r->index == -1) {
            r->index = num;
            num++;
        }
        return r->index;
    }

    int prefix(string &s) {
        node *r = root;
        for(int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            r = r->next[id];
            if(r == NULL) {
                return 0;
            }
        }
        return r->prefix_count;
    }

    void dfs(node *r) {
        for(int i = 0; i < 26; i++) {
            if(r->next[i] != NULL) {
                dfs(r->next[i]);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    trie t;
    while(true) {
        getline(cin, s);
        if(s == "") {
            break;
        }
        t.insert(s);
    }

    while(cin >> s) {
        cout << t.prefix(s) << "\n";
    }

    return 0;
}