/*

    Subsets II
    https://leetcode.com/problems/subsets-ii/
    Time : O(2^n.n)
    Space: O(n) due to output to store a subset + function call-stack excluding output otherwise O((2^n).n)
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {
public:

    void helper(vector<int> nums, int n, int i, vector<int>& s, vector<vector<int>>& ans, bool taken) {

        // base case

        if (i == n) {

            // you've managed to build a subset

            ans.push_back(s);
            return;

        }

        // recursive case

        // generate unique subsets for nums[i...n-1]

        // make a decision for the nums[i]

        // option 1 : include nums[i] into subset

        if (i == 0 || nums[i] != nums[i - 1] || taken) { // i == 0 || nums[i] != nums[i-1] || (nums[i] == nums[i-1] and taken == true)

            s.push_back(nums[i]);
            helper(nums, n, i + 1, s, ans, true);
            s.pop_back(); // backtracking

        }

        // option 2 : exclude nums[i] from subset

        helper(nums, n, i + 1, s, ans, false);


    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans; // to store all the subsets
        vector<int> s; // to store a single subset

        int n = nums.size();

        helper(nums, n, 0, s, ans, false);

        return ans;

    }
};