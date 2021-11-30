
def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
    words1 = s1.split()
    words2 = s2.split()
    d = {}
    for w in words1:
        if w not in d:
            d[w] = 1
        else:
            d[w] += 1
    for w in words2:
        if w not in d:
            d[w] = 1
        else:
            d[w] += 1
    ans = []
    for w in words1:
        if d[w] == 1:
            ans.append(w)
    for w in words2:
        if d[w] == 1:
            ans.append(w)
    return ans