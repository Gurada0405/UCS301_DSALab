#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    Edge* edges;
    
    Graph(int v, int e) {
        V = v;
        E = e;
        edges = new Edge[e];
    }
    
    ~Graph() {
        delete[] edges;
    }
};

class GraphAlgorithms {
private:
    int find(int parent[], int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }
    
    void unionSets(int parent[], int rank[], int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        
        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
    
    void sortEdges(Edge edges[], int n) {
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (edges[j].weight > edges[j+1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j+1];
                    edges[j+1] = temp;
                }
            }
        }
    }
    
    int minKey(int key[], bool mstSet[], int V) {
        int min = 1000000, min_index;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

public:
    void BFS(int** graph, int V, int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        
        int* queue = new int[V];
        int front = 0, rear = 0;
        
        visited[start] = true;
        queue[rear++] = start;
        
        cout << "BFS Traversal: ";
        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";
            
            for (int i = 0; i < V; i++) {
                if (graph[current][i] && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
        
        delete[] visited;
        delete[] queue;
    }
    
    void DFSUtil(int** graph, int V, int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        
        for (int i = 0; i < V; i++) {
            if (graph[v][i] && !visited[i]) {
                DFSUtil(graph, V, i, visited);
            }
        }
    }
    
    void DFS(int** graph, int V, int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        
        cout << "DFS Traversal: ";
        DFSUtil(graph, V, start, visited);
        cout << endl;
        
        delete[] visited;
    }
    
    void kruskalMST(Graph* graph) {
        int V = graph->V;
        Edge* result = new Edge[V-1];
        int e = 0;
        int i = 0;
        
        sortEdges(graph->edges, graph->E);
        
        int* parent = new int[V];
        int* rank = new int[V];
        
        for (int v = 0; v < V; v++) {
            parent[v] = v;
            rank[v] = 0;
        }
        
        while (e < V - 1 && i < graph->E) {
            Edge next_edge = graph->edges[i++];
            
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);
            
            if (x != y) {
                result[e++] = next_edge;
                unionSets(parent, rank, x, y);
            }
        }
        
        cout << "Kruskal's MST:\n";
        int totalWeight = 0;
        for (i = 0; i < e; i++) {
            cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
            totalWeight += result[i].weight;
        }
        cout << "Total weight: " << totalWeight << endl;
        
        delete[] result;
        delete[] parent;
        delete[] rank;
    }
    
    void primMST(int** graph, int V) {
        int* parent = new int[V];
        int* key = new int[V];
        bool* mstSet = new bool[V];
        
        for (int i = 0; i < V; i++) {
            key[i] = 1000000;
            mstSet[i] = false;
        }
        
        key[0] = 0;
        parent[0] = -1;
        
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet, V);
            mstSet[u] = true;
            
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        
        cout << "Prim's MST:\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
            totalWeight += graph[i][parent[i]];
        }
        cout << "Total weight: " << totalWeight << endl;
        
        delete[] parent;
        delete[] key;
        delete[] mstSet;
    }
    
    void dijkstra(int** graph, int V, int src) {
        int* dist = new int[V];
        bool* sptSet = new bool[V];
        
        for (int i = 0; i < V; i++) {
            dist[i] = 1000000;
            sptSet[i] = false;
        }
        
        dist[src] = 0;
        
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(dist, sptSet, V);
            sptSet[u] = true;
            
            for (int v = 0; v < V; v++) {
                if (!sptSet[v] && graph[u][v] && dist[u] != 1000000 && 
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        
        cout << "Dijkstra's Shortest Path from vertex " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
        
        delete[] dist;
        delete[] sptSet;
    }
    
    int** createGraph(int V) {
        int** graph = new int*[V];
        for (int i = 0; i < V; i++) {
            graph[i] = new int[V];
            for (int j = 0; j < V; j++) {
                graph[i][j] = 0;
            }
        }
        return graph;
    }
    
    void deleteGraph(int** graph, int V) {
        for (int i = 0; i < V; i++) {
            delete[] graph[i];
        }
        delete[] graph;
    }
};

int main() {
    GraphAlgorithms algo;
    int V = 5;
    
    int** graph = algo.createGraph(V);
    
    graph[0][1] = 2; graph[1][0] = 2;
    graph[0][3] = 6; graph[3][0] = 6;
    graph[1][2] = 3; graph[2][1] = 3;
    graph[1][3] = 8; graph[3][1] = 8;
    graph[1][4] = 5; graph[4][1] = 5;
    graph[2][4] = 7; graph[4][2] = 7;
    graph[3][4] = 9; graph[4][3] = 9;
    
    cout << "=== Graph Algorithms ===\n\n";
    
    algo.BFS(graph, V, 0);
    cout << endl;
    
    algo.DFS(graph, V, 0);
    cout << endl;
    
    Graph* g = new Graph(V, 7);
    g->edges[0] = {0, 1, 2};
    g->edges[1] = {0, 3, 6};
    g->edges[2] = {1, 2, 3};
    g->edges[3] = {1, 3, 8};
    g->edges[4] = {1, 4, 5};
    g->edges[5] = {2, 4, 7};
    g->edges[6] = {3, 4, 9};
    
    algo.kruskalMST(g);
    cout << endl;
    
    algo.primMST(graph, V);
    cout << endl;
    
    algo.dijkstra(graph, V, 0);
    
    delete g;
    algo.deleteGraph(graph, V);
    
    return 0;
}