class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, sum = 0, min_length = INT_MAX;
        
        for (int end = 0; end < n; ++end) {
            sum += nums[end];
            
            while (sum >= target) {
                min_length = min(min_length, end - start + 1);
                sum -= nums[start];
                ++start;
            }
        }
        
        return min_length == INT_MAX ? 0 : min_length;
    }
};
