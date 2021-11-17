bool check_is_mirror(TreeNode* p, TreeNode* q)
{
    if(p== NULL and q == NULL)
        return true;
    else if(p == NULL or q == NULL)
        return false;
    else if(p->val == q->val)
    {
        bool pleft_qright = check_is_mirror(p->left,q->right);
        bool pright_qleft = check_is_mirror(p->right,q->left);
        return pleft_qright and pright_qleft;
    }
    else
        return false;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        bool check = check_is_mirror(root->left,root->right);
        return check;
    }
};
