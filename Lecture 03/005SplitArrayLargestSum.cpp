/*

    Split Array Largest Sum
    https://leetcode.com/problems/find-a-peak-element-ii/
    Time : O(nloga) where n is the size of nums[] and a is the size of the search space and is equal to sum(nums[]) - max(nums[])
    Space: O(1)
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {
public:

    bool canSplit(vector<int>& nums, int k, int m) {

        // can you split nums[] in k non-empty subarrays such that the largest sum of the split <= 'm' ?

        // find out the no. of non-empty subarrays into which nums[] should be split such that the largest sum of the split <= m

        int numCuts = 0; // to track the no. of cuts we've to make to ensure the largest sum of the split doesn't exceed 'm'
        int sum = 0; // to track the sum of a subarray part of the split

        int i = 0;

        while (i < nums.size()) {

            if (sum + nums[i] > m) {

                // nums[i] cannot be part of the current subarray i.e. we make a cut at the i-1th index

                numCuts++;
                sum = 0;
                continue;

            }

            // num[i] can be part of the current subarray

            sum = sum + nums[i];
            i++;

        }

        // to ensure that the largest sum of a split of num[] doesn't exceed 'm', we've made 'numCuts' cuts

        // i.e. we partitioned nums[] into numCuts + 1 subarrays

        return numCuts + 1 <= k; // if this condition evalautes to true then it also means we can split nums[] in k non-empty subarrays such that the largest sum of the split <= 'm'

    }

    int splitArray(vector<int>& nums, int k) {

        // define the bounds of the search space

        // lower bound - assume k = n then there is only 1 way to split the array which is to have n subarrays each of size 1
        // upper bound - assume k = 1 then there is only 1 way to split the array  which is to have 1 subarray of size n

        // therefore the minimum value of the largest sum lies between max(nums[]) ans sum(nums[])

        int s = *max_element(nums.begin(), nums.end()); // to store the max(num[]), max_element is present in <algorithm>
        int e = accumulate(nums.begin(), nums.end(), 0); // to store the sum(nums[]), accumulate is present in <numeric>

        int ans; // to store the minimized largest sum of a split

        while (s <= e) {

            int m = s + (e - s) / 2;

            // can the largest sum of a split with k non-empty subarrays be <= m ?

            if (canSplit(nums, k, m)) {

                // the largest sum of a split with k non-empty subarrays can be <= m

                ans = m;

                // now, to minimize the largset sum of a split, move towards the left of 'm'

                e = m - 1;

            } else {

                // the largest sum of a split with k non-empty subarrays cannot be <= m

                // therefore, increase the largest sum of a split by moving towards the right of 'm'

                s = m + 1;

            }

        }

        return ans;

    }
};