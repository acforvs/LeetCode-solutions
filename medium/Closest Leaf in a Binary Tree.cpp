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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> g;
        dfs(g, root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> used;

        for (auto &[node, l] : g) {
            if (node != nullptr && node->val == k) {
                q.push(node);
                used.insert(node);
            }
        }

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if (top == nullptr) continue;
            if (g[top].size() <= 1) return top->val;

            for (auto &node : g[top]) {
                if (used.find(node) == used.end()) {
                    used.insert(node);
                    q.push(node);
                }
            }

        }
        assert(false);
    }

    void dfs(unordered_map<TreeNode*, vector<TreeNode*>>& g, TreeNode* node, TreeNode* parent) {
        if (node == nullptr) return;

        if (g.find(node) == g.end()) {
            vector<TreeNode*> test;
            g[node] = test;
        }
        if (g.find(parent) == g.end()) {
            vector<TreeNode*> test;
            g[parent] = test;
        }
        g[node].push_back(parent);
        g[parent].push_back(node);

        dfs(g, node->left, node);
        dfs(g, node->right, node);
    }
};
