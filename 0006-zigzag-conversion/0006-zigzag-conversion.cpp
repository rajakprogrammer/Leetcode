class Solution {
public:
    string convert(string s, int numRows) {
        // Handle the simple case where no zigzag is needed
        if (numRows == 1) {
            return s;
        }
        
        // Initialize a vector of strings to hold the zigzag rows
        vector<string> ans(numRows);
        bool flag = false;
        int i = 0;
        
        // Loop through each character in the input string
        for (auto ch : s) {
            ans[i] += ch;  // Add the character to the current row
            
            // Change direction when reaching the first or last row
            if (i == 0 || i == numRows - 1) {
                flag = !flag;
            }
            
            // Move to the next row
            if (flag) {
                i += 1;  // Move down
            } else {
                i -= 1;  // Move up
            }
        }
        
        // Concatenate all rows into a single string
        string zigzag = "";
        for (auto str : ans) {
            zigzag += str;
        }
        
        return zigzag;
    }
};
