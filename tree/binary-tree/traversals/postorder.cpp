#include <iostream>
#include <vector>
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
    void solve(TreeNode* root, vector<int> &ans) {
        if(root == nullptr) {
            return;
        }
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // Implement the postorder traversal logic here
        if(root == nullptr) {
            return {};
        }
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<int> result = solution.postorderTraversal(root);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Sample Input:
Tree structure:
        1
       / \
      2   3
     / \
    4   5

Correct Output:
4 5 2 3 1
*/
