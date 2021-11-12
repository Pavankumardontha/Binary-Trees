vector<int> rightView(Node *root)
    {
       vector<int> ans;
       if(root==NULL)
       return ans;
       else
       {
           queue<Node*> q;
           q.push(root);
           q.push(NULL);
           ans.push_back(root->data);
           while(!q.empty())
           {
               Node* temp = q.front();
               q.pop();
               if(temp)
               {
                   if(temp->right!=NULL)
                   q.push(temp->right);
                   if(temp->left!=NULL)
                   q.push(temp->left);
               }
               else
               {
                   if(!q.empty())
                   {
                       q.push(NULL);
                       ans.push_back(q.front()->data);
                   }
               }
           }
           return ans;
       }
   }
