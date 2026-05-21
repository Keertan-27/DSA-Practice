def longestSustringwithoutRepeating(s):
    mp ={}
    left, maxLen = 0,0
    for right in range(len(s)):
        if s[right] in mp and mp[s[right]] >= left:
            left = mp[s[right]] +1
        
        mp[s[right]] = right
        maxLen = max(maxLen, right-left+1)
    
    return maxLen

s = "cadbzabcd"
ans = longestSustringwithoutRepeating(s)
print(ans)
