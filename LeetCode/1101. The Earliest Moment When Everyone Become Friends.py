class Solution:
    def init_union(self, n):
        self.par = [v for v in range(n)]
    
    def union_find(self, v):
        if v == self.par[v]:
            return v
        self.par[v] = self.union_find(self.par[v])
        return self.par[v]
    
    def union_same(self, v1, v2):
        return self.union_find(v1) == self.union_find(v2)
    
    def union_merge(self, v1, v2):
        p1 = self.union_find(v1)
        p2 = self.union_find(v2)
        if random.random() < 0.5:
            self.par[p1] = p2
        else:
            self.par[p2] = p1
    
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        # A simple Kruscal MST algorithm will do
        # Firstly, we sort the log list with their timestamp in ascending order.
        # Secondly, apply kruscal algorithm to connect the peoples, record and check their union find set iteratively.
        # Finally, check the union find set to verify if everyone is in the same group. If yes, return the moments where everyone is in the same group. Otherwise, return -1
        self.init_union(n)
        logs.sort(key=lambda x: x[0])
        stamp = -1
        for t, u, v in logs:
            if not self.union_same(u, v):
                stamp = t
                self.union_merge(u, v)
        
        # Make hidden nodes directly points to roots
        for v in range(n):
            self.union_find(v)
        root = self.par[0]

        # Check if same group (root). if not, return -1. OW, return stamp
        for v in range(n):
            if self.union_find(v) != root:
                return -1
        return stamp
