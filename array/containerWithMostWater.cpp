11. Container With Most Water
Attempted
Medium
Topics
Companies
Hint
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1



// Brute force approach to solve this problem 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAns = 0;
        for(int i = 0; i < height.size()-1; i++){
            for(int j = i+1; j < height.size(); j++) {
                int minHeight = max(height[i], height[j]);
                int width = j-i;
                maxAns = max(maxAns, (minHeight * width));
            }
        }
        return maxAns;
    }
};


// Optimised approach to solve this problem 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int maxAns = 0;

        while(start < end) {

            // Simplification
            // int minHeight = min(height[start], height[end]);// minHeight will control the water
            // int width = (end - start)
            // water(represents area) = minHeight * width
            maxAns = max(maxAns, ((end - start)*(min(height[start], height[end]))));
            (height[start]< height[end])? start++ : end--;
        }
        return maxAns;
    }
};