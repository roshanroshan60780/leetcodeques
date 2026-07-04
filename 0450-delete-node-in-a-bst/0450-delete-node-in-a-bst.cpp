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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp=root,*parent=nullptr;
        while(temp){
            if(temp->val==key) break;
            if(temp->val < key){
                parent=temp;
                temp=temp->right;
            }
            else{
                parent=temp;
                temp=temp->left;
            }
        }
        if(temp==nullptr) return root;
        if(!temp->left){
            if(temp->right){
                if(parent){
                    if(parent->left == temp) parent->left=temp->right;
                    else parent->right=temp->right;
                    delete temp;
                    return root;
                }
                else return root->right;
            }
            else{
                if(parent){
                    if(parent->left==temp) parent->left=nullptr;
                    else parent->right=nullptr;
                    return root;
                }
                else return nullptr;
            }
        }
        else{
            if(!temp->right){
                if(parent){
                    if(parent->left == temp) parent->left=temp->left;
                    else parent->right=temp->left;
                    delete temp;
                    return root;
                }
                else return root->left;
            }

            else{
                TreeNode* inorderpred=temp->left , *inpredparent=nullptr;
                while(inorderpred->right){
                    inpredparent=inorderpred;
                    inorderpred=inorderpred->right;
                }
                if(inpredparent) inpredparent->right = inorderpred->left;
                else{

                }
                if(inpredparent)inorderpred->left=temp->left;
                inorderpred->right=temp->right;
                if(parent){
                    if(parent->left==temp) parent->left=inorderpred;
                    else parent->right=inorderpred;
                    return root;
                }
                else return inorderpred;

            }
        }
        return root;
    }
};