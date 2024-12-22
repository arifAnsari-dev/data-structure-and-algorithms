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

    // Implementation of the Solve function 
    void solve(TreeNode* root, vector<int> &ans) {
        if(root == nullptr){
            return;
        }
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }


    vector<int> inorderTraversal(TreeNode* root) {
        // Implement the inorder traversal logic here
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
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

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
     \
      2
     /
    3

Correct Output:
1 3 2
*/
