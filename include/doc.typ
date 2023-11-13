// The project function defines how your document looks.
// It takes your content and some metadata and formats it.
// Go ahead and customize it to your liking!
#let project(title: "", authors: (), body) = {
  // Set the document's basic properties.
  set document(author: authors, title: title)
  set page(numbering: "1", number-align: center)
  set heading(numbering: "1.")
  set text(font: "Linux Libertine", lang: "zh")

  // Title row.
  align(center)[
    #block(text(weight: 700, 1.75em, title))
  ]

  // Author information.
  pad(
    top: 0.5em,
    bottom: 0.5em,
    x: 2em,
    grid(
      columns: (1fr,) * calc.min(3, authors.len()),
      gutter: 1em,
      ..authors.map(author => align(center, strong(author))),
    ),
  )

  // Main body.
  set par(justify: true)

  body
}


#show: project.with(
  title: "ICPC模板 2023.8",
  authors: (
    "夏凡",
  ),
)

// 目录
#outline()

#pagebreak()
// 1
= 基本算法
== 离散
#let text = read("templates/Base/Discrete.hpp")
#raw(text, lang: "cpp")

== FastRead
#let text = read("templates/Base/FastRead.hpp")
#raw(text, lang: "cpp")

== LCA
#let text = read("templates/Base/LCA.hpp")
#raw(text, lang: "cpp")

== Map (防Hack)
#let text = read("templates/Base/Map.hpp")
#raw(text, lang: "cpp")

== 排序
#let text = read("templates/Base/Sort.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 2
= 数据结构
== 并查集
#let text = read("templates/DataStructure/DSU.hpp")
#raw(text, lang: "cpp")

== 树状数组
#let text = read("templates/DataStructure/Fenwick.hpp")
#raw(text, lang: "cpp")

== 线段树
=== 单点修改
#let text = read("templates/DataStructure/SegTree.hpp")
#raw(text, lang: "cpp")

=== Lazy
#let text = read("templates/DataStructure/SegTreeLazy.hpp")
#raw(text, lang: "cpp")

== Splay
#let text = read("templates/DataStructure/Splay.hpp")
#raw(text, lang: "cpp")

== ST表
#let text = read("templates/DataStructure/ST.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 3
= DP
== 背包
#let text = read("templates/DP/KP.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 4
= 计算几何
== Circle
#let text = read("templates/Geometry/Circle.hpp")
#raw(text, lang: "cpp")

== 最近点对
#let text = read("templates/Geometry/NearestPoints.hpp")
#raw(text, lang: "cpp")

== Vector2
#let text = read("templates/Geometry/Vector2.hpp")
#raw(text, lang: "cpp")

== Vector3
#let text = read("templates/Geometry/Vector3.hpp")
#raw(text, lang: "cpp")


#pagebreak()
// 5
= 图论
== 最小生成树
=== Kruskal $O(E log(E))$
#let text = read("templates/Graph/Kruskal.hpp")
#raw(text, lang: "cpp")

=== Prim $O(V^2)$
#let text = read("templates/Graph/Prim.hpp")
#raw(text, lang: "cpp")

== 最短路
=== Dijkstra $O(V^2)$
#let text = read("templates/Graph/Dijkstra.hpp")
#raw(text, lang: "cpp")

=== Floyd $O(V^3)$
#let text = read("templates/Graph/Floyd.hpp")
#raw(text, lang: "cpp")

=== Bellman-Ford $O(V E)$
#let text = read("templates/Graph/BellmanFord.hpp")
#raw(text, lang: "cpp")


== 求最大匹配
=== Augment Path (增广路) $O(V E)$
#let text = read("templates/Graph/AugmentPath.hpp")
#raw(text, lang: "cpp")

=== Hopcroft Karp $O(E sqrt(V))$
#let text = read("templates/Graph/HopcroftKarp.hpp")
#raw(text, lang: "cpp")

=== 转为网络流
将源点连上左边所有点，右边所有点连上汇点，容量皆为 1。原来的每条边从左往右连边，容量也皆为 1，最大流即最大匹配。
如果使用 Dinic 算法求该网络的最大流，可在 $O(sqrt(n)m)$ 求出。

== 网络流
=== 最大流 (Dinic) $O(V^2 E)$
#let text = read("templates/Graph/MaxFlow.hpp")
#raw(text, lang: "cpp")

=== 最小费用最大流 (SPFA) $O(V E^2)$
#let text = read("templates/Graph/MCFGraph.hpp")
#raw(text, lang: "cpp")

== 树链剖分 (HLD)
#let text = read("templates/Graph/HLD.hpp")
#raw(text, lang: "cpp")

=== Kruskal 重构树
#let text = read("templates/Graph/KruskalRebuildTree.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 6
= 数论
== 数学
#let text = read("templates/Number/Math.hpp")
#raw(text, lang: "cpp")

== 自动取模
#let text = read("templates/Number/Mint.hpp")
#raw(text, lang: "cpp")

== 组合数
#let text = read("templates/Number/Comb.hpp")
#raw(text, lang: "cpp")

== 字符串哈希
#let text = read("templates/Number/Hash.hpp")
#raw(text, lang: "cpp")

== 素数 (线性筛)
#let text = read("templates/Number/Primes.hpp")
#raw(text, lang: "cpp")

== Int128
#let text = read("templates/Number/i128.hpp")
#raw(text, lang: "cpp")

== 矩阵
#let text = read("templates/Number/Matrix.hpp")
#raw(text, lang: "cpp")

== 大数
#let text = read("templates/Number/Interger2.hpp")
#raw(text, lang: "cpp")

== 多项式，FFT
#let text = read("templates/Number/Poly.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 7
= 字符串
== KMP
#let text = read("templates/String/KMP.hpp")
#raw(text, lang: "cpp")

== AC自动机
#let text = read("templates/String/ACAuto_2.hpp")
#raw(text, lang: "cpp")

== Trie
#let text = read("templates/String/Trie.hpp")
#raw(text, lang: "cpp")

== SAM
#let text = read("templates/String/SAM.hpp")
#raw(text, lang: "cpp")

== Manacher
给定一个长度为 $n$ 的字符串 $s$，请找到所有对 $(i, j)$ 使得子串 $s[i...j]$ 为一个回文串。当 $t = t_("rev")$ 时，字符串 t 是一个回文串 $（t_("rev")$ 是 $t$ 的反转字符串）。

#let text = read("templates/String/Manacher.hpp")
#raw(text, lang: "cpp")

== Z algorithm
对于个长度为 $n$ 的字符串 $s$。定义函数 $z[i]$ 表示 $s$ 和 $s[i,n-1]$（即以 $s[i]$ 开头的后缀）的最长公共前缀（LCP）的长度。$z$ 被称为 $s$ 的 $Z$ 函数。特别地，$z[0] = 0$。

#let text = read("templates/String/Z_algorithm.hpp")
#raw(text, lang: "cpp")