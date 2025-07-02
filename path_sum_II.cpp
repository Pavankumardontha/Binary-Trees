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

void solve(TreeNode* root, vector<int>& temp, int current_sum , int target_sum,vector<vector<int>>& ans)
{
    if(root==NULL)
    return;
    current_sum = current_sum + root->val;
    temp.push_back(root->val);
    if(root->left == NULL and root->right == NULL)
    {
        if(current_sum == target_sum)
        ans.push_back(temp);
    }
    solve(root->left,temp,current_sum,target_sum,ans);
    solve(root->right,temp,current_sum,target_sum,ans);
    current_sum = current_sum - root->val;
    temp.pop_back();
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,temp,0,targetSum,ans);
        return ans;
    }
};
