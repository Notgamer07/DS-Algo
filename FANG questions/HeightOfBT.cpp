/*FInd the height of the Binary Tree.
    To find the height, we need longest path of leaf node to the BT*/
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
        void inorder(Node* node){
            if(node == nullptr) return ;
            inorder(node->left);
            cout<<node->data<<" ";
            inorder(node->right);
        }
    };
    
    // editing of code starts from here, previous is copied from BinaryTree.cpp
    int HeightCount(Node* node){
        int n;
        if(node == nullptr) return 0;
        int max1=HeightCount(node->left);
        int max2=HeightCount(node->right);
        if(max1>=max2) n=max1+1;
        if(max1<=max2) n=max2+1;
        return n;
    }

    int main(){
        // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        BinaryTree tree;
        tree.root=tree.enterNode();
        cout<<"The height = "<<HeightCount(tree.root);
        return 0;
    }