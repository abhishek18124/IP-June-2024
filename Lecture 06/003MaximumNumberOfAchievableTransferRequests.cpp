/*

    Maximum Number of Achievable Transfer Requests
    https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
    Time : O((2^M)*N)
    Space: O(M+N)
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {

public:

    int maxSoFar = 0; // to track the maximum no. of achievable transfer requests

    void helper(const vector<vector<int>>& requests, vector<int>& v, int i, int cnt) {

        // base case

        if (i == requests.size()) {

            // we've taken decisions for all the requests

            bool flag = true; // assume all the decisions were valid

            for (int i = 0; i < v.size(); i++) {

                if (v[i] != 0) {

                    // net-flow of employees in the ith building is not zero

                    flag = false;
                    break;

                }

            }

            if (flag) {
                // all the decisions were valid
                maxSoFar = max(maxSoFar, cnt);
            }

            return;

        }

        // recursive case

        // make a decision for the ith request i.e. requests[i]

        int from_i = requests[i][0];
        int to_i   = requests[i][1];

        // accept the ith request

        v[from_i]--;
        v[to_i]++;

        helper(requests, v, i + 1, cnt + 1);

        // do not accept the ith request

        v[from_i]++;
        v[to_i]--;

        helper(requests, v, i + 1, cnt);

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {

        vector<int> v(n, 0); // to track no. net employee movement in a building

        helper(requests, v, 0, 0);

        return maxSoFar;

    }

};