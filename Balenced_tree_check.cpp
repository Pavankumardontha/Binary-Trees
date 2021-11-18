int height(Node* root)
{
    if(root==NULL)
    return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + max(left_height,right_height);
}

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL)
        return true;
        else
        {
            int left_height = height(root->left);
            int right_height = height(root->right);
            if(abs(left_height - right_height) > 1 ) //root is not balenced
            return false;
            else //root is balenced so we will check its left and right subtrees.
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
