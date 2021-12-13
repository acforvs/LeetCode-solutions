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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        longestPath(root, ans);
        return ans;
    }

    const pair<int, int> longestPath(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return {0, 0};
        }

        int incr = 1, decr = 1;
        if (root->left) {
            const pair<int, int> left = longestPath(root->left, ans);
            if (root->val == root->left->val + 1) {
                decr = left.second + 1;
            } else if (root->val == root->left->val - 1) {
                incr = left.first + 1;
            }
        }

        if (root->right) {
            const pair<int, int> right = longestPath(root->right, ans);

            if (root->val == root->right->val + 1) {
                decr = max(decr, right.second + 1);
            } else if (root->val == root->right->val - 1) {
                incr = max(incr, right.first + 1);
            }
        }
        ans = max(ans, incr + decr - 1);
        return {incr, decr};
    }
};
