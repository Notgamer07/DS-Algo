#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int l){
    vector<int> temp;
    int i=s,j=mid+1;
    while (i<=mid && j<= l){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=l){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = 0; k<temp.size();k++){
        arr[k+s] = temp[k];
    }
}
void mergeSort(vector<int> &arr,int s,int l){
    if(s<l){
    int mid = (s + l) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, l);
    merge(arr, s, mid, l);     
    }
}
int main(){
    vector<int> ar = {23,34,56,74,34,56,34};
    mergeSort(ar,0,ar.size()-1);
    for(int i: ar) cout<<i<<" ";
}