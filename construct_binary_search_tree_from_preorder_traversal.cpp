/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Since its a BST , we know that,
Elements in left subtree < Root element < Elements in right subtree
*/

TreeNode* solve(int i, int j, vector<int>& preorder)
{
    if(i>j)
    return NULL;
    TreeNode* node = new TreeNode(preorder[i]);
    /*
    Now we have to decide what elements in the preorder will come to the left of 
    current node and what elements will come to the right of the current node.
    */
    int left_subtree_ending_index = -1;
    for(int ind=i+1;ind<=j;ind++)
    {
        if(preorder[ind]<preorder[i])
        left_subtree_ending_index = ind;
        else
        break;
    }
    if(left_subtree_ending_index==-1)
    {
        // all elements from [i+1,j] belong to the right subtree
        node->right = solve(i+1,j,preorder);
    }
    else if(left_subtree_ending_index == j)
    {
        // all elements from (i+1,j) belong to the left subtree
        node->left = solve(i+1,j,preorder);
    }
    else
    {
        node->left = solve(i+1,left_subtree_ending_index,preorder);
        node->right = solve(left_subtree_ending_index+1,j,preorder);
    }
    return node;
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int n = preorder.size();
        int i = 0;
        int j = n-1;
        return solve(i,j,preorder);
    }
};
