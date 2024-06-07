/*

    Search a 2D Matrix
    https://leetcode.com/problems/search-a-2d-matrix/
    Time : O(log(mn))
    Space: O(1)
    @author : Abhishek Srivastava
    LinkedIn: bit.ly/srivabhishek

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        // define the bounds of the search space

        int s = 0;
        int e = m * n - 1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            // index 'mid' in the underlying 1D array corresponds to cell index (mid/n, mid%n) in the given 2D array

            int i = mid / n;
            int j = mid % n;

            if (target == matrix[i][j]) {

                return true;

            } else if (target < matrix[i][j]) {

                e = mid - 1;

            } else {

                s = mid + 1;

            }

        }

        return false;

    }
};