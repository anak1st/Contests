fn read_str() -> String {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    buf.trim().to_string()
}

fn read<T: std::str::FromStr>() -> T {
    read_str().parse().ok().unwrap()
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read_str().split_whitespace().map(|e| e.parse().ok().unwrap()).collect()
}

fn solve() {
    let n = read::<usize>();
    let mut a = read_vec::<i64>();
    a.sort();
    let sum = a.iter().sum::<i64>();
    println!("let vec[{}] = {:?}, sum = {}", n, a, sum);
}

fn main() {
    let t = read::<usize>();
    for _ in 0..t {
        solve();
    }
}