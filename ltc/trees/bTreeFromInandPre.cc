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
  TreeNode* buildTree(vector<int>&preorder, vector<int>& inorder, int start, int end){
    static int preindex = 0;
        
    if ( start > end )
      return NULL;
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->val = preorder[preindex++];
    node->left = NULL;
    node->right = NULL;
        
    if ( start == end )
      return node;
            
    //preindex++;
        
    int inIndex = find(inorder.begin(), inorder.end(), node->val) - inorder.begin();
    node->left  = buildTree(preorder, inorder, start, inIndex-1);
    node->right = buildTree(preorder, inorder, inIndex+1, end);
    return node;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if ( !preorder.size() || !inorder.size() || (preorder.size() != inorder.size() )) return NULL;
    else return buildTree(preorder, inorder, 0, preorder.size()-1);
  }
};
