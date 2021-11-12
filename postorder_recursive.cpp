vector<int> ans;
void postorder(Node* root)
{
    if(root==NULL)
    return;
    else
    postorder(root->left);
    postorder(root->right);
    ans.push_back(root->data);
    return;
}
vector <int> postOrder(Node* root)
{
    ans.clear();
    postorder(root);
    return ans;
}
