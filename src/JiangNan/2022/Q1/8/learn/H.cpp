#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long i64;

struct trie {
    struct node {
        i64 c;
        i64 prefix;
        i64 ans;
        node *next[2];
        node() {
            c = 0;
            prefix = 0;
            ans = 0;
            for(int i = 0; i < 2; i++) {
                next[i] = NULL;
            }
        }
        void clear() {
            c = 0;
            prefix = 0;
            ans = 0;
            for(int i = 0; i < 2; i++) {
                if(next[i] != NULL) {
                    next[i]->clear();
                }
            }
        }
        ~node() {
            for(int i = 0; i < 2; i++) {
                if(next[i] != NULL) {
                    delete next[i];
                }
            }
        }
    };

    node *root;
    int c[32][2];
    trie() {
        root = new node;
        clear_c();
    }
    ~trie() {
        delete root;
        clear_c();
    }
    void clear() {
        root->clear();
        clear_c();
    }
    void clear_c() {
        for(int i = 0; i <= 31; i++) {
            for(int j = 0; j < 2; j++) {
                c[i][j] = 0;
            }
        }
    }

    void insert(i64 x, i64 add) {
        node *r = root;
        for(int i = 30; i >= 0; i--) {
            i64 d = (1 << i) & x ? 1 : 0;
            if(r->next[d] == NULL) {
                r->next[d] = new node();
            }
            r = r->next[d];
            c[i][d]++;
            r->prefix += add;
            // c[i][1 - t] : 当前点对应的j的个数;
            r->ans += add * c[i][1 - d];
        }
        r->c += add;
    }

    i64 cal(int x) {
        node *r = root;
        i64 ans = 0;
        for(int i = 30; i >= 0; i--) {
            int d = (1 << i) & x ? 1 : 0;
            node *br = r->next[1 - d];
            if(br != NULL) {
                ans += br->ans - (br->prefix * c[i][d]);
            }
            r = r->next[d];
            if(r == NULL) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    trie t;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        t.clear();
        for(int i = 0; i < n; i++) {
            t.insert(a[i], 1);
        }
        i64 ans = 0;
        t.clear_c();
        for(int i = 0; i < n - 1; i++) {
            t.insert(a[i], -1);
            ans += t.cal(a[i]);
        }
        cout << ans << "\n";
    }

    return 0;
}