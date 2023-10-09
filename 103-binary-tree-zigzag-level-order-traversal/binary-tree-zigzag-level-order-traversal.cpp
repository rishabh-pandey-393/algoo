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
        vector<vector<int>> V;
        if(root==NULL) return V;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            vector<int>v;
            int x=Q.size();
            for(int i=0;i<x;i++){
                v.push_back(Q.front()->val);
                if(Q.front()->left!=NULL) Q.push(Q.front()->left);
                if(Q.front()->right!=NULL) Q.push(Q.front()->right);
                Q.pop();
            }
            V.push_back(v);
        }
        for(int i=0;i<V.size();i++){
            if(i%2!=0) reverse(V[i].begin(), V[i].end());
        }
        return V;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root);
    }
};