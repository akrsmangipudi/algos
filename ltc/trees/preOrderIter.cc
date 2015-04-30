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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if ( !root ) return res;
    std::stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* temp = NULL;
    while ( !stk.empty() )
      {
	temp = stk.top();
	stk.pop();
	res.push_back(temp->val);
	if ( temp->right ) stk.push(temp->right);
	if ( temp->left  ) stk.push(temp->left);
      }
    return res;    
  }
};
