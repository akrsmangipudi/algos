/*   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

Output

[1, 3, 4]

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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    if ( !root ) return result;
    queue<TreeNode*> Q;
    Q.push(root);  
    Q.push(NULL);
    TreeNode* temp, *prev;
    while( !Q.empty() )
      {
	temp = Q.front();
	Q.pop();
	if ( temp == NULL )
	  {
	    result.push_back(prev->val);
	    if ( !Q.empty() )
	      Q.push(NULL);
	  }
	else
	  {
	    if ( temp->left  ) Q.push(temp->left);
	    if ( temp->right ) Q.push(temp->right);
	    prev = temp;
	  }
      }
    return result;
  }
};
