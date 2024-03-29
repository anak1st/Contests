# 问题
VTuber 的粉丝每天都在成倍增长。
然而，有的时候，Vtuber 会被 SuperChat 钓鱼，被开盒，和xny谈恋爱，导致粉丝大大减少。
VTuber 总共直播了 $n$ 次，每次直播都会使得粉丝数量翻倍，在最开始时候粉丝数量为 $1$。
但是会有 m 个突发事件，每次突发事件都会导致粉丝数量变少，如果之前有 $z$ 个粉丝，那么发生事件后粉丝数量变为 $\lfloor \frac{z}{3} \rfloor$，第 $i$ 个突发事件发生在第 $x_i$ 次直播，一旦某场直播发生了突发事件，那么这场直播就不会增长粉丝数量。

- $\lfloor \frac{z}{3} \rfloor$ 表示 $z$ 除以 $3$ 向下取整。

求最终的粉丝数量

你有 $T$ 组测试数据。
# 数据范围
$1 \leq T \leq 1000$
$1 \leq n \leq 60$ 
$1 \leq m \leq 60$ 
$1 \leq x_i \leq n$。

# 输入格式
第一行包含一个整数 $T$。
接下来 $T$ 组测试，每组包含两行，第一行两个整数 $n$ $m$。
第二行，包含 $m$ 个整数 $x_1, x_2, x_3, ..., x_m$。

# 输出格式
对于每组测试数据，输出一行一个整数 $z$ 表示最后的粉丝数量。

# 输入输出样例
in
```
3
1 0
2
2 1
2
5 1
5
```

out
```
2
0
5
```