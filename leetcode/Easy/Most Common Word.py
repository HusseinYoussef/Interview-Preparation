
def mostCommonWord(paragraph: str, banned: List[str]) -> str:
    
    mp = {}
    for w in banned:
        mp[w] = -1000000
    
    ans = ""
    mx = 0
    words = paragraph.split(' ')
    for w in words:
        s = ""
        for c in w.lower():
            if(not c.isalpha()):
                break
            s += c
        if(s not in mp.keys()):
            mp[s] = 1
        else:
            mp[s] += 1
        if mp[s] > mx:
            mx = mp[s]
            ans = s
    return ans
    