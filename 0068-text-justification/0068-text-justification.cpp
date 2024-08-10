class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int index = 0;

        // Loop over all the words
        while (index < words.size()) {
            int totalChars = words[index].length();
            int last = index + 1;

            // Determine how many words can fit in the current line
            while (last < words.size()) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length();
                last++;
            }

            // Create the current line
            string line;
            int numWords = last - index;
            int numSpaces = maxWidth - totalChars + (numWords - 1);

            // If we're on the last line or the line has only one word, we left-justify
            if (last == words.size() || numWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += ' ';
                }
                line += string(maxWidth - line.length(), ' ');
            } 
            // Else we distribute spaces evenly between words
            else {
                int spaces = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        line += string(spaces + (i - index < extraSpaces ? 1 : 0), ' ');
                    }
                }
            }

            // Add the line to the result and move to the next set of words
            result.push_back(line);
            index = last;
        }

        return result;
    }
};
