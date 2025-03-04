#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val){
        data = val;
        left = right =nullptr;
        height = 1; 
    }
};

class avalTree
{
 
public:
    Node* root;
    avalTree(){
        root = nullptr;
    }
    int getHeight(Node* temp){
        if(temp == nullptr){
            return 0;
        }
        else 
        return temp->height;
    }
    int getHeightFactor(Node* temp){
        if(temp == nullptr)
            return 0;
        else
            return getHeight(temp->left) - getHeight(temp->right);
    }
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* temp = x->right;
        x->right = y;
        y->left = temp;
        y->height=max(getHeight(y->left) , getHeight(y->right))+1;
        x->height=max(getHeight(x->left) , getHeight(x->right))+1;
        return x;
    }
    Node* leftRotate(Node* y){
        Node* x = y->right;
        Node* temp = x->left;
        x->left = y;
        y->right = temp;
        y->height=max(getHeight(y->left) , getHeight(y->right))+1;
        x->height=max(getHeight(x->left) , getHeight(x->right))+1;
        return x;
    }
    Node* insert(Node* node, int val){
        if(node == nullptr){
            return new Node(val);
        }
        if(val < node->data){
            node->left = insert(node->left, val);
        }
        else if(val > node->data){
            node->right = insert(node->right, val);
        }
        else{
            return node;
        }
        node->height= max(getHeight(node->left), getHeight(node->right))+1;
        int balance = getHeightFactor(node);
        if(balance > 1 && val < node->left->data){
            return rightRotate(node);
        }
        if(balance >1 && val > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance <-1 && val < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        if(balance <-1 && val > node->right->data){
            return leftRotate(node);
        }
        return node;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void d1(Node* node){
        if (node == nullptr){
            return;
        }
        d1(node->left);
        cout<<node->data<<" ";
        d1(node->right);
    }
    void display(){
        cout<<"output ";
        d1(root);
    }
};

int main(){
    avalTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // Causes RR rotation
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.display();
    return 0;
}