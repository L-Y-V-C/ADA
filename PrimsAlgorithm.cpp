#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Graph {
    int n;
    std::vector<std::vector<int>> G;
    Graph(int in_n) : n(in_n), G(in_n, std::vector<int>(in_n, -1)) {}
    void addEdge(int x, int y, int w) {
        G[x][y] = G[y][x] = w;
    }
};

void primsAlgorithm(const Graph& graph) {
    int n = graph.n;
    std::vector<int> key(n, std::numeric_limits<int>::max());
    std::vector<int> parent(n, -1);
    std::vector<bool> inMST(n, 0);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    key[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph.G[u][v] != -1 && !inMST[v] && graph.G[u][v] < key[v]) {
                key[v] = graph.G[u][v];
                parent[v] = u;
                pq.push({ key[v], v });
            }
        }
    }
    int totalEdgeWeight = 0;
    printf("Orden de seleccion del MST:\n\nRaiz: %d\n", parent[1]);
    for (int v = 1; v < n; v++) {
        if (parent[v] != -1) {
            printf(" %d --- %d , peso: %d\n", parent[v], v, graph.G[parent[v]][v]);
            totalEdgeWeight += graph.G[parent[v]][v];
        }
    }
    printf("\nPeso total de las aristas del MST: %d\n", totalEdgeWeight);
}

int
main() {
    // n -> cantidad de nodos
    int n = 8;

    Graph graph(n);
    graph.addEdge(0, 1, 7);
    graph.addEdge(0, 4, 10);
    graph.addEdge(0, 7, 15);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 12);
    graph.addEdge(1, 6, 9);
    graph.addEdge(2, 3, 6);
    graph.addEdge(2, 4, 8);
    graph.addEdge(2, 5, 14);
    graph.addEdge(4, 5, 3);

    primsAlgorithm(graph);
}
