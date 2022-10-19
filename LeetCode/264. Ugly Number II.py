class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        factors = [2, 3, 5]
        minheap = [1,]
        table = set([1,])
        top = 0
        for _ in range(n):
            top = minheap[0]
            heapq.heappop(minheap)
            for f in factors:
                new_val = top * f
                if not new_val in table:
                    heapq.heappush(minheap, top * f)
                    table.add(new_val)
        return top
