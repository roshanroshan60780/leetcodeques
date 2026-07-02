/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree;
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(temp){
                string s=to_string(temp->val);
                tree += s + " ";
                q.push(temp->left);
                q.push(temp->right);
            }
            else tree += "NULL ";

        }
        return tree;
    }

    // Decodes your encoded val to tree.
    TreeNode* deserialize(string val) {
        stringstream ss(val);
        string token;
        vector<string> nodes;
        while (ss >> token){
            nodes.push_back(token);
        }
        queue<TreeNode*> q;
        TreeNode *root , *temp;
        if(nodes[0]=="NULL") return NULL;
        else{
            int x=stoi(nodes[0]);
            root=new TreeNode(x);
            q.push(root);
        }
            int i=1;
            while(!q.empty()){
            temp=q.front();
            q.pop();
            if(nodes[i]=="NULL") temp->left=NULL;
            else{
                int x=stoi(nodes[i]);
                TreeNode* L=new TreeNode(x);
                temp->left=L;
                q.push(L);
            }
            if(nodes[i+1]=="NULL") temp->right=NULL;
            else{
                int x=stoi(nodes[i+1]);
                TreeNode* R=new TreeNode(x);
                temp->right=R;
                q.push(R);
            }
            i=i+2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));