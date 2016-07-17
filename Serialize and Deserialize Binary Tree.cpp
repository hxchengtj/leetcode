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
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if(t) {
                ans.append(to_string(t->val));
                q.push(t->left);
                q.push(t->right);
            }
            else ans.append("null");
            ans.push_back(',');
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        queue<TreeNode*> q;
        int n = data.size(), i = 0, j = 0;
        while(j < n && data[j] != ',') j++;
        if(data.substr(0, j) == "null") return root;
        else root = new TreeNode(stoi(data.substr(0, j)));
        i = j+1;
        q.push(root);
        bool isLeft = true;
        for(j = j+1; j < n; j++) {
            if(data[j] == ',') {
                TreeNode* t = NULL;
                if(data.substr(i, j-i) != "null") {
                    t = new TreeNode(stoi(data.substr(i, j-i)));
                    q.push(t);
                }
                TreeNode* a = q.front();
                if(isLeft) {
                    a->left = t;
                    isLeft = false;
                } else {
                    a->right = t;
                    isLeft = true;
                    q.pop();
                }
                i = j+1;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
