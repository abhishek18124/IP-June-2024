
// brute-force O(n^2) -> TLE

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int maxSoFar = 0;
		int n = prices.size();

		for (int i = 0; i <= n - 2; i++) {

			for (int j = i + 1; j <= n - 1; j++) {

				maxSoFar = max(maxSoFar, prices[j] - prices[i]);

			}

		}

		return maxSoFar;

	}
};


// approach 2 - time : O(n) space : O(n) due suffMax[]

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		int maxSoFar = 0;

		vector<int> suffMax(n);
		suffMax[n - 1] = prices[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			suffMax[i] = max(prices[i], suffMax[i + 1]);
		}

		for (int i = 0; i <= n - 2; i++) {

			maxSoFar = max(maxSoFar, suffMax[i] - prices[i]);

		}

		return maxSoFar;


	}
};

// approach 3 - time : O(n) space : O(1)

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		int maxSoFar = 0;

		int suffMaxSoFar = prices[n - 1];

		for (int i = n - 2; i >= 0; i--) {

			suffMaxSoFar = max(suffMaxSoFar, prices[i]);
			maxSoFar = max(maxSoFar, suffMaxSoFar - prices[i]);

		}

		return maxSoFar;

	}
};