vector<int> ans;
void inorder(Node* root)
{
    if(root==NULL)
    return;
    else
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
    return;
}
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) 
    {
        ans.clear();
        inorder(root);
        return ans;
    }
};
