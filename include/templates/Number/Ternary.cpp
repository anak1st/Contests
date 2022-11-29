#include <algorithm>
#include <cmath>
#include <functional>

double Ternary(std::function<double(double)> F, int limit) {
    double L = 0, R = 1e18;
    double Lmid, Rmid;
    for (int i = 0; i < limit; i++) {
        Lmid = L + (R - L) / 3;
        Rmid = R - (R - L) / 3;
        if (F(Lmid) < F(Rmid)) {
            R = Rmid;
        } else {
            L = Lmid;
        }
    }
    // if input_type is float / double
    // double ans = F(L);
    // if input_type is int / i64
    double ans = std::min(F(ceil(L)), F(floor(L)));
    return ans;
}