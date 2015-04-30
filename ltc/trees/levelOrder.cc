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
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if ( !root ) return result;
    queue<TreeNode*> Q;
    vector<int> level;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
      TreeNode* temp = Q.front();
      Q.pop();
      if ( !temp )
        {
	  result.insert(result.begin(),level);
	  level.clear();
	  if ( !Q.empty()){
	    Q.push(NULL);
	  }
        }
      else
        {
	  level.push_back(temp->val);
	  if ( temp->left  ) Q.push(temp->left);
	  if ( temp->right ) Q.push(temp->right);
        }
    }
    return result;
  }
};
