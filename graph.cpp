#include<iostream>
using namespace std;
int main(){
    int node, routes;
    cin>>node>>routes;
    int graph[node+1][node+1];
    for (int i=0;i<routes;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v] = 1;
    }
    for(int i=0;i<routes;i++){
        for (int j=0;j<routes;j++){
            if (graph[i][j] == 1){
                cout<<i<<"<->"<<j<<endl;
            }
        }
    }
}