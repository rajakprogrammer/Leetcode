class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int l = 1;  // Initialize l to 1, because nums[0] is always a unique element
        for (int r = 1; r < nums.size(); r++) {
            if (nums[r] != nums[r - 1]) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};
