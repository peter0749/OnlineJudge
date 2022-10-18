class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        # pop: only when need to extend old bins to right (index - 1)
        # other: accumulate from old heights from left
        stack = []
        max_area = 0
        for index in range(len(heights)):
            # left: record the left-most index that satisfy heights[left] >= heights[index]
            left = index
            while len(stack) > 0 and heights[index] <= stack[-1][1]:
                # pop and extent the >= height[index] bins to index-1
                top = stack.pop()
                area = top[1] * (index - top[0])
                max_area = max(max_area, area)
                left = top[0] # update left point
            # accumulate from old heights from left-most to index
            if len(stack) > 0:
                area = stack[-1][1] * (index - stack[-1][0] + 1)
                max_area = max(max_area, area)
            stack.append((left, heights[index]))
        while len(stack) > 0:
            left, height = stack.pop()
            area = height * (len(heights) - left)
            max_area = max(max_area, area)
        return max_area
    
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        '''
        1 0 1 0 0
        2 0 2 1 1
        3 1 3 2 2
        4 0 0 3 0
        '''
        N, M = len(matrix), len(matrix[0])
        matrix = [[int(xx) for xx in x] for x in matrix]
        for i in range(1,N):
            for j in range(M):
                matrix[i][j] += (matrix[i-1][j] if matrix[i][j]>0 else 0)
        return max(self.largestRectangleArea(matrix[i]) for i in range(N))
