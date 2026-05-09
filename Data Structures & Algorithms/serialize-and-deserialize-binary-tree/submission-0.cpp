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

class Codec {
public:
    void dfs(TreeNode* root, string &s){
        if(root == NULL){
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        dfs(root, s);
        return s;
    }
    TreeNode* solve(vector<string> &nodes, int &i){
        if(nodes[i] == "N"){
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;
        root->left = solve(nodes, i);
        root->right = solve(nodes, i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";
        for(char c : data){
            if(c == ','){
                nodes.push_back(temp);
                temp = "";
            }
            else {
                temp += c;
            }
        }
        int i = 0;
        return solve(nodes, i);
    }
};
