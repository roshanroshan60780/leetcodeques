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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            vector<int> temp1;
            while(!q1.empty()){
                if(q1.front()->left){
                    q2.push(q1.front()->left);
                }
                if(q1.front()->right){
                    q2.push(q1.front()->right);
                }
                temp1.push_back(q1.front()->val);
                q1.pop();
            }
            if(!temp1.empty()) ans.push_back(temp1);
            vector<int> temp2;
            while(!q2.empty()){
                if(q2.front()->left){
                    q1.push(q2.front()->left);
                }
                if(q2.front()->right){
                    q1.push(q2.front()->right);
                }
                temp2.push_back(q2.front()->val);
                q2.pop();
            }
            if(!temp2.empty()) ans.push_back(temp2);
        }
        return ans;
    }
};