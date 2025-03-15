/* to check if the tree is balanced or not 
    a balanced tree is abs[(height of right)-(height of left)]<=1*/
#include <iostream>
#include <math.h>
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

class Tree{
    public:
        Node* head;
        Tree(){
            head = nullptr;
        }
        Node* enterNode(){
            int val;
            cout<<"Enter the data :";
            cin>>val;
            if(val == -1){
                return nullptr;
            }
            Node* node = new Node(val);
            cout<<"Left node ";
            node->left = enterNode();
            cout<<"Right node ";
            node->right = enterNode();
            return node;
        }
        int height(Node* temp){
            if(temp == nullptr){
                return 0;
            }
            int left = height(temp->left);
            int right = height(temp->right);
            return max(left, right) +1;
        }
        bool isbalanced(Node* temp){
            if(temp == nullptr) return true;
            int h1 = height(temp->left);
            int h2 = height(temp->right);
            if (abs(h1-h2)<=1){ 
                if (isbalanced(temp->left) && isbalanced(temp->right)) return true;
                }
            else return false;
            return false;
        }
};
int main(){
    Tree t;
    t.head=t.enterNode();
    bool ba = t.isbalanced(t.head);
    if(ba) cout<<"\nTree is Balanced ";
    else cout<<"\n Tree is not Balanced ";
    return 0;
}