class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        # pop: only when need to extend old bins to right (index - 1)
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
            stack.append((left, heights[index]))
        while len(stack) > 0:
            left, height = stack.pop()
            area = height * (len(heights) - left)
            max_area = max(max_area, area)
        return max_area
