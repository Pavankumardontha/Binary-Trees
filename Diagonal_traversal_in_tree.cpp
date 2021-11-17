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
