class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """
        # Concatenate all elements in word1 and word2 and compare the results
        return ''.join(word1) == ''.join(word2)

if __name__ == "__main__":
    word1 = ["ab", "c"]
    word2 = ["a", "bc"]
    solution = Solution()
    
    if solution.arrayStringsAreEqual(word1, word2):
        print("Yes")
    else:
        print("No")
