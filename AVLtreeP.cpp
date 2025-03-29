#include <iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* right;
    Node* left;
    Node(int val){
        value = val;
        right = left = nullptr;
    }
};
class tree{
    public:
    Node* head;
    tree(){
        head = nullptr;
    }
};
int height(Node* node){
    if (node == nullptr){
        return 0;
    }
    int max1 = height(node->left);
    int max2 = height(node->right);
    return max(max1,max2)+1;
}
Node* leftrotate(Node* node){
    Node* x = node->left;
    Node* y = x->right;
    // Perform rotation
    x->right = node;
    node->left = y;
    return x;
}
Node* rightrotate(Node* node){
    Node* x = node->right;
    Node* y = x->left;
    //perform rotation
    x->left = node;
    node->right = y;
    return x;
}
Node* insertTree(Node* node, int val){
    if(node == nullptr){
        Node* x = new Node(val);
        return x;
    }
    if(val < node->value){
        node->left = insertTree(node->left, val);
    }
    else if( val > node->value){
        node->right = insertTree(node->right, val);
    }
    else{
        return node;
    }
    int balance = height(node->left) - height(node->right);
    if(balance > 1 && val < node->left->value){
        return leftrotate(node);
    }
    if (balance < -1 && val > node->right->value){
        return rightrotate(node);
    }
    if(balance > 1 && val > node->left->value){
        node->left = rightrotate(node->left);
        return leftrotate(node);
    }
    if(balance < -1 && val < node->right->value){
        node->right = leftrotate(node->right);
        return rightrotate(node);
    }
    return node;
}
int main(){
    tree t;
    t.head = insertTree(t.head,25);
    t.head = insertTree(t.head,30);
    t.head = insertTree(t.head,26);
    t.head = insertTree(t.head,40);
    t.head = insertTree(t.head,80);
    cout<<"Tree head :"<<t.head->value<<endl;
    cout<<"Tree left :"<<t.head->left->value<<endl;
    cout<<"Tree right :"<<t.head->right->value<<endl;
}