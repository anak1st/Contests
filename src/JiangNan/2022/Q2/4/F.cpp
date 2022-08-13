/**
 * @author: XiaFan
 * @date: 07-05 18:09
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

    int a, b;
    while (cin >> a >> b) {
        if (a > b) {
            swap(a, b);
        }
        double f = (sqrt(5) + 1) / 2;
        cout << (a != int((b - a) * f)) << "\n";
    }

    return 0;
}