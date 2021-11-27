def reverseWords(s: str) -> str:
    ans = ""
    words = s.split(' ')
    for w in words:
        ans += w[::-1] + " "
    
    return ans[:-1]

print(reverseWords("Let's take LeetCode contest"))