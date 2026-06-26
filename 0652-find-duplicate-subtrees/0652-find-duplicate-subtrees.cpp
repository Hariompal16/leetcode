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
string tree(TreeNode* root,vector<TreeNode*>&ans,unordered_map<string,int>&mpp){
    if(root==NULL){
        return "N";
    }

    string s=to_string(root->val)+','+tree(root->left,ans,mpp)+','+tree(root->right,ans,mpp);
    if(mpp[s]==1){
        ans.push_back(root);
    }
    mpp[s]++;
    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>mpp;
        tree(root,ans,mpp); 
        return ans;
    }
};