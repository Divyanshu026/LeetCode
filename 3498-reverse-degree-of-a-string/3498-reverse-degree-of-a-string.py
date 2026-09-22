class Solution:
    def reverseDegree(self, s: str) -> int:
        # x = 'z'-'a'
        res = 0
        # print(x)
        for i in range(len(s)):
            value = ord('z') - ord(s[i]) + 1
            res+= (i+1)*(value)
        return res