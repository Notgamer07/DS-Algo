#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int ed){
    int pvt = arr[ed];
    int i = st, j = st;
    while(j<ed){
        if(arr[j]<pvt){
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i],arr[ed]);
    return i;
}
void quickSort(vector<int> &arr, int st, int end){
    if(st<end){
        int idx = partition(arr,st,end);
        quickSort(arr,st,idx-1);
        quickSort(arr,idx+1,end);
    }
}

int main(){
    vector<int> arr = {12,35,31,8,32,17};
    quickSort(arr,0,arr.size()-1);
    for(int i:arr) cout<<i<<" ";
}
