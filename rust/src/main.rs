// #![allow(unused)]
use std::cmp::{max, min};
// use std::io::{stdin, stdout, BufWriter, Read, Write};
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet, VecDeque};
use std::mem::swap;
use std::vec;
// use proconio::input;

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn read<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.split_whitespace().map(|x| x.parse().ok().unwrap()).collect()
}

fn fast_pow(mut a: i64, mut b: i64, m: i64) -> i64 {
    let mut res = 1;
    while b > 0 {
        if b % 2 == 1 {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    res
}

fn solve(scan: &mut Scanner) {
    let mut shape = read_vec::<usize>();
    let mut cuboid = Vec::new();
    for _ in 0..shape[0] {
        let mut reactangle = Vec::new();
        for _ in 0..shape[1] {
            reactangle.push(scan.read::<String>().as_bytes().to_vec());
        }
        cuboid.push(reactangle);
    }
    // println!("{:?}", cuboid);
    let mut start = vec![0, 0, 0];
    for i in 1..3 {
        start[i] = scan.read::<usize>() - 1;
    }

    let bfs = |_x: usize, _y: usize, _z: usize| {
        let mut queue = VecDeque::new();
        queue.push_back((_x, _y, _z, 1_i64));
        let mut vis = vec![vec![vec![0; shape[2]]; shape[1]]; shape[0]];
        let d = vec![(0, 0, 1), (0, 0, -1), (0, 1, 0), (0, -1, 0), (1, 0, 0), (-1, 0, 0)];
        let mut ans = 0_i64;
        while !queue.is_empty() {
            let (x, y, z, step) = queue.pop_front().unwrap();
            if vis[x][y][z] != 0 {
                continue;
            }
            vis[x][y][z] = step;
            ans += 1;
            for i in 0..d.len() {
                let nx = x as i64 + d[i].0;
                let ny = y as i64 + d[i].1;
                let nz = z as i64 + d[i].2;
                if nx >= 0 && nx < shape[0] as i64 
                && ny >= 0 && ny < shape[1] as i64 
                && nz >= 0 && nz < shape[2] as i64 {
                    let nx = nx as usize;
                    let ny = ny as usize;
                    let nz = nz as usize;
                    if vis[nx][ny][nz] == 0 && cuboid[nx][ny][nz] == b'.' {
                        queue.push_back((nx, ny, nz, step + 1));
                    }
                }
            }
        }
        return ans;
    };

    let mut ans = bfs(start[0], start[1], start[2]);

    println!("{}", ans);
}

fn main() {
    let mut scan = Scanner::default();
    let mut t = 1;
    // t = scan.read::<usize>();
    for _ in 0..t {
        solve(&mut scan);
    }
}
