class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt=1
        l=0
        for r in range(len(nums)):
            if nums[r]!=nums[l]:
                nums[l+1] = nums[r]
                cnt=cnt+1
                l=l+1

        
        return cnt
