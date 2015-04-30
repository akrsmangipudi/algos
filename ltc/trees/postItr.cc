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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if ( !root ) return result;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
      TreeNode* temp = stk.top();
      stk.pop();
      result.insert(result.begin(),temp->val);
      if ( temp->left ) stk.push(temp->left);
      if ( temp->right) stk.push(temp->right);
    }
        
    return result;    
  }
};
