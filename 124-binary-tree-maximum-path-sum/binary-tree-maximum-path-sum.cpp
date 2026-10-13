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
    int m=INT_MIN;
    int dfs(TreeNode* rt){
        if(!rt) return 0;
        int l=max(0,dfs(rt->left));
        int r=max(0,dfs(rt->right));
        m=max(m,rt->val+l+r);
        return rt->val+max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return m;
    }
};