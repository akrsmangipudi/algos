/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if ( !root ) return;
    std::queue<TreeLinkNode*> Q;
    Q.push(root);
    Q.push(NULL);
    while ( !Q.empty() ){
      TreeLinkNode* temp = Q.front();
      Q.pop();
      if ( temp == NULL ){
	if ( !Q.empty() )
	  Q.push(NULL);
      }
      else
	{
	  temp->next = Q.front();
	  if ( temp->left ) Q.push(temp->left);
	  if ( temp->right) Q.push(temp->right);
	}
    }
        
  }
};
