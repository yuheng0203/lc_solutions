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
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(TreeNode* node, int sum){
        
        path.push_back(node->val);
        sum -= node->val;
        if(!node->left && !node->right && sum == 0){
            ans.push_back(path);
        }
        if(node->left) dfs(node->left, sum);
        if(node->right) dfs(node->right, sum);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return ans;
        }
        dfs(root, targetSum);
        return ans;
    }
};