Problem statement
You’re given an array 'arr' of size 'n' and an integer 'k'.

Your task is to split 'arr' into 'k' sub-arrays such that the maximum sum achieved from the 'k' subarrays formed must be the minimum possible.

A subarray is a contiguous part of the array.

Return the minimum possible value of the maximum sum obtained after splitting the array into 'k' partitions.



Example:
Input: ‘arr’ = [1, 1, 2] and ‘k’ = 2 

Output: 2

Explanation: If we want to make two subarrays, there are two possibilities: [[1], [1, 2]] and [[1, 1], [2]]. We can see that the maximum sum of any subarray is minimized in the second case. Hence, the answer is 2, which is the maximum sum of any subarray in [[1, 1], [2]].


// Same problem as painter's partition problem (min(max)) pattern binary search 

// Brute force approach: linear search on the range of answers 


// Optimised approach binary search on the range of possible answers 


// Implementation of optimised apporach 

// Implementation of the countSubArrays function 
int countSubArrays(int maxAllowedSum, vector<int> &arr) {
	int subArraysCount = 1, subArraySum = 0;

	for(int i = 0; i < arr.size(); i++) {
		if(subArraySum + arr[i] <= maxAllowedSum) {
			subArraySum += arr[i];
		} else {
			subArraysCount++;
			subArraySum = arr[i];
		}
	}
	return subArraysCount;
}


int splitArray(vector<int> &arr, int k) {
	// Write your code here.
	if(k > arr.size()) {
		return -1;
	}

	int maxSumAllowed = *max_element(arr.begin(), arr.end());
	int highestSum = accumulate(arr.begin(), arr.end(), 0);
	int ans = -1;
	
	while(maxSumAllowed <= highestSum) {
		int mid = maxSumAllowed + (highestSum - maxSumAllowed)/2;

		int subArrays = countSubArrays(mid, arr);

		if(subArrays <= k) {
			ans = mid;
			highestSum = mid - 1;
		} else {
			maxSumAllowed = mid + 1;
		}
	}
	return ans;
}
