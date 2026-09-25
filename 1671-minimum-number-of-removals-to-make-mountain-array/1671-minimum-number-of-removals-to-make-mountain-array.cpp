class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
          int n = nums.size();

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // Longest Increasing Subsequence ending at i
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Longest Decreasing Subsequence starting at i
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {

                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int minRemovals = n;

        // Consider every element as the peak
        for (int i = 0; i < n; i++) {

            // Peak must have both increasing and decreasing sides
            if (LIS[i] > 1 && LDS[i] > 1) {

                int mountainLength = LIS[i] + LDS[i] - 1;

                minRemovals = min(
                    minRemovals,
                    n - mountainLength
                );
            }
        }

        return minRemovals; 
    }
};