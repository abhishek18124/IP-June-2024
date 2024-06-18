/*

    Gray Code
    https://leetcode.com/problems/gray-code/
    Time : O(2^n)
    Space: O(n) due to the fn callstack
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {
public:

    void f(int n, vector<int>& ans) {

        // base case

        if (n == 0) {
            ans.push_back(0);
            return;
        }

        // recursive case

        // generate n-bit gray code sequence

        // 1. generate n-1th bit gray code sequence

        f(n - 1, ans);

        // 2. generate n-bit gray code sequence from n-1 bit gray code sequence

        int mask = (1 << (n - 1));

        for (int j = ans.size() - 1; j >= 0; j--) {

            ans.push_back(ans[j] | mask);

        }

    }

    vector<int> grayCode(int n) {

        vector<int> ans;

        f(n, ans);

        return ans;

    }
};