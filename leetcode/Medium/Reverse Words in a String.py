
def reverseWords(s: str) -> str:
    words = s.strip().split(' ')
    ans = ""
    for w in words[::-1]:
        w = w.strip()
        if len(w):
            ans += w + " "
    return ans[:-1]