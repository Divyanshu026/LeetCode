class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        x = len(nums)
        for i in range(x):
            if nums[i]>=target:
                 return i
        return x