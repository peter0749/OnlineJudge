class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        c = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[c] = nums[i]
                c += 1
        for i in range(c, len(nums)):
            nums[i] = 0
