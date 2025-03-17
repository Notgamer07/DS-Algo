#include <iostream>
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
class AVLtree{
    public:
    Node* head;
    AVLtree(){
        head == nullptr;
    }
    Node* enter(){
        int val;
        cout<<"Enter data: ";
        cin>>val;
        if(val == -1) return nullptr;
        Node* node = new Node(val);
        cout<<"Enter the left of "<<val<<" :";
        node->left=enter();
        cout<<"Enter the right of "<<val<<" :";
        node->right=enter();
        return node;
    }
    void inorder(Node* node){
        if(node == nullptr) return;
        inorder(node->left);
        cout<<node->data<<"->";
        inorder(node->right);
    }
    void insert()
};
int main(){
    AVLtree tree;
    tree.head=tree.enter();
    tree.inorder(tree.head);
    return 0;
}