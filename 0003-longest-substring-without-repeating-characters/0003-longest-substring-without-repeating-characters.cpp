class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1); // Keeps track of the last occurrence of each character
        int maxLen = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i]] >= start) {
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
