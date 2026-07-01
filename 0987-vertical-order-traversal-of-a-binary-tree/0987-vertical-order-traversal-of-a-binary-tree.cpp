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
    map<int,map<int,multiset<int>>> mp;
    void helper(TreeNode* root , int x , int y){
        if(root==nullptr) return;
        helper(root->left,x-1,y+1);
        mp[x][y].insert(root->val);
        helper(root->right , x+1 , y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        vector<vector<int>> ans;

        for (auto &[x, innerMap] : mp) {
            vector<int> temp;
            for (auto &[y, ms] : innerMap) {
                temp.insert(temp.end(), ms.begin(), ms.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};