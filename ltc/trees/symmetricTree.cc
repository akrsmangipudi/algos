/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

  For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
  But the following is not:
    1
   / \
  2   2
   \   \
   3    3
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
  bool isMirror(TreeNode* r1, TreeNode* r2){
    if ( !r1 && !r2) return true;
    if ( !r1 || !r2) return false;
    else{
      return (r1->val==r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }
  }
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    return isMirror(root->left, root->right);      
  }
};
