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
    int global_max = 0;

    int treeHeight(TreeNode* root){
        if(!root) return 0;

        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);

        int local_diameter = left_height + right_height;
        global_max = max(local_diameter, global_max);
        return max(left_height, right_height) + 1;
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        //global_max = 0;
        treeHeight(root);
        return global_max;
    }
};
