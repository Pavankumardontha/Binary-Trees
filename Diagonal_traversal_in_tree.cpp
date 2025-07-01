class Solution {
  public:
    vector<int> diagonal(Node *root) 
    {
        vector<int> ans;
        if(root==NULL)
        return ans;
        queue<Node*> q;
        q.push(root);
        Node* temp;
        Node* current;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            // add all the right nodes to ans and left nodes into the queue
            current = temp;
            while(current!=NULL)
            {
                ans.push_back(current->data);
                // if there is any left node to the current node, we push it into the queue
                if(current->left != NULL)
                {
                    // these left nodes belong to the next diagonal
                    q.push(current->left);
                }
                current = current->right;
            }
        }
        return ans;
    }
};


vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root==NULL)
    return ans;
    deque<Node*> dq;
    dq.push_front(root);
    while(!dq.empty())
    {
        Node* temp = dq.front();
        dq.pop_front();
        ans.push_back(temp->data);
        if(temp->right!=NULL)
        dq.push_front(temp->right);
        if(temp->left!=NULL)
        dq.push_back(temp->left);
    }
    return ans;
}
