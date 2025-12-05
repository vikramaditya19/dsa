#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int V; // number of vertices
    vector<vector<pair<int,int>>> adj; // (node, weight)
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w = 1, bool undirected = true) {
        adj[u].push_back({v, w});
        if (undirected)
            adj[v].push_back({u, w});
    }

    // -----------------------------------------------------------
    // 1. BFS
    // -----------------------------------------------------------
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS : ";
        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for (auto &p : adj[node]) {
                int neigh = p.first;
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << endl;
    }

    // -----------------------------------------------------------
    // 2. DFS (recursive)
    // -----------------------------------------------------------
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto &p : adj[node]) {
            int neigh = p.first;
            if (!visited[neigh])
                DFSUtil(neigh, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS : ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // -----------------------------------------------------------
    // 3. Minimum Spanning Tree – Kruskal
    // -----------------------------------------------------------
    struct Edge {
        int u, v, w;
    };

    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int a, int b) {
            a = find(a); b = find(b);
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    };

    void KruskalMST() {
        vector<Edge> edges;

        // Create edge list
        for (int u = 0; u < V; u++) {
            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if (u < v)  // avoid duplicates
                    edges.push_back({u, v, w});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](Edge &a, Edge &b) { return a.w < b.w; });

        DSU dsu(V);
        int mstWeight = 0;

        cout << "Kruskal MST edges: \n";
        for (auto &e : edges) {
            if (dsu.find(e.u) != dsu.find(e.v)) {
                dsu.unite(e.u, e.v);
                mstWeight += e.w;
                cout << e.u << " -- " << e.v << "  (w=" << e.w << ")\n";
            }
        }
        cout << "Total MST Weight = " << mstWeight << "\n";
    }

    // -----------------------------------------------------------
    // 4. Minimum Spanning Tree – Prim's Algorithm
    // -----------------------------------------------------------
    void PrimMST(int start = 0) {
        vector<bool> inMST(V, false);
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>
        > pq;  // (weight, node)

        pq.push({0, start});
        int mstWeight = 0;

        cout << "Prim's MST edges:\n";

        while (!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();

            if (inMST[node]) continue;
            inMST[node] = true;
            mstWeight += w;

            if (w != 0)
                cout << "Included node: " << node << " (w=" << w << ")\n";

            for (auto &p : adj[node]) {
                int neigh = p.first;
                int weight = p.second;
                if (!inMST[neigh])
                    pq.push({weight, neigh});
            }
        }

        cout << "Total MST Weight = " << mstWeight << "\n";
    }

    // -----------------------------------------------------------
    // 5. Dijkstra's Shortest Path Algorithm
    // -----------------------------------------------------------
    void Dijkstra(int start) {
        vector<int> dist(V, 1e9);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for (auto &p : adj[node]) {
                int neigh = p.first;
                int weight = p.second;

                if (dist[neigh] > d + weight) {
                    dist[neigh] = d + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        cout << "Dijkstra Distances from " << start << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " = " << dist[i] << "\n";
    }
};


// ==========================================================
// MAIN DRIVER
// ==========================================================
int main() {
    Graph g(5);

    // Sample weighted graph for MST + Dijkstra
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);

    cout << endl;
    g.BFS(0);
    g.DFS(0);

    cout << "\n=== Kruskal ===\n";
    g.KruskalMST();

    cout << "\n=== Prim ===\n";
    g.PrimMST();

    cout << "\n=== Dijkstra ===\n";
    g.Dijkstra(0);

    return 0;
}
