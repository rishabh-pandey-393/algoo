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
    string s = "";

    void ser(TreeNode* root) {
        if(root == nullptr) {
            s += '*';
            return;
        }

        s += to_string(root->val) + '#';
        ser(root->left);
        ser(root->right);
    }

    void deser(int& i, string& data, TreeNode*& root) {
        if(data[i] == '*') {
            i++;
            return;
        }
        if(i == data.size()) return;

        int val = 0, fl = 1;
        if(data[i] == '-') fl = -1, i++;
        while(data[i] != '#') val = val * 10 + (data[i++] - '0');
        i++;

        root = new TreeNode(fl * val);
        deser(i, data, root->left);
        deser(i, data, root->right);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ser(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        int i = 0;
        deser(i, data, root);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));