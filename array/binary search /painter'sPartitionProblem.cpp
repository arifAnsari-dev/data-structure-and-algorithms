

Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11


// Brute force approach: same(just a change of variables and array names, in the book allocation proboem )


// This is the optimised approach for the above problem (also similar to the book allocation problem )
// Binary search on answers 

// Implementation of calcPainters function 
int calcPainters(int maxAreaAllowed, vector<int> &boards) {
    int painters = 1, areaAssigned = 0;

    for(int i = 0; i < boards.size(); i++) {
        if(areaAssigned + boards[i] <= maxAreaAllowed) {
            areaAssigned += boards[i];
        } else {
            painters++;
            areaAssigned = boards[i];
        }
    }
    return painters;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    if(k > boards.size()) {
        return -1;
    }

    int maxAreaAllowed = *max_element(boards.begin(), boards.end());
    int highestArea = accumulate(boards.begin(), boards.end(), 0);

    while(maxAreaAllowed <= highestArea) {
        int mid = maxAreaAllowed + (highestArea - maxAreaAllowed)/2;
        int painters = calcPainters(mid, boards);

        if(painters > k) {
            maxAreaAllowed = mid + 1;
        } else {
            highestArea = mid - 1;
        }
    }
    return maxAreaAllowed;
}