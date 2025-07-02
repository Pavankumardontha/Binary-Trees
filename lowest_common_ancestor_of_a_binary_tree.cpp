/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* solve(TreeNode* root, TreeNode* &p, TreeNode* &q)
{
    // check if any of either p or q is present either in the leftsubtree or the right subtree
    // we need the first node which has p and q on both the different sides
    if(root==NULL)
    return root;
    else if(root==p)
    return p;
    else if(root==q)
    return q;
    TreeNode* left = solve(root->left,p,q);
    TreeNode* right = solve(root->right,p,q);
    // if both left and right subtree return non-NULL values, then current node is the LCA. If not the non-NULL value of either left or right.  
    if(left != NULL and right!=NULL)
    return root;
    else if(left!=NULL)
    return left;
    else if(right!=NULL)
    return right;
    else
    return NULL;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return solve(root,p,q);   
    }
};
