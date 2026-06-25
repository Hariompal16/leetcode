/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<vector<int>>ans;
  void tree(TreeNode* root, int targetSum, vector<int>&result,int sum){
    if(root==NULL){
        return;
    }
    sum+=root->val;
    result.push_back(root->val);
    if(root->left==NULL&&root->right==NULL){
        if(sum==targetSum)
        ans.push_back(result);
    }
    tree(root->left,targetSum,result,sum);
    tree(root->right,targetSum,result,sum);
    result.pop_back();
  }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>result;
        tree(root,targetSum,result,0);
        return ans;
    }
};