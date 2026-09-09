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
struct Hash {
    size_t operator()(const pair<TreeNode*, bool>& p) const {
        return hash<TreeNode*>()(p.first) ^
               (hash<bool>()(p.second) << 1);
    }
};
private:

    int func(TreeNode* curr , bool last ,unordered_map<pair<TreeNode*, bool>, int, Hash>& dp){
          //last represent wether parent is robbed or not
        if(!curr) return 0;
        if(dp.count({curr,last})) return dp[{curr,last}];
        if(last){
            return dp[{curr,last}]= func(curr->left,false,dp) + func(curr->right,false,dp);
        }
        return dp[{curr,last}] = max(curr->val + func(curr->left,true,dp)+func(curr->right , true,dp),
         func(curr->left,false,dp)+func(curr->right , false,dp));
    }
public:
    int rob(TreeNode* root) {
        unordered_map<pair<TreeNode*, bool>, int, Hash> dp;
        return func(root,false,dp);
    }
};