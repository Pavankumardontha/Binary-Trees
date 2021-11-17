bool isIdentical(TreeNode* p, TreeNode* q)
{
    if(p==NULL and q==NULL)
        return true;
    else if(p==NULL or q==NULL)
        return false;
    else 
    {
        if(p->val == q->val)
        {
            bool left = isIdentical(p->left,q->left);
            bool right = isIdentical(p->right,q->right);
            return left and right;
        }
        else
            return false;
    }
}
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) 
    {
        if(root == NULL and subroot == NULL)
            return true;
        else if(root == NULL or subroot == NULL)
            return false;
        else if(root->val == subroot->val)
        {
            bool identical = isIdentical(root,subroot);
            return identical or isSubtree(root->left,subroot) or isSubtree(root->right,subroot);
        }
        else
            return isSubtree(root->left,subroot) or isSubtree(root->right,subroot);
        
    }
};
