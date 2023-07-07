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
    int f(TreeNode * root){
        if(!root) return 0;
        int l=f(root->left);
        int r=f(root->right);
        if(l==-1 or r==-1 or abs(l-r)>1) return -1;
        return max(l,r)+1; 
    }
    bool isBalanced(TreeNode* root) {
        if(f(root)==-1) return false;
        return true;
    }
};