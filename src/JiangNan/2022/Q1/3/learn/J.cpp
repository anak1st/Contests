#include <bits/stdc++.h>

struct fri {
    double x, v;
};

bool judge(int n, double time, std::vector<fri> &f) {
    double mxleft = f[0].x - time * f[0].v;
    double mxright = f[0].x + time * f[0].v;
    for(int i = 1; i < n; i++) {
        double curleft = f[i].x - time * f[i].v;
        double curright = f[i].x + time * f[i].v;
        mxleft = std::max(mxleft, curleft);
        mxright = std::min(mxright, curright);
    }
    // std::cerr << std::fixed << std::setprecision(7) << mxleft;
    // std::cerr << " $ ";
    // std::cerr << std::fixed << std::setprecision(7) << mxright;
    // std::cerr << "\n";
    return mxleft <= mxright;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<fri> f(n);
    for(int i = 0; i < n; i++) {
        std::cin >> f[i].x;
    }
    for(int i = 0; i < n; i++) {
        std::cin >> f[i].v;
    }

    double left = 0, right = 1e9;
    while(right - left > 1e-7) {
        double mid = (left + right) / 2;
        if(judge(n, mid, f)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    std::cout << std::fixed << std::setprecision(7) << right << '\n';

    return 0;
}