#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data = val;
        right = left = nullptr;
    }
};  
class BinaryTree{
public:
    Node* root; 
    BinaryTree(){
        root = nullptr;
    }
    Node* insert(){
        cout<<"Enter data";
        int val;
        cin>>val;
        if(val == -1) {
            return nullptr;
        }
        Node* node = new Node(val);
        cout<<"Enter the left node of "<<val<<endl;
        node->left = insert();
        cout<<"Enter the right  node of "<<val<<endl;
        node->right = insert();
        return node;
    }
};
int LeafCount(Node* node){
    if(node == nullptr) return 0;
    if(node->left == nullptr && node->right == nullptr){
        return 1;
    }
    return LeafCount(node->left) + LeafCount(node->right);
}
int main(){
    BinaryTree tree;
    tree.root = tree.insert();
    cout<<"\n Number of Leaf equal to "<<LeafCount(tree.root);
    return 0;
}