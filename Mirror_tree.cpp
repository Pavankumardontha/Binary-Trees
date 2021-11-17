void mirror(Node* root) 
    {
        if(root==NULL)
        return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL)
            q.push(node->left);
            if(node->right!=NULL)
            q.push(node->right);
            Node* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }
