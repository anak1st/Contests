#pragma once
#include "XCPC.h"

struct HopcroftKarp {
    int m;
    int n;
    const int NIL{0};
    const int INF{INT_MAX};

    std::vector<std::vector<int>> adj;

    std::vector<int> pair_u;  ///< value of vertex 'u' ranges from 1 to m
    std::vector<int> pair_v;  ///< value of vertex 'v' ranges from 1 to n
    std::vector<int> dist;    ///< dist represents the distance between vertex 'u' and vertex 'v'

    HopcroftKarp(int _m, int _n) : m(_m), n(_n) { 
        adj = std::vector<std::vector<int>>(_m + 1); 
    }

    void addEdge(int u, int v) {
        assert(1 <= u && u <= m);
        assert(1 <= v && v <= n);
        adj[u].push_back(v);
    }

    /**
     * @brief This functions checks whether an augmenting path is available
     * exists beginning with free vertex u
     * @param u represents position of vertex
     * @returns `true` if there is an augmenting path beginning with free vertex u
     */
    bool dfs(int u) {
        if (u != NIL) {
            for (auto v : adj[u]) {
                // Follow the distances set by BFS search
                if (dist[pair_v[v]] == dist[u] + 1) {
                    // If dfs for pair of v also return true then new matching
                    // possible, store the matching
                    if (dfs(pair_v[v]) == true) {
                        pair_v[v] = u;
                        pair_u[u] = v;
                        return true;
                    }
                }
            }

            dist[u] = INF;  // If there is no augmenting path beginning with u
                            // then set distance to infinite.
            return false;
        }
        return true;
    }

    /**
     * @brief This function checks for the possibility of augmented path
     * availability
     * @returns `true` if there is an augmenting path available
     */
    bool bfs() {
        std::queue<int> q;  // an integer queue for bfs

        // First layer of vertices (set distance as 0)
        for (int u = 1; u <= m; u++) {
            // If this is a free vertex, add it to queue
            if (pair_u[u] == NIL) {
                dist[u] = 0;  // u is not matched so distance is 0
                q.push(u);
            }

            else {
                dist[u] = INF;  // set distance as infinite so that this vertex
                                // is considered next time for availibility
            }
        }

        dist[NIL] = INF;  // Initialize distance to NIL as infinite

        // q is going to contain vertices of left side only.
        while (!q.empty()) {
            int u = q.front();  // dequeue a vertex
            q.pop();

            // If this node is not NIL and can provide a shorter path to NIL
            // then
            if (dist[u] < dist[NIL]) {
                // Get all the adjacent vertices of the dequeued vertex u
                for (auto v : adj[u]) {
                    // If pair of v is not considered so far i.e. (v, pair_v[v])
                    // is not yet explored edge.
                    if (dist[pair_v[v]] == INF) {
                        dist[pair_v[v]] = dist[u] + 1;
                        q.push(pair_v[v]);  // Consider the pair and push it to queue
                    }
                }
            }
        }

        return (dist[NIL] != INF);  // If we could come back to NIL using alternating path of
                                    // distinct vertices then there is an augmenting path
                                    // available
    }

    /**
     * @returns size of maximum matching
     */
    int solve() {
        // pair_u[u] stores pair of u in matching on left side of Bipartite
        // Graph. If u doesn't have any pair, then pair_u[u] is NIL
        pair_u = std::vector<int>(m + 1, NIL);

        // pair_v[v] stores pair of v in matching on right side of Biparite
        // Graph. If v doesn't have any pair, then pair_u[v] is NIL
        pair_v = std::vector<int>(n + 1, NIL);

        dist = std::vector<int>(m + 1);  // dist[u] stores distance of left side vertices

        int result = 0;  // Initialize result

        // Keep updating the result while there is an augmenting path possible.
        while (bfs()) {
            // Find a free vertex to check for a matching
            for (int u = 1; u <= m; u++) {
                // If current vertex is free and there is
                // an augmenting path from current vertex
                // then increment the result
                if (pair_u[u] == NIL && dfs(u)) {
                    result++;
                }
            }
        }
        return result;
    }
};
