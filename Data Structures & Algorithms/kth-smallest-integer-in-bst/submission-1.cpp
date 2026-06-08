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
    int result = -1;

    void inOrder(TreeNode* node, int k, int& count){
        if(!node || count >= k) return;

        inOrder(node->left, k, count);

        count++;
        if(count == k){
            result = node->val;
            return;
        }

        inOrder(node->right, k, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        inOrder(root, k, count);
        return result;
    }
};
