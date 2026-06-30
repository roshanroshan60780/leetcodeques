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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root==nullptr) return ans;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            ans.push_back(temp->val);
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return ans;
    }
};