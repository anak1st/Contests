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
  title: "ICPC模板（临时） 2023.10",
  authors: (
    "夏凡",
  ),
)

// 目录
#outline()

#pagebreak()

= 计算几何

== Vector2
#let text = read("templates/Geometry/Vector2.hpp")
#raw(text, lang: "cpp")

== Vector3
#let text = read("templates/Geometry/Vector3.hpp")
#raw(text, lang: "cpp")

#pagebreak()

= 数论

== 自动取模
#let text = read("templates/Number/Mint.hpp")
#raw(text, lang: "cpp")

== 组合数
#let text = read("templates/Number/Comb.hpp")
#raw(text, lang: "cpp")

== 大数
#let text = read("templates/Number/Interger2.hpp")
#raw(text, lang: "cpp")
