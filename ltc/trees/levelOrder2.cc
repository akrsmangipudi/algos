/*    3
   / \
  9  20
    /  \
   15   7
out put 
[
  [3],
  [9,20],
  [15,7]
  ]
*/

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
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> lvlAll;
    vector<int> curlvl;
    if ( !root ) return lvlAll;
    queue<TreeNode*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
      TreeNode* temp = Q.front();
      Q.pop();
      if ( temp == NULL ){
	lvlAll.push_back(curlvl);
	curlvl.clear();
	if ( !Q.empty() ){
	  Q.push(NULL);
	}
                
      }
      else
	{
	  curlvl.push_back(temp->val);
	  if ( temp->left) Q.push(temp->left);
	  if ( temp->right) Q.push(temp->right);
	}
    }
    return lvlAll;
  }
};
