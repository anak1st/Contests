/**
 * @author: XiaFan
 * @date: 07-05 17:54
 **/
#include <algorithm>
#include <cassert>
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
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        if (n % (m + 1) == 0) {
            cout << "Rabbit\n";
        } else {
            cout << "Grass\n";
        }
    }

    return 0;
}