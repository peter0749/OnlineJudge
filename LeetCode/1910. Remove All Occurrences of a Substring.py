'''
預先建表，一口氣先消掉長的 substring，減少迭代次數
Python 的 str.find 是 boyer-moore-horspool 不需要自己刻
時間 50ms 左右
'''

class Solution:
    def generate(self, part: str, ret: set, max_depth=2, depth=0, max_length=100):
        if depth >= max_depth or len(part)*2 > max_length:
            return
        for i in range(len(part)):
            new_str = f'{part[:i]}{part}{part[i:]}'
            ret.add(new_str)
            self.generate(new_str, ret, max_depth=max_depth, depth=depth+1, max_length=max_length)
    def removeOccurrences(self, s: str, part: str) -> str:
        candidates = set([part])
        self.generate(part, candidates)

        while True:
            found = False
            for c in candidates:
                index = s.find(c)
                if index >= 0:
                    s = f'{s[:index]}{s[index+len(c):]}'
                    found = True
            if not found:
                break
        return s
