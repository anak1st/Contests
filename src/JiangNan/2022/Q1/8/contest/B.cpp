#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    map<string, string> a;
    for(int i = 0; i < n; i++) {
        string all;
        getline(cin, all);
        stringstream ss(all);
        string world, fullworld;
        ss >> world;
        ss >> fullworld;
        string s;
        while(ss >> s) {
            fullworld = fullworld + " " + s;
        }
        a[world] = fullworld;
    }

    int m;
    cin >> m;
    cin.ignore();

    for(int i = 0; i < m; i++) {
        string all;
        getline(cin, all);
        stringstream ss(all);
        string w;
        while(ss >> w) {
            if(a.count(w)) {
                cout << a[w] << " ";
            } else {
                cout << w << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}