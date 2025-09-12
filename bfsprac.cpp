#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> &graph, int start){
    int n = graph.size();
    vector<bool> visited(n,false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout<<"Node "<<node<<" : ";
        for(int connection : graph[node]){
            cout<<connection<<"->";
            if(!visited[connection]){
                q.push(connection);
                visited[connection] = true;
            }
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> graph = {
        {1,2}
        ,{0,4}
        ,{0,3}
        ,{1,2,5}
        ,{1,5}
        ,{3,4}
    };
    bfs(graph,0);
}