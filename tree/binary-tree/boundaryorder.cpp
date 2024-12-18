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

    // IMplementation of printRightBoundary function 
    void printRightBoundary(TreeNode* root, vector<int> &ans) {
        if(root == nullptr or (root->left == nullptr and root->right == nullptr)) {
            return;
        }
        if(root->right) {
            printRightBoundary(root->right, ans);
        } else if(root->left) {
            printRightBoundary(root->left, ans);
        }

        ans.push_back(root->val);
    }

    // Implementation of printLeaf function 
    void printLeaf(TreeNode* root, vector<int> &ans) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr and root->right == nullptr) {
            ans.push_back(root->val);
            return;
        }
        printLeaf(root->left, ans);
        printLeaf(root->right, ans);
    }

    // Implementation of printLeftBoundary function 
    void printLeftBoundary(TreeNode* root, vector<int> &ans) {
        if(root == nullptr or (root->left == nullptr and root->right == nullptr)) {
            return;
        }
        ans.push_back(root->val);
        if(root->left) {
            printLeftBoundary(root->left, ans);
        } else if(root->right) {
            printLeftBoundary(root->right, ans);
        }
    }

    vector<int> boundaryTraversal(TreeNode* root) {
        // Implement the boundary order traversal logic here
        if(root == nullptr) {
            return {};
        }

        vector<int> ans;
        ans.push_back(root->val);

        printLeftBoundary(root->left, ans);

        printLeaf(root->left, ans);
        printLeaf(root->right, ans);

        printRightBoundary(root->right, ans);

        return ans;
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
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    Solution solution;
    vector<int> result = solution.boundaryTraversal(root);

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
     / \ / \
    4  5 6  7
             / \
            8   9

Correct Output:
1 2 4 5 6 8 9 7 3
*/
