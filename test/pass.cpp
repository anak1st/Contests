/**
 * @author: XiaFan
 * @date: 2023-02-03 15:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {

    int args1 = 1, args2 = 2;
    char args3[] = "3";

    printf("str\n");
    printf("str%d\n", args1);
    printf("str%dstr%d\n", args1, args2);
    printf("str%dstr%dstr%s\n", args1, args2, args3);

    return 0;
}