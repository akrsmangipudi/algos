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
  int height(TreeNode* root){
    if ( !root ) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return ( lh > rh ) ? lh+1 : rh+1;
  }
  bool isBalanced(TreeNode *root) {
    if ( !root || (!root->left && !root->right)) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return ( (abs(lh - rh) <=1 ) && isBalanced(root->left) && isBalanced(root->right));
  }
};
