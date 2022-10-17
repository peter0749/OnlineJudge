class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        small_ans = [0,0,1,2,4,6,9,12,18,27]
        
        if n < len(small_ans):
            return small_ans[n]
        
        # ans = 3x3x[2|3|4]
        threes = n // 3
        remain = n % 3
        res = int(3**threes)
        
        # case '3'
        if remain == 0:
            return res
        
        # case max(case_2, case_4)
        return max(res * remain, res//3 * (remain+3))
        
        
        return res
