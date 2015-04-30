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
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if ( !root ) return result;
    queue<TreeNode*> Q;
    vector<int> level;
    bool ltor = false;
    Q.push(root);
    Q.push(NULL);
    TreeNode* temp = NULL;
    while ( !Q.empty() )
      {
	temp = Q.front();
	Q.pop();
	if ( temp == NULL )
	  {
	    result.push_back(level);
	    level.clear();
	    ltor = !ltor;
	    if ( !Q.empty() ) Q.push(NULL);
	  }
	else
	  {
	    if ( ltor ) 
	      {
		level.insert(level.begin(), temp->val);
	      }
	    else level.push_back(temp->val);
	    if ( temp->left  ) Q.push(temp->left);
	    if ( temp->right ) Q.push(temp->right);
	  }
      }
    return result; 
  }
};
