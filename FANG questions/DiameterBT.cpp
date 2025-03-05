/*Find diameter of Binary tree.
Diameter = longest distance between two LEAF nodes*/

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
    };
    int HeightCount(Node* node){
        int n;
        if(node == nullptr || (node->left == nullptr && node->right == nullptr)) return 0;
        int max1=HeightCount(node->left);
        int max2=HeightCount(node->right);
        if(max1>=max2) n=max1+1;
        if(max1<=max2) n=max2+1;
        return n;
    }
    int diameter(Node* node){
        if(node == nullptr || (node->left == nullptr && node->right == nullptr)) return 0;
        int dia_left = diameter(node->left); 
        int dia_right = diameter(node->right);
        int dia_mix = HeightCount(node->left) + HeightCount(node->right) + 1;
        if(dia_left > dia_right && dia_left > dia_mix ) {return dia_left;}
        else if (dia_right > dia_left && dia_right > dia_mix) {return dia_right;}
        else {return dia_mix;}
    }
    int main(){
        // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        BinaryTree tree;
        tree.root=tree.enterNode();
        cout<<"The diameter = "<<diameter(tree.root);
        return 0;
    }