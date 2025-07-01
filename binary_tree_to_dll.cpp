/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 

pair<Node*,Node*> solve(Node* &root)
{
    // returns head and tail of the DLL
    if(root==NULL)
    return {NULL,NULL};
    
    // inorder : left subtree,current node, right subtree
    Node* head = NULL;
    Node* tail = NULL;
    Node* left = root->left;
    Node* right = root->right;
    pair<Node*,Node*> temp1 = solve(left);
    pair<Node*,Node*> temp2 = solve(right);
    
    // attach left subtree DLL to head and tail
    if(temp1.first != NULL)
    {
        head = temp1.first;
        tail = temp1.second;
    }
    
    // attach the current node
    if(head == NULL)
    {
        head = root;
        tail = root;
    }
    else
    {
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    
    // attach the right subtree
    if(temp2.first != NULL)
    {
        tail->right = temp2.first;
        temp2.first->left = tail;
        tail = temp2.second;
    }
    tail->right=NULL;
    return {head,tail};
}

// This function should return head to the DLL
class Solution {
  public:
    Node* bToDLL(Node* root) 
    {
        pair<Node*,Node*> ans = solve(root);
        return ans.first;
        
    }
};
