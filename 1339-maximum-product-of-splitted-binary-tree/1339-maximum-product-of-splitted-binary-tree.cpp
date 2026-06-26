/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    long long total = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    // Calculate total sum of tree
    void findTotal(TreeNode* root) {
        if (!root) return;

        total += root->val;

        findTotal(root->left);
        findTotal(root->right);
    }

    // Returns subtree sum
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = left + right + root->val;

        ans = max(ans, subSum * (total - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        findTotal(root);

        dfs(root);

        return ans % MOD;
    }
};