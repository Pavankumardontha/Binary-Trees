/*
We cannot construct a unique binary tree using only inorder, only preorder or only postorder traversal. We need atleast two traversal orders to construct a unique binary tree.

Can we construct tree using:
1) Preorder + Inorder = YES
2) Postorder + Inorder = YES
3) Preorder + Postorder = NO (preorder: 1 2 3 , postorder : 3 2 1 : we get multiple trees using these)

Note that this is possible only there are unique elements in the entire binary tree. If there are any duplicates then we cannot construct a unique binary tree. If the traversals are given using 
the node pointers then we can create them even if duplicate values are present since the pointers are always unique. But with only values given in the traversals , if there are any duplicates then
we cannot create a unique binary tree.

We will construct the algorithm using an example

inorder :  4 2 8 5 9 1 6 3 7 10
preorder : 1 2 4 5 8 9 3 6 7 10
indices  : 0 1 2 3 4 5 6 7 8 9  

Now the first element in the preorder is the root node. All the elements which are to the left of the root node in the inorder will form the leftsubtree and all the elements which are to the right of the root in the
inorder will form the right subtree.

current_node : 1
elements to the left of current node in inorder traversal : [4,2,8,5,9]
elements to the right of current node in the inorder traversal : [6,3,7,10]

Now will move to the next call -> 
current_node = 2 
left elements :[4]
right elements : [8,5,9]

now will move to the next call and so on......

IMPORTANT POINTS:
1) preorder ALWAYS has the node first. But you don't know the size of either branch.
2) inorder ALWAYS has the left branch to the left of the node, and right branch right of the node. So now you know the size of each branch.
3) By finding the position of a node in the inorder traversal , we can clearly say how many nodes are in its left subtree and how many are in its right subtree. Lets say we have a the position of node at index i in 
the inorder traversal. lets say there are x elements to the left and y elements to the right of it. Now in the preorder , if the position of the same node is j, from j the next (x+y) elements in the preorder will 
belong on the left and right subtree of the node.

In each function call , we need the preorder index and the current inorder range for the preorder index.


So at each step , we need to explore the pre-order element
1) find the inorder index of the current pre-order element which we have to explore
2) split the index range [i,j] into 2 by using the index which we found in step 1.
*/

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

// [i,j] = current inorder range , ind = current preorder index to be explored
TreeNode* construct(int i, int j, int &ind,vector<int> &preorder,vector<int>& inorder,unordered_map<int,int>& mp, int& n)
{
    if(i>=n or j<0 or i>j)
    return NULL;
    else
    {
        // find the inorder index of the current preorder element which we need to explore
        // increment the preorder index every time we go the next steps since its explored
        int inorder_index = mp[preorder[ind]];
        TreeNode* temp = new TreeNode(preorder[ind]);
        ind++;
        temp->left = construct(i,inorder_index-1,ind,preorder,inorder,mp,n);
        temp->right = construct(inorder_index+1,j,ind,preorder,inorder,mp,n);
        return temp;
    }
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> mp; // to find the index of a node in the inorder array
        int n = inorder.size();
        for(int i=0;i<n;i++)
        mp[inorder[i]]=i;
        int ind=0;
        return construct(0,n-1,ind,preorder,inorder,mp,n);   
    }
};
