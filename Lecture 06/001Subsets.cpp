/*

    Subsets
    https://leetcode.com/problems/subsets/
    Time : O(2^n.n)
    Space: O(n) due to output to store a subset + function call-stack
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {
public:

    void helper(vector<int> nums, int n, int i, vector<int>& s, vector<vector<int>>& ans) {

        // base case

        if (i == n) {

            // you've managed to build a subset

            ans.push_back(s);
            return;

        }

        // recursive case

        // generate subsets for nums[i...n-1]

        // make a decision for the nums[i]

        // option 1 : include nums[i] into subset

        s.push_back(nums[i]);
        helper(nums, n, i + 1, s, ans);

        // option 2 : exclude nums[i] from subset

        s.pop_back(); // backtrack
        helper(nums, n, i + 1, s, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans; // to store all the subsets
        vector<int> s; // to store a single subset

        int n = nums.size();

        helper(nums, n, 0, s, ans);

        return ans;

    }
};