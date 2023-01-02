class Solution:
    def dfs(self, graph, start):
        visited = [False for _ in range(len(graph))]
        num_visited = 1

        stack = [start,]
        visited[start] = True

        while stack:
            p = stack[-1]
            stack.pop()
            for nn in graph[p]:
                if not visited[nn]:
                    stack.append(nn)
                    visited[nn] = True
                    num_visited += 1
        return num_visited


    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        N = len(bombs)

        # Build graph
        graph = [[] for _ in range(N)]
        for i in range(N):
            xi, yi, ri = bombs[i]
            ri2 = ri * ri
            for j in range(i+1, N):
                xj, yj, rj = bombs[j]
                rj2 = rj * rj
                dX, dY = (xi - xj), (yi - yj)
                dist2 = dX * dX + dY * dY
                # Check if bombs[i], bombs[j] are overlapped
                if ri2 >= dist2:
                    graph[i].append(j)
                if rj2 >= dist2:
                    graph[j].append(i)
        # Find maximum denotation by DFS
        return max(self.dfs(graph, i) for i in range(N))
