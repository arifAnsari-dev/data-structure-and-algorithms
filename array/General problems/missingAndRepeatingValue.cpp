
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].



// Solution 
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repNumber, missNumber;
        int gridSum = 0, expectedSum;

        unordered_set<int> st;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                if(st.find(grid[i][j]) != st.end()) {
                    repNumber = grid[i][j];
                }
                st.insert(grid[i][j]);
                gridSum += grid[i][j];
            }
        }

        int n = grid.size();
        expectedSum = (n*n *(n*n + 1))/2;

        missNumber = expectedSum - gridSum + repNumber;

        return {repNumber, missNumber};
    }
};