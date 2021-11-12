vector<int> leftView(Node *root)
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
               if(temp->left!=NULL)
               q.push(temp->left);
               if(temp->right!=NULL)
               q.push(temp->right);
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
