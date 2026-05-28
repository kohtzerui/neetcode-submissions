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
private:
    int max_diameter = 0;
    int calculateHeight(TreeNode* node){
        if(node == nullptr) return 0;
        int left_height = calculateHeight(node->left);
        int right_height = calculateHeight(node->right);
        max_diameter = max(max_diameter, left_height + right_height);
        return max(left_height, right_height) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        this->max_diameter = 0;
        calculateHeight(root);
        return this->max_diameter;
    }
};
