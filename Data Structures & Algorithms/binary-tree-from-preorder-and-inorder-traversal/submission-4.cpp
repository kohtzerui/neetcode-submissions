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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        // The absolute root of the tree is always the first preorder element
        TreeNode* root = new TreeNode(preorder[0]);
        std::stack<TreeNode*> st;
        st.push(root);
        
        int inorder_idx = 0;

        // Iterate through the rest of the preorder array
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* current_node = st.top();
            TreeNode* new_node = new TreeNode(preorder[i]);

            // If the top of the stack does NOT match the inorder pointer,
            // we are still diving down the left side.
            if (current_node->val != inorder[inorder_idx]) {
                current_node->left = new_node;
                st.push(new_node);
            } 
            // We hit the bottom left! Time to make a U-Turn.
            else {
                // Pop from the stack as long as we match the inorder path
                while (!st.empty() && st.top()->val == inorder[inorder_idx]) {
                    current_node = st.top();
                    st.pop();
                    inorder_idx++;
                }
                // We've backed up as far as we need to. Attach the new node to the right!
                current_node->right = new_node;
                st.push(new_node);
            }
        }

        return root;
    }
};
