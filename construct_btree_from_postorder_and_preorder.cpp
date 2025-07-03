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

// Here the last node is the root node. We traverse from the left
// [i,j] is the range of inorder. ind is the current index of the postorder which we are exploring
TreeNode* construct(int i, int j, int& ind, vector<int> inorder, vector<int>& postorder, unordered_map<int,int>& mp, int& n)
{
    if(i>j or i>=n or j<0)
    return NULL;
    else
    {
        // find the index of the current element (postorder[ind]) in the inorder traversal
        int current_inorder_ind = mp[postorder[ind]];
        TreeNode* temp = new TreeNode(postorder[ind]);
        ind--;

        // since this is postorder , its order is (L)(R)(current_node)
        temp->right = construct(current_inorder_ind+1,j,ind,inorder,postorder,mp,n);
        temp->left = construct(i,current_inorder_ind-1,ind,inorder,postorder,mp,n);
        return temp; 
    }
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = postorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[inorder[i]]=i;

        int ind=n-1;
        return construct(0, n-1, ind, inorder, postorder, mp, n);
    }
};
