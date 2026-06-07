"""
LeetCode #30 - Substring with Concatenation of All Words

Topic: Hash Map, Sliding Window, String

Approach:
- Store required word frequencies in a hash map
- Use a sliding window with word-sized jumps
- Maintain frequencies of words inside the current window
- Shrink the window when a word appears too many times
- Record starting indices whenever all words are matched

Time Complexity: O(n)
Space Complexity: O(k)
"""
from typing import List

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:

        if not s or not words:
            return []

        wl = len(words[0])
        wc = len(words)

        need = {}

        for w in words:
            need[w] = need.get(w, 0) + 1

        ans = []

        for offset in range(wl):

            left = offset
            right = offset

            have = {}
            count = 0

            while right + wl <= len(s):

                word = s[right:right + wl]
                right += wl

                if word in need:

                    have[word] = have.get(word, 0) + 1
                    count += 1

                    while have[word] > need[word]:

                        left_word = s[left:left + wl]
                        have[left_word] -= 1
                        count -= 1
                        left += wl

                    if count == wc:

                        ans.append(left)

                        left_word = s[left:left + wl]
                        have[left_word] -= 1
                        count -= 1
                        left += wl

                else:

                    have.clear()
                    count = 0
                    left = right

        return ans


obj = Solution()

s = "barfoofoobarthefoobarman"
words = ["bar", "foo", "the"]

print(obj.findSubstring(s, words))
