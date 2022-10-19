class Solution(object):
    
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return False
        factors = [2, 3, 5]
        for f in factors:
            while n % f == 0:
                n = n // f
        if n == 1:
            return True
        return False
