#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=3;
    vector<vector<int>> graph(n);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(0);
    graph[2].push_back(0);
    for (vector<int> i : graph){
        for(int ne : i){
            cout<<ne<<" ";
        }
        cout<<endl;
    }
}