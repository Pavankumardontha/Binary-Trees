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
take a full complete binary tree and start to index from the start. 
if the parent is at index i, then its left child will be at index 2i and its right child will be at index 2i+1.
At each level take the (last_node_index) - (first_node_index) + 1 to get the maximum width.
But this will overflow. Notice that we want the difference between the end nodes. 
Even if we start the numbering from 0,1,2,.... also it works since we want only the difference. By starting the 
numbering from index 0 at each level will not lead to overflow.

           1
        2     3
       4  5  6  7

Here if we go by our previous logic of 2i,2i+1 we will have 
1 -> index 1
2 -> index 2
3 -> index 3
4 -> index 4
5 -> index 5
6 -> index 6
7 -> index 7

But now imagine the below tree which is left skeweed
             1
            2
          3
        4
       5
      6
     7

In this case, notice the indices
1 -> 1
2 -> 2
3 -> 4
4 -> 8
5 -> 16
6 -> 32
7 -> 64
.
.

So the index value doubles now rapidly and this leads to overflow. Given that there can be maximum of 3000 nodes. So this
clearly leads to overflow. After 31 levels it will come upto 2^31 which will become greater than the value of INT_MAX
so we have to take long long but also after 2 ^ 63 the long long limit will also be reached. So we have to optimise the code in some way. 

           1
        2     3
       4  5  6  7

Solution : Use modulus !!!
*/

long long int mod = 2e10+7;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        return 0;
        if(root->left == NULL and root->right==NULL)
        return 1;
        queue<pair<long long int,TreeNode*>> q; //{index,Node*}
        q.push({1,root});
        q.push({0,NULL}); // this is there just to tell that the new level is starting
        pair<long long int,TreeNode*> temp;
        long long int ans = 1;
        TreeNode* current;
        long long int level_starting_index=1;
        long long int level_ending_index;
        long long int current_index;
        long long int current_level_width;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            current = temp.second;
            current_index = temp.first;
            if(current == NULL)
            {
                if(!q.empty())
                {
                    q.push({0,NULL});
                    level_starting_index = q.front().first;
                }
            }
            else
            {
                if(current->left != NULL)
                {
                    long long int left_child_index = (2*1LL*((current_index)%mod))%mod;
                    q.push({left_child_index,current->left});
                }
                if(current->right != NULL)
                {
                    long long int right_child_index = ((2*1LL*((current_index)%mod))%mod + 1)%mod;
                    q.push({right_child_index,current->right});
                }
                // check if the current node is the last node of current level or not
                if(!q.empty())
                {
                    if(q.front().second == NULL)
                    {
                        level_ending_index = current_index;
                        current_level_width = level_ending_index - level_starting_index + 1;
                        ans = max(ans,current_level_width);
                    }
                }
            }
        }
        return ans;
    }
};
