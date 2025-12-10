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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr != nullptr || !st.empty()) {

            // Step 1: Go as left as possible
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* topNode = st.top();

                // Step 2: If right child exists and not yet processed, go right
                if (topNode->right != nullptr && lastVisited != topNode->right) {
                    curr = topNode->right;
                }
                else {
                    // Step 3: Visit the node
                    ans.push_back(topNode->val);
                    lastVisited = topNode;
                    st.pop();
                }
            }
        }

        return ans;
    }
};
