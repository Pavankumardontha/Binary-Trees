bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL or q==NULL)
            return false;
        else
        {
            if(p->val == q->val)
            {
                bool left = isSameTree(p->left,q->left);
                bool right = isSameTree(p->right,q->right);
                return left and right;
            }
            else
                return false;
        }
    }
