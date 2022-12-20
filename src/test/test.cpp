/**
 * @author: XiaFan
 * @date: 12-20 00:11
 **/
#include <bits/stdc++.h>
#include "testing/MetaLisp.hpp"

using i64 = long long;

int main() {
    
    using p = add<number<1>, number<2>>;
    using l = list<number<1>, number<2>, number<3>>;
    display<p>();
    display<length<l>>();

    return 0;
}