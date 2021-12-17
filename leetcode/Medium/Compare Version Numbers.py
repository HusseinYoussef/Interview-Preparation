
def compareVersion(version1: str, version2: str) -> int:
    
    revisions1 = version1.split('.')
    revisions2 = version2.split('.')
    
    l = max(len(revisions1), len(revisions2))
    for idx in range(l):
        r1 = 0
        r2 = 0
        if idx < len(revisions1):
            r1 = int(revisions1[idx])
        if idx < len(revisions2):
            r2 = int(revisions2[idx])
        if r1 < r2:
            return -1
        elif r1 > r2:
            return 1
    return 0