"""
LeetCode #1 - Two Sum

Topic: Array, Hash Map

Approach:
- Store numbers and their indices in a hash map
- For each number, check if its complement exists
- Return the indices when a match is found

Time Complexity: O(n)
Space Complexity: O(n)
"""

from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d={}
        for i in range (len(nums)):
            need=target-nums[i]

            if need in d:
                return[d[need],i]
            d[nums[i]]=i
obj = Solution()
nums=[2,7,11,15]
target=9
print(obj.twoSum(nums,target))
