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
    vector<vector<int>> levelOrder(TreeNode* r) {
        vector<vector<int>> o;
        if(r==nullptr)
            return o;
        storeLevel(o,r,0);
        return o;
    }
    void storeLevel(vector<vector<int>> &o,TreeNode* r,int d){
        if(o.size()<d+1)
            o.resize(o.size()+1);
        o[d].push_back(r->val);
        if(r->left!=nullptr)
            storeLevel(o,r->left,d+1);
        if(r->right != nullptr)
            storeLevel(o, r->right,d+1);
        return;      
    }
};