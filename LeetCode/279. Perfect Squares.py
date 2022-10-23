class Solution(object):
    def numSquares(self, n):
        """
        # DP solution
        dp = list(range(n+1))
        upper = int(n ** 0.5)
        for i in range(1, upper+1):
            dp[i*i] = 1
        for i in range(2, n+1):
            best_val = dp[i]
            for j in range(upper+1):
                if j*j > i:
                    break
                if dp[j*j]+dp[i-j*j] < best_val:
                    best_val = dp[j*j]+dp[i-j*j]
            dp[i] = best_val
        return dp[n]
        """
        # BFS solution
        if n == 1:
            return 1
        if n == 2:
            return 2
        level = 1
        current_level = [n,]
        while current_level:
            next_level = []
            for par in current_level:
                for i in range(1, par+1):
                    if i*i > par:
                        break
                    if par == i*i:
                        return level
                    next_level.append(par-i*i)
            current_level = next_level
            level += 1
        return -1
