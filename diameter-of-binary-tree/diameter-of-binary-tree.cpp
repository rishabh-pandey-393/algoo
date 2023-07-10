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
    int ans;
    int f(TreeNode* root){
        if(!root) return 0;
        int l=1+f(root->left);
        int r=1+f(root->right);
        if(ans<l+r-1) ans=l+r-1;
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        f(root);
        return ans-1;
    }
};