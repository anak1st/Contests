/**
 * @author: XiaFan
 * @date: 04-25 19:17
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
        int index;
        node() {
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
            count = 0;
            index = -1;
        }
    };
    node *root;
    int num;
    trie() {
        root = new node;
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
            r->count++;
        }
        if(r->index == -1) {
            r->index = num;
            num++;
        }
        return r->index;
    }
};

struct fset {
    std::vector<int> f;
    int n;
    fset(int size) : f(size), n(size) {
        for(int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        if(f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        f[rx] = ry;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    trie t;
    string a, b;
    const int maxsticks = 250000;
    vector<int> c(maxsticks * 2, 0);
    fset f(maxsticks * 2);
    while(cin >> a >> b) {
        int i = t.insert(a);
        int j = t.insert(b);
        c[i]++;
        c[j]++;
        f.merge(i, j);
    }
    int father = f.find(0);
    int num = 0;
    for(int i = 0; i < t.num; i++) {
        if(f.find(i) != father) {
            cout << "Impossible" << endl;
            return 0;
        }
        num += c[i] % 2;
    }
    if(num == 0 || num == 2) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}