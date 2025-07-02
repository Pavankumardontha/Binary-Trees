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

// DO 'All Nodes distance K in Binary tree 

void find_parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
{
    // each node has only one parent
    if(root==NULL)
    return;
    parent[root]=NULL;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left != NULL)
        {
            parent[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

TreeNode* findNode(TreeNode* root, int start)
{
    if(root==NULL or root->val == start)
    return root;
    TreeNode* left = findNode(root->left,start);
    TreeNode* right = findNode(root->right,start);
    if(left != NULL)
    return left;
    if(right != NULL)
    return right;
    return NULL;
}

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<TreeNode*,TreeNode*> parent;
        find_parents(root,parent);
        
        unordered_map<TreeNode*,bool> visited;
        for(auto it = parent.begin(); it!= parent.end(); it++)
        visited[it->first]=false;

        int ans=0;
        TreeNode* current_node;
        int current_dis;
        pair<int,TreeNode*> temp;
        queue<pair<int,TreeNode*>> q;
        TreeNode* start_node = findNode(root,start);
        q.push({0,start_node});
        visited[start_node]=true;
        while(!q.empty()) 
        {
            temp = q.front();
            current_dis = temp.first;
            ans = max(ans,current_dis);
            current_node = temp.second;
            q.pop();
            if(parent[current_node]!=NULL and visited[parent[current_node]]==false)
            {
                q.push({current_dis+1,parent[current_node]});
                visited[parent[current_node]]=true;
            }
            if(current_node->left != NULL and visited[current_node->left]==false)
            {
                q.push({current_dis+1,current_node->left});
                visited[current_node->left]=true;
            }
            if(current_node->right != NULL and visited[current_node->right]==false)
            {
                q.push({current_dis+1,current_node->right});
                visited[current_node->right]=true;
            }
        }
        return ans;  
    }
};
