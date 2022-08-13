/**
 * @author: XiaFan
 * @date: 04-26 11:30
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
        int c;        // count
        int prefixc;  // prefix count
        int index;
        node() {
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            c = 0;
            prefixc = 0;
            index = -1;
        }
        void clear() {
            for(int i = 0; i < 2; i++) {
                if(next[i] != NULL) {
                    next[i]->clear();
                }
            }
            c = 0;
            prefixc = 0;
            index = -1;
        }
    };

    node *root;  // root->prefix_c : all nodes
    int num;     // different nodes

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
        r->prefixc++;
        for(int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            if(r->next[id] == NULL) {
                r->next[id] = new node;
            }
            r = r->next[id];
            r->prefixc++;
        }
        r->c++;

        if(r->index == -1) {
            r->index = num;
            num++;
        }
        return r->index;
    }

    int count(string &s) {
        node *r = root;
        for(int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            r = r->next[id];
            if(r == NULL) {
                return 0;
            }
        }
        return r->c;
    }

    int prefix_count(string &s) {
        node *r = root;
        for(int i = 0; i < (int)s.length(); i++) {
            int id = s[i] - 'a';
            r = r->next[id];
            if(r == NULL) {
                return 0;
            }
        }
        return r->prefixc;
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

    trie t;
    string _s;
    vector<string> s;
    while(cin >> _s) {
        t.insert(_s);
        s.push_back(_s);
    }

    for(int i = 0; i < (int)s.size(); i++) {
        int len = s[i].length();
        for(int j = 1; j < len; j++) {
            string a = s[i].substr(0, j);
            string b = s[i].substr(j, len - j);
            cout << "d:" << a << " " << b << "\n";
            if(t.count(a) && t.count(b)) {
                cout << s[i] << "\n";
            }
        }
    }

    return 0;
}