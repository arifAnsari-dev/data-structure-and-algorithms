
Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

Note: If multiple occurrences are there, please return the smallest index.

Examples:

Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.
Input: arr[] = [11, 22, 33, 44, 55], k = 445
Output: -1
Explanation: 445 is not present.
Input: arr[] = [1, 1, 1, 1, 2], k = 1
Output: 0
Explanation: 1 appears at index 0.


// Iterative Approach

class Solution {
    
  private:
    // Implemenation of the solve function 
    int solve(vector<int> &arr, int start, int end, int target) {
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            
            if(arr[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if(arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    
  public:
    int binarysearch(vector<int> &arr, int k) {
        return solve(arr, 0, arr.size()-1, k);
    }
};


// Recurisive approach 

class Solution {
  public:
    
    // Implementation of the solve function 
    int solve(vector<int> &arr, int start, int end, int target){
        if(start > end) {
            return -1;
        }
        
        int mid = start + (end - start)/2;
        if(arr[mid] == target) {
            int leftIndex = solve(arr, start, mid -1, target);
            return (leftIndex != -1) ? leftIndex : mid;
        } else if(arr[mid] > target) {
            return solve(arr, start, mid - 1, target);
        } else {
            return solve(arr, mid + 1, end, target);
        }
    }
    
    
    int binarysearch(vector<int> &arr, int k) {
        // code here
        return solve(arr, 0, arr.size()-1, k);
    }
};