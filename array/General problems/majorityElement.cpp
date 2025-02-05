/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/



// The brute force approach to solve this problem is 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(auto possibleAns: nums) {
            int currentAns = possibleAns;
            int count = 0;
            for(auto element: nums) {
                if(element == currentAns) {
                    count++;
                }
            }
            if(count > nums.size()/2) {
                return currentAns;
            }
        }
        return -1;
    }
    
};


// Another approach to solve this problem 

Using sorting and counting the frequency of each element, before a different element comes(elements are sorted: remember that)
count frequency if greater than n/2, it's a majority element or not 


// Optimial approach to solve this problem 


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == ans) {
                count++;
            } else {
                count--;
            }

            if(count == 0) {
                ans = nums[i];
                count = 1;
            }
        }
        count = 0;
        for(auto element: nums) {
            if(element == ans) {
                count++;
            }
        }
        if(count > nums.size()/2) {
            return ans;
        }
        return -1;
    }
};