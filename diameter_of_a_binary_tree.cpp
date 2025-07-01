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
If we compute the height of left substree and the height of right subtree for all the nodes , we would take 
O(N^(2)) time complexity and O(N) auxilary recursion stack space.
Time complexity = O(N^2) because we have N nodes and at each node we compute the left and right subtree height which again
is O(N)

Optimised approach : 
So instead of this , what we can do this , while computing the height of each node, we can compute the diameter of that particular node also. We can then compare it 
with the global max and update accordingly. 
Time complexity ; O(N) and space: O(N)
*/

int height(TreeNode* root)
{
    if(root==NULL)
    return 0;
    else if(root->left == NULL and root->right==NULL)
    return 1;
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l,r);
    }
}
int solve1(TreeNode* root)
{
    if(root == NULL)
    return 0;
    // calculate the diameter taking the current node into account
    int diameter = height(root->left) + height(root->right);
    
    // now calculate the diamter of each node present in the left subtree and the right subtree
    int l = solve1(root->left);
    int r = solve1(root->right);
    return max(diameter,max(l,r));
    // this is O(N^2) time complexity lets now see approach 2
}


int ans=0; // global ans
int solve2(TreeNode* root)
{
    // while calculating height only we do the diameter calculation as well and store the result in global ans
    if(root==NULL)
    return 0;
    if(root->left == NULL and root->right == NULL)
    return 1;
    int left_subtree_height = solve2(root->left);
    int right_subtree_height = solve2(root->right);
    int current_node_diameter = left_subtree_height + right_subtree_height; // we will compare this with the global ans;
    ans = max(ans,current_node_diameter);
    return 1+max(left_subtree_height,right_subtree_height);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        //return solve1(root);
        ans=0;
        solve2(root);
        return ans;
    }
};
