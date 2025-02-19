// Two sum leetcode:

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]



// BruteForce approach to solve this problem 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Better approach to solve this problem
store the indices corresponding to the elements 
sort the array
apply two pointers technique(start(index = 0) , end(index = nums.size()-1))

get the currentSum(arr[start] + arr[end] and compare with target)

shift the left and right pointer accordingly


//Optimised approach to solve this problem 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> elementIndex;

        for(int i = 0; i < nums.size(); i++) {
            if(elementIndex.find(target - nums[i]) != elementIndex.end()){
                return {i, elementIndex[target - nums[i]]};
            }
            elementIndex[nums[i]] = i;
        }
        return {};
    }

};