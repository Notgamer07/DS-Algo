// Tree traversal using stack
#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *right,*left;
    Node(int val){data = val; right = left =nullptr;}
};
class Tree{
    Node* insert(Node* node, int val){
        if(node == nullptr) return new Node(val);
        else if(node->data > val) node->left = insert(node->left,val);
        else if (node->data < val) node->right = insert(node->right,val);
        return node;
    }
    public:
    Node* root;
    Tree(){root =nullptr;}
    void append(int val){
        root = insert(root,val);
    }
};
int main(){
    Tree t;
    stack<Node*> s;
    t.append(4);
    t.append(2);
    t.append(6);
    t.append(1);
    t.append(3);
    t.append(5);
    t.append(7);
    cout<<"Tring to traverse over it now :"<<endl;
    Node* current = t.root;
    while((current)||(!s.empty())){
        while(current){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout<<current->data<<endl;
        current = current->right;
    }
}