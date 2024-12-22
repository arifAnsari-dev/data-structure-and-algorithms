#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    // Implementation of the solve function 
    vector<vector<int>> solve(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> currentPath(n);

            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                currentPath[i] = node->val;

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(currentPath);
        }
        return ans;
    }

    
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Implement the level order traversal logic here
        if(root == nullptr) {
            return {{}};
        }
        return solve(root);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    for (const auto& level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Sample Input:
Tree structure:
        1
       / \
      2   3
     / \ / \
    4  5 6  7

Correct Output:
1 
2 3 
4 5 6 7
*/
