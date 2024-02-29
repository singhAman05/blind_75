/*
  In this question we have just simply run the BFS and keft on checking according to given condition
*/


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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        bool fl = 1;
        q.push(root);
        while(!q.empty()){
            int si = q.size();
            int pre = fl==0 ? INT_MAX : INT_MIN;
            cout<<pre<<" ";
            while(si--){
                TreeNode* node = q.front();
                int val = node->val;
                q.pop();
                if(fl){
                    if(val <= pre || val%2==0) return 0;                    
                }
                else{
                    if(val>=pre || val&1) return 0;
                }
                pre=val;
                if(node->left){ q.push(node->left);cout<<node->left->val<<" ";}
                if(node->right) {q.push(node->right);cout<<node->right->val<<" ";}
            }
            fl=!fl;
        }
        return 1;
    }
};
