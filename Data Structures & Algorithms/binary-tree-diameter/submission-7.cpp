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
    int treeHeight(TreeNode* root, int& global_max){
        if(!root) return 0;

        int left_height = treeHeight(root->left, global_max);
        int right_height = treeHeight(root->right, global_max);

        int local_diameter = left_height + right_height;
        global_max = max(local_diameter, global_max);
        return max(left_height, right_height) + 1;
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        int global_max = 0;
        treeHeight(root, global_max);
        return global_max;
    }
};
