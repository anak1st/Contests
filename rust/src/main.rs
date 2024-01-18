#![allow(unused_imports)]
use std::cmp::{max, min};
use std::io::{stdin, stdout, BufWriter, Write};

struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn new() -> Self {
        Scanner {
            buffer: Vec::<String>::new(),
        }
    }
    fn read<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
    fn read_vector<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.read::<T>()).collect::<Vec<_>>()
    }
}

fn solve(scan: &mut Scanner) {
    let n = scan.read::<usize>();
    let f = scan.read::<i64>();
    let a = scan.read::<i64>();
    let b = scan.read::<i64>();
    let m = scan.read_vector::<i64>(n);
    
    let mut ans = min(m[0] * a, b);
    
    for i in 0..(n - 1) {
        let dif = m[i + 1] - m[i];
        ans += min(dif * a, b);
    }

    if f > ans {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    let mut scan = Scanner::new();
    // let stdout = stdout();
    // let mut writer = BufWriter::new(stdout.lock());

    let t = scan.read::<usize>();
    for _ in 0..t {
        solve(&mut scan);
    }
}
