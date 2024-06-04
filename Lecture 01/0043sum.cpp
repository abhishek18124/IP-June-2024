// time  : nlogn + n^2 ~ O(n^2)
// space : O(1) + sorting space (depends on the language)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans; // to track all the valid triplets

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            if (i != 0 and nums[i] == nums[i - 1]) {

                // you cannot choose nums[i] as the 1st element of the valid triplet

                continue;

            }

            // fix nums[i] as the 1st element of a potential triplet

            // search for nums[j] and nums[k] in sorted subarray nums[i+1...n-1]

            // such that nums[j] + nums[k] = - nums[i]

            int targetSum = -nums[i];

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int pairSum = nums[j] + nums[k];

                if (pairSum == targetSum) {

                    // you've found a valid triplet

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k and nums[j] == nums[j - 1]) j++;
                    while (j < k and nums[k] == nums[k + 1]) k--;

                } else if (pairSum > targetSum) {

                    k--;

                } else {

                    // pairSum < targetSum

                    j++;

                }

            }


        }

        return ans;

    }
};