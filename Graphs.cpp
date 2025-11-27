#include <iostream>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

struct Graph {
    int V;                     
    vector<vector<pair<int,int>>> adj; // (neighbor, weight)
    vector<Edge> edges;      

    Graph(int n = 0) {
        V = n;
        adj.assign(V, {});
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});    
        edges.push_back({u, v, w});
    }
};

//  BFS 
void BFS(const Graph &g, int src) {
    vector<bool> vis(g.V, false);
    queue<int> q;
    vis[src] = true;
    q.push(src);

    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (auto [v, w] : g.adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

// DFS (recursive) 
void dfsUtil(const Graph &g, int u, vector<bool> &vis) {
    vis[u] = true;
    cout << u << " ";
    for (auto [v, w] : g.adj[u]) {
        if (!vis[v]) dfsUtil(g, v, vis);
    }
}
void DFS(const Graph &g, int src) {
    vector<bool> vis(g.V, false);
    cout << "DFS: ";
    dfsUtil(g, src, vis);
    cout << "\n";
}

// Kruskal (MST) 
struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        p.resize(n);
        r.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

void MST_Kruskal(Graph &g) {
    vector<Edge> e = g.edges;
    sort(e.begin(), e.end(), [](const Edge &a, const Edge &b){
        return a.w < b.w;
    });
    DSU dsu(g.V);
    int mst_wt = 0;

    cout << "Kruskal MST edges:\n";
    for (auto &ed : e) {
        if (dsu.unite(ed.u, ed.v)) {
            cout << ed.u << " - " << ed.v << "  wt = " << ed.w << "\n";
            mst_wt += ed.w;
        }
    }
    cout << "Total weight = " << mst_wt << "\n";
}

//  Prim
void MST_Prim(const Graph &g, int src) {
    const int INF = 1e9;
    vector<int> key(g.V, INF), parent(g.V, -1);
    vector<bool> inMST(g.V, false);

    key[src] = 0;
    // (key, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [k, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto [v, w] : g.adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Prim MST edges:\n";
    int mst_wt = 0;
    for (int v = 0; v < g.V; ++v) {
        if (parent[v] != -1) {
            cout << parent[v] << " - " << v << "  wt = " << key[v] << "\n";
            mst_wt += key[v];
        }
    }
    cout << "Total weight = " << mst_wt << "\n";
}

// Dijkstra (single-source shortest path)
void Dijkstra(const Graph &g, int src) {
    const int INF = 1e9;
    vector<int> dist(g.V, INF);
    dist[src] = 0;

    // (dist, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g.adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra distances from " << src << ":\n";
    for (int i = 0; i < g.V; ++i)
        cout << "Vertex " << i << " : " << dist[i] << "\n";
}


int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter edges (u v w) 0-indexed:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src = 0;               
    cout << "Enter source vertex for traversals and Dijkstra: ";
    cin >> src;

    BFS(g, src);
    DFS(g, src);
    MST_Kruskal(g);
    MST_Prim(g, src);
    Dijkstra(g, src);

    return 0;
}


// aditional ques
//Q1
#include <iostream>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);        // undirected
    }

    vector<bool> vis(V, false);
    int components = 0;

    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            components++;
            // BFS/DFS from i
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << components << "\n";
    return 0;
}

//Q2
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    const int INF = 1e9;
    vector<vector<int>> dist(m, vector<int>(n, INF));
    dist[0][0] = grid[0][0];          // include cost of starting cell if required

    using State = pair<int, pair<int,int>>; // (dist, (x,y))
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({dist[0][0], {0,0}});

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int d = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;
        if (d != dist[x][y]) continue;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            int w = grid[nx][ny];    // cost of destination cell
            if (dist[x][y] + w < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + w;
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    cout << dist[m-1][n-1] << "\n";
    return 0;
}


