/*  Given a binary search tree which is also a complete binary tree.
The problem is to convert the given BST into a Min Heap with the condition that all the values
in the left subtree of a node should be less than all the values in the right subtree of the node. 
This condition is applied to all the nodes, in the resultant converted Min Heap.  
 Input:           4
                /   \
              2     6
            /  \   /  \
          1   3  5    7  

          
Output:          1
               /   \
             2     5
           /  \   /  \
         3   4  6    7 
         
Explanation: The given BST has been transformed into a Min Heap. All the nodes in the Min Heap satisfy the given condition, that is, values in the left subtree of a node should be less than the values in the right subtree of the node. */


void inOrder(BinaryTreeNode* root,vector<int>&ans)

{

    if(root==NULL)return;

    //LNR

    inOrder(root->left,ans);

    ans.push_back(root->data);

    inOrder(root->right,ans);

    

}

void preOrder(BinaryTreeNode* &root,vector<int>&ans,int &index)

{

    if(root==NULL)return;

    //NLR

    root->data=ans[index++];

    preOrder(root->left,ans,index);

    preOrder(root->right,ans,index);

}

 

BinaryTreeNode* convertBST(BinaryTreeNode* root)

{

    // Write your code here.

    vector<int> ans;

    inOrder(root,ans);

    int index=0;

    preOrder(root,ans,index);

    return root;

}
