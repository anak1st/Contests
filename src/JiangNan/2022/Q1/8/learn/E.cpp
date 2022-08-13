// c++ < 11
/**
 * @author: XiaFan
 * @date: 04-26 08:34
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
        node *next[2];
        int count;
        int prefix_count;
        int index;
        node() {
            for(int i = 0; i < 2; i++) {
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
    bool ok;

    trie() {
        root = new node;
        num = 0;
        ok = true;
    }
    void clear() {
        root->clear();
        num = 0;
        ok = true;
    }

    int insert(string &s) {
        node *r = root;
        for(int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - '0';

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

    int prefix(const string &s) {
        node *r = root;
        for(int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - '0';
            r = r->next[id];
            if(r == NULL) {
                return 0;
            }
        }
        return r->prefix_count;
    }

    void dfs(node *r) {
        if(r->count > 0) {
            // cout << "c:" << r->count << " " << r->prefix_count << "\n";
            if(r->prefix_count >= 2) {
                ok = false;
            }
        }
        for(int i = 0; i < 2; i++) {
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
    int c = 1;
    while(cin >> s) {
        if(s == "9") {
            t.dfs(t.root);
            cout << "Set " << c << " is ";
            if(!t.ok) {
                cout << "not ";
            }
            cout << "immediately decodable\n";
            c++;
            t.clear();
        } else {
            t.insert(s);
        }
    }

    return 0;
}