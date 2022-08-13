/**
 * @author: XiaFan
 * @date: 05-15 18:48
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);
    map<string, string> mp;
    while (getline(cin, s)) {
        if (s == "END") {
            break;
        }
        stringstream ss(s);
        string a, b;
        ss >> a >> b;
        mp[b] = a;
    }
    getline(cin, s);
    while (getline(cin, s)) {
        if (s == "END") {
            break;
        }
        string tmp;
        string out;
        for (auto i : s) {
            if ('a' <= i && i <= 'z') {
                tmp += i;
            } else {
                if (!tmp.empty()) {
                    if (mp.count(tmp)) {
                        out += mp[tmp];
                    } else {
                        out += tmp;
                    }
                    tmp.clear();
                }
                out += i;
            }
        }
        if (!tmp.empty()) {
            if (mp.count(tmp)) {
                out += mp[tmp];
            } else {
                out += tmp;
            }
            tmp.clear();
        }
        cout << out << "\n";
    }

    return 0;
}