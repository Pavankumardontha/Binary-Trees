vector<int> ans;
void pre_order(Node* root)
{
    if(root==NULL)
    return;
    else
    ans.push_back(root->data);
    pre_order(root->left);
    pre_order(root->right);
    return;
}
//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  ans.clear();
  pre_order(root);
  return ans;
}
