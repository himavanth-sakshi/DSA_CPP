#include <iostream>

using namespace std; 

class node{

    public:
        int data;
        node* left; 
        node* right;
    
    node(int d){
        this->data = d; 
        this-> left = NULL;
        this-> right = NULL;
    }
};


/*
here node* is used because 
- we are pointing to a whole structure instead of int
- node* is a pointer to a struct or class
- Lets you build dynamic structures

*/ 
node* buildTree(node* root){
    cout<< "Enter a value : "<< endl; 
    int data; 
    cin>> data; 
    root = new node(data);

    if(data==-1){
        return NULL;
    }

    cout<< "Enter data for inserting in left of "<< data << endl; 
    root->left = buildTree(root->left);
    cout <<"Enter data for inserting in right of "<< data << endl; 
    root->right = buildTree(root->right);
    return root;
}


//level order traversal 

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL){ // level is complete so go to next line
            cout<<endl;// adding endl to go to next line
            
            if(!q.empty()){// queue still has child nodes
                q.push(NULL);
            }
        }

        else{
            cout<< temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


/* inorder traversal - LNR--> left node Right
the below will give 4,2,5,1,6,3
    1
  /     \
2       3
/ \     /
4   5   6

*/
void inorderTraversal(node* root){
    if(root ==NULL){
        return; 
    }

    inorderTraversal(root->left);
    cout<<root-> data<< " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root){
    if(root ==NULL){
        return; 
    }
    cout<<root-> data<< " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root){
    if(root ==NULL){
        return; 
    }

    preorderTraversal(root->left);
    preorderTraversal(root->right);
    cout<<root-> data<< " ";
}

int noOfLeafNode(node* root) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return 1;  // ✅ If leaf node, return 1

    return noOfLeafNode(root->left) + noOfLeafNode(root->right);  // ✅ Sum of left and right leaf nodes
}

int main(){

    node* root = NULL;

    root = buildTree(root);

    levelOrderTraversal(root);

    inorderTraversal(root);

    
    int count = noOfLeafNode(root); 
    cout<< count; 





    return 0;
}