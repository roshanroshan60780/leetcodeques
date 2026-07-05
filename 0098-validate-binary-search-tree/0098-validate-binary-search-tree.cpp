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
private:
    bool helper(TreeNode* root , long long lower , long long upper){
        if(!root) return true;
        if(root->left && (root->left->val >= root->val ||root->left->val <= lower)) return false;
        if(root->right && (root->right->val <= root->val || root->right->val >= upper)) return false;
        bool L=true , R=true;
        if(root->left) L=helper(root->left , lower , root->val);
        if(root->right) R=helper(root->right ,root->val, upper);
        return  L && R ;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root , INT_MIN - 1LL , INT_MAX +1LL);
    }
};