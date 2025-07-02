/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void find_parents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp)
{
    // each node has only one parent , since the max size of the tree is 500 , the map size can be at max 500
    queue<TreeNode*> q;
    q.push(root);
    mp[root]=NULL; // there is no parent to the root nodde
    TreeNode* temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left!=NULL)
        {
            mp[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            mp[temp->right]=temp;
            q.push(temp->right);
        }
    }
}
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        /*
        If we have pointers which point to the parent node from the current node, we can directly 
        do BFS to calculate the distance. But here we do not have the parent pointers present in current node
        so we need to store the parents.
        */
        unordered_map<TreeNode*,TreeNode*> parent;
        find_parents(root,parent);
        vector<int> ans;
        // start bfs from the target node
        // we also need a visited map to tell whether a node is visited or not
        unordered_map<TreeNode*,bool> visited;
        // set all the node pointers to false before starting the bfs
        for(auto it=parent.begin();it!=parent.end();it++)
        visited[it->first]=false;
        queue<pair<int,TreeNode*>>q;
        q.push({0,target});
        pair<int,TreeNode*> temp;
        TreeNode* current_node;
        int current_dis;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            current_dis = temp.first;
            current_node = temp.second;
            visited[current_node]=true;
            if(current_dis == k)
            ans.push_back(current_node->val);
            if(parent[current_node] != NULL and visited[parent[current_node]]==false)
            {
                q.push({current_dis+1,parent[current_node]});
                visited[parent[current_node]]=true;
            }
            if(current_node->left!=NULL and visited[current_node->left]==false)
            {
                q.push({current_dis+1,current_node->left});
                visited[current_node->left]=true;
            }
            if(current_node->right!=NULL and visited[current_node->right]==false)
            {
                q.push({current_dis+1,current_node->right});
                visited[current_node->right]=true;
            }
        }
        return ans;
    }
};
