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
    int height(Node* node){
        if(node == nullptr) return 0;
        int left = height(node->left);
        int right = height(node->right);
        return max(left,right)+1;
    }
    int heightFactor(Node* node){
        return height(node->left)-height(node->right);
    }
    Node* insert(){
        int val;
        cout<<"Enter data :";
        cin>>val;
        if(val == -1) return nullptr;
        Node* node= new Node(val);
        cout<<"Enter the right of "<<val<<" :";
        node->right = insert();
        int heightfactor = heightFactor(node);
        if(heightfactor < -1){ //RR rotation
            Node* x = node->right;
            Node* y = x->left;
            x->left = node;
            node->right = y;
            return x; 
        }
        else return node;
    }
};
int main(){
    AVLtree tree;
    tree.head=tree.insert();
    cout<<endl<<"root ->"<<tree.head->data;
    AVLtree t;
    t.head=t.enter();
    cout<<endl<<"head->"<<t.head->data;
    return 0;
}