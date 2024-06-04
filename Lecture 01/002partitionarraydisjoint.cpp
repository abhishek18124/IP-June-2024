// time : O(n) space : O(n) due rightSuffMin
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {

        int minLeftLength = 1;
        int leftMaxSoFar = nums[0];

        int n = nums.size();

        vector<int> rightSuffMin(n);
        rightSuffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightSuffMin[i] = min(nums[i], rightSuffMin[i + 1]);
        }

        for (int i = 0; i <= n - 2; i++) {

            leftMaxSoFar = max(leftMaxSoFar, nums[i]);

            // can I make a cut at the ith index ?

            // yes if leftMaxSoFar <= rightSuffMin[i+1]

            if (leftMaxSoFar <= rightSuffMin[i + 1]) {

                // you can make a cut at the ith index

                minLeftLength = i + 1;
                break;

            }

        }

        return minLeftLength;

    }
};


// approach 2 - time : O(n) space : O(1)

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {

        int leftMaxSoFar = nums[0];
        int minLeftLength = 1;

        int maxSoFar = nums[0];
        int n = nums.size();

        for (int i = 1; i <= n - 2; i++) {

            maxSoFar = max(maxSoFar, nums[i]);

            if (nums[i] < leftMaxSoFar) {

                // nums[i] and all the values preceding it will be part of the left

                minLeftLength = i + 1;
                leftMaxSoFar = maxSoFar;

            }

        }

        return minLeftLength;

    }
};