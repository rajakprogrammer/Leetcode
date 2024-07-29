#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0; // No jumps needed if there's only one element
        }

        int jumps = 0; // Number of jumps
        int current_end = 0; // The end of the current jump range
        int farthest = 0; // The farthest point we can reach with the current number of jumps

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]); // Update the farthest point we can reach

            // If we have reached the end of the current jump range
            if (i == current_end) {
                jumps++; // Increase the number of jumps
                current_end = farthest; // Update the end of the current jump range

                // If the farthest point we can reach is the end or beyond, we can stop
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};
