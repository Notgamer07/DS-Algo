#include<iostream>
#include<vector>
using namespace std;

#define V 5
void bellford(int graph[V][V], int src){
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    for(int k=0; k<V-1; k++){
    for(int i=0; i<V; i++){
    for(int j=0; j<V; j++){
        if (graph[i][j] != 0 && dist[i] != INT_MAX &&
                    dist[j] + graph[i][j] < dist[j]){
                        dist[j] = dist[i] + graph[i][j]; 
                    }
    }
    }
    }
    for (int u = 0; u < V; u++) {
    for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                cout << "Graph contains a negative weight cycle!" << endl;
                return;
            }
        }
    }

    cout << "Vertex\tDistance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << "\t" << "INF" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}

int main(){
    int graph[V][V] = {
        {0, 6, 0, 7, 0},
        {0, 0, 5, 8, -4},
        {0, -2, 0, 0, 0},
        {0, 0, -3, 0, 9},
        {2, 0, 7, 0, 0}
    };
    bellford(graph,0);
}