Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

// Brute force approach for this problem 
use sort function in C++ stl, (sort(arr.begin(), arr.end()));

or use another sorting algorithm(less efficient) like selection sort bubble sort or insertion sort 



// Optimised approach to solve this problem (dutchman flag algorithm)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int currentIndex = 0;

        while(currentIndex <= end) {
            if(nums[currentIndex] == 0) {
                swap(nums[currentIndex++], nums[start++]);
            } else if(nums[currentIndex] == 1) {
                currentIndex++;
            } else {
                swap(nums[currentIndex], nums[end--]);
            }
        }
    }
};



