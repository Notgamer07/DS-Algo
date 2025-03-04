#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
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
    Node* enterNode(){
        cout<<"Enter the data :"<<endl;
        int val;
        cin>>val;
        if(val == -1){
            return nullptr;
        }
        Node* node = new Node(val);
        cout<<"Enter left node of the "<<val<<endl;
        node->left = enterNode();
        cout<<"Enter right node of the "<<val<<endl;
        node->right = enterNode();
        return node;
    }
    void LevelOrderTraversal(){
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp == nullptr){
                cout<<endl;
                if(!q.empty()) q.push(NULL);
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
        }
    }
};

int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    BinaryTree tree;
    tree.root=tree.enterNode();
    tree.LevelOrderTraversal();
    return 0;
}