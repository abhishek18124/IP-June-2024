class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0;
        int curMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = 0;
        
        for (int i=0;i<nums.size();i++) {
            // Normal Kadane's
            curMax = max(curMax, 0) + nums[i];
            maxSum = max(maxSum, curMax);
            
            // Kadane's but with min to find minimum subarray
            curMin = min(curMin, 0) + nums[i];
            minSum = min(minSum, curMin);
            
            totalSum += nums[i];  
        }

        if (totalSum == minSum) {
            return maxSum;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};
