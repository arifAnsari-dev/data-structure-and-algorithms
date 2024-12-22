#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    int result = solution.height(root);

    cout << result << endl;

    return 0;
}

/*
Sample Input:
Tree structure:
        1
       / \
      2   3
     / \    \
    4   5    6

Correct Output:
3
*/
