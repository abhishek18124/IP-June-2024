/*

    Find Peak Element
    https://leetcode.com/problems/find-peak-element/
    Time : O(logn)
    Space: O(1)
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        // define the bounds of the search space, a peak in nums[] is present in [0, n-1]

        int s = 0;
        int e = n - 1;

        while (s <= e) {

            int m = s + (e - s) / 2;

            // is nums[m] a peak in nums[] ?

            if (m + 1 < n and nums[m] < nums[m + 1]) {

                // nums[m] cannot be the peak, look for the peak in [m+1, e]

                s = m + 1;

            } else if (m - 1 >= 0 and nums[m] < nums[m - 1]) {

                // nums[m] cannot be the peak, look for the peak in [s, m-1]

                e = m - 1;

            } else {

                // nums[m] is a peak in nums[]

                return m;

            }

        }

        return -1; // since nums[] has >=1 peaks therefore this code not reachble

    }
};