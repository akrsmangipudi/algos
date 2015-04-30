/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,
    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
  vector<int> curPath;
  int findSum(vector<int> path){
    int val = 0;
    for (vector<int>::iterator it = path.begin(); it != path.end(); ++it ){
      val = val*10 + (*it);
    }
    return val;
  }
  int sumNumbers(TreeNode *root) {
    int sum = 0;
    if ( !root ) return sum;
    if ( !root->left && !root->right ){
      curPath.push_back(root->val);
      sum += findSum(curPath);
      return sum;
    }
    curPath.push_back(root->val);
    if ( root->right){
      sum += sumNumbers(root->right);
      curPath.pop_back();
    }
    if ( root->left ){
      sum += sumNumbers(root->left);
      curPath.pop_back();
    }
    return sum;
  }
};
