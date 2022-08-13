#include <algorithm>
#include <iostream>
#include <queue>

template<typename T> T fpower(int a, int x) {
    T res = 1;
    while(x) {
        if(x % 2) {
            res = (res * a);
        }
        x /= 2;
        a = (a * a);
    }
    return res;
}

struct point {
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}

    friend bool operator==(const point &lhs, const point &rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y);
    }

    friend bool operator<(const point &lhs, const point &rhs) {
        if(lhs.x == rhs.x) {
            return (lhs.y < rhs.y);
        }
        return (lhs.x < rhs.x);
    }
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m, len, bit;
bool vis[20][20][16384], blank[20][20];

struct snake {
    point head;
    int hash, s;
    snake(point head, int hash = 0, int s = 0) : head(head), hash(hash), s(s) {}
    bool block(const point &p) {
        point temp = head;
        int temp_hash = hash;
        for(int i = 0; i < len - 1; ++i) {
            int d = temp_hash % 4;
            temp_hash /= 4;
            temp.x -= dx[d];
            temp.y -= dy[d];
            if(temp == p) {
                return true;
            }
        }
        return false;
    }
};

int bfs(const point &start, int start_hash) {
    std::queue<snake> q;
    q.push(snake(point(start.x, start.y), start_hash));
    vis[start.x][start.y][start_hash] = true;

    while(!q.empty()) {
        snake now = q.front();
        q.pop();

        if(now.head == point(0, 0)) {
            return now.s;
        }
        for(int d = 0; d < 4; d++) {
            int tx = now.head.x + dx[d];
            int ty = now.head.y + dy[d];
            if(tx < 0 || ty < 0 || tx >= n || ty >= m || !blank[tx][ty]) {
                continue;
            }
            if(!now.block(point(tx, ty))) {
                // remove front 2 bit
                int new_hash = (now.hash * 4) & (bit - 1);
                // push_back 2 new bit
                new_hash += d;

                if(!vis[tx][ty][new_hash]) {
                    vis[tx][ty][new_hash] = true;
                    q.push(snake(point(tx, ty), new_hash, now.s + 1));
                }
            }
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for(int test = 1; true; test++) {
        std::cin >> n >> m >> len;
        if(n == 0 && m == 0 && len == 0) {
            break;
        }

        bit = fpower<int>(4, len - 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                blank[i][j] = 1;
                for(int k = 0; k < bit; k++) {
                    vis[i][j][k] = 0;
                }
            }
        }

        int x, y;
        std::cin >> x >> y;
        x--, y--;
        point start(x, y);

        int start_hash = 0, px = start.x, py = start.y;
        for(int i = 0; i < len - 1; i++) {
            std::cin >> x >> y;
            x--, y--;
            for(int d = 0; d < 4; d++) {
                if(px - dx[d] == x && py - dy[d] == y) {
                    // push_back 2 new bit
                    start_hash += d << (i * 2);
                    px = x;
                    py = y;
                    break;
                }
            }
        }

        int stones;
        std::cin >> stones;
        while(stones--) {
            std::cin >> x >> y;
            x--, y--;
            blank[x][y] = 0;
        }

        std::cout << "Case " << test << ": " << bfs(start, start_hash) << "\n";
    }
    return 0;
}
