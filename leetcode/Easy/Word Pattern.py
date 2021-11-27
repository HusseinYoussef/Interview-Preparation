
def wordPattern(pattern: str, s: str) -> bool:

    words = s.split(' ')
    if len(pattern) != len(words):
        return False

    d = {}
    t = {}
    for i in range(len(pattern)):
        if pattern[i] not in d.keys() and words[i] not in t.keys():
            d[pattern[i]] = words[i]
            t[words[i]] = pattern[i]
        else:
            if (pattern[i] not in d.keys() and words[i] in t.keys()) or (pattern[i] in d.keys() and words[i] not in t.keys()) or (d[pattern[i]] != words[i] or t[words[i]] != pattern[i]):
                return False
    return True

print(wordPattern("aaaa", "dog dog dog dog"))