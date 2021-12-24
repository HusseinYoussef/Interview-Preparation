
def simplifyPath(path: str) -> str:
    folders = path.split('/')
    st = []
    for f in folders:
        if len(f):
            if f == '..' and len(st):
                st.pop()
            elif f != '.' and f != '..':
                st.append(f)
    ans = "/"
    for f in st:
        if len(f):
            ans += f + '/'

    return ans[:-1]