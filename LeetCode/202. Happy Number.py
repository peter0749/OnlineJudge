class Solution(object):
    
    def next_val(self, n):
        s = 0
        while n>0:
            r = n%10
            s += (r*r)
            n = n // 10
        return s
    
    def isHappy(self, n):
        if n == 1:
            return True
        # Floyd’s Cycle Detection Algorithm
        n_slow = n
        n_fast = n
        while True:
            n_slow = self.next_val(n_slow)
            n_fast = self.next_val(self.next_val(n_fast))
            #print(n_slow, n_fast)
            if n_slow == 1:
                return True
            if n_slow == n_fast:
                return False
        return False
