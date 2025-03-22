/*
give the height of a tree 

what is height --> The height of a binary tree is the number of 
edges (or sometimes nodes) on the longest path from the root node to a leaf node.
*/

// this can be soved using recursion!!

int height(node* root) {
    if (root == NULL)
        return 0;  // or return -1 if you count edges only

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
