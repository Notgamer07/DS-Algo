#include<iostream>
using namespace std;
#define N 100
class HashTable{
    public:
    int arr[N]={};
    void extract(int);
    void insert(int,int);
    int Hash(int);
};
int HashTable :: Hash(int key){
    int i = 0;
    int hash; 
    while((key+i)<N){
        hash = (key+i)%N;
        if(arr[hash] == 0){
            return hash;
        }
    }
    cout<<"Run Out of Memory"<<endl;
    return 0;
}
void HashTable :: insert(int key, int value){
    int hash = Hash(key);
    if(arr[hash] != 0){
        cout<<"HASH COLLISION !"<<endl;
        return;
    }
    arr[hash] = value;
    cout<<"Key value inserted successdully"<<endl;
}
void HashTable :: extract(int key){
    int hash = Hash(key);
    if(arr[hash] == 0){
        cout<<"Invalid Key";
        return ;
    }
    cout<<key<<" : "<<arr[hash]<<endl;
}

int main(){
    HashTable dict;
    dict.insert(20,90);
    dict.insert(220,40);
    dict.extract(20);
}