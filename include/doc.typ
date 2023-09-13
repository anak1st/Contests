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

== ST表
#let text = read("templates/DataStructure/ST.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 2
= 基本算法
== 排序
#let text = read("templates/Base/Sort.hpp")
#raw(text, lang: "cpp")

== 离散
#let text = read("templates/Base/Discrete.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 3
= 图论
== 最小生成树
=== Kruskal
#let text = read("templates/Graph/Kruskal.hpp")
#raw(text, lang: "cpp")

=== Prim
#let text = read("templates/Graph/Prim.hpp")
#raw(text, lang: "cpp")

== 最短路
=== Dijkstra
#let text = read("templates/Graph/Dijkstra.hpp")
#raw(text, lang: "cpp")

// === Floyd
// #let text = read("templates/Graph/Floyd.hpp")
// #raw(text, lang: "cpp")

== 求最大匹配 / 网络流
=== Augment Path (增广路)
#let text = read("templates/Graph/AugmentPath.hpp")
#raw(text, lang: "cpp")

=== Hopcroft Karp
#let text = read("templates/Graph/HopcroftKarp.hpp")
#raw(text, lang: "cpp")

=== 最大流 (Dinic)
#let text = read("templates/Graph/MaxFlow.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 4
= DP
== 背包
#let text = read("templates/DP/KP.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 5
= 计算几何
== Circle
#let text = read("templates/Geometry/Circle.hpp")
#raw(text, lang: "cpp")

== Vector
#let text = read("templates/Geometry/Vector2.hpp")
#raw(text, lang: "cpp")

#pagebreak()
// 6
= 数论
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

#pagebreak()
// 7
= 字符串
== KMP
#let text = read("templates/String/KMP.hpp")
#raw(text, lang: "cpp")

== AC自动机
=== AC自动机 (1)
#let text = read("templates/String/ACAuto_1.hpp")
#raw(text, lang: "cpp")

=== AC自动机 (2)
#let text = read("templates/String/ACAuto_2.hpp")
#raw(text, lang: "cpp")

== Trie
#let text = read("templates/String/Trie.hpp")
#raw(text, lang: "cpp")