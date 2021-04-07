#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

const int MAX_SIZE = 100;
 
class disjoint_set {
private:
    int components;
    int id[MAX_SIZE];
    int sizeof_ids[MAX_SIZE];
    int n;
 
public:
    disjoint_set(int n)
        :components(n), n(n) {
        for (int i = 0; i < components; ++i) {
            id[i] = i;
            sizeof_ids[i] = 1;
        }
    }
 
    void join(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) {
            return;
        }
        if (sizeof_ids[i] < sizeof_ids[j]) {
            id[i] = j;
            sizeof_ids[j] += sizeof_ids[i];
            sizeof_ids[i] = 1;
        } else {
            id[j] = i;
            sizeof_ids[i] += sizeof_ids[j];
            sizeof_ids[j] = 1;
        }
        components--;
    }
 
    int find(int p) {
        if (p != id[p]) {
            id[p] = find(id[p]);
        }
        return id[p];
    }
 
    bool is_connected(int p, int q) {
        return find(p) == find(q);
    }
 
    int size() const {
        return components;
    }
};

struct edge {
    int u;
    int v;
    int cost;
 
    edge(int v, int cost)
        :v(v), cost(cost) {
    }
 
    
    bool operator >(const edge &e) const {
        return (cost != e.cost ? cost > e.cost : v > e.v);
    }
    edge(int u, int v, int cost)
        :u(u), v(v), cost(cost) {
    }
 
    
    bool operator <(const edge &e) const {
        return cost < e.cost;
    }
};
 

typedef std::priority_queue<edge, std::vector<edge>, std::greater<edge>> min_heap;

const int oo = std::numeric_limits<int>::max();

const int MAX_VERTEX = 100;

bool seen[MAX_VERTEX];

std::vector<std::vector<int>> adj(MAX_VERTEX);

std::vector<std::vector<int>> cost(MAX_VERTEX, std::vector<int>(MAX_VERTEX, oo));

min_heap pq;
 
void relax(int u) {
    seen[u] = true;
    for (auto v : adj[u]) {
        if (!seen[v]) {
            pq.push(edge(v, cost[u][v]));
        }
    }
}
 


void printGraph(int N)
{
    for (int i = 0; i < N; i++)
    {

        std::cout << i << " --> ";
        
        for (int v : adj[i])
            std::cout << v << " ";
        std::cout << std::endl;
    }
}

int prim(int s) {
    int min_cost = 0;
    relax(s);
    while (!pq.empty()) {
        
        edge e = pq.top();
        pq.pop();
        if (!seen[e.v]) {
            min_cost += e.cost;
            relax(e.v);
        }
    }
    return min_cost;
}

std::vector<edge> edges;
 
int kruskal(int no_vertex) {
    int min_cost = 0;
    std::sort(edges.begin(), edges.end());
    disjoint_set ds(no_vertex);
    for (auto e : edges) {
        if (!ds.is_connected(e.u, e.v)) {
            min_cost += e.cost;
            ds.join(e.u, e.v);
        }
    }
    return min_cost;
}

std::vector<int> dist(MAX_VERTEX, oo);
typedef std::pair<int, int> vertex;
void dijkstra(int s) {
    typedef std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int>> > min_heap;
    min_heap pq;
    dist[s] = 0;
    pq.push(vertex(0, s));
    while (!pq.empty()) {
        int u = pq.top().second;
        int cost_to_u = pq.top().first;
        pq.pop();
        if (dist[u] == cost_to_u) {
            for (auto v : adj[u]) {
                if (dist[v] > dist[u] + cost[u][v]) {
                    dist[v] = dist[u] + cost[u][v];
                    pq.push(vertex(dist[v], v));
                }
            }
        }
    }
}

void add_edge(int u, int v, int c) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cost[u][v] = c;
    cost[v][u] = c;
}
 
void test_minimum_spanning_tree() {
    int N = 7;
    add_edge(0, 1, 3);
    add_edge(0, 2, 3);
    add_edge(0, 3, 1);
    add_edge(0, 4, 2);
    add_edge(1, 2, 2);
    add_edge(2, 3, 11);
    add_edge(3, 4, 9);
    printGraph(N);
    std::cout << "min cost Prim: " << prim(0) << std::endl;
    edges.push_back(edge(0, 1, 3));
    edges.push_back(edge(0, 2, 3));
    edges.push_back(edge(0, 3, 1));
    edges.push_back(edge(0, 4, 2));
    edges.push_back(edge(1, 2, 2));
    edges.push_back(edge(2, 3, 11));
    edges.push_back(edge(3, 4, 9));
    printGraph(N);
    std::cout << "min cost Kruskal: " << kruskal(5) << std::endl;
    //Dijkstra 
    add_edge(0, 1, 13);
    add_edge(1, 2, 8);
    add_edge(2, 4, 1);
    add_edge(0, 2, 18);
    add_edge(0, 3, 20);
    add_edge(0, 4, 23);
    dijkstra(0);
    for (int v = 0; v <= 4; ++v) {
        std::cout << "shortest path from 0->" << v << ": " << dist[v] << "\n";
    }
}
 
int main() {
    test_minimum_spanning_tree();
    system("pause");
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 76d0d7e6529d5e44513576c00cdeb0ceb180d358
