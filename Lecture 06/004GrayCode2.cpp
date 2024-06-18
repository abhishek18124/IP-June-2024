/*

    Gray Code
    https://leetcode.com/problems/gray-code/
    Time : O((2^n)*n)
    Space: O(2^n) due to the fn callstack and the unordered_set 'seen'
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {

    bool flag = false; // assume we've not yet built an n-bit gray code sequence

public:

    void helper(int n, vector<int>& res, unordered_set<int>& seen) {

        // base case

        if (res.size() == 1 << n) {

            // you've managed to build an n-bit gray code sequence

            flag = true;

            return;

        }

        // recursive case

        // decide the next element

        for (int i = 0; i < n; i++) {

            int lastElement = res.back(); // res[res.size()-1]

            // flip the ith bit of lastElement

            int mask = 1 << i;
            int nextElement = lastElement ^ mask;

            if (seen.find(nextElement) != seen.end()) {

                // nextElement has been tracked previously

                continue;

            }

            res.push_back(nextElement);
            seen.insert(nextElement);

            helper(n, res, seen);

            if (flag) {

                // we've managed to build a n-bit gray code sequence

                return;

            }

            res.pop_back(); // backtracking (optional, think why ?)
            seen.erase(nextElement); // backtracking (optional, think why ?)

        }


    }

    vector<int> grayCode(int n) {

        vector<int> res; // to store the n-bit gray code sequence
        res.push_back(0); // n-bit gray code sequence starts with zero

        unordered_set<int> seen; // to store elements we've tracked so far
        seen.insert(0);

        helper(n, res, seen);

        return res;

    }
};