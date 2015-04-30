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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    if ( !root ) return result;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    TreeNode* temp = NULL;
    while(1)
      {
	while ( current != NULL )
	  {
	    stk.push(current);
	    current = current->left;
	  }
	if ( !stk.empty() )
	  {
	    temp = stk.top();
	    stk.pop();
	    result.push_back(temp->val);
	    if ( temp->right ) current = temp->right;
	  }
	else break;
      }
    return result;
  }
};
