class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cnt=0
        l=0 
        for r in range(len(nums)):
            if nums[r]==val: continue
            else:
                cnt+=1
                nums[l],nums[r]=nums[r],nums[l]
                l+=1
        return cnt