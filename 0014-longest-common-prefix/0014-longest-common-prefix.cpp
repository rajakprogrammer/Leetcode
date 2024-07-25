class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize result string to store the common prefix
        string res = "";
        
        // Iterate over each character index of the first string in the vector
        for (int i = 0; i < strs[0].size(); i++) {
            // Iterate over each string in the vector
            for (auto s : strs) {
                // If the character at the current index of the string does not match the character
                // at the same index of the first string, return the result string as it is
                if (s[i] != strs[0][i]) {
                    return res;
                }
            }
            // If the character at the current index matches in all strings, append it to the result
            res += strs[0][i];
        }
        
        // Return the longest common prefix
        return res;
    }
};
