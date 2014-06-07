// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        res.push_back(binarySearch(A,n,target,true));
        res.push_back(binarySearch(A,n,target,false));
        return res;
    }
    
    int binarySearch(int A[], int n, int target, bool isStart) {
        int res = -1, left = 0, right = n-1;
        while(left <= right) {
            int mid = left+(right-left)/2;
            if(A[mid] < target) left = mid+1;
            else if(A[mid] > target) right = mid-1;
            else {
                res = mid;
                if(isStart) right = mid-1;
                else left = mid+1;
            }
        }
        return res;
    }
};
