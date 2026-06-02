"""
LeetCode #4 - Median of Two Sorted Arrays

Difficulty: Hard
Topic: Array, Binary Search

Approach:
- Binary search on the smaller array
- Find a partition such that:
  max(left side) <= min(right side)
- Compute median from partition boundaries

Time Complexity: O(log(min(m,n)))
Space Complexity: O(1)
"""
from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m = len(nums1)
        n = len(nums2)

        left = 0
        right = m

        while left <= right:

            p1 = (left + right) // 2
            p2 = (m + n + 1) // 2 - p1

            if p1 == 0:
                maxLeft1 = float('-inf')
            else:
                maxLeft1 = nums1[p1 - 1]

            if p1 == m:
                minRight1 = float('inf')
            else:
                minRight1 = nums1[p1]

            if p2 == 0:
                maxLeft2 = float('-inf')
            else:
                maxLeft2 = nums2[p2 - 1]

            if p2 == n:
                minRight2 = float('inf')
            else:
                minRight2 = nums2[p2]

            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:

                if (m + n) % 2 == 0:
                    return (max(maxLeft1, maxLeft2) +
                            min(minRight1, minRight2)) / 2

                else:
                    return max(maxLeft1, maxLeft2)

            elif maxLeft1 > minRight2:
                right = p1 - 1

            else:
                left = p1 + 1


obj = Solution()

nums1 = [1, 2]
nums2 = [3, 4]

print(obj.findMedianSortedArrays(nums1, nums2))
