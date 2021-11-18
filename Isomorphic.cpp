bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1==NULL and root2==NULL)
        return true;
        else if(root1==NULL or root2==NULL)
        return false;
        else if(root1->data == root2->data)
        {
            bool left = isIsomorphic(root1->left,root2->left) || isIsomorphic(root1->left,root2->right);
            bool right = isIsomorphic(root1->right,root2->left) || isIsomorphic(root1->right,root2->right);
            return left && right;
        }
        else
        return false;
    }
