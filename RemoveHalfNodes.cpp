Node *RemoveHalfNodes(Node *root)
{
   if(root==NULL)
   return root;
   else
   {
       if(root->left!=NULL && root->right!=NULL)
       {
           root->left = RemoveHalfNodes(root->left);
           root->right = RemoveHalfNodes(root->right);
           return root;
       }
       else if(root->left == NULL and root->right == NULL)
       return root;
       else
       {
           if(root->left!=NULL)
           root = RemoveHalfNodes(root->left);
           else
           root = RemoveHalfNodes(root->right);
           return root;
       }
   }
}
