# 这是 C-- !
C++的语法太复杂了，于是人们发明了C--，这种语言语法更加优美，不需要声明变量类型，类型明明可以通过自动推导而得出！
为了大道至简，这种语言只有两种语句，`let` 和 `println!`，`let` 用来声明变量，`println!` 用来输出。

## let name = val;
声明一个变量，如果变量被 `""` 包裹，那么 val 就是一个字符串，否则 val 就是一个整数
- `let` 声明的变量只有两种**整数**和**字符串**，不会有超出 int 范围的数字，也不会有小数，字符串长度**不**会超过 1e5
字符串由以下字符组成
- `0` ~ `9`
- `a` ~ `z`
- `A` ~ `Z`
- `.,;:?!{}[]()+-=*/%` （标点符号）

## println!("format", args...);
format 只由一下符号组成
- `{}` （占位符，自己不输出，逐步输出参数内容）
- `0` ~ `9`
- `a` ~ `z`
- `A` ~ `Z`
- ` ` （空格！）
注意，最后需要输出回车！
`println!()` 中的占位符 `{}` 会被后面的参数替换，参数之间用 `,` 分隔，参数数量和占位符数量一定相等，占位符数量不会超过 10 个，参数数量不会超过 10 个，参数类型和变量类型一样，参数中的变量一定是声明过的。

## 占位符
占位符数量一定和 args 数量相当，占位符数量一定和参数数量相当，用于被替换以输出变量/参数，比如：
``` Rust
println!("str");
println!("str{}", args1);
println!("str{}str{}", args1, args2);
println!("str{}str{}str{}", args1, args2, args3);
...
```
相当于 C++
``` C++
std::cout << "str" << std::endl;
std::cout << "str" << args1 << std::endl;
std::cout << "str" << args1 << "str" << args2 << std::endl;
std::cout << "str" << args1 << "str" << args2 << "str" << args3 << std::endl;
...
```
对于 C
``` C
// 假设 args1, args2 都是 int， args3 是 char[]
printf("str\n");
printf("str%d\n", args1);
printf("str%dstr%d\n", args1, args2);
printf("str%dstr%dstr%s\n", args1, args2, args3);
...
```

## 保证
- 每个语句之间没有空行，总共只有两种语句
- 每个语句前没有空格，最后是`;`，语句数量不超过 10，以下是具体格式
  - `let x = y;`，
    - 保证 `let` 后、`=` 连边有空格
    
  - `println!("str{}str{}", arg1, arg2);`
    - 保证每个 `,` 后有空格


# 例子
**in**
``` Rust
let a = "rust";
let b = "C--";
println!("{} is {}", a, b);
```
**out**
```
rust is C--
C-- is rust
```
