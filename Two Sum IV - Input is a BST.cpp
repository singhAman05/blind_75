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

// TC O(N)
// SC O(N)

class Solution {
public:
    unordered_map<int,int> mp;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;
        if(mp.count(k-root->val)) return 1;
        
        mp[root->val]++;
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};
