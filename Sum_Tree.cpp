int sum(Node* root)
{
    if(root==NULL)
    return 0;
    else
    {
        int left_sum = sum(root->left);
        int right_sum = sum(root->right);
        return left_sum + right_sum + root->data;
    }
}
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
         if(root==NULL)
         return true;
         else if(root->left ==  NULL or root->right == NULL)
         return true;
         else
         {
             if(root->data == sum(root->left) + sum(root->right))
             {
                 bool left_check = isSumTree(root->left);
                 bool right_check = isSumTree(root->right);
                 return left_check and right_check;
             }
             else
             return false;
         }
    }
};
