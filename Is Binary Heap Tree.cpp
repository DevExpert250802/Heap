/* You have been given a binary tree of integers.

Your task is to check if it is a binary heap tree or not.

Note:

A binary tree is a tree in which each parent node has at most two children. 

A binary heap tree has the following properties. 
1. It must be a complete binary tree. In the complete binary tree every level, except the last level, is completely filled and the last level is as far left as possible.

2. Every parent must be greater than all children nodes. */

#include <bits/stdc++.h> 
int countNodes(BinaryTreeNode<int>* root){

    if(root == NULL){
      return 0;
    }
    int ans = countNodes(root->left) + countNodes(root->right) +1;

    return ans;
  }
  bool isCBT(BinaryTreeNode<int>* root, int index, int cnt){

    if(root == NULL){

        return true;

    }

     if(index >= cnt){

        return false;
     }

    else{
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);
        return (left && right);
    }
  }
  bool isMaxOrder(BinaryTreeNode<int>* root){
    if(root->left == NULL && root->right == NULL){

        return true;
    }

    if(root->right == NULL){
        return (root->data > root->left->data);
    }

    else{
        bool left = isMaxOrder(root->left);

        bool right = isMaxOrder(root->right);

        return (left && right && (root->data >= root->left->data && root->data >= root->right->data));
    }
  }
bool isBinaryHeapTree(BinaryTreeNode<int>* root) 

{
    int index = 0;

    int totalCount = countNodes(root);
    if(isCBT(root,index,totalCount) && isMaxOrder(root))
    {
       return true;
    }
    else
    {
        return false;
    }
}
