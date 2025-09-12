#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> &graph, int start){
    queue<int> q;
    int n = graph.size();
    vector<bool> visited(n,false);
    q.push(start);
    visited[start] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int ne:graph[node]){
            cout<<"->"<<ne;
            if(!visited[ne]){
            q.push(ne);
            visited[ne] = true;
           }
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> gp =  {
        {1, 2},    // neighbors of 0
        {0, 3, 4}, // neighbors of 1
        {0,4},       // neighbors of 2
        {1,3},       // neighbors of 3
        {1,2,4}        // neighbors of 4
    };
    bfs(gp, 1);
}