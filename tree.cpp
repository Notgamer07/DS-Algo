#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
class Tree{
    public:
    Node* root;
    Tree(){
        root=nullptr;
    }
    void append(int val){
        if(root == nullptr){
            root = new Node(val); 
            return;
        }
        else{
            Node* temp=root;
            while(true){
            if(val < temp->data){
                if (temp->left == nullptr){
                temp->left=new Node(val);
                return;
                }
                temp=temp->left;
            }
            else{
                if(temp->right == nullptr){
                temp->right=new Node(val);
                return;
                }
                temp=temp->right;
                }
            }
        }
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
    Tree tree;
    tree.append(5);
    tree.append(8);
    tree.append(1);
    tree.append(2);
    tree.append(10);
    tree.append(4);
    tree.display();
    return 0;
}