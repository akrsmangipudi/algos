/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int minDepth(TreeNode *root) {
    if ( !root ) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    Q.push(NULL);
    TreeNode* temp =NULL;
    int count = 0;
    while(!Q.empty()){
      temp = Q.front();
      Q.pop();
      if ( temp == NULL){
	count++;
	if (!Q.empty()) Q.push(NULL);
      }
      else {
	if ( (!temp->left && !temp->right) ) return ++count;
	else {
	  if ( temp->left  ) Q.push(temp->left);
	  if ( temp->right ) Q.push(temp->right);
	}
      }
    }
    return count;        
  }
};
