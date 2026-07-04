/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> bfsfromtarget(TreeNode* target , int k , unordered_map<TreeNode* , TreeNode*>& parent ){
        int currentlevel=0;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int size=q.size();
            
            if(currentlevel==k) break;
            currentlevel++;
            for(int i=0 ; i<size ; i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && visited.find(temp->left)==visited.end()){
                    visited.insert(temp->left);
                    q.push(temp->left);
                }
                if(temp->right && visited.find(temp->right)==visited.end()){
                    visited.insert(temp->right);
                    q.push(temp->right);
                }
                if(parent.count(temp) && visited.find(parent[temp])== visited.end()){
                    visited.insert(parent[temp]);
                    q.push(parent[temp]);
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent[temp->left]=temp;}
            if(temp->right){
                q.push(temp->right);
                parent[temp->right]=temp;}
        }
        return bfsfromtarget(target , k , parent);
    }
};