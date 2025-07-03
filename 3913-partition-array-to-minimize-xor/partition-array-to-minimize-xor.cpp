class Solution {
public:
       int dfs(vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        int n = nums.size();
        if (j == 1) {
            int xor_sum = 0;
            for (int idx = i; idx < n; ++idx) {
                xor_sum ^= nums[idx];
            }
            return xor_sum;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int min_max = INT_MAX;
        int current_xor = 0;
        for (int s = i; s <= n - j; ++s) {
            current_xor ^= nums[s];
            int remaining_max = dfs(nums, s + 1, j - 1, memo);
            min_max = min(min_max, max(current_xor, remaining_max));
        }
        memo[i][j] = min_max;
        return min_max;
    }
    int minXor(vector<int>& nums, int k) {
         int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        return dfs(nums, 0, k, memo);
    }
};