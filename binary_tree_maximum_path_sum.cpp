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

int ans= INT_MIN;
int solve(TreeNode* root)
{
    if(root==NULL)
    return 0;
    // ignore the path if it gives negative values. So the minimum value of both the max_left_sum and the max_right_sum is 0
    int max_left_sum = max(0,solve(root->left)); 
    int max_right_sum = max(0,solve(root->right));
    int current_ans = root->val + max_right_sum + max_left_sum;
    ans = max(ans,current_ans);
    return root->val + max(max_left_sum,max_right_sum);
} 
class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
        /* This is maximum path sum between any 2 nodes in a binary tree. The 2 nodes can be either leaf or
        non-leaf nodes it DOES NOT MATTER */
        ans = INT_MIN;
        solve(root);
        return ans;      
    }
};
