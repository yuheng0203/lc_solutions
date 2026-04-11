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
    int ans, maxDepth;
    void dfs(TreeNode* root, int depth){
        if(!root){
            return;
        }
        if(depth > maxDepth){
            maxDepth = depth;
            ans = 0;
        }
        if(depth == maxDepth){
            ans += root->val;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        ans = 0;
        maxDepth = 0;
        dfs(root, 0);
        return ans;
    }
};