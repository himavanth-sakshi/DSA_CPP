/*
Question: you have a tree, find out the number of leaf nodes of the tree

for a leaf node the condition is it doesnt have both left and right nodes
*/

#include "trees_basic.h"
#include <iostream>

using namespace std;


int noOfLeafNode(binaryTreeNode<int> *root){
    int count =0;
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    if(root->left==NULL& toot-> right==NULL){
        count++;
    }
}

int main(){
    noOfLeafNode(root);
    cout<< count;


}