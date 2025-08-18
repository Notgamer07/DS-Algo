#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val){data = val; left = right = nullptr;}  
};
class Tree{
    public: 
    Node *root;
    Tree(){root = nullptr;}
    void append(int val){
        root = insert(root,val);
    }
    int height(Node* node){
        int count = 0;
        if (!node) return 0; 
        int max1 = height(node->left);
        int max2 = height(node->right);
        count = max(max1,max2)+1;
        return count;
    }
    void display(){
        cout<<"Preorder :";
        preorder(root);
        cout<<"Inorder :";
        inorder(root);
    }
    private:
    void preorder(Node* node){
        if(node == nullptr) return;
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    void inorder(Node* node){
        if(node == nullptr) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    Node *insert(Node* node, int val){
        if(!node) return new Node(val);
        else if (node->data < val) node->right = insert(node->right,val);
        else if(node->data > val) node->left = insert(node->left,val);
        int bf = height(node->left) - height(node->right);
        if(bf>1 && val < node->left->data) return LeftRotate(node); // LL rotation
        else if(bf < -1 && val > node->right->data) return rightRotate(node); // RR rotation
        else if (bf > 1 && val >node->left->data) { // L-R rotation
            node->left = rightRotate(node->left);
            return LeftRotate(node);
        }
        else if (bf < -1 && val < node->right->data) { // R-L rotation
            node->right = LeftRotate(node->right);
            return rightRotate(node);
        }
        return node;
    }
    Node* LeftRotate(Node* node){
        Node *b = node->left;
        Node *br = node->left->right;
        node->left = br;
        b->right = node;
        return b;
    }
    Node *rightRotate(Node* node){
        Node* b = node->right;
        Node* bl = node->right->left;
        node->right = bl;
        b->left = node;
        return b;
    }
    
};
int main(){
    Tree t;
    t.append(10);
    t.append(20);
    t.append(15);
    t.display();
    cout<<endl<<t.height(t.root)<<endl;
}